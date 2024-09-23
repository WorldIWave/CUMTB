/*第二章2.10
    已知长度为n的线性表A采用顺序存储结构，请写一个时间复杂度为O（n）、空间复杂度为O（1）的算法，该算法可删除线性表中所有值为item的数据元素。*/

#include <iostream>
using namespace std;

void removeItem(int arr[], int& n, int item) {
    int j = 0; // j 用于记录有效元素存放位置

    for (int i = 0; i < n; i++) {
        if (arr[i] != item) {
            arr[j++] = arr[i]; // 将不等于 item 的元素前移
        }
    }

    n = j; // 更新数组长度，删除 item 后的有效元素数量
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 3, 5, 3, 7, 9, 3};
    int n = 8;
    int item = 3;

    cout << "Original Array: ";
    printArray(arr, n);

    removeItem(arr, n, item); // 删除所有值为 item 的元素

    cout << "Modified Array: ";
    printArray(arr, n);

    return 0;
}
