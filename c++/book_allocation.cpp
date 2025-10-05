
#include <iostream>
#include <algorithm>
using namespace std;

// Helper function
bool isPossible(int A[], int n, int m, int maxPages) {
    int studentsRequired = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] > maxPages) return false;
        if (currSum + A[i] > maxPages) {
            studentsRequired++;
            currSum = A[i];
            if (studentsRequired > m) return false;
        } else {
            currSum += A[i];
        }
    }
    return true;
}

// Main function to find minimum maximum pages
int allocateBooks(int A[], int n, int m) {
    if (m > n) return -1; // More students than books

    int sum = 0, maxBook = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        maxBook = max(maxBook, A[i]);
    }

    int low = maxBook, high = sum;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low)/2;
        if (isPossible(A, n, m, mid)) {
            result = mid;
            high = mid - 1; // try to minimize
        } else {
            low = mid + 1; // increase limit
        }
    }

    return result;
}

// Driver code
int main() {
    int A[] = {12, 34, 67, 90};
    int n = sizeof(A)/sizeof(A[0]);
    int m = 2; // number of students

    cout << "Minimum maximum pages = " << allocateBooks(A, n, m) << endl;
    return 0;
}
=======
// Problem: Book Allocation - Allocate minimum pages to each student
// Given an array of page counts and the number of students, find the minimum maximum pages any student can be assigned.
#include <bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int>& pages, int students, int maxPages) {
    int count = 1;
    int currPages = 0;
    for (int page : pages) {
        if (currPages + page <= maxPages) {
            currPages += page;
        } else {
            count++;
            currPages = page;
            if (page > maxPages) return false;
        }
    }
    return count <= students;
}

int bookAllocation(vector<int>& pages, int students) {
    if (pages.size() < students) return -1;
    int left = *max_element(pages.begin(), pages.end());
    int right = accumulate(pages.begin(), pages.end(), 0);
    int result = INT_MAX;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canAllocate(pages, students, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> pages = {10, 20, 30, 40};
    int students = 2;
    cout << bookAllocation(pages, students) << endl;
    return 0;
}

