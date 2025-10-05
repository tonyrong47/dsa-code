class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        l =0
        r = n-1
        max_area = 0
        
        while l < r:
             w = r -l
             h = min(height[l] ,height[r])
             a = w*h
             max_area = max(max_area, a)

             if height[l] < height[r]:
                l = l+ 1
             else:
                r = r-1

        return max_area
