#include<bits/stdc++.h>
using namespace std;

int findLIS(int arr[], int n){
    int dp[n];

    dp[0] = 1;

    for(int i = 1;i<n;i++){

        dp[i] = 1;

        for(int j = 0;j<i;j++){
            if(arr[i] > arr[j] && dp[i] <= dp[j]){
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp, dp + n);
}

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };

    int n = 8;

    int result = findLIS(arr, n);

    cout<<result<<endl;
    return 0;
}