#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int max(int a, int b, int c){
    return a>b && a>c?a:b>c?b:c;
}

int max(int a, int b){
    return a>b?a:b;
}


int getMaxCoins(int grid[][MAX], int row, int column){

    int right, right_top, right_down;

    for(int i = column - 1;i>=0;i--){
        for(int j = 0;j<row;j++){

            if(i == column - 1){
                right = 0;
            }

            else{
                right = grid[j][i + 1];
            }

            if(i == column - 1 || j == 0){
                right_top = 0;
            }

            else{
                right_top = grid[j - 1][i + 1];
            }

            if(i == column - 1 || j == row - 1){
                right_down = 0;
            }

            else{
                right_down = grid[j + 1][i + 1];
            }

            grid[j][i] = grid[j][i] + max(right, right_top, right_down);
        }
    }

    int result = 0;

    for(int i = 0;i<row;i++){
        result = max(result, grid[i][0]);
    }

    return result;
}

int main(){
    int gold[MAX][MAX]= { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };

    int result = getMaxCoins(gold, 4, 4);

    cout<<result<<endl;
    return 0;
}