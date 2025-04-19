#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& nums){
    int n = nums.size();
    for(int i = 1; i < n; i++){
        int cur = nums[i], j = i;
        while(j > 0 && nums[j - 1] > cur){
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = cur;
    }
}

int main(){
    vector<int> nums = {8, 2, 1, 5, 9, 7, 6};
    insertionSort(nums);
    for(const auto& n: nums){
        cout << n << " ";
    }
    return 0;
}