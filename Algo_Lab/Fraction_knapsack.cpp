#include <bits/stdc++.h>
using namespace std;

struct triplet{
    double profit, cost, p_and_c;
};

class compare{
public:
    bool operator()(const triplet a, const triplet b){
        return a.p_and_c > b.p_and_c;
    }
}cmp;

double frac_knap(vector<triplet> &ar, int n, int weight){
    double tot_prof = 0.0;
    for(int i = 0; i < n; i++){
        if(ar[i].cost <= weight){
            tot_prof += ar[i].profit;
            weight -= ar[i].cost;
        }else{
            tot_prof += ar[i].profit * (weight / ar[i].cost);
            break;
        }
    }
    return tot_prof;
}

int main(){
    int n, weight;
    cin >> n>> weight;
    vector<triplet> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i].profit >> ar[i].cost;
        ar[i].p_and_c = ar[i].profit / ar[i].cost;
    }
    sort(ar.begin(), ar.end(), cmp);
    cout << frac_knap(ar, n, weight) << '\n';
    return 0;
}