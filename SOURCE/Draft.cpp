// File này để test chức năng các hàm sort: kiểm tra xem code đúng chưa
#include <bits/stdc++.h>
using namespace std;

// ++comparisions &&
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


int main() 
{
    int a[] = {5, 34, 23, 2, 4, 6, 7, 8, 8};
    int n = sizeof(a) / sizeof(a[0]);
    long long comparisions = 0;
    radix_sort(a, n, comparisions);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << comparisions << endl;
    return 0;
}