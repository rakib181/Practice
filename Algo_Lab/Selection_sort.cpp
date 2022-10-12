#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &ar, int n){
    for(int i = 0; i < n; i++){
        int mn_idx = i;
        for(int j = i + 1; j < n; j++){
            if(ar[i] > ar[j])mn_idx = j;
        }
        swap(ar[i], ar[mn_idx]);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    selection_sort(ar, n);
    for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
    }
    return 0;
}