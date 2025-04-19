// Time complexity: O(n log n), worst case O(n log n), best case O(n log n)
// Space complexity: O(1)
// Not stable sort

#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &nums, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest]) 
        largest = left;
    if (right < n && nums[right] > nums[largest]) 
        largest = right;

    if (largest != i) {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

void heapSort(vector<int> &nums) {
    int n = nums.size();

    // 建立 Max-Heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(nums, n, i);
    }

    // 逐步取出最大值
    for (int i = n - 1; i > 0; --i) {
        swap(nums[0], nums[i]);  // 將最大值移到正確位置
        heapify(nums, i, 0);     // 調整剩餘的堆
    }
}

int main() {
    vector<int> nums = {8, 2, 1, 5, 9, 7, 6};
    heapSort(nums);

    for (const auto &n : nums) {
        cout << n << " ";
    }
}

