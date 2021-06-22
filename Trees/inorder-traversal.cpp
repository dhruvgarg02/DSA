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

void inorder_recursion(Node* root, vector<int>& res) {
    if (!root) return;
    inorder_recursion(root->left, res);
    res.push_back(root->data);
    inorder_recursion(root->right, res);
}

void inorder_iterative(Node* root, vector<int>& res) {
    stack<Node *> s;

    while (root or !s.empty()) {

        while (root) {
            s.push(root);
            root = root->left;
        }

        root = s.top(); s.pop();
        res.push_back(root->data);
        root = root->right;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    Node* root = buildTree();

    vector<int> res;
    inorder_recursion(root, res);
    for (auto i : res) cout<<i<<" ";
    cout<<"\n";
    res.clear();

    inorder_iterative(root, res);
    for (auto i : res) cout<<i<<" ";
    cout<<"\n";
    res.clear();

    return 0;
}
