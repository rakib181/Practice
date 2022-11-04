#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char ch;
    Node *next;
    explicit Node(char _ch){
        this -> ch = _ch;
        this -> next = nullptr;
    }
};

class Stack{
public:
    Node *tp;
    int sz;
    Stack(){
        this -> tp = nullptr;
        this -> sz = 0;
    }

    bool isEmpty() const{
        return tp == nullptr;
    }
    void push(char ch){
        Node *tmp = new Node(ch);
        tmp -> ch = ch;
        tmp -> next = tp;
        tp = tmp;
        sz++;
    }
     bool pop(){
        Node *tmp = tp;
        if(isEmpty()){
            return false;
        }
        tp = tp -> next;
        free(tmp);
        sz--;
        return true;
    }
    char top() const{
        return tp -> ch;
    }
}st;

bool isValid(string &input){
    for(auto ch : input){
        switch (ch) {
            case '(':
            case '{':
            case '[':
                st.push(ch);
                break;
            case ')': if(!st.isEmpty() and st.top() == '('){
                st.pop();
                }else return false;
            break;
            case '}': if(!st.isEmpty() and st.top() == '{'){
                    st.pop();
                }else return false;
            break;
            case ']': if(!st.isEmpty() and st.top() == '['){
                    st.pop();
                }else return false;
            break;
            default:
                continue;
        }
    }
    return st.isEmpty();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if(isValid(s)){
        cout << "Valid !" << '\n';
    }else cout << "Invalid !" << '\n';
    return 0;
}
