#include<bits/stdc++.h>
using namespace std;

int BellsNumber(int n){
    int bells[n + 1][n + 1];

    bells[0][0] = 1;

    for(int i = 1;i<=n;i++){
        bells[i][0] = bells[i - 1][i - 1];

        for(int j = 1;j<=i;j++){
            bells[i][j] = bells[i - 1][j - 1] + bells[i][j - 1];
        }
    }

    return bells[n][0];
}

int main(){
    int n = 5;
    for(int i = 0;i<=n;i++){
        cout<<BellsNumber(i)<<endl;
    }

    return 0;
}