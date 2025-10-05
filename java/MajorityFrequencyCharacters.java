//#leetcodeProblem number--3692
import java.util.*;

class Solution {
    public String majorityFrequencyGroup(String s) {
        Map<Character,Integer> freq = new HashMap<>();
        for(char ch : s.toCharArray())
            freq.put(ch, freq.getOrDefault(ch, 0) + 1);

        Map<Integer,List<Character>> group = new HashMap<>();
        for(Map.Entry<Character,Integer> entry : freq.entrySet())
            group.computeIfAbsent(entry.getValue(), k -> new ArrayList<>()).add(entry.getKey());

        int maxgroupsize = 0, chosenFreq = 0;
        for(Map.Entry<Integer,List<Character>> entry : group.entrySet()) {
            int freqVal = entry.getKey(), size = entry.getValue().size();
            if(size > maxgroupsize || (size == maxgroupsize && freqVal > chosenFreq)) {
                maxgroupsize = size;
                chosenFreq = freqVal;
            }
        }

        List<Character> res = group.get(chosenFreq);
        StringBuilder sb = new StringBuilder();
        for(char ch : res)
            sb.append(ch);
        return sb.toString();
    }
}
