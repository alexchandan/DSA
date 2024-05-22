#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArr(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> mergedArr;

    // check if arr1 is empty
    if (arr1.size() == 0)
    {
        return arr2;
    }

    int i = 0;
    int j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            mergedArr.push_back(arr1[i]);
            i++;
        }
        else
        {
            mergedArr.push_back(arr2[j]);
            j++;
        }
    }

    // copy the remaining element from arr1;
    while (i < arr1.size())
    {
        mergedArr.push_back(arr1[i]);
        i++;
    }

    // if arr2 still contains some elements;
    while (j < arr2.size())
    {
        mergedArr.push_back(arr2[j]);
        j++;
    }

    return mergedArr;
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
    vector<int> arr1, arr2;
    arr1 = {1, 2, 4, 5};
    arr2 = {3, 4, 7, 50, 52};

    vector<int> mergedArr = mergeSortedArr(arr1, arr2);
    display(mergedArr);

    return 0;
}