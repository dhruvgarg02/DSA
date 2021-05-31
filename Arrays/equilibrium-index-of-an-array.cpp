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
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
        sum += temp;
    }
    int left = 0;
    for (int i = 0; i < n; i++) {
        if (sum - left - v[i] == left) cout<<i<<endl;
        left += v[i];
    }
    v.clear();
    return 0;
}
