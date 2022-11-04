#include<bits/stdc++.h>
using namespace std;
#define int long long int

int ways(vector<int> &ar, int n, int k, vector<vector<int>> &dp){
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - ar[i] >= 0)dp[i][j] += dp[i][j - ar[i]];
        }
    }
    return dp[n][k];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> ar(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    vector<vector<int>> dp(n + 2, vector<int> (k + 2, 0));
    cout << ways(ar, n, k, dp) << '\n';
    return 0;
}
