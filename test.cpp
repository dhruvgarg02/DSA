#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    ll n; cin >> n;
    vector<ll> arr(n);

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << -arr[0] << endl;
        return 0;
    }

    cout << 1 << " " << n << endl;
    for (ll i = 0; i < n; i++) {
        cout << (ll)arr[i]*-n << " ";
    }
    cout << endl << 2 << " " << n << endl;
    for (ll i = 1; i < n; i++) {
        cout << (ll)arr[i]*(n-1) << " ";
    }
    cout << endl << 1 << " " << 1 << endl;
    cout << (ll)(n-1)*arr[0] << endl;

    return 0;
}
