#include<bits/stdc++.h>
using namespace std;

int findMaxSum(int arr[], int index, int n, int k){
    int dp[n][n];

    for(int i = 0;i<n;i++){
        if(arr[i] > arr[0]){
            dp[0][i] = arr[i] + arr[0];
        }
        else{
            dp[0][i] = arr[i];
        }
    }

    for(int i = 1;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[j] > arr[i] && j > i){
                if(dp[i - 1][i] + arr[j] > dp[i - 1][j]){
                    dp[i][j] = dp[i - 1][i] + arr[j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[index][k];
}

int main(){
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = 7;

    int index = 4;
    int k = 6;

    int result = findMaxSum(arr, index, n, k);
    cout<<result<<endl;
    return 0;
}