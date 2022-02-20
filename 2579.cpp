#include <iostream>

using namespace std;

int stairs[301]={0};
int dp[301]={0};

int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> stairs[i];
    }
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = stairs[0] > stairs[1] ? stairs[0]+stairs[n] : stairs[1]+stairs[n];
    for(int i=3;i<n;i++){
        dp[i] = dp[i-2] + stairs[i] > dp[i-3] + stairs[i-1] + stairs[i] ? dp[i-2] + stairs[i] : dp[i-3] + stairs[i-1] + stairs[i];
    }
    
    printf("%d", dp[n-1]);
}