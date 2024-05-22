#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // swap the min with arr[i];
        // int temp = min;
        // arr[i] = min;
        // min = temp;
        if (min != i)
        {
            // swap the min with arr[i];
            swap(arr[min], arr[i]);
            // int temp = arr[min];
            // arr[min] = arr[i];
            // arr[i] = temp;
        }
    }
}

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {2, 4, 1, 5, 7, 1, 0, -23, -4};
    cout << "before sorting the array:" << endl;
    display(arr);

    selection_sort(arr);
    cout << "After sorting" << endl;
    display(arr);

    return 0;
}