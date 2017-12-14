/*
 * 排序相关的算法
*/

#include <stdint.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
 * 算法：快速排序(递归)
*/
void QuickSort(int a[], int low, int high) {
   if (low >= high) { return; }

   int first = low;
   int last = high;
   int key = a[first];  /*用字表的第一个记录作为枢轴*/

   while(first < last) {
       while(first < last && a[last] >= key) {
           --last;
       }

       a[first] = a[last];  /*将比第一个小的移到低端*/

       while(first < last && a[first] <= key) {
           ++first;
       }
        
       a[last] = a[first];  /*将比第一个大的移到高端*/
   }
   a[first] = key;  /*枢轴记录到位*/
   QuickSort(a, low, first-1);
   QuickSort(a, first+1, high);
}

int main() {
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
    int count = sizeof(a) / sizeof(a[0]);

    QuickSort(a, 0, count - 1);   /*第三个参数要减1否则内存越界*/

    for(int i = 0; i < count; i++) {
        cout << a[i] << ",";
    }

    cout << endl;
    return 0;
} 
