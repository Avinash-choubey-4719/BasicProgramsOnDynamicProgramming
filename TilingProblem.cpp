#include<bits/stdc++.h>
using namespace std;

int getNumberOFWays(int n){
    int ways[n + 1];

    ways[0] = 0;
    ways[1] = 1;

    for(int i = 2;i<=n;i++){
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    return ways[n];
}

int main(){
    int n = 5;

    int result = getNumberOFWays(n);

    cout<<result<<endl;

    return 0;
}