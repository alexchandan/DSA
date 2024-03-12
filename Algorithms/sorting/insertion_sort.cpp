#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    vector<int> arr = {3, 4, 7, -1, -10, 2, 2, 0, 1};
    cout << "Before sort" << endl;
    display(arr);

    insertion_sort(arr);
    cout << "After sort: " << endl;

    display(arr);
    return 0;
}