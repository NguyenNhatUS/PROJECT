// File này để test chức năng các hàm sort: kiểm tra xem code đúng chưa
#include<bits/stdc++.h>
using namespace std;


void heapify(int a[], int n, int i, long long &comparisions)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // ++comparisions
    if (++comparisions && left < n && ++comparisions && a[left] > a[largest])
    {
        largest = left;
    }
    if (++comparisions && right < n && ++comparisions && a[right] > a[largest])
    {
        largest = right;
    }
    if (++comparisions && largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest, comparisions);
    }
}

void heap_sort(int a[], int n, long long &comparisions)
{
    for (int i = n / 2 - 1; ++comparisions && i >= 0; i--)
    {
        heapify(a, n, i, comparisions);
    }
    for (int i = n - 1; ++comparisions && i > 0; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0, comparisions);
    }
}


int main() {
    int a[] = {5,34,23,2,4,6,7,8,8};
    int n = sizeof(a) / sizeof(a[0]);
    long long comparisions = 0;
    heap_sort(a,n,comparisions);
    for(int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << comparisions << endl;
    return 0;
}