#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int res = 0; int curr_sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        curr_sum += v[i];
        if (mp.find(curr_sum-k) != mp.end())
            res += mp[curr_sum-k];
        mp[curr_sum]++;
    }
    cout<<res;
    v.clear();
    return 0;
}
