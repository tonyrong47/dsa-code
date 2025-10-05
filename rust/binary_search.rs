fn binary_search(arr: &[i32], target: i32) -> Option<usize> {
    let mut low = 0;
    let mut high = arr.len();

    while low < high {
        let mid = low + (high - low) / 2;
        if arr[mid] == target {
            return Some(mid);
        } else if arr[mid] < target {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    None
}

fn main() {
    let arr = [1, 3, 5, 7, 9, 11, 13];
    let target = 7;

    match binary_search(&arr, target) {
        Some(index) => println!("Found {} at index {}", target, index),
        None => println!("{} not found in array", target),
    }
}
