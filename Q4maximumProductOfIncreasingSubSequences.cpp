#include<bits/stdc++.h>
using namespace std;

long long int  maxProduct(long long int arr[], int n){
    long long int increasing[n];

    for(int i = 0;i<n;i++){
        increasing[i] = arr[i];
    }    

    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[i] > arr[j] && increasing[i] < (increasing[j] * arr[i])){
                increasing[i] = arr[i] * increasing[j];
            }
        }
    }

    return *max_element(increasing, increasing + n);
}

int main(){
    long long int arr[] = { 3, 100, 4, 5, 150, 6 };

    int n = 6;

    int result = maxProduct(arr, n);

    cout<<result<<endl;
    return 0;
}