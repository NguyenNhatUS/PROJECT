// main: viết hàm main để chạy chương trình
#include "sorting.h"
#include "sorting.cpp"
using namespace std;

void processArg(int argc, char *argv[])
{
    string Algo;
    string inputFile = "";
    string outputFile = "";
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-a") == 0)
        {
            Algo = argv[++i];
        }
        if (strcmp(argv[i], "-i") == 0)
        {
            inputFile = argv[++i];
        }
        if (strcmp(argv[i], "-o") == 0)
        {
            outputFile = argv[++i];
        }
    }
    ifstream fin;
    fin.open(inputFile);
    int n;
    fin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> a[i];
    }
    processSort(Algo, a, n);
    ofstream fout;
    fout.open(outputFile);
    fout << n << endl;
    for (int i = 0; i < n; i++)
    {
        fout << a[i] << " ";
    }
    fin.close();
    fout.close();
}

int main(int argc, char *argv[])
{
    string filename = argv[4];
    GenerateArrayAndWrite(filename);
    processArg(argc, argv);
    return 0;
}
