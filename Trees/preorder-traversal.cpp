#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;

    //constructor
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree() {
    int d;
    cin>>d;
    if (d == -1) return NULL;
    Node *node = new Node(d);
    node->left = buildTree();
    node->right = buildTree();
    return node;
}

void preorder_recursion(Node *root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->data);
    preorder_recursion(root->left, res);
    preorder_recursion(root->right, res);
}

void preorder_iteration(Node *root, vector<int>& res) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);

    while(!s.empty()) {
        Node* curr = s.top(); s.pop();
        res.push_back(curr->data);
        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}

void preorder_space_saver_iteration(Node *root, vector<int>& res) {
    if (!root) return;
    stack<Node*> s;

    Node* curr = root;
    while(curr or !s.empty()) {
        while(curr) {
            res.push_back(curr->data);
            if (curr->right) s.push(curr->right);
            curr = curr->left;
        }
        if (!s.empty()) {
            curr = s.top(); s.pop();
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    Node *root = buildTree();
    vector<int> res;

    preorder_recursion(root, res);
    for (auto i : res) cout<<i<<" ";
    cout<<"\n";
    res.clear();

    preorder_iteration(root, res);
    for (auto i : res) cout<<i<<" ";
    cout<<"\n";
    res.clear();

    preorder_space_saver_iteration(root, res);
    for (auto i : res) cout<<i<<" ";
    cout<<"\n";
    res.clear();

    return 0;
}
