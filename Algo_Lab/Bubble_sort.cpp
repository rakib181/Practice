#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &ar, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(ar[i] > ar[j])swap(ar[i], ar[j]);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    bubble_sort(ar, n);
    for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
    }
    return 0;
}