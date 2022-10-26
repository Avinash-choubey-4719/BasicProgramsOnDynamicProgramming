#include<bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n){
    int increasing[n];

    for(int i = 0;i<n;i++){
        increasing[i] = arr[i];
    }

    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[i] > arr[j] && increasing[i] < increasing[j] + arr[i]){
                increasing[i] = arr[i] + increasing[j];
            }
        }
    }

    return *max_element(increasing, increasing + n);
}

int main(){
    int arr[] = {1, 101, 2, 3, 100, 4, 5};

    int n = 7;

    int result = maxSum(arr, n);
    cout<<result<<endl;
    return 0;
}