// File này để test chức năng các hàm sort: kiểm tra xem code đúng chưa
#include <bits/stdc++.h>
using namespace std;

// ++comparisions &&
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


int main() 
{
    int a[] = {5, 34, 23, 2, 4, 6, 7, 8, 8};
    int n = sizeof(a) / sizeof(a[0]);
    long long comparisions = 0;
     flash_sort(a, n, comparisions);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << comparisions << endl;
    return 0;
}