class Solution
  def can_ship_within_days(weights, capacity, days)
    current_weight = 0
    days_needed = 1

    weights.each do |weight|
      if current_weight + weight > capacity
        days_needed += 1
        current_weight = weight
        return false if days_needed > days
      else
        current_weight += weight
      end
    end

    true
  end

  def ship_within_days(weights, days)
    left = weights.max
    right = weights.sum

    while left < right
      mid = left + (right - left) / 2
      if can_ship_within_days(weights, mid, days)
        right = mid
      else
        left = mid + 1
      end
    end

    left
  end
end
