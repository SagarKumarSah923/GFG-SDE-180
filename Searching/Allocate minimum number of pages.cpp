#include <iostream>
#include <climits>

class Solution {
public:
    bool isPossible(int arr[], int n, int m, int curr_min) {
        int studentsRequired = 1;
        int curr_sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > curr_min)
                return false;

            if (curr_sum + arr[i] > curr_min) {
                studentsRequired++;
                curr_sum = arr[i];
                if (studentsRequired > m)
                    return false;
            } else {
                curr_sum += arr[i];
            }
        }
        return true;
    }

    int findPages(int arr[], int n, int m) {
        long long sum = 0;
        if (n < m)
            return -1;

        for (int i = 0; i < n; i++)
            sum += arr[i];

        int start = 0, end = sum;
        int result = INT_MAX;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (isPossible(arr, n, m, mid)) {
                result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    int arr[] = {12, 34, 67, 90}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 2; // Number of students
    int result = solution.findPages(arr, n, m);
    
    if (result == -1) {
        std::cout << "It is not possible to allocate books." << std::endl;
    } else {
        std::cout << "Minimum number of pages: " << result << std::endl;
    }
    
    return 0;
}
