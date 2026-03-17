#include <iostream>
#include <string>
using namespace std;

template <typename T, size_t N>
int searchValue(T (&arr)[N], T key)
{
    int left = 0;
    int right = N - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

template <typename T>
void showResult(int pos, T value)
{
    if (pos != -1)
        cout << value << " found at index " << pos << endl;
    else
        cout << value << " not found" << endl;
}

int main()
{
    int nums[5] = {11, 12, 22, 25, 64};
    int key1 = 22;
    int pos1 = searchValue(nums, key1);
    showResult(pos1, key1);

    float decimals[4] = {0.57, 1.62, 2.71, 3.14};
    float key2 = 2.71;
    int pos2 = searchValue(decimals, key2);
    showResult(pos2, key2);

    string cars[4] = {"Audi", "BMW", "Honda", "Toyota"};
    string key3 = "Honda";
    int pos3 = searchValue(cars, key3);
    showResult(pos3, key3);

    return 0;
}


