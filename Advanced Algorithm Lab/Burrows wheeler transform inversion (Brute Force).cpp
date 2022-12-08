#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = (int) s.size(), nn = n - 1;
    vector<string> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = s[i];
    }
    sort(ans.begin(), ans.end());
    while (nn--) {
       for(int i = 0; i < n; i++){
           ans[i] = s[i] + ans[i];
       }
       sort(ans.begin(), ans.end());
    }
    for(int i = 1; i < n; i++){
        cout << ans[0][i];
    }
    return 0;
}
