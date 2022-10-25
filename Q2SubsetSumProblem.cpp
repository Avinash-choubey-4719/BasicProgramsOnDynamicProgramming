#include<bits/stdc++.h>
using namespace std;

bool hasSubsetWithGivenSum(int arr[], int sum, int n){
    bool dp[sum + 1][n + 1];

    for(int i = 0;i<=n;i++){
        dp[0][i] = true;
    }

    for(int i = 1;i<=sum;i++){
        dp[0][i] = false;
    }

    for(int i = 1;i<=sum;i++){
        for(int j = 1;j<=n;j++){
            dp[i][j] = dp[i - arr[j - 1]][j] || dp[i][j - 1];
        }
    }

    return dp[sum][n];
}

int main(){
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = 6;

    int sum = 9;
    int result = hasSubsetWithGivenSum(arr, sum, n);

    cout<<result<<endl;
    return 0;
}