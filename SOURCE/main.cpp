// main: viết hàm main để chạy chương trình
#include "sorting.h"
using namespace std;

// Generator
template <class T>
void HoanVi(T &a, T &b) {
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n ) {
	for (int i = 0; i < n; i++) {
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i++) {
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType) {
	switch (dataType) {
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		cout << "Error: unknown data type!" << endl;
	}
}



void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

void process(int argc,char* argv[]) {
    int dataType;
    int dataSize = atoi(argv[1]);
    if(strcmp(argv[2],"sorted") == 0) {
        dataType = 1;
    }
    else if(strcmp(argv[2],"nsorted") == 0) {
        dataType = 3;
    }
    else if(strcmp(argv[2],"rsorted") == 0) {
        dataType = 2;
    }
    else {
        dataType = 0;
    }
    int *a = new int[dataSize];
    GenerateData(a,dataSize,dataType);
    if(strcmp(argv[3],"heap-sort") == 0) {
        heap_sort(a,dataSize);
    }
    for(int i = 0;i < dataSize;i++) {
        cout << a[i] << " ";
    }
}

int main(int argc,char* argv[]) {
    cout << "Prototype for command line: " << endl;
    cout << "./program_name dataSize dataOrder Algorithm" << endl;
    process(argc,argv);
    return 0;
}