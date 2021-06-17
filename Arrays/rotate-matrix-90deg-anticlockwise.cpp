#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void transpose(vector<vector<int>>& v, int n) {
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

void cycles(vector<vector<int>>& v, int n) {
    for (int i = 0; i < n/2; i++) {
        for (int j = i; j < n-i-1; j++) {
            int temp = v[i][j];
            v[i][j] = v[j][n-i-1];
            v[j][n-i-1] = v[n-i-1][n-j-1];
            v[n-i-1][n-j-1] = v[n-j-1][i];
            v[n-j-1][i] = temp;
        }
    }

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
    //Two methods are implemented
    // comment out one of the following methods
    transpose(v, n);
    cycles(v, n);
    return 0;
}
