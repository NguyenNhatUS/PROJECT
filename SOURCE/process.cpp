#include "sorting.h"

vector<string> algorithm = {"selection-sort","insertion-sort","bubble-sort","radix-sort","flash-sort",
                            "heap-sort","shaker-sort","shell-sort","merge-sort","quick-sort","counting-sort"};


vector<string> output_parameters = {"-time","-cmp","-both"};

vector<string> input_parameters = {"-rand","-sorted","-rsorted","-nsorted"};


bool isNumber(string s) {
	for(int i = 0;i < s.size();i++) {
		if(s[i] > '9' || s[i] > '0') return false;
	}
	return true;
}

// Generate an array with Dataorder dataType
void genAndWrite(string filename,int n,int dataType) {
	ofstream fout;
	fout.open(filename);
	int *a = new int[n];
	GenerateData(a,n,dataType);
	fout << n << endl;
	for(int i = 0;i < n;i++) {
		fout << a[i] << " ";
	}
	delete[] a;
	fout.close();
}










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