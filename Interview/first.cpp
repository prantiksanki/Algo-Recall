#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Helper function to get the maximum in a subarray from index s to e
int getMax(const vector<int>& arr, int s, int e) {
    int maxi = INT_MIN;
    for (int i = s; i <= e && i < arr.size(); i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

// Function to get the minimum of maximums among valid windows
int minOfMaxInWindows(const vector<int>& arr, int f, int b) {
    int n = arr.size();
    int ans = INT_MAX;

    // Check all possible starting indices with at most b skips
    for (int i = 0; i <= b; i++) {
        int start = i;
        int end = i + f - 1;

        if (end >= n) continue;

        int maxi = getMax(arr, start, end);
        ans = min(ans, maxi);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 10, 2};
    int f = 2;
    int b = 2;

    cout << minOfMaxInWindows(arr, f, b) << endl;

    return 0;
}
