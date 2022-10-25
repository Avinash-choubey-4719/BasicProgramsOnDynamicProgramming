#include<bits/stdc++.h>
using namespace std;

bool hasSubsetSumDivisibleByM(int arr[], int n, int m){
    bool dp[m + 1];
    memset(dp, false, m + 1);

    for(int i = 0;i<n;i++){
        if(dp[0] ==  true){
            return true;
        }

        int temp[m];
        memset(temp, false, m);

        for(int j = 0;j<m;j++){
            if(dp[j] == true){
                if(dp[(j + arr[i]) % m] == false){
                    temp[j + arr[i] % m] = true;
                }
            }
        }

        for(int j = 0;j<m;j++){
            if(temp[j]){
                dp[j] = true;
            }
        }

        dp[arr[i] % m] = true;
    }
}

int main(){
    int arr[] = {3, 1, 7, 5};
    int n = 4;
    int m = 6;

    bool result = hasSubsetSumDivisibleByM(arr, n, m);
    cout<<result<<endl;
    return 0;
}