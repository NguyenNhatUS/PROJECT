// trình bày các thuật toán sort ở đây
#include <sorting.h>

void copyArray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

struct Record
{
    long long comparision;
    double time;
};

Record getRecord(int a[], int n, void (*sortFunctionCmp)(int[], int, long long &), void (*sortFunction)(int[], int))
{
    Record record;
    record.comparision = 0;
    record.time = 0;
    int *b = new int[n];
    copyArray(a, b, n);
    sortFunctionCmp(a, n, record.comparision);
    auto start = high_resolution_clock::now();
    sortFunction(b, n);
    auto end = high_resolution_clock::now();
    duration<double, std::milli> duration = end - start;
    record.time = duration.count();
    delete[] b;
    return record;
}

// Selection Sort
// Original Function
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

// Funtion with comparision counter
void selection_sort(int a[], int n, long long &comparisions)
{
    for (int i = 0; ++comparisions && i < n - 1; i++)
    {
        for (int j = i + 1; ++comparisions && j < n; j++)
        {
            if (++comparisions && a[i] > a[j])
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

void shell_sort(int arr[], int n, long long &comparisions)
{
    for (int gap = n / 2; ++comparisions && gap > 0; gap /= 2)
    {
        for (int i = gap; ++comparisions && i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; ++comparisions && j >= gap && ++comparisions && arr[j - gap] > temp; j -= gap)
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
    // ++comparisions
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

void CountingSort(int arr[], int n, int mi, int mx, long long &comparisions)
{
    int d = 0, cs = mx - mi;
    int count[cs + 1];
    for (int i = 0; ++comparisions && i <= cs; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; ++comparisions && i < n; i++)
    {
        count[arr[i] - mi]++;
    }
    for (int i = 0; ++comparisions && i <= cs; i++)
    {
        if (++comparisions && count[i] > 0)
        {
            for (int j = 1; ++comparisions && j <= count[i]; j++)
            {
                arr[d++] = i + mi;
            }
        }
    }
}

void counting_sort(int a[], int n, long long &comparisions)
{
    int min = a[0], max = a[0];
    for (int i = 1; ++comparisions && i < n; i++)
    {
        if (++comparisions && min > a[i])
            min = a[i];
        if (++comparisions && max < a[i])
            max = a[i];
    }
    CountingSort(a, n, min, max, comparisions);
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

void Counting(int a[], int n, int exp, long long &comparisions)
{
    int output[n];
    int count[10] = {0};
    for (int i = 0; ++comparisions && i < n; i++)
    {
        count[(a[i] / exp) % 10]++;
    }
    for (int i = 1; ++comparisions && i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; ++comparisions && i >= 0; i--)
    {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }
    for (int i = 0; ++comparisions && i < n; i++)
    {
        a[i] = output[i];
    }
}

void solve(int a[], int n, long long &comparisions)
{
    int maxNum = a[0];
    for (int i = 1; ++comparisions && i < n; i++)
    {
        if (++comparisions && maxNum < a[i])
            maxNum = a[i];
    }
    for (int exp = 1; ++comparisions && maxNum / exp > 0; exp *= 10)
    {
        Counting(a, n, exp, comparisions);
    }
}

void radix_sort(int a[], int n, long long &comparisions)
{
    int list1[n];
    int list2[n];
    int count1 = 0, count2 = 0;
    for (int i = 0; ++comparisions && i < n; i++)
    {
        if (++comparisions && a[i] < 0)
        {
            list2[count2++] = -a[i];
        }
        else
        {
            list1[count1++] = a[i];
        }
    }
    solve(list1, count1, comparisions);
    solve(list2, count2, comparisions);
    for (int i = 0; ++comparisions && i < count2; i++)
    {
        a[i] = -list2[count2 - i - 1];
    }
    for (int i = 0; ++comparisions && i < count1; i++)
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

void flash_sort(int a[], int n, long long &comparisions)
{
    int __L[300000];
    if (++comparisions && n <= 1)
        return;
    int m = n * 0.43;
    if (++comparisions && m <= 2)
        m = 2;
    for (int i = 0; ++comparisions && i < m; i++)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; ++comparisions && i < n; i++)
    {
        if (++comparisions && Mx < a[i])
            Mx = a[i];
        if (++comparisions && Mn > a[i])
            Mn = a[i];
    }
    if (++comparisions && Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; ++comparisions && i < n; i++)
        ++__L[getK(a[i])];
    for (int i = 1; ++comparisions && i < m; i++)
        __L[i] += __L[i - 1];
    int count = 0;
    int i = 0;
    while (++comparisions && count < n)
    {
        int k = getK(a[i]);
        while (++comparisions && i >= __L[k])
            k = getK(a[++i]);
        int z = a[i];
        while (++comparisions && i != __L[k])
        {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            count++;
        }
    }
    for (int k = 1; ++comparisions && k < m; k++)
    {
        for (int i = __L[k] - 2; ++comparisions && i >= __L[k - 1]; i--)
            if (++comparisions && a[i] > a[i + 1])
            {
                int t = a[i], j = i;
                while (++comparisions && t > a[j + 1])
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

void shaker_sort(int a[], int n, long long &comparisions)
{
    int left = 0;
    int right = n - 1;
    int k = 0;
    int i;
    while (++comparisions && left < right)
    {
        for (i = left; ++comparisions && i < right; i++)
        {
            if (++comparisions && a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;
        for (i = right; ++comparisions && i > left; i--)
        {
            if (++comparisions && a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}
