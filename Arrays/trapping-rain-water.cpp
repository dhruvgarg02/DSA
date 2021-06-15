#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int trappingWater(int arr[], int n){
        int l = 0, r = n-1, maxl = 0, maxr = 0, water = 0;
        while(l!=r){
            if(arr[l] <= arr[r]){
                maxl = max(maxl, arr[l]);
                water += maxl - arr[l];
                l++;
            }
            else{
                maxr = max(maxr, arr[r]);
                water += maxr - arr[r];
                r--;
            }
        }
        return water;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        cout << obj.trappingWater(a, n) << endl;
    }
    return 0;
}
