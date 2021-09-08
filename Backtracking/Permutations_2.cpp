#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

// Here Nums can have duplicate elements;
//method 1
void method_1 (vector<int>& nums, vector<vector<int>>& res, vector<bool>& visited, vector<int>& curr) {
    if (curr.size() == nums.size()) {
        res.push_back(curr);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (visited[i] == true) continue;
        if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;   // Important
        curr.push_back(nums[i]);
        visited[i] = true;
        method_1(nums, res, visited, curr);
        curr.pop_back();    // Backtracking
        visited[i] = false;
    }
}

// method 2
void method_2(vector<int> nums, vector<vector<int>>& res, int i) {  // Notice pass by value and NOT reference
    for (int i : nums) cout<<i <<" ";
    cout<<endl;

    if (i == nums.size()) {
        res.push_back(nums);
        return;
    }

    for (int j = i; j < nums.size(); j++) {
        if (i != j && nums[i] == nums[j]) continue;     // Important
        swap(nums[i], nums[j]);
        method_2(nums, res, i+1);
        // Here we are not swapping back to retain the sorted order of the original array
    }
}

// method 2 (Pass by reference)
void method_2_ref(vector<int>& nums, vector<vector<int>>& res, int i) {

    if (i == nums.size()) {
        res.push_back(nums);
        return;
    }

    for (int j = i; j < nums.size(); j++) {
        if (i != j && nums[i] == nums[j]) continue;
        swap(nums[i], nums[j]);
        method_2_ref(nums, res, i+1);
    }

    // restore nums
    for (int j = i+1; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
    }
}

// method 3
void method_3(unordered_map<int, int>& mp, vector<int>& curr, int n, vector<vector<int>>& res) {
    if (curr.size() == n) {
        res.push_back(curr);
        return;
    }
    for (auto [key, value] : mp) {
        if (value == 0) continue;
        curr.push_back(key);
        mp[key]--;
        method_3(mp, curr, n, res);
        mp[key]++;
        curr.pop_back();
    }
}

// method 4
void method_4(vector<int>& nums, vector<vector<int>>& res) {
    sort(nums.begin(), nums.end());
    do {
        res.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> nums(n);
    for (auto &i : nums) {
        cin >> i;
    }
    vector<vector<int>> res;

    // method 1
    // vector<bool> visited(n, false);
    // vector<int> curr;
    // sort(nums.begin(), nums.end());
    // method_1(nums, res, visited, curr);

    // method 2
    // sort(nums.begin(), nums.end());
    // method_2(nums, res, 0);

    // method 2 Pass by reference
    // sort(nums.begin(), nums.end());
    // method_2_ref(nums, res, 0);

    // method 3
    unordered_map<int, int> mp;
    for (auto i : nums) mp[i]++;
    vector<int> curr;
    int s = nums.size();
    method_3(mp, curr, s, res);

    // method 4
    // method_4(nums, res);

    for (auto permutation : res) {
        for (auto i : permutation) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
