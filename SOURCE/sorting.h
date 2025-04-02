#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip>

using namespace std;

// Swap function
void Swap(int &a,int &b);

// Sort Algorithm
// 1
void selection_sort(int a[],int n,long long& comparisions);

// 2
void insertion_sort(int a[],int n,long long& comparisions);

// 3
void bubble_sort(int a[],int n,long long& comparisions);

// 4
void shell_sort(int a[],int n,long long& comparisions);

// 5
void heap_sort(int a[],int n,long long& comparisions);

// 6
void merge_sort(int a[],int n,long long& comparisions);

// 7
void quick_sort(int a[],int n,long long& comparisions);

// 8
void counting_sort(int a[],int n,long long& comparisions);

// 9
void radix_sort(int a[],int n,long long& comparisions);

// 10
void flash_sort(int a[],int n,long long& comparisions);

// 11
void shaker_sort(int a[],int n,long long& comparisions);


// Data Generator
void GenerateRandomData(int a[], int n);

void GenerateSortedData(int a[], int n);

void GenerateReverseData(int a[], int n );

void GenerateNearlySortedData(int a[], int n);

void GenerateData(int a[], int n, int dataType);


//Processing commandline args
void processArg(int argc, char* argv[]);