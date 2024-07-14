#include <iostream>

using namespace std;

void rotate(int nums[], int n, int k) {
    k = k % n;

    int count = 0; 
    for (int start = 0; count < n; ++start) {
        int current = start;
        int prev = nums[start];
        do {
            int next = (current + k) % n;
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;
            count++;
        } while (start != current);
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    rotate(nums, n, k);

    cout << "Rotated array: ";
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

