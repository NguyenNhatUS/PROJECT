// trình bày các thuật toán sort ở đây
#include "sorting.h"

void copyArray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

struct Record
{
    long long comparison;
    double time;
};

// hàm để tính toán running time và số lượng phép so sánh
Record getRecord(int a[], int n, void (*sortFunctionCmp)(int[], int, long long &), void (*sortFunction)(int[], int))
{
    Record record;
    record.comparison = 0;
    record.time = 0;
    int *b = new int[n];
    copyArray(a, b, n);
    sortFunctionCmp(a, n, record.comparison); // Đếm số phép so sánh
    auto start = high_resolution_clock::now(); // Thời gian bắt đầu
    sortFunction(b, n);
    auto end = high_resolution_clock::now();  // Thời gian kết thúc
    duration<double, std::milli> duration = end - start; // Running time
    record.time = duration.count();  // Gán record.time = running time
    delete[] b;
    return record;
}

// Selection Sort
// Original Functions
void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

// Funtion with comparison counter
void selection_sort(int a[], int n, long long &comparisons)
{
    for (int i = 0; ++comparisons && i < n - 1; i++)
    {
        for (int j = i + 1; ++comparisons && j < n; j++)
        {
            if (++comparisons && a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Insertion Sort
void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void insertion_sort(int a[], int n, long long &comparisons)
{
    for (int i = 1; ++comparisons && i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (++comparisons && j >= 0 && ++comparisons && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Bubble Sort
void bubble_sort(int a[], int n)
{
    bool swap = true;
    int temp;
    for (int i = 0; swap; i++)
    {
        swap = false;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap = true;
            }
        }
    }
}

void bubble_sort(int a[], int n, long long &comparisons)
{
    bool swap = true;
    int temp;
    for (int i = 0; ++comparisons && swap; i++)
    {
        swap = false;
        for (int j = 0; ++comparisons && j < n - 1; j++)
        {
            if (++comparisons && a[j] > a[j + 1])
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
void shell_sort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shell_sort(int arr[], int n, long long &comparisons)
{
    for (int gap = n / 2; ++comparisons && gap > 0; gap /= 2)
    {
        for (int i = gap; ++comparisons && i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; ++comparisons && j >= gap && ++comparisons && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Heap Sort
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

void heapify(int a[], int n, int i, long long &comparisons)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (++comparisons && left < n && ++comparisons && a[left] > a[largest])
    {
        largest = left;
    }
    if (++comparisons && right < n && ++comparisons && a[right] > a[largest])
    {
        largest = right;
    }
    if (++comparisons && largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest, comparisons);
    }
}

void heap_sort(int a[], int n, long long &comparisons)
{
    for (int i = n / 2 - 1; ++comparisons && i >= 0; i--)
    {
        heapify(a, n, i, comparisons);
    }
    for (int i = n - 1; ++comparisons && i > 0; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0, comparisons);
    }
}

// Merge Sort
void merge(int a[], int left, int mid, int right)
{
    if (left >= right)
        return;
    int *temp = new int[right - left + 1];
    int i = left, j = mid + 1, count = 0;
    while (i <= mid && j <= right)
    {
        if (a[i] < a[j])
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
    while (i <= mid)
    {
        temp[count++] = a[i++];
    }
    while (j <= right)
    {
        temp[count++] = a[j++];
    }
    for (int o = 0; o < count; o++)
    {
        a[left + o] = temp[o];
    }
    delete[] temp;
}

void MergeSort(int a[], int left, int right)
{
    if (right <= left)
        return;
    int mid = left + (right - left) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

void merge_sort(int a[], int n)
{
    MergeSort(a, 0, n - 1);
}

void merge(int a[], int left, int mid, int right, long long &comparisons)
{
    if (++comparisons && left >= right)
        return;
    int *temp = new int[right - left + 1];
    int i = left, j = mid + 1, count = 0;
    while (++comparisons && i <= mid && ++comparisons && j <= right)
    {
        if (++comparisons && a[i] < a[j])
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
    while (++comparisons && i <= mid)
    {
        temp[count++] = a[i++];
    }
    while (++comparisons && j <= right)
    {
        temp[count++] = a[j++];
    }
    for (int o = 0; ++comparisons && o < count; o++)
    {
        a[left + o] = temp[o];
    }
    delete[] temp;
}

void MergeSort(int a[], int left, int right, long long &comparisons)
{
    if (++comparisons && right <= left)
        return;
    int mid = left + (right - left) / 2;
    MergeSort(a, left, mid, comparisons);
    MergeSort(a, mid + 1, right, comparisons);
    merge(a, left, mid, right, comparisons);
}

void merge_sort(int a[], int n, long long &comparisons)
{
    MergeSort(a, 0, n - 1, comparisons);
}

// Quick Sort

int partition(int a[], int left, int right)
{
    int pivot = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[right]);
    return i;
}

void quickSort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int pi = partition(a, left, right);
    quickSort(a, left, pi - 1);
    quickSort(a, pi + 1, right);
}

void quick_sort(int a[], int n)
{
    quickSort(a, 0, n - 1);
}

int partition(int a[], int left, int right, long long &comparisons)
{
    int pivot = a[right];
    int i = left - 1;
    for (int j = left; ++comparisons && j < right; j++)
    {
        if (++comparisons && a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[right]);
    return i;
}

void quickSort(int a[], int left, int right, long long &comparisons)
{
    if (++comparisons && left >= right)
        return;
    int pi = partition(a, left, right, comparisons);
    quickSort(a, left, pi - 1, comparisons);
    quickSort(a, pi + 1, right, comparisons);
}

void quick_sort(int a[], int n, long long &comparisons)
{
    quickSort(a, 0, n - 1, comparisons);
}

// Counting Sort
void CountingSort(int arr[], int n, int mi, int mx)
{
    int d = 0, cs = mx - mi;
    int count[cs + 1];
    for (int i = 0; i <= cs; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - mi]++;
    }
    for (int i = 0; i <= cs; i++)
    {
        if (count[i] > 0)
        {
            for (int j = 1; j <= count[i]; j++)
            {
                arr[d++] = i + mi;
            }
        }
    }
}

void counting_sort(int a[], int n)
{
    int min = a[0], max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (min > a[i])
            min = a[i];
        if (max < a[i])
            max = a[i];
    }
    CountingSort(a, n, min, max);
}

void CountingSort(int arr[], int n, int mi, int mx, long long &comparisons)
{
    int d = 0, cs = mx - mi;
    int count[cs + 1];
    for (int i = 0; ++comparisons && i <= cs; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; ++comparisons && i < n; i++)
    {
        count[arr[i] - mi]++;
    }
    for (int i = 0; ++comparisons && i <= cs; i++)
    {
        if (++comparisons && count[i] > 0)
        {
            for (int j = 1; ++comparisons && j <= count[i]; j++)
            {
                arr[d++] = i + mi;
            }
        }
    }
}

void counting_sort(int a[], int n, long long &comparisons)
{
    int min = a[0], max = a[0];
    for (int i = 1; ++comparisons && i < n; i++)
    {
        if (++comparisons && min > a[i])
            min = a[i];
        if (++comparisons && max < a[i])
            max = a[i];
    }
    CountingSort(a, n, min, max, comparisons);
}

// Radix Sort
void Counting(int a[], int n, int exp)
{
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(a[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

void solve(int a[], int n)
{
    int maxNum = a[0];
    for (int i = 1; i < n; i++)
    {
        if (maxNum < a[i])
            maxNum = a[i];
    }
    for (int exp = 1; maxNum / exp > 0; exp *= 10)
    {
        Counting(a, n, exp);
    }
}

void radix_sort(int a[], int n)
{
    int list1[n];
    int list2[n];
    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            list2[count2++] = -a[i];
        }
        else
        {
            list1[count1++] = a[i];
        }
    }
    solve(list1, count1);
    solve(list2, count2);
    for (int i = 0; i < count2; i++)
    {
        a[i] = -list2[count2 - i - 1];
    }
    for (int i = 0; i < count1; i++)
    {
        a[i + count2] = list1[i];
    }
}

void Counting(int a[], int n, int exp, long long &comparisons)
{
    int output[n];
    int count[10] = {0};
    for (int i = 0; ++comparisons && i < n; i++)
    {
        count[(a[i] / exp) % 10]++;
    }
    for (int i = 1; ++comparisons && i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; ++comparisons && i >= 0; i--)
    {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }
    for (int i = 0; ++comparisons && i < n; i++)
    {
        a[i] = output[i];
    }
}

void solve(int a[], int n, long long &comparisons)
{
    int maxNum = a[0];
    for (int i = 1; ++comparisons && i < n; i++)
    {
        if (++comparisons && maxNum < a[i])
            maxNum = a[i];
    }
    for (int exp = 1; ++comparisons && maxNum / exp > 0; exp *= 10)
    {
        Counting(a, n, exp, comparisons);
    }
}

void radix_sort(int a[], int n, long long &comparisons)
{
    int list1[n];
    int list2[n];
    int count1 = 0, count2 = 0;
    for (int i = 0; ++comparisons && i < n; i++)
    {
        if (++comparisons && a[i] < 0)
        {
            list2[count2++] = -a[i];
        }
        else
        {
            list1[count1++] = a[i];
        }
    }
    solve(list1, count1, comparisons);
    solve(list2, count2, comparisons);
    for (int i = 0; ++comparisons && i < count2; i++)
    {
        a[i] = -list2[count2 - i - 1];
    }
    for (int i = 0; ++comparisons && i < count1; i++)
    {
        a[i + count2] = list1[i];
    }
}

// Flash Sort
void flash_sort(int a[], int n)
{
    int __L[300000];
    if (n <= 1)
        return;
    int m = n * 0.43;
    if (m <= 2)
        m = 2;
    for (int i = 0; i < m; i++)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; i < n; i++)
    {
        if (Mx < a[i])
            Mx = a[i];
        if (Mn > a[i])
            Mn = a[i];
    }
    if (Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; i < n; i++)
        ++__L[getK(a[i])];
    for (int i = 1; i < m; i++)
        __L[i] += __L[i - 1];
    int count = 0;
    int i = 0;
    while (count < n)
    {
        int k = getK(a[i]);
        while (i >= __L[k])
            k = getK(a[++i]);
        int z = a[i];
        while (i != __L[k])
        {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            count++;
        }
    }
    for (int k = 1; k < m; k++)
    {
        for (int i = __L[k] - 2; i >= __L[k - 1]; i--)
            if (a[i] > a[i + 1])
            {
                int t = a[i], j = i;
                while (t > a[j + 1])
                {
                    a[j] = a[j + 1];
                    j++;
                }
                a[j] = t;
            }
    }
}

void flash_sort(int a[], int n, long long &comparisons)
{
    int __L[300000];
    if (++comparisons && n <= 1)
        return;
    int m = n * 0.43;
    if (++comparisons && m <= 2)
        m = 2;
    for (int i = 0; ++comparisons && i < m; i++)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; ++comparisons && i < n; i++)
    {
        if (++comparisons && Mx < a[i])
            Mx = a[i];
        if (++comparisons && Mn > a[i])
            Mn = a[i];
    }
    if (++comparisons && Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; ++comparisons && i < n; i++)
        ++__L[getK(a[i])];
    for (int i = 1; ++comparisons && i < m; i++)
        __L[i] += __L[i - 1];
    int count = 0;
    int i = 0;
    while (++comparisons && count < n)
    {
        int k = getK(a[i]);
        while (++comparisons && i >= __L[k])
            k = getK(a[++i]);
        int z = a[i];
        while (++comparisons && i != __L[k])
        {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            count++;
        }
    }
    for (int k = 1; ++comparisons && k < m; k++)
    {
        for (int i = __L[k] - 2; ++comparisons && i >= __L[k - 1]; i--)
            if (++comparisons && a[i] > a[i + 1])
            {
                int t = a[i], j = i;
                while (++comparisons && t > a[j + 1])
                {
                    a[j] = a[j + 1];
                    j++;
                }
                a[j] = t;
            }
    }
}

// Shaker Sort
void shaker_sort(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int k = 0;
    int i;
    while (left < right)
    {
        for (i = left; i < right; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;
        for (i = right; i > left; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}

void shaker_sort(int a[], int n, long long &comparisons)
{
    int left = 0;
    int right = n - 1;
    int k = 0;
    int i;
    while (++comparisons && left < right)
    {
        for (i = left; ++comparisons && i < right; i++)
        {
            if (++comparisons && a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;
        for (i = right; ++comparisons && i > left; i--)
        {
            if (++comparisons && a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}
