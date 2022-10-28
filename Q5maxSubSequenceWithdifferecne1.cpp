#include<bits/stdc++.h>
using namespace std;

int findMaxLength(int arr[], int n){
    int dp[n];

    for(int i = 0;i<n;i++){
        dp[i] = 1;
    }

    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(abs(arr[i] - arr[j]) == 1){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    return *max_element(dp, dp + n);
}

int main(){
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = 7;

    int result = findMaxLength(arr, n);

    cout<<result<<endl;
    return 0;
}