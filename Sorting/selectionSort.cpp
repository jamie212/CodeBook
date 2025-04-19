#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n - 1; i++){
        int min_val = nums[i], min_idx = i;
        for(int j = i + 1; j < n; j++){
            if(nums[j] < min_val){
                min_val = nums[j];
                min_idx = j;
            }
        }
        swap(nums[i], nums[min_idx]);
    }
}

int main(){
    vector<int> nums = {8, 2, 1, 5, 9, 7, 6};
    selectionSort(nums);
    for(const auto& n: nums){
        cout << n << " ";
    }
}