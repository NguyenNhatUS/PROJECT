#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#include<algorithm>
#include<chrono>
using namespace std;
using namespace std::chrono;


struct Record {
    long long comparision;
    double time;
};

// Original functions
void selection_sort(int a[], int n);
void insertion_sort(int a[], int n);
void bubble_sort(int a[], int n);
void shaker_sort(int a[], int n);
void shell_sort(int a[], int n);
void heap_sort(int a[], int n);
void merge_sort(int a[], int n);
void quick_sort(int a[], int n);
void counting_sort(int a[], int n);
void radix_sort(int a[], int n);
void flash_sort(int a[], int n);


// Sort Algorithm with Comparision counter
void selection_sort(int a[],int n,long long& comparisions);
void insertion_sort(int a[],int n,long long& comparisions);
void bubble_sort(int a[],int n,long long& comparisions);
void shell_sort(int a[],int n,long long& comparisions);
void heap_sort(int a[],int n,long long& comparisions);
void merge_sort(int a[],int n,long long& comparisions);
void quick_sort(int a[],int n,long long& comparisions);
void counting_sort(int a[],int n,long long& comparisions);
void radix_sort(int a[],int n,long long& comparisions);
void flash_sort(int a[],int n,long long& comparisions);
void shaker_sort(int a[],int n,long long& comparisions);

// Data Generator
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n );
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

//Processing commandline args
void processArg(int argc, char* argv[]);