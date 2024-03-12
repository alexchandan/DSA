#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// printing the array
void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {2, 4, 5, 1, 7, 0, 2};
    cout << "Before sort: " << endl;
    display(arr);
    bubble_sort(arr);
    cout << "After sort: " << endl;
    display(arr);

    return 0;
}