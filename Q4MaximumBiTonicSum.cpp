#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

int maximumSumBiTonic(int arr[], int n){
    int increasing[n];
    int decreasing[n];

    for(int i = 0;i<n;i++){
        increasing[i] = arr[i];
        decreasing[i] = arr[i];
    }

    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[i] > arr[j] && increasing[i] < arr[i] + increasing[j]){
                increasing[i] = arr[i] + increasing[j];
            }
        }
    }

    for(int i = n - 2;i>=0;i--){
        for(int j = n - 1;j>i;j--){
            if(arr[i] > arr[j] && decreasing[i] < decreasing[j] + arr[i]){
                decreasing[i] = arr[i] + decreasing[j];
            }
        }
    }

    int max_sum = INT_MIN;

    for(int i = 0;i<n;i++){
        max_sum = max(max_sum, increasing[i] + decreasing[i] - arr[i]);
    }

    return max_sum;
}

int main(){
    int arr[] = { 1, 15, 51, 45, 33, 100, 12, 18, 9 };
    int n = 9;

    int result = maximumSumBiTonic(arr, n);

    cout<<result<<endl;
    return 0;
}