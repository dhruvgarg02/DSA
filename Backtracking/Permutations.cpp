#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

//method 1
void method_1 (vector<int>& nums, vector<vector<int>>& res, vector<bool>& visited, vector<int>& curr) {
    if (curr.size() == nums.size()) {
        res.push_back(curr);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (visited[i] == true) continue;
        curr.push_back(nums[i]);
        visited[i] = true;
        method_1(nums, res, visited, curr);
        curr.pop_back();    // Backtracking
        visited[i] = false;
    }
}

// method 2
void method_2(vector<int>& nums, vector<vector<int>>& res, int i) {
    if (i == nums.size()) {
        res.push_back(nums);
        return;
    }

    for (int j = i; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
        method_2(nums, res, i+1);
        swap(nums[i], nums[j]);     // Backtracking
    }
}

// method 3
void method_3(vector<int>& nums, vector<vector<int>>& res) {
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
    // method_1(nums, res, visited, curr);

    // method 2
    // vector<int> curr;
    // method_2(nums, res, 0);

    // method 3
    method_3(nums, res);

    for (auto permutation : res) {
        for (auto i : permutation) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
