#pragma once
#include <stdexcept>

int binsearch(int nums[], int n, int target, int checkType) {
    int left = 0, right = n - 1;
    int prevMid = -1;  

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

        if (checkType == 1 && prevMid != -1) {
            // Pivot checking logic
            if (nums[mid] > nums[prevMid] && target < nums[prevMid]) {
                throw std::runtime_error("Pivot checking failed: expected smaller pivot");
            }
            if (nums[mid] < nums[prevMid] && target > nums[prevMid]) {
                throw std::runtime_error("Pivot checking failed: expected larger pivot");
            }
        }
        prevMid = mid;

        if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

        if (checkType == 2) {
            // Neighbors checking
            if (mid - 1 >= 0 && nums[mid - 1] == target) return mid - 1;
            if (mid + 1 < n && nums[mid + 1] == target) return mid + 1;

            if ((mid - 1 >= 0 && nums[mid] < nums[mid - 1]) ||
                (mid + 1 < n && nums[mid] > nums[mid + 1])) {
                throw std::runtime_error("Neighbors checking failed");
            }
        }

    }
    return -1;
}
