#include <bits/stdc++.h>
using  namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    auto partition = [&](int l, int r)-> int{
        int pivot = ar[l];
        int i = l;
        for(int k = l + 1; k <= r; k++){
            if(ar[k] <= pivot){
                swap(ar[++i], ar[k]);
            }
        }
        if(ar[i] < ar[l])swap(ar[i], ar[l]);
        return i;
    };
    function<void (int, int)> quick = [&](int l, int r){
        if(l < r){
            int p = partition(l, r);
            quick(l, p - 1);
            quick(p + 1, r);
        }
    };
    quick(0, n - 1);
    for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
    }
    return 0;
}