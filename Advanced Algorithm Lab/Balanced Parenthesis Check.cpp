#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string& input){
    stack<char> st;
    for(auto ch : input) {
        switch (ch) {
            case '(':
            case '{':
            case '[':
                st.push(ch);
                break;
            case ')':
                if (!st.empty() and st.top() == '(') {
                    st.pop();
                }else return false;
                break;
            case '}':
                if (!st.empty() and st.top() == '{') {
                    st.pop();
                } else return false;
                break;
            case ']':
                if (!st.empty() and st.top() == '[') {
                    st.pop();
                } else return false;
                break;
            default:
                continue;
        }
    }
    if(st.empty())return true;
    else return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if(isBalanced(s)){
        cout << "Balanced !" << '\n';
    }else cout << "Not Balanced !" << '\n';
    return 0;
}
