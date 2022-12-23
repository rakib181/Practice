#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Matrix_chain_multiplication(vector<int> &p, int n){
    vector<vector<int>> M(n, vector<int> (n, INT_MAX)), S(n, vector<int> (n, 0));
    for(int i = 1; i < n; i++){
        M[i][i] = 0;
        S[i][i + 1] = i;
    }
    for(int L = 2; L < n; L++){
        for(int i = 1; i + L - 1 < n; i++){
            int j = i + L - 1, temp = INT_MAX, temp_k;
            for(int k = i; k < j; k++){
               int q = M[i][k] + M[k + 1][j] + (p[i - 1] * p[k] * p[j]);
               if(temp > q){
                   temp = q;
                   temp_k = k;
               }
            }
            M[i][j] = temp;
            S[i][j] = temp_k;
        }
    }
    cout << "M - TABLE : "<< '\n';
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(i > j)cout << "      ";
            else cout << M[i][j] << "   ";
        }
        cout << '\n';
    }
    cout << "S - TABLE : " << '\n';
    for(int i = 1; i < n; i++){
        for(int j = 2; j < n; j++){
            if(i >= j)cout << "     ";
            else cout << S[i][j] << "    ";
        }
        cout << '\n';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++)cin >> p[i];
    Matrix_chain_multiplication(p, n);
    return 0;
}
