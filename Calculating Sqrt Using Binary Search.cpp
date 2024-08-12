#include<bits/stdc++.h>
using namespace std;
const double esp=10e-6;

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);
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
   return 0;
}
