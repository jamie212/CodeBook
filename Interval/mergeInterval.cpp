// merge intervals to make the intervals non-overlapping
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    vector<int> currentInterval = intervals[0];

    for (const auto& interval: intervals) {
        if (interval[0] <= currentInterval[1]) { // Overlap, need to merge
            currentInterval[1] = max(currentInterval[1], interval[1]);
        } 
        else { // Non-overlap
            merged.push_back(currentInterval);
            currentInterval = interval;
        }
    }
    merged.push_back(currentInterval); // Add the last interval

    return merged;
}

int main() {
    vector<vector<int>> intervals = {{2, 6}, {1, 3}, {8, 10}, {11, 15}, {13, 20}};
    vector<vector<int>> merged = mergeIntervals(intervals);

    cout << "Merged Intervals: " << endl;
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}