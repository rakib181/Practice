#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &ar, int l, int r){
    int pivot = ar[r], i = l - 1;
    for(int j = l; j < r; j++){
        if(ar[j] < pivot){
            swap(ar[++i], ar[j]);
        }
    }
    swap(ar[++i], ar[r]);
    return i;
}

void quick_sort(vector<int> &ar, int l, int r){
    if(l < r){
        int p = partition(ar, l, r);
        quick_sort(ar, l, p - 1);
        quick_sort(ar, p, r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    quick_sort(ar, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
    }
    return 0;
}