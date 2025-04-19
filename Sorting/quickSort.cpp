// Time complexity: O(n log n), worst case O(n^2), best case O(n log n)
// Space complexity: O(log n)
// Not stable sort

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int low, int high){
    int left = low + 1, right = high;
    int pivot = nums[low];
    while(true){
        while(left <= right && nums[left] <= pivot) left++;
        while(left <= right && nums[right] > pivot) right--;
        if(right < left) break;
        swap(nums[left], nums[right]);
    }
    swap(nums[right], nums[low]);
    return right;
}

void quickSort(vector<int>& nums, int low, int high){
    if(low >= high) return;
    int p = partition(nums, low, high);
    quickSort(nums, low, p - 1);
    quickSort(nums, p + 1, high);
}

int main(){
    vector<int> nums = {8, 2, 1, 5, 9, 7, 6};
    int n = nums.size();
    quickSort(nums, 0, n - 1);
    for(const auto& n: nums){
        cout << n << " ";
    }
}
