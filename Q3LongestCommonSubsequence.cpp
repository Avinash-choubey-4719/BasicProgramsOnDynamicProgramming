#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

int findLCS(string s1, string s2, int m, int n, vector<vector<int>>&dp){
    if(n == 0 || m == 0){
        return 0;
    }

    if(s1[m - 1] == s2[n - 1]){
        return dp[m][n] = 1 + findLCS(s1, s2, m - 1, n - 1, dp);
    }

    if(dp[m][n] != -1){
        return dp[m][n];
    }

    return dp[m][n] = max(findLCS(s1, s2, m, n - 1, dp), findLCS(s1, s2, m - 1, n, dp));
}

int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    int result = findLCS(s1, s2, m, n, dp);

    cout<<result<<endl;
    return 0;
}