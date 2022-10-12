#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    function<void(int, int, int)> merge = [&](int l, int mid, int r){
        vector<int> tmp;
        int i = l, j = mid + 1;
        while(i <= mid and j <= r){
            if(ar[i] >= ar[j]){
                tmp.push_back(ar[j++]);
            }else tmp.push_back(ar[i++]);
        }
        while (i <= mid){
            tmp.push_back(ar[i++]);
        }
        while(j <= r){
            tmp.push_back(ar[j++]);
        }
        for(int i = l, k = 0; i <= r; i++){
           ar[i] = tmp[k++];
        }
    };

    function<void(int, int)> merge_sort = [&](int l, int r){
        if(l < r){
            int mid = (l + r) >> 1;
            merge_sort(l, mid);
            merge_sort(mid + 1, r);
            merge(l, mid, r);
        }
    };
    merge_sort(0, n - 1);
    for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
    }
    return 0;
}