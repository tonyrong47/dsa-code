#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {2, 3, 4, 5, 6};
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    cout << "Sum = " << sum << endl;
    return 0;
}
