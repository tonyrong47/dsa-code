impl Solution {
    fn can_ship_within_days(weights: &Vec<i32>, capacity: i32, days: i32) -> bool {
        let mut current_weight = 0;
        let mut days_needed = 1;

        for &weight in weights.iter() {
            if current_weight + weight > capacity {
                days_needed += 1;
                current_weight = weight;
                if days_needed > days {
                    return false;
                }
            } else {
                current_weight += weight;
            }
        }
        true
    }

    pub fn ship_within_days(weights: Vec<i32>, days: i32) -> i32 {
        let mut left = *weights.iter().max().unwrap();
        let mut right: i32 = weights.iter().sum();

        while left < right {
            let mid = left + (right - left) / 2;
            if Solution::can_ship_within_days(&weights, mid, days) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        left
    }
}

struct Solution;
