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

void insertion_sort(int a[],int n,long long& comparisions) {

}

// 3
void bubble_sort(int a[],int n,long long& comparisions) {

}

// 4
void shell_sort(int a[],int n,long long& comparisions) {

}

// 5
void heap_sort(int a[],int n,long long& comparisions) {
    
}

// 6
void merge_sort(int a[],int n,long long& comparisions) {
    
}

// 7
void quick_sort(int a[],int n,long long& comparisions) {
    
}

// 8
void counting_sort(int a[],int n,long long& comparisions) {
    
}

// 9
void radix_sort(int a[],int n,long long& comparisions) {
    
}

// 10
void flash_sort(int a[],int n,long long& comparisions) {
    
}

// 11
void shaker_sort(int a[],int n,long long& comparisions) {
    
}


