#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
};

struct Node *new_node(int xx){
    Node *tmp = (Node *) malloc(sizeof (Node));
    tmp -> val = xx;
    tmp -> left = tmp -> right = nullptr;
    return tmp;
}

class BST{
public:
   Node *insert(Node *root, int xx){
        if(root == nullptr){
            return new_node(xx);
        }
        if(xx > root -> val){
           root -> right = insert(root -> right, xx);
        }else if(xx < root -> val){
           root -> left = insert(root -> left, xx);
        }
       return root;
    }
    void pre_order(Node *root){
        if(root == nullptr){
            return;
        }
        cout << root -> val << ' ';
        pre_order(root -> left);
        pre_order(root -> right);
    }

    void in_order(Node *root){
       if(root == nullptr){
           return;
       }
        in_order(root -> left);
        cout << root -> val << ' ';
        in_order(root -> right);
   }

    void post_order(Node *root){
        if(root == nullptr){
            return;
        }
        post_order(root -> left);
        post_order(root -> right);
        cout << root -> val << ' ';
    }
}BS;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *root = BS.insert(root, 50);
    BS.insert(root, 30);
    BS.insert(root, 20);
    BS.insert(root, 40);
    BS.insert(root, 70);
    BS.insert(root, 60);
    BS.insert(root, 80);
    BS.pre_order(root);
    cout << '\n';
    BS.in_order(root);
    cout << '\n';
    BS.post_order(root);
    return 0;
}
