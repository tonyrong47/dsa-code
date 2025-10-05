fn merge_sort(arr: &mut [i32]) {
    let len = arr.len();
    if len <= 1 {
        return; // base case
    }

    let mid = len / 2;
    let mut left = arr[..mid].to_vec();
    let mut right = arr[mid..].to_vec();

    // Recursively sort both halves
    merge_sort(&mut left);
    merge_sort(&mut right);

    // Merge the sorted halves
    merge(arr, &left, &right);
}

fn merge(arr: &mut [i32], left: &[i32], right: &[i32]) {
    let mut i = 0; // index for left
    let mut j = 0; // index for right
    let mut k = 0; // index for arr

    while i < left.len() && j < right.len() {
        if left[i] <= right[j] {
            arr[k] = left[i];
            i += 1;
        } else {
            arr[k] = right[j];
            j += 1;
        }
        k += 1;
    }

    // Copy remaining elements from left
    while i < left.len() {
        arr[k] = left[i];
        i += 1;
        k += 1;
    }

    // Copy remaining elements from right
    while j < right.len() {
        arr[k] = right[j];
        j += 1;
        k += 1;
    }
}

fn main() {
    let mut arr = [38, 27, 43, 3, 9, 82, 10];
    println!("Before sorting: {:?}", arr);

    merge_sort(&mut arr);

    println!("After sorting:  {:?}", arr);
}
