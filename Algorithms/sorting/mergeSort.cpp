#include <iostream>
#include <vector>
using namespace std;

// merge two sorted array into one sorted array

void conquer(vector<int> &arr, int left, int right, int mid)
{
    // create temporary array to hold left and right sub array
    vector<int> tmpArr1(mid - left + 1);
    vector<int> tmpArr2(right - mid);

    // copy data to temporary array
    for (int i = 0; i < tmpArr1.size(); i++)
    {
        // tmpArr1.push_back(arr[left + i]);
        tmpArr1[i] = arr[left + i];
    }

    for (int j = 0; j < tmpArr2.size(); j++)
    {
        // tmpArr2.push_back(arr[mid + 1 + j]);
        tmpArr2[j] = arr[mid + 1 + j];
    }

    // merge two sorted array;
    int i = 0;    // for traversing the tmpArr1;
    int j = 0;    // for traversing the tmpArr2;
    int k = left; // for traversing the original arr;
    while (i < tmpArr1.size() && j < tmpArr2.size())
    {
        if (tmpArr1[i] <= tmpArr2[j])
        {
            arr[k++] = tmpArr1[i++];
        }

        else
        {
            arr[k++] = tmpArr2[j++];
        }
    }

    // if tmpArr1 is greater than tmpArr2
    while (i < tmpArr1.size())
    {
        arr[k++] = tmpArr1[i++];
    }

    // if tmpArr2 is greater than tmpArr1
    while (j < tmpArr2.size())
    {
        arr[k++] = tmpArr2[j++];
    }
}

// function for diving the arr into two parts.
void divide(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        divide(arr, left, mid);
        divide(arr, mid + 1, right);

        conquer(arr, left, right, mid);
    }
}

// display function to print the array
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
    vector<int> arr = {1, 4, 1, 6, 3, 0, 9, -23, -2, 1};

    cout << "Array elements before sorting" << endl;
    display(arr);

    divide(arr, 0, arr.size() - 1);

    cout << endl;
    cout << "Array elements after sorting" << endl;
    display(arr);

    return 0;
}