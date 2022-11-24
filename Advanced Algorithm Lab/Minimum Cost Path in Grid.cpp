#include <bits/stdc++.h>
using namespace std;

void min_cost_path(vector<vector<int>> &grid, int n, int m){
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    vector<vector<pair<int, int>>> path(n + 1, vector<pair<int, int>> (m + 1));
    dp[0][0] = grid[0][0]; path[0][0] = {0, 0};
    for(int i = 1; i < m; i++){
        dp[0][i] += dp[0][i - 1] + grid[0][i];
        path[0][i] = {0, i - 1};
    }
    for(int i = 1; i < n; i++){
        dp[i][0] +=  dp[i - 1][0] + grid[i][0];
        path[i][0] = {i - 1, 0};
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dp[i - 1][j] >= dp[i][j - 1]){
                dp[i][j] = dp[i][j - 1] + grid[i][j];
                path[i][j] = {i, j - 1};
            }else{
                dp[i][j] = dp[i - 1][j] + grid[i][j];
                path[i][j] = {i - 1, j};
            }
        }
    }
    stack<pair<int, int>> st;
    int ii = n - 1, jj = m - 1;
    while (true){
        if (ii == 0 and jj == 0)break;
        st.push({ii, jj});
        int i = path[ii][jj].first;
        int j = path[ii][jj].second;
        ii = i; jj = j;
    }
    st.push({ii, jj});
    cout << "Minimum cost : " << dp[n - 1][m - 1] << '\n' << "Path -> ";
    while (!st.empty()){
        cout << "(" << st.top().first << "," << st.top().second << ")" << ' ';
        st.pop();
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int> (m + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    min_cost_path(grid, n, m);
    return 0;
}
