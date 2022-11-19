#include<bits/stdc++.h>
using namespace std;
#define int long long int

int count_path(int n, int m, vector<vector<int>> &grid){
    for(int i = 0; i <= n; i++){
        grid[i][0] = 1;
    }
    for(int i = 0; i <= m; i++){
        grid[0][i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            grid[i][j] += (grid[i - 1][j] + grid[i][j - 1]);
        }
    }
    return grid[n][m];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int> (m + 1));
    cout << count_path(n, m, grid) << '\n';
    return 0;
}
