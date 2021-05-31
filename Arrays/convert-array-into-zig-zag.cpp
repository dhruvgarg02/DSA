#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    for (int i = 1; i < n; i++) {
        if (i % 2 and v[i] < v[i-1])
            swap(v[i], v[i-1]);
        else if (!(i % 2) and v[i] > v[i-1])
            swap(v[i], v[i-1]);
    }

    for (int i : v) cout<<i<<" ";
    return 0;
}
