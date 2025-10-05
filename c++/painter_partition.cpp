#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int boards[], int n, int k, long long maxTime) {
    int paintersRequired = 1;
    long long currSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return false;
        if (currSum + boards[i] > maxTime) {
            paintersRequired++;
            currSum = boards[i];
            if (paintersRequired > k) return false;
        } else {
            currSum += boards[i];
        }
    }
    return true;
}

long long painterPartition(int boards[], int n, int k) {
    long long sum = 0;
    int maxBoard = 0;
    for (int i = 0; i < n; i++) {
        sum += boards[i];
        maxBoard = max(maxBoard, boards[i]);
    }

    long long low = maxBoard, high = sum, result = 0;

    while (low <= high) {
        long long mid = low + (high - low)/2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1; // try to minimize time
        } else {
            low = mid + 1; // increase time
        }
    }

    return result;
}

int main() {
    int boards[] = {10, 20, 30, 40};
    int n = sizeof(boards)/sizeof(boards[0]);
    int k = 2; // painters

    cout << "Minimum time required = " << painterPartition(boards, n, k) << endl;
    return 0;
}
