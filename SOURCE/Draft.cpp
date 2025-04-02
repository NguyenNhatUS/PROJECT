// File này để test chức năng các hàm sort: kiểm tra xem code đúng chưa
#include <bits/stdc++.h>
using namespace std;

// ++comparisions &&

void shell_sort(int arr[], int n,long long& comparisions) {
    for (int gap = n / 2; ++comparisions && gap > 0; gap /= 2) {
        for (int i = gap; ++comparisions && i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; ++comparisions && j >= gap && ++comparisions && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() 
{
    int a[] = {5, 34, 23, 2, 4, 6, 7, 8, 8};
    int n = sizeof(a) / sizeof(a[0]);
    long long comparisions = 0;
    shell_sort(a, n, comparisions);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << comparisions << endl;
    return 0;
}