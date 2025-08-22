#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int lcs(string &s1 , string &s2 , int n , int m){
    for(int i =0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }

    for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
            }
        }
    }

    return dp[n][m];
}
int main() {
    
    string s1 = "hgdv", s2 = "hdgaaa";

    cout << lcs(s1 , s2 , 4 , 6) << endl;
    return 0;
}
