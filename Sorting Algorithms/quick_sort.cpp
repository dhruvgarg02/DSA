#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int partition(vector<int>& nums, int l, int r) {

    // Taking Last Elememt as pivot
    // int i = l, j = l;
    // int pivot = r;
    // for (j = l; j < r; j++) {
    //     if (nums[j] < nums[pivot]) {
    //         swap(nums[i], nums[j]);
    //         i++;
    //     }
    // }
    // swap(nums[i], nums[pivot]);
    // return i;

    // Taking First Element as Pivot
    int i = l+1, j;
    int pivot = l;

    for (j = l+1; j <= r; j++) {
        if (nums[j] < nums[pivot]) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i-1], nums[pivot]);
    return i-1;
}

void quickSort(vector<int>& nums, int l, int r) {
    if (l < r) {
        int pivotIndex = partition(nums, l, r);
        quickSort(nums, l, pivotIndex-1);
        quickSort(nums, pivotIndex+1, r);
    }
    return;
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
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    quickSort(nums, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
