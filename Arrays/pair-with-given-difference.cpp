#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

vector<int> pairWithGivenDifference(int n, vector<int>& v, int k) {
    sort(v.begin(), v.end());
    int i = 0, j = 1;
    for (j = 1; j < n; j++) {
        if (v[j] - v[i] == k) return {v[i], v[j]};
        while(v[j] - v[i] > k and i < j) i++;
    }
    return {};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    int n; cin>>n;
    int k; cin>>k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    vector<int> res = pairWithGivenDifference(n, v, k);
    if(res.size() != 0) cout<<res[0]<<" "<<res[1];
    else cout<<"No pair found";
    return 0;
}
