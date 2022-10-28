#include<bits/stdc++.h>
using namespace std;

int findMaxLenght(int arr[], int n){
    int dp[n];

    for(int i = 0;i<n;i++){
        dp[i] = 1;
    }

    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(abs(arr[j] - arr[i]) <= 1){
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

    int result = findMaxLenght(arr, n);
    cout<<result<<endl;
    return 0;  
}