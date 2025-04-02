// trình bày các thuật toán sort ở đây
// #include <sorting.h>
#include <bits/stdc++.h>
using namespace std;

// Selection Sort
void selection_sort(int a[], int n, long long &comparisions)
{
    for (int i = 0; ++comparisions && i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; ++comparisions && j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Insertion Sort
void insertion_sort(int a[], int n, long long &comparisions)
{
    for (int i = 1; ++comparisions && i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (++comparisions && j >= 0 && ++comparisions && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Bubble Sort
void bubble_sort(int a[], int n, long long &comparisions)
{
    bool swap = true;
    int temp;
    for (int i = 0; ++comparisions && swap; i++)
    {
        swap = false;
        for (int j = 0; ++comparisions && j < n - 1; j++)
        {
            if (++comparisions && a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap = true;
            }
        }
    }
}

// Shell Sort
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

// Heap Sort

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

// Merge Sort
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
    if (++comparisions && right <= left)
        return;
    int mid = left + (right - left) / 2;
    MergeSort(a, left, mid, comparisions);
    MergeSort(a, mid + 1, right, comparisions);
    merge(a, left, mid, right, comparisions);
}

void merge_sort(int a[], int n, long long &comparisions)
{
    MergeSort(a, 0, n - 1, comparisions);
}

// Quick Sort
int partition(int a[], int left, int right, long long &comparisions)
{
    int pivot = a[right];
    int i = left - 1;
    for (int j = left; ++comparisions && j < right; j++)
    {
        if (++comparisions && a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[right]);
    return i;
}

void quickSort(int a[], int left, int right, long long &comparisions)
{
    if (++comparisions && left >= right)
        return;
    int pi = partition(a, left, right, comparisions);
    quickSort(a, left, pi - 1, comparisions);
    quickSort(a, pi + 1, right, comparisions);
}

void quick_sort(int a[], int n, long long &comparisions)
{
    quickSort(a, 0, n - 1, comparisions);
}

// Counting Sort
void counting_sort(int a[], int n, long long &comparisions)
{
}

// Radix Sort
void radix_sort(int a[], int n, long long &comparisions)
{
}

// Flash Sort
void flash_sort(int a[], int n, long long &comparisions)
{
}

// Shaker Sort
void shaker_sort(int a[], int n, long long &comparisions)
{
    int Left = 0;
    int Right = n - 1;
    int k = 0;
    int i;
    while (++comparisions && Left < Right)
    {
        for (i = Left; ++comparisions && i < Right; i++)
        {
            if (++comparisions && a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (i = Right; ++comparisions && i > Left; i--)
        {
            if (++comparisions && a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}
