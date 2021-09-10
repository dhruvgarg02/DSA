#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

vector<string> keypad{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void letterCombinations(string digits, string& curr, vector<string>& res, int i) {
    if (i == digits.length()) {
        res.push_back(curr);
        return;
    }

    int n = keypad[digits[i] - '0'].size();
    for (int j = 0; j < n; j++) {
        curr.push_back(keypad[digits[i]-'0'][j]);
        letterCombinations(digits, curr, res, ++i);
        i--;
        curr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    string digits;
    cin>>digits;
    vector<string> res;
    string curr;
    letterCombinations(digits, curr, res, 0);
    for (auto i : res) {
        cout << i << endl;
    }

    return 0;
}
