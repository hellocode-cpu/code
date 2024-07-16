#include<iostream>
#include<cstring>
#include<vector>
#include<climits>
using namespace std;

int dp[100][100];
int matrixChainMemoised(int* p, int i, int j) {
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j],
                       matrixChainMemoised(p, i, k)
                       + matrixChainMemoised(p, k + 1, j)
                       + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MatrixChainOrder(int* p, int n) {
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}


int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a(n); // Create a vector of size n

    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> a[i];
    }

    // Initialize dp array to -1
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
    }

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(a.data(), n);

    return 0;
}
