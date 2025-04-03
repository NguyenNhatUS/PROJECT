#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

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
    srand(time(0));
    int n = 10000;
    int a[n];
    for(int i = 0;i < n;i++) {
        a[i] = rand() % n;
    }
    long long comparisions = 0;
    auto start = high_resolution_clock::now();
    heap_sort(a,n,comparisions);
    auto end = high_resolution_clock::now();
    duration<double, milli> duration = end - start;
    cout << "Running time: " << duration.count() << " ms" << endl;
    for(int x : a) cout << x << " ";
    return 0;
}
