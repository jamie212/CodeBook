// Time complexity: O(n log n), worst case O(n log n), best case O(n log n)
// Space complexity: O(n)
// Stable sort

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int left, int mid, int right){
    vector<int> merged;
    int idx1 = left, idx2 = mid + 1;
    while(idx1 <= mid && idx2 <= right){
        if(nums[idx1] <= nums[idx2]){
            merged.push_back(nums[idx1]);
            idx1++;
        }
        else{
            merged.push_back(nums[idx2]);
            idx2++;
        }
    }
    while(idx1 <= mid){
        merged.push_back(nums[idx1]);
        idx1++;
    }
    while(idx2 <= right){
        merged.push_back(nums[idx2]);
        idx2++;
    }
    for (int i = left; i <= right; i++) {
        nums[i] = merged[i - left];  // 注意merged是片段的，idx要映射到nums
    }
    return; 
}

void mergeSort(vector<int>& nums, int left, int right){
    if(left == right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
    return;
}

int main(){
    vector<int> nums = {8, 2, 1, 5, 9, 7, 6};
    int n = nums.size();
    mergeSort(nums, 0, n - 1);
    for(const auto& n: nums){
        cout << n << " ";
    }
}

