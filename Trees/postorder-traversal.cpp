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

void postorder_recursion(Node *root, vector<int>& res) {
    if (!root) return;
    postorder_recursion(root->left, res);
    postorder_recursion(root->right, res);
    res.push_back(root->data);
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

    postorder_recursion(root, res);
    for(auto i : res) cout<<i<<" ";
    cout<<"\n";
    res.empty();

    return 0;
}
