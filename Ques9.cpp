#include <iostream>
#include <limits>

using namespace std;

int maxDifference(int nums[], int n) {
    if (n < 2) {
        return 0;
    }

    int minElement = nums[0]; 
    int maxDiff = 0;

    
    for (int i = 1; i < n; ++i) {
        maxDiff = max(maxDiff, nums[i] - minElement);
        minElement = min(minElement, nums[i]);
    }

    return maxDiff;
}

int main() {
    int nums[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(nums) / sizeof(nums[0]);


    int result = maxDifference(nums, n);

    cout << "Maximum difference between any two elements in the array: " << result << endl;

    return 0;
}

