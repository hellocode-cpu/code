#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumPlatform(int n, vector<int>& arr, vector<int>& dep) {
        // Sorting both arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platforms_needed = 0, max_platforms = 0;
        int i = 0, j = 0;

        while (i < n && j < n) {
            // If next event in sorted order is arrival, increment count of platforms needed
            if (arr[i] <= dep[j]) {
                platforms_needed++;
                i++;
            }
            // If next event in sorted order is departure, decrement count of platforms needed
            else {
                platforms_needed--;
                j++;
            }

            // Update the maximum platforms needed
            max_platforms = max(max_platforms, platforms_needed);
        }

        return max_platforms;
    }
};

int main() {
    Solution sol;
    int n = 6;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    
    cout << "Minimum number of platforms required: " << sol.minimumPlatform(n, arr, dep) << endl;
    
    return 0;
}
