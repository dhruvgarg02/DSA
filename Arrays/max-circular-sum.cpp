#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll kadane(vector<int>& v) {
    ll curr = 0;
    ll max_sum = LONG_MIN;
    for (int i = 0; i < v.size(); i++) {
        curr += v[i];
        max_sum = max(max_sum, curr);
        if (curr < 0) curr = 0;
    }
    return max_sum;
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
        sum += temp;
    }
    ll kad = kadane(v);
    vector<int> v_neg (n);
    for (int i = 0; i < n; i++)
        v_neg[i] = -v[i];
    ll min_sum = kadane(v_neg);
    ll cir = sum + min_sum;
    kad = max(cir, kad);
    cout<<kad<<endl;
    return 0;
}
