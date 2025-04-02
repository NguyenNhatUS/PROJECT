// trình bày các thuật toán sort ở đây
#include<sorting.h>

void selection_sort(int a[],int n,long long& comparisions) {
    for(int i = 0;++ comparisions && i < n - 1;i++) {
        int index = i;
        for(int j = i + 1;comparisions++ && j < n;j++) {
            if(++comparisions && a[j] < a[index]) {
                index = j;
            }
        }
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}
