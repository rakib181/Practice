#include<bits/stdc++.h>
using namespace std;

void Egyptian_Fraction(int n, int d, vector<int> &ans){
      if(n == 0)return;
      int new_d = ceil((double) d / n);
      ans.push_back(new_d);
      Egyptian_Fraction(n * new_d - d, new_d * d, ans);
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<int> ans;
    Egyptian_Fraction(n, d, ans);
    for(int i = 0; i < (int) ans.size(); i++){
        cout << "1/" << ans[i] << "," [i == (int) ans.size() - 1];
    }
    return 0;
}
