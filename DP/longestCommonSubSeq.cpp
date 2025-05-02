// length of longest subsequence of two strings
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(text1[i] == text2[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else{
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    cout << "Length of Longest Common Subsequence: " << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}