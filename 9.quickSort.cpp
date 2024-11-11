#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = low - 1;       // Index of the smaller element

    // Traverse through the array and rearrange elements based on pivot
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++; // Increment index of the smaller element
            swap(arr[i], arr[j]);
        }
    }

    // Place the pivot element in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return the partition index
}

// Function to perform quick sort
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Get the partition index

        // Recursively sort elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

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

    // Perform quick sort
    quickSort(arr, 0, n - 1);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
