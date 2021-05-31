#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
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
    int i = 0;
    int j = 0;
    int sum = v[0];
    for (int i = 1; i < n+1; i++) {
        while (sum > k and j < i-1) {
            sum -= v[j];
            j++;
        }
        if (sum == k) {
            cout<<"Subarray with sum "<<k<<" starts at "<<j<<" and ends at "<<i-1<<"\n";
            return 0;
        }
        if (i < n) sum += v[i];
    }
    cout<<"There is no subarray with sum "<<k<<" !!\n";
    return 0;
}

