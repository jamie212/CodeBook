// Given two strings word1 and word2
// return the minimum number of operations required to convert word1 to word2.
// operations: insert a character, delete a character, replace a character
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minOperation(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // dp[i][j]: num of operation for turning word1[0 ~ i - 1] into word2[0 ~ j - 1]
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j; // word1 is empty, insert all of word2
            } 
            else if (j == 0) {
                dp[i][j] = i; // word2 is empty, remove all of word1
            } 
            else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            } 
            else {
                dp[i][j] = min({dp[i - 1][j] + 1,       // Remove
                                dp[i][j - 1] + 1,       // Insert
                                dp[i - 1][j - 1] + 1}); // Replace
            }
        }
    }

    return dp[m][n];
}


int main(){
    string word1 = "horse";
    string word2 = "ros";

    cout << "Minimum operations required: " << minOperation(word1, word2) << endl;
    return 0;
}

