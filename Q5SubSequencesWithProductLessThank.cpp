#include<bits/stdc++.h>
using namespace std;

int findLenght(int arr[], int n, int k){
    int dp[k + 1][n + 1];

    memset(dp, 0, sizeof(dp));

    for(int i = 1;i<=k;i++){
        for(int j = 1;j<=n;j++){
            dp[i][j] = dp[i][j - 1];

            if(arr[j - 1] <= i){
                dp[i][j] += dp[i/arr[j- 1]][j - 1] + 1;
            }
        }
    }

    return dp[k][n];
}

int main(){
    int arr[] = {1, 2, 3, 4};
    int n = 4;

    int result = findLenght(arr, n, 10);

    cout<<result<<endl;
    return 0;
}