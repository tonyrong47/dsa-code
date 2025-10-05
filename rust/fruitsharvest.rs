impl Solution {
    pub fn max_total_fruits(fruits: Vec<Vec<i32>>, start_pos: i32, k: i32) -> i32 {
        let n = fruits.len();
        let mut ans = 0;
        let mut prefix = vec![0; n + 1];
        for i in 0..n {
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }

        let mut l = 0;
        for r in 0..n {
            while l <= r && !Self::can_reach(fruits[l][0], fruits[r][0], start_pos, k) {
                l += 1;
            }
            if l <= r {
                ans = ans.max(prefix[r + 1] - prefix[l]);
            }
        }
        ans
    }
    fn can_reach(left: i32, right: i32, start: i32, k: i32) -> bool {
        let go_left_first = (start - left).abs() + (right - left);
        let go_right_first = (right - start).abs() + (right - left);
        go_left_first.min(go_right_first) <= k
    }
}
