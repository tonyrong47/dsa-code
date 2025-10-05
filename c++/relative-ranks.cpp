#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedScore = score;
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        unordered_map<int, string> rankMapping;
        for (int i = 0; i < sortedScore.size(); i++) {
            if (i < 3) {
                rankMapping[sortedScore[i]] = medals[i];
            } else {
                rankMapping[sortedScore[i]] = to_string(i + 1);
            }
        }
        vector<string> result;
        for (int s : score) {
            result.push_back(rankMapping[s]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> score = {10, 3, 8, 9, 4};

    cout << "Scores: ";
    for (int sc : score) cout << sc << " ";
    cout << endl;

    vector<string> ranks = s.findRelativeRanks(score);

    cout << "Ranks: ";
    for (auto& r : ranks) cout << r << " ";
    cout << endl;

    return 0;
}
