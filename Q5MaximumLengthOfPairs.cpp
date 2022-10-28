#include<bits/stdc++.h>
using namespace std;

struct pairs{
    int a;
    int b;
};

int findMaxLength(pairs arr[], int n){
    int dp[n];

    for(int i = 0;i<n;i++){
        dp[i] = 1;
    }

    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[i].a > arr[j].b && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }

   return *max_element(dp, dp + n);
}

int main(){
    pairs arr[] = { {5, 24}, {15, 25}, {27, 40}, {50, 60} };
    int n = 4;

    int result = findMaxLength(arr, n);

    cout<<result<<endl;
    return 0;
}