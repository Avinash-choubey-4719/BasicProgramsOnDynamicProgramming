#include<bits/stdc++.h>
using namespace std;

int NthFibonnaciNumber(int n){
    if(n == 0){
        return 0;
    }

    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2;i<=n;i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main(){
    int n = 10;
    int result = NthFibonnaciNumber(n);
    cout<<result<<endl;
    return 0;
}