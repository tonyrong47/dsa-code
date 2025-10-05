#include <iostream>
using namespace std;
class Solution
{
public:
    int earliestTime(vector<vector<int>> &tasks)
    {
        int minTime = INT_MAX;
        for (int i = 0; i < tasks.size(); i++)
        {
            int start = tasks[i][0], end = tasks[i][1];
            minTime = min(minTime, start + end);
        }
        return minTime;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> tasks = {{1, 6}, {2, 3}};
    cout << "Earliest Time to Finish One Task : " << s.earliestTime(tasks) << endl;
    return 0;
}