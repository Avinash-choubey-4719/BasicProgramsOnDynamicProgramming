#include<bits/stdc++.h>
using namespace std;

int NthCatalanNumbers(int n){
    int catalan[n + 1];

    catalan[0] = 1;
    catalan[1] = 1;

    for(int i = 2;i<=n;i++){
        catalan[i] = 0;

        for(int j = 0;j<i;j++){
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[n];
}

int main(){
    int n = 10;
    int result = NthCatalanNumbers(n);
    cout<<result<<endl;
    return 0;
}