//main diffrence between greedy and dp is , in greedy we have predefined process and in dp we have to try all 


// memozition or top-down approch
// we store result for future use in an array
//    vector<int>dp(n+1 , -1);

#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    int n = 100;
    vector<int> dp(n + 1, -1);
    int ans = fib(n, dp);
    cout << ans << endl;

    return 0;
}


//tabulation or bottom-up aprochhhhh

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n = 10;
    vector<int> fib(n + 1, 0);
    fib[0] =0;
    fib[1]=1;
    for(int i =2;i<=n;i++){
        fib[i] = fib[i-2]+fib[i-1];
    }
    cout << fib[n] << endl;
    return 0;
}
