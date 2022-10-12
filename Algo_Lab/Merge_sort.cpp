#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &ar, int l, int mid, int r){
    int i = l, j = mid + 1;
    vector<int> tmp;
    while(i <= mid and j <= r){
        if(ar[i] < ar[j])tmp.push_back(ar[i++]);
        else tmp.push_back(ar[j++]);
    }
    while(i <= mid){
        tmp.push_back(ar[i++]);
    }
    while(j <= r){
        tmp.push_back(ar[j++]);
    }
    for(int idx = l, k = 0; idx <= r; idx++){
        ar[idx] = tmp[k++];
    }
}

void merge_sort(vector<int> &ar, int l, int r){
    if(l < r){
        int mid = (l + r) >> 1;
        merge_sort(ar, l, mid);
        merge_sort(ar, mid + 1, r);
        merge(ar, l, mid, r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    merge_sort(ar, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
    }
}