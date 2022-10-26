#include<bits/stdc++.h>
using namespace std;

int findNumberOfSquences(int m, int n){
    int dp[m + 1][n + 1];

    for(int i = 0;i<=m;i++){
        for(int j = 0;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

            else if(i < j){
                dp[i][j] = 0;
            }

            else if(j == 1){
                dp[i][j] = i;
            }

            else{
                dp[i][j] = dp[i - 1][j] + dp[i/2][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main(){
    int m = 10;
    int n = 4;

    int result = findNumberOfSquences(m, n);

    cout<<result<<endl;
    return 0;
}