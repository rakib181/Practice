#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &ar, int n, int d){
    vector<int> cnt(10, 0), output(n);
    for(int i = 0; i < n; i++){
        cnt[(ar[i] / d) % 10]++;
    }
    for(int i = 1; i < 10; i++){
        cnt[i] += cnt[i - 1];
    }
    for(int i = n - 1; i >= 0; i--){
       output[--cnt[(ar[i] / d) % 10]] = ar[i];
    }
    for(int i = 0; i < n; i++){
        ar[i] = output[i];
    }
}

void radix(vector<int> &ar, int n){
    int mx = *max_element(ar.begin(), ar.end()), d = 1;
    while(mx / d){
        counting_sort(ar, n, d);
        d *= 10;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++)cin >> ar[i];
    radix(ar, n);
    for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
    }
    return 0;
}

