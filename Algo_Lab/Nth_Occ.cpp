#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n;
    cin >> s >> n;
    set<int> st;
    for(int i = 0; i < s.size(); i++)
    {
        st.insert(s[i] - '0');
    }
    int cnt = n, nth_large;
    if(st.size() < n)
    {
        cout << "NA" << '\n';
        return 0;
    }
    auto x = st.end(); x--;
    for(auto it = x; it != st.begin(); it--)
    {
        cnt--;
        if(cnt == 0)
        {
            nth_large = *it;
            break;
        }
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] - '0' == nth_large)
        {
            cout << i + 1 << '\n';
            break;
        }
    }
    return 0;
}
