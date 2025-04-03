// main: viết hàm main để chạy chương trình
#include<sorting.h>

void PrintArray(int a[],int n) {
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
}


int main(int argc,char* argv[]) {
    processArg(argc,argv);
    return 0;
}