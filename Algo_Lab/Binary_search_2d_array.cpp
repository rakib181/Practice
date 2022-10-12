#include <bits/stdc++.h>
using namespace std;

bool binary(vector<vector<int>> &ar, int x){
   int row = ar.size() - 1, col = ar[0].size() - 1;

   int low = 0, high = row * col - 1;
   while(low <= high){
       int mid = low + (high - low) / 2;
       if(ar[mid / col][mid % col] == x)return true;
       else if(ar[mid / col][mid % col] < x){
           low = mid + 1;
       }else high = mid - 1;
   }
    return false;
}

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> ar(n + 1, vector<int> (m + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ar[i][j];
        }
    }
    cout << binary(ar, x) << '\n';
    return 0;
}