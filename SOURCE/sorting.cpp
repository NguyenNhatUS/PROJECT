// trình bày các thuật toán sort ở đây
#include<sorting.h>

// Swap function
void Swap(int &a,int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
 
// Selection Sort
void selection_sort(int a[],int n,long long& comparisions) {
    for(int i = 0;++comparisions && i < n - 1;i++) {
        int index = i;
        for(int j = i + 1;++comparisions && j < n;j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Insertion Sort
void insertion_sort(int a[],int n,long long& comparisions) {
    for(int i = 1;++comparisions && i < n;i++) {
        int j = i - 1;
        int key = a[i];
        while(++comparisions && j >= 0 && ++comparisions &&  a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Bubble Sort
void bubble_sort(int a[],int n,long long& comparisions) {

}

// Shell Sort
void shell_sort(int a[],int n,long long& comparisions) {

}

// Heap Sort

void heapify(int a[],int n,int i,long long& comparisions) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // ++comparisions
    if(++comparisions && left < n && ++comparisions && a[left] > a[largest]) {
        largest = left;
    }
    if(++comparisions && right < n && ++comparisions && a[right] > a[largest]) {
        largest = right;
    }   
    if(++comparisions && largest != i) {
        swap(a[largest],a[i]);
        heapify(a,n,largest,comparisions);
    }
}

void heap_sort(int a[],int n,long long& comparisions) {
    for(int i = n / 2 - 1;++comparisions && i >= 0;i--) {
        heapify(a,n,i,comparisions);
    }
    for(int i = n - 1;++comparisions && i > 0;i--) {
        swap(a[i],a[0]);
        heapify(a,i,0,comparisions);
    }
}

// Merge Sort

void merge(int a[],int left,int mid,int right,long long &comparisions) {

}

void merge_sort(int a[],int n,long long& comparisions) {
    
}

// Quick Sort
void quick_sort(int a[],int n,long long& comparisions) {
    
}

// Counting Sort
void counting_sort(int a[],int n,long long& comparisions) {
    
}

// Radix Sort
void radix_sort(int a[],int n,long long& comparisions) {
    
}

// Flash Sort
void flash_sort(int a[],int n,long long& comparisions) {
    
}

// Shaker Sort
void shaker_sort(int a[],int n,long long& comparisions) {
    
}


