#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll kadane(vector<int>& v) {
    ll curr = 0;
    ll max_sum = 0;
    for (int i = 0; i < v.size(); i++) {
        curr += v[i];
        max_sum = max(max_sum, curr);
        if (curr < 0) curr = 0;
    }
    return max_sum;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n;
        cin>>k;
        ll sum = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
            sum += v[i];
        }
        if (k > 1) {
            v.resize(n*2);
            for (int i = 0; i < n; i++)
                v[i+n] = v[i];
        }
        ll res = kadane(v);
        if (sum > 0 and k > 1)
            res += (k-2)*sum;
        cout<<res<<"\n";
    }
    return 0;
}
