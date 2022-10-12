#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++)cin >> ar[i];
    for(int i = 1; i < n; i++){
        int j = i - 1, key = ar[i];
        while(j >= 0 and ar[j] > key){
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;
    }
    for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
    }
    return 0;
}
