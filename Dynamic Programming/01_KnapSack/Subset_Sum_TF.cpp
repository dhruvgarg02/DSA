#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

bool subsetSum(vector<int>& array, int target) {
    int n = array.size();
    vector<vector<bool>> dp(n+1, vector<bool> (target+1, false));

    for (int i = 0; i < n+1; i++) {
        dp[i][0] = true;
    }

    for (int i = 0; i < n+1; i++) {
        for (int j = 1;  j < target+1; j++) {
            if (array[i-1] <= j) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - array[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];
}

bool subsetSum_1d(vector<int>& array, int target) {
    vector<bool> dp(target+1, false);

    dp[0] = 1;
    for (auto i : array) {
        for (int j = target; j >= i; j--) {
            dp[j] = dp[j] || dp[j - i];
        }
    }

    return dp.back();
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      #ifndef ONLINE_JUDGE
      freopen("Input.txt","r",stdin);
      freopen("Output.txt","w",stdout);
      #endif

      int n;
      cin >> n;
      vector<int> array;
      int temp;

      for (int i = 0; i < n; i++) {
          cin >> temp;
          array.push_back(temp);
      }

      int target;
      cin >> target;
      cout << subsetSum_1d(array, target);

      return 0;
}
