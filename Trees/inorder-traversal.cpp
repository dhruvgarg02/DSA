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

void inorder_iterative(Node* root) {
    stack<Node *> s;
    Node *curr = root;

    while (curr or !s.empty()) {

        while (curr) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top(); s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
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

    inorder_iterative(root);

    return 0;
}
