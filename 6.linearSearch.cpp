#include <iostream>
#include <vector>
using namespace std;

// Function to perform linear search
int linearSearch(const vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main()
{
    int n, target;

    // Input the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Declare a vector with size 'n'
    vector<int> arr(n);

    // Input array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Input the target value to search
    cout << "Enter the target value to search: ";
    cin >> target;

    // Performing linear search
    int result = linearSearch(arr, target);

    // Output the result
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
