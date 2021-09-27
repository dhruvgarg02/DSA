#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void print_1_to_N(int n) {
    if (n == 0) return;
    print_1_to_N(n-1);
    cout << n << " ";
}

void print_N_to_1(int n) {
    if (n == 0) return;
    cout << n << " ";
    print_N_to_1(n-1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../Input.txt","r",stdin);
    freopen("../Output.txt","w",stdout);
    #endif

    int n;
    cin >> n;

    print_1_to_N(n);
    cout << endl;
    print_N_to_1(n);

    return 0;
}
