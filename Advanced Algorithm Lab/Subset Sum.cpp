#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool subset_sum(vector<int> &Set, int n, int k, vector<vector<bool>> &dp){
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
           dp[i][j] = dp[i - 1][j];
           if(j - Set[i] >= 0){
               bool ok = dp[i][j] | dp[i - 1][j - Set[i]];
               dp[i][j] = ok;
           }
        }
    }
    return dp[n][k];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> Set(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> Set[i];
    }
    vector<vector<bool>> dp(n + 2, vector<bool> (k + 2, false));
    cout << subset_sum(Set, n, k, dp) << '\n';
    return 0;
}
