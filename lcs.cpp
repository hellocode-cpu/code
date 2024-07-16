#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int lcs(char *a,char *b,int m,int n,vector<vector<int>> &dp)
{
    if(m==0||n==0)
    {
        return 0;
    }
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    if(a[m-1]==b[n-1])
    {
        return 1+lcs(a,b,m-1,n-1,dp);
    }
    return max(lcs(a,b,m,n-1,dp),lcs(a,b,m-1,n,dp));
}
int main()
{
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    int m = str1.length();
    int n = str2.length();

    // Convert strings to C-style strings
    char a[m + 1];
    char b[n + 1];
    strcpy(a, str1.c_str());
    strcpy(b, str2.c_str());
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    cout<<lcs(a,b,m,n,dp);


}
