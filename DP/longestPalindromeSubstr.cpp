// Given a string s, return the longest palindromic substring in s (contiguous)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string longestPalindrome(string s) {
    int start = 0, maxlen = 1, n = s.size(), curlen = 0;
        for(int i = 0; i < n; i++){
            // case1: odd length palindrome
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                curlen = right - left + 1;
                if(curlen > maxlen){
                    start = left;
                    maxlen = curlen;
                }
                left--;
                right++;
            }

            // case2: even length palindrome
            left = i, right = i + 1;
            while(left >= 0 && right < n && s[left] == s[right]){
                curlen = right - left + 1;
                if(curlen > maxlen){
                    start = left;
                    maxlen = curlen;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxlen);
}

int main() {
    string s = "babad";

    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;

    return 0;
}