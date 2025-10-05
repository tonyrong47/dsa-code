#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uidgid.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/kallsyms.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A kernel module to intercept sys_openat calls");

// Pointer to original system call
static asmlinkage long (*original_openat)(const struct pt_regs *);

// New system call
static asmlinkage long hook_openat(const struct pt_regs *regs)
{
    const char __user *pathname = (const char __user *)regs->di;
    char *kernel_path;
    kuid_t target_uid = make_kuid(&init_user_ns, 1000); // UID to monitor
    struct task_struct *task = current;

    kernel_path = kmalloc(256, GFP_KERNEL);
    if (!kernel_path) return original_openat(regs);

    if (strncpy_from_user(kernel_path, pathname, 255) > 0) {
        kernel_path[255] = '\0';

        if (task->real_cred->uid.val == target_uid.val) {
            pr_info("[Interceptor] User %d opened file: %s\n", target_uid.val, kernel_path);
        }
    }

    kfree(kernel_path);
    return original_openat(regs);
}

// Initialization
static int __init interceptor_init(void)
{
    pr_info("[Interceptor] Module loaded\n");

    original_openat = (void *)kallsyms_lookup_name("sys_openat");
    if (!original_openat) {
        pr_err("[Interceptor] Cannot find sys_openat\n");
        return -ENOENT;
    }

    pr_info("[Interceptor] sys_openat located at: %px\n", original_openat);

    // Note: Modifying syscall table requires bypassing protections
    // This is intentionally left as an educational example

    return 0;
}

// Exit
static void __exit interceptor_exit(void)
{
    pr_info("[Interceptor] Module unloaded\n");

    // Restore original syscall
    // This requires kernel permissions
}

module_init(interceptor_init);
module_exit(interceptor_exit);
