#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void printPrime(int n) {
    vector<bool> prime(n+1, true);

    for (int i = 2; i*i <= n; i++) {
        if (prime[i] == true) {
            for (int j = i*i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (prime[i] == true) cout << i << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../Input.txt","r",stdin);
    freopen("../Output.txt","w",stdout);
    #endif

    printPrime(500);

    return 0;
}
