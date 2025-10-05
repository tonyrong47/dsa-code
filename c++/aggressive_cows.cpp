
#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int stalls[], int n, int c, int minDist) {
    int lastPos = stalls[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
            if (count == c) return true;
        }
    }
    return false;
}

int aggressiveCows(int stalls[], int n, int c) {
    sort(stalls, stalls + n);

    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (isPossible(stalls, n, c, mid)) {
            result = mid;
            low = mid + 1; // try for bigger distance
        } else {
            high = mid - 1; // reduce distance
        }
    }
// Problem: Aggressive Cows - Find the maximum minimum distance to place cows in stalls
// Given an array of stall positions and the number of cows, return the largest minimum distance possible.
#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(vector<int>& stalls, int dist, int cows) {
    int count = 1;
    int lastPos = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
    }
    return count >= cows;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int left = 1;
    int right = stalls[stalls.size() - 1] - stalls[0];
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlaceCows(stalls, mid, cows)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {

    int stalls[] = {1, 2, 8, 4, 9};
    int n = sizeof(stalls)/sizeof(stalls[0]);
    int c = 3; // number of cows

    cout << "Largest minimum distance = " << aggressiveCows(stalls, n, c) << endl;
    return 0;
}
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << aggressiveCows(stalls, cows) << endl;
    return 0;
