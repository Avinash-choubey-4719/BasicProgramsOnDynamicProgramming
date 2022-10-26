#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

string findLCS(string s1, string s2, int m, int n){
    int dp[m + 1][n + 1];

    for(int i = 0;i<=m;i++){
        for(int j = 0;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

            else if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = m;
    int j = n;
    string result = "";

    while(i > 0 && j > 0){
        if(dp[i][j] == 1 + dp[i - 1][j - 1]){
            result = result + s1[i];
            i--;
            j--;
        }   

        else if(dp[i][j] = dp[i - 1][j]){
            i--;
        }

        else{
            j--;
        }
    }

    return result;
}

int max1(int a, int b, int c){
    return a>b && a>c?a:b>c?b:c;
}

int main(){
    string s1 = "geeks";
    string s2 = "geeksfor";
    string s3 = "geeksforgeeks";

    string result1 = findLCS(findLCS(s1, s2, s1.length(), s2.length()), s3, (findLCS(s1, s2, s1.length(), s2.length())).length(), s3.length());
    string result2 = findLCS(findLCS(s2, s3, s2.length(), s3.length()), s1, (findLCS(s2, s3, s2.length(), s3.length())).length(), s1.length());
    string result3 = findLCS(findLCS(s1, s3, s1.length(), s3.length()), s2, (findLCS(s1, s3, s1.length(), s3.length())).length(), s2.length());

    int result = max1(result1.length(), result2.length(), result3.length());

    cout<<result<<endl;

    return 0;
}