#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    return a<b?a:b;
}

int PermutationCoefficient(int n, int k){
    int coef[n + 1][k + 1];

    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=min(i, k);j++){
            
            if(j == 0){
                coef[i][j] = 1;
            }

            else{
                coef[i][j] = coef[i - 1][j] + (j*coef[i - 1][j - 1]);
            }

            coef[i][j + 1] = 0;
        }
    }

    return coef[n][k];
}

int main(){
    int n = 5;
    int k = 2;

    int result = PermutationCoefficient(n, k);
    cout<<result<<endl;
    return 0;
}