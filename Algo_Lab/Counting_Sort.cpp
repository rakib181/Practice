#include <bits/stdc++.h>

using namespace std;

void counting_sort(vector<int> &ar, int n){
    int mx = *max_element(ar.begin(), ar.end());
    vector<int> cnt(mx + 1, 0);
    for(int i = 0; i < n; i++){
        cnt[ar[i]]++;
    }
    for(int i = 1; i <= mx; i++){
        cnt[i] += cnt[i - 1];
    }
    for(int i = n - 1; i >= 0; i--){
        ar[--cnt[ar[i]]] = ar[i];
    }
}

int main() {
     int n;
     cin >> n;
     vector<int> ar(n);
     for(int i = 0; i < n; i++){
         cin >> ar[i];
     }
     counting_sort(ar, n);
     for(int i = 0; i < n; i++){
         cout << ar[i] << ' ';
     }
    return 0;
}
