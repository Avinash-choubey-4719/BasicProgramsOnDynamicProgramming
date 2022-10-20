#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    return a>b?b:a;
}

int binomialCoefficient(int n, int k){
    if(k > n){
        return 0;
    }

    if(k == 0 || n == k){
        return n;
    }

    int coef[n + 1][k + 1];

    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=min(i, k);j++){
            if(j == 0 || i == j){
                coef[i][j] = 1;
            }

            else{
                coef[i][j] = coef[i - 1][j - 1] + coef[i - 1][j];
            }
        }
    }

    return coef[n][k];
}

int main(){
    int n = 5;

    int result = binomialCoefficient(n, 2);
    cout<<result<<endl;
    return 0;
}