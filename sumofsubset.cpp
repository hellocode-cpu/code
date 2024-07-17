#include <bits/stdc++.h>
using namespace std;

// Print all subsets if there is at least one subset of set[]
// with sum equal to given sum
bool flag = 0;

void PrintSubsetSum(int i, int n, int set[], int targetSum, vector<int>& subset) {
    // targetSum is zero then there exists a subset.
    if (targetSum == 0) {
        // Prints valid subset
        flag = 1;
        cout << "[ ";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << "]";
        return;
    }

    if (i == n) {
        // return if we have reached the end of the array
        return;
    }

    // Not considering current element
    PrintSubsetSum(i + 1, n, set, targetSum, subset);

    // consider current element if it is less than or equal
    // to targetSum
    if (set[i] <= targetSum) {
        // push the current element in subset
        subset.push_back(set[i]);

        // Recursive call for consider current element
        PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset);

        // pop-back element after recursive call to restore
        // subset's original configuration
        subset.pop_back();
    }
}

// Driver code
int main() {
    // User input for the first test case
    int n, sum;
    cout << "Enter the number of elements in the set: ";
    cin >> n;
    int set[n];
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; ++i) {
        cin >> set[i];
    }
    cout << "Enter the target sum: ";
    cin >> sum;

    vector<int> subset;
    cout << "Output:\n";
    PrintSubsetSum(0, n, set, sum, subset);
    if (!flag) {
        cout << "There is no such subset";
    }
    cout << endl;

    return 0;
}
