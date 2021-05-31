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
    unordered_map<int, int> mp;
    int curr_sum = 0;
    for (int i = 0 ; i < n; i++) {
        curr_sum += v[i];
        if (curr_sum == k) {
            cout<<"Subarray with sum "<<k<<" starts at "<<0<<" and ends at "<<i<<"\n";
            return 0;
        }
        if (mp.find(curr_sum-k) != mp.end()) {
            cout<<"Subarray with sum "<<k<<" starts at "<<mp[curr_sum-k] + 1<<" and ends at "<<i<<"\n";
            return 0;
        }
        mp[curr_sum] = i;
    }
    cout<<"There is no subarray with sum "<<k<<" !!\n";
    return 0;
}
