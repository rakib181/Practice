#include<bits/stdc++.h>
using namespace std;
const double esp=10e-6;

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    auto st=clock();
    double x;
    cin>>x;
    double lo=0,hi=x;
    while(hi-lo>esp){
      double mid=(hi+lo)/2;
      if(mid*mid>x){
         hi=mid;
      }else{
         lo=mid;
      }
    }
    cout<<lo;
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
