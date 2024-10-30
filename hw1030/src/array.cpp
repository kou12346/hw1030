#include <iostream>
using namespace std;

int *change_size(int *&arr, int &size, int new_size) {
    int *new_arr = new int[new_size]; // 建立新陣列
    int *recycler = arr; // 指向舊陣列以便後續刪除

    // 將舊陣列的元素複製到新陣列
    copy(arr, arr + size, new_arr);

    // 將新位置的元素填入值
    for (int i = size; i < new_size; i++) {
        new_arr[i] = i + 1;  // 這裡可以依照需求填入其他數值
    }

    delete[] recycler; // 釋放舊陣列的記憶體
    arr = new_arr;  // 將新陣列指向 arr
    size = new_size;  // 更新 size 的值為 new_size
    return arr;
}

void print_arr(int *arr, int size) { // 印出陣列函數
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 3;
    int *arr = new int[size];

    // 初始化陣列元素
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    print_arr(arr, size);  // 輸出初始陣列

    int new_size;
    cout << "輸入 new_size: ";
    cin >> new_size;  // 輸入新陣列大小

    change_size(arr, size, new_size);  // 改變陣列大小
    print_arr(arr, new_size);  // 輸出新的陣列

    delete[] arr;  // 最後釋放記憶體
}
