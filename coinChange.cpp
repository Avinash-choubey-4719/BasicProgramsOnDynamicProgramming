#include<bits/stdc++.h>
using namespace std;

int coinChange(int coins[], int n, int sum){
    int dp[sum + 1][n + 1];

    for(int i = 0;i<=n;i++){
        dp[0][i] = 1;
    }

    for(int i = 1;i<=sum;i++){
        for(int j = 0;j<=n;j++){
            int x = i>=coins[j]?dp[i - coins[j]][j]:0;

            int y = j>=1?dp[i][j - 1]:0;

            dp[i][j] = x + y;
        }
    }

    return dp[sum][n];
}

int main(){
    int coins[] = {2, 5, 3, 6};
    int sum = 10;

    int result = coinChange(coins, 4, sum);
    cout<<result<<endl;
    return 0;
}