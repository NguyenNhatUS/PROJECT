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

using namespace std;


struct Record {
    long long comparision;
    double time;
};

// Sort Algorithm
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