fn quick_sort(arr: &mut [i32]) {
    if arr.len() <= 1 {
        return; // base case
    }

    let pivot_index = partition(arr);

    // Recursively sort left and right partitions
    let (left, right) = arr.split_at_mut(pivot_index);
    quick_sort(left);
    quick_sort(&mut right[1..]); // skip pivot
}

fn partition(arr: &mut [i32]) -> usize {
    let len = arr.len();
    let pivot_index = len - 1; // choose last element as pivot
    let pivot = arr[pivot_index];
    let mut i = 0;

    for j in 0..pivot_index {
        if arr[j] <= pivot {
            arr.swap(i, j);
            i += 1;
        }
    }

    arr.swap(i, pivot_index);
    i
}

fn main() {
    let mut arr = [34, 7, 23, 32, 5, 62];
    println!("Before sorting: {:?}", arr);

    quick_sort(&mut arr);

    println!("After sorting:  {:?}", arr);
}
