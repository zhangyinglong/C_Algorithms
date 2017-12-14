/*
 * 搜索相关的算法
*/

#include <stdint.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
 * 算法：二分搜索算法
*/
int binarySearch(int a[], int count, int key) {
    if (NULL == a || 0 == count) { return -1; }

    int lowerBound = 0;
    int upperBound = count;

    while (lowerBound < upperBound) {
        int midIndex = lowerBound + (upperBound - lowerBound) / 2;
        if (a[midIndex] == key) {
            return midIndex;
        } else if (a[midIndex] < key) {
            lowerBound = midIndex + 1;
        } else {
            upperBound = midIndex;
        }
    }
    return -1;
}

int main() {
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
    int count = sizeof(a) / sizeof(a[0]);
    int key = 72;

    int index = binarySearch(a, count, key);

    cout << "搜索关键字：" << key << "结果位置：" << index << endl;
    return 0;
} 
