#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void rotate(vector<vector<int>>& v, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            swap(v[i][j], v[j][i]);

    reverse(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        cout<<endl;
        for (int j = 0; j < n; j++)
            cout<<v[i][j]<<" ";
    }
    return;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int t;
            cin>>t;
            temp.push_back(t);
        }
        v.push_back(temp);
    }
    rotate(v, n);
    return 0;
}
