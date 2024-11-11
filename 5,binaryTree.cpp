#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search
int binarySearch(const vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Check if the target is at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1; // If target is smaller, ignore the right half
    }

    // Target not found
    return -1;
}

int main()
{
    int n, target;

    // Input number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Declare vector with size 'n'
    vector<int> arr(n);

    // Input sorted elements
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Input target value to search
    cout << "Enter the target value to search: ";
    cin >> target;

    // Performing binary search
    int result = binarySearch(arr, target);

    // Output the result
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
