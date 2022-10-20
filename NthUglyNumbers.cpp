#include<bits/stdc++.h>
using namespace std;

int min(int a, int b, int c){
    return a<b && a<c?a:b<c?b:c;
}

int NthUglyNumber(int n){
    int ugly[n + 1];
    ugly[0] = 1;

    int i2, i3, i5;
    i2 = i3 = i5 = 0;

    int next_multiple_of2 = 2, next_multiple_of3 = 3, next_multiple_of5 = 5;
    int next_ugly = 1;

    for(int i = 1;i<=n;i++){
        next_ugly = min(next_multiple_of2 , next_multiple_of3 , next_multiple_of5);
        ugly[i] = next_ugly;

        if(next_ugly == next_multiple_of2){
            i2++;
            next_multiple_of2 = ugly[i2] * 2;
        }

        else if(next_ugly == next_multiple_of3){
            i3++;
            next_multiple_of3 = ugly[i3] * 3;
        }

        else if(next_ugly == next_multiple_of5){
            i5++;
            next_multiple_of5 = ugly[i5] * 5;
        }
    }

    return ugly[n];
}

int main(){ 
    int n = 4;
    int result = NthUglyNumber(n);

    cout<<result<<endl;
    return 0;
}