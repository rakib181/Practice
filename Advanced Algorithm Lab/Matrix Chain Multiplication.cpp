#include<bits/stdc++.h>
using namespace std;
#define int long long int

int Matrix_chain_multiplication(vector<int> &p, int n){
    vector<vector<int>> M(n, vector<int> (n, INT_MAX));
    for(int i = 1; i < n; i++){
        M[i][i] = 0;
    }
    for(int L = 2; L < n; L++){
        for(int i = 1; i + L - 1 < n; i++){
            int j = i + L - 1;
            for(int k = i; k < j; k++){
                M[i][j] = min(M[i][j], M[i][k] + M[k + 1][j] + (p[i - 1] * p[k] * p[j]));
            }
        }
    }
    return M[1][n - 1];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++)cin >> p[i];
    cout << Matrix_chain_multiplication(p, n)  << '\n';
    return 0;
}
