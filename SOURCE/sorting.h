#ifndef SORTING_H
#define SORTING_H

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

//supportting
void heapify(int a[], int n, int i);
void merge(int a[], int left, int mid, int right);
void MergeSort(int a[], int left, int right);
int partition(int a[], int left, int right);
void CountingSort(int arr[], int n, int mi, int mx);
void Counting(int a[], int n, int exp);


// Sort Algorithm
void selection_sort(int a[], int n);
void insertion_sort(int a[], int n);
void bubble_sort(int a[], int n);
void shell_sort(int a[], int n);
void heap_sort(int a[], int n);
void merge_sort(int a[],int n);
void quick_sort(int a[],int n);
void counting_sort(int a[], int n);
void radix_sort(int a[], int n);
void flash_sort(int a[], int n);
void shaker_sort(int a[], int n);

// Data Generator
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n );
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

//Processing commandline args
void processArg(int argc, char* argv[]); 

#endif
