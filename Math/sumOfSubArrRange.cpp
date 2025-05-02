// Brute-force: O(n^2)
// Optimized: O(n)
// Thought: sum of subarray ranges = sum of max of all aub arr - sum of min of all sub arr
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long sumOfMin(vector<int>& nums) {
    int n = nums.size();
    vector<int> small_before(n, -1);
    stack<int> s;
    s.push(0);
    for(int i = 1; i < n; i++){
        while(!s.empty() && nums[i] < nums[s.top()]){
            s.pop();
        }
        if(!s.empty()) small_before[i] = s.top();
        s.push(i);
    }

    while(!s.empty()) s.pop();

    vector<long long> small_after(n, n);
    s.push(n - 1);
    for(int i = n - 2; i >= 0; i--){
        while(!s.empty() && nums[i] <= nums[s.top()]){
            s.pop();
        }
        if(!s.empty()) small_after[i] = s.top();
        s.push(i);
    }

    long long sumMin = 0;
    for(int i = 0; i < n; i++){
        sumMin += (long long)nums[i] * (long long)(i - small_before[i]) * (long long)(small_after[i] - i); 
    }
    return sumMin;
}

long long sumOfMax(vector<int>& nums) {
    int n = nums.size();
    vector<int> large_before(n, -1);
    stack<int> s;
    s.push(0);
    for(int i = 1; i < n; i++){
        while(!s.empty() && nums[i] > nums[s.top()]){
            s.pop();
        }
        if(!s.empty()) large_before[i] = s.top();
        s.push(i);
    }

    while(!s.empty()) s.pop();

    vector<long long> large_after(n, n);
    s.push(n - 1);
    for(int i = n - 2; i >= 0; i--){
        while(!s.empty() && nums[i] >= nums[s.top()]){
            s.pop();
        }
        if(!s.empty()) large_after[i] = s.top();
        s.push(i);
    }

    long long sumMax = 0;
    for(int i = 0; i < n; i++){
        sumMax += (long long)nums[i] * (long long)(i - large_before[i]) * (long long)(large_after[i] - i); 
    }
    return sumMax;
}
int main() {
    vector<int> nums = {1, 4, 6, 7, 3, 7, 8, 1};
    long long sumRange = sumOfMax(nums) - sumOfMin(nums);
    cout << "Sum of subarray ranges: " << sumRange << endl;
    return 0;
}