#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

string findLRS(string str, int n){
    int dp[n + 1][n + 1];

    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            dp[i][j] = 0;
        }
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

            else if(str[i - 1] == str[j - 1] && i != j){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n;
    int j = n;
    string result = "";

    while(i > 0 && j > 0){
        if(dp[i][j] == 1 + dp[i - 1][j - 1]){
            result = result + str[i - 1];
            i--;
            j--;
        }
        

        else if(dp[i][j] == dp[i - 1][j]){
            i--;
        }

        else{
            j--;
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

int main(){
    string str = "AABEBCDD";
    int n = str.length();

    string result = findLRS(str, n);

    cout<<result<<endl;
    return 0;
}