#include <iostream>
#include <vector>
using namespace std;

int partation(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // placing pivot to its right index
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // partition of the array by finding the pivot
        int pivIndex = partation(arr, low, high);

        // Sorting the left side of the pivot
        quickSort(arr, low, pivIndex - 1);

        // Sorting the right side of the array
        quickSort(arr, pivIndex + 1, high);
    }
}

int main()
{

    vector<int> arr = {8, -12, 4, 0, -5, 5, 9, 0, 0, -1};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    // printing the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}