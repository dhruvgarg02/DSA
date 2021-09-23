#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void recursion(vector<vector<int>> &res, vector<int> &curr, int i, int &n, int &k) {
    if (curr.size() == k) {
        res.push_back(curr);
        return;
    }


    for (int j = i; j < n+1; j++) {
        curr.push_back(j);
        recursion(res, curr, j+1, n, k);
        curr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../Input.txt","r",stdin);
    freopen("../Output.txt","w",stdout);
    #endif

    int n, k;
    cin >> n >> k;

    vector<vector<int>> res;
    vector<int> curr;

    recursion(res, curr, 1, n, k);a

    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}
