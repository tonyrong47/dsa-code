/*
Question:
Given a sorted array and a target, find the index of the largest element 
that is strictly smaller than the target (Predecessor).

If no such element exists, return -1.

Example:
Input: arr = [2, 4, 6, 8, 10], target = 7
Output: 6
Explanation: 6 is the largest element < 7
*/

function predecessor(arr, target) {
  let low = 0;
  let high = arr.length - 1;

  while (low <= high) {
    let mid = Math.floor((low + high) / 2);

    if (arr[mid] < target) {
      // arr[mid] is a valid candidate, but maybe there's a larger one
      low = mid + 1; // move right to find a larger candidate
    } else {
      // arr[mid] >= target → go left
      high = mid - 1;
    }
  }

  return high >= 0 ? high : -1;
}

// Example runs:
console.log(predecessor([2, 4, 4, 6, 6, 8, 10], 7)); // Output: 4
console.log(predecessor([2, 4, 6, 8, 10], 1)); // Output: -1 (no smaller element)
console.log(predecessor([2, 4, 6, 8, 10, 10], 10)); // Output: 3
