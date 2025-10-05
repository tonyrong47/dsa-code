#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

// Comparator to sort activities by finish time
bool cmp(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cin >> n; // number of activities

    vector<Activity> activities(n);
    for(int i = 0; i < n; i++)
        cin >> activities[i].start >> activities[i].finish;

    // Sort activities by finish time
    sort(activities.begin(), activities.end(), cmp);

    int count = 0;
    int lastFinish = -1;

    for(auto act : activities) {
        if(act.start >= lastFinish) {
            count++;
            lastFinish = act.finish;
            cout << "Selected activity: (" << act.start << ", " << act.finish << ")\n";
        }
    }

    cout << "Maximum number of non-overlapping activities: " << count << endl;

    return 0;
}
