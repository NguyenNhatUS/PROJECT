// File này để test chức năng các hàm sort: kiểm tra xem code đúng chưa
#include<bits/stdc++.h>
using namespace std;


void merge(int a[], int left, int mid, int right, long long &comparisions)
{
    if (++comparisions && left >= right)
        return;
    int *temp = new int[right - left + 1];
    int i = left, j = mid + 1, count = 0;
    while (++comparisions && i <= mid && ++comparisions && j <= right)
    {
        if (++comparisions && a[i] < a[j])
        {
            temp[count++] = a[i];
            i++;
        }
        else
        {
            temp[count++] = a[j];
            j++;
        }
    }
    while (++comparisions && i <= mid)
    {
        temp[count++] = a[i++];
    }
    while (++comparisions && j <= right)
    {
        temp[count++] = a[j++];
    }
    for (int o = 0; ++comparisions && o < count; o++)
    {
        a[left + o] = temp[o];
    }
    delete[] temp;
}

void MergeSort(int a[], int left, int right, long long &comparisions)
{
    if (++comparisions && right <= left) return;
    int mid = left + (right - left) / 2;
    MergeSort(a, left, mid, comparisions);
    MergeSort(a, mid + 1, right, comparisions);
    merge(a, left, mid, right, comparisions);
}

void merge_sort(int a[], int n, long long &comparisions)
{
    MergeSort(a, 0, n - 1, comparisions);
}

int main() {
    int a[] = {5,34,23,2,4,6,7,8,8};
    int n = sizeof(a) / sizeof(a[0]);
    long long comparisions = 0;
    merge_sort(a,n,comparisions);
    for(int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << comparisions << endl;
    return 0;
}