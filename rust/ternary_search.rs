fn ternary_search(arr: &[i32], target: i32) -> Option<usize> {
    let mut left = 0;
    let mut right = arr.len() - 1;

    while left <= right {
        let mid1 = left + (right - left) / 3;
        let mid2 = right - (right - left) / 3;

        if arr[mid1] == target {
            return Some(mid1);
        }
        if arr[mid2] == target {
            return Some(mid2);
        }

        if target < arr[mid1] {
            // Search in left one-third
            if mid1 == 0 { break; } // prevent underflow
            right = mid1 - 1;
        } else if target > arr[mid2] {
            // Search in right one-third
            left = mid2 + 1;
        } else {
            // Search in middle one-third
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    None
}

fn main() {
    let arr = [2, 4, 6, 8, 10, 12, 14, 16, 18];
    let target = 14;

    match ternary_search(&arr, target) {
        Some(index) => println!("Found {} at index {}", target, index),
        None => println!("{} not found in array", target),
    }
}
