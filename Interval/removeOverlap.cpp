// remove min interval to make the intervals non-overlapping
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int n = intervals.size(), lastEnd = INT_MIN, del = 0;
    for(int i = 0; i < n; i++){
        if(intervals[i][0] < lastEnd){ // overlap
            del++;
            lastEnd = min(lastEnd, intervals[i][1]);
        }
        else{
            lastEnd = intervals[i][1];
        }
    }
    return del;
}

int main() {
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
    cout << "Number of intervals to delete: " << eraseOverlapIntervals(intervals) << endl;
    return 0;
}