#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void buySell(vector<int>& v, int n) {
    int buy = 0, sell = 0;
    bool flag = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > v[i-1]) {
            sell++;
            flag = 1;
        }
        else if (buy == sell) {
            buy = sell = i;
        }
        else {
            cout<<"Buy at: "<<buy<<" and Sell at: "<<sell<<"\n";
            buy = sell = i;
        }
    }
    if (flag == 0) return;
    else if (buy != n-1 and sell == n-1) {
        cout<<"Buy at: "<<buy<<" and Sell at: "<<sell;
    }
    return;
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        v.push_back(t);
    }
    buySell(v, n);
    return 0;
}
