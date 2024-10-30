#include<iostream>
using namespace std;
int *change_size(int *&arr, int size, int new_size) {
    int *new_arr = new int[new_size]; //新的陣列 
    int *recycler = arr; //舊的陣列 
    copy(arr, arr + size, new_arr); //舊的複製到新的 
    int num=size; //舊陣列大小
 
    while(num<new_size){
    	num+=2; //當舊陣列大小小於新陣列大小，新陣列長度=舊陣列長度+2 size+=2 
	}
	
	for(int i=size-1;i<num;i++){
		new_arr[i]=i+1;   //把新陣列中的空陣列塞入數字 
	}
    delete[] recycler; //刪除舊陣列 
    arr = new_arr;  
    return arr;
}
void print_arr(int *arr,int size){   //輸出陣列函式 
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
} 
int main() {
    int size = 3;
    int *arr = new int[size];

    // Inserting elements.
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    };

    print_arr(arr, size);  // Print initial array.
	
    int new_size;
    
	cout<<"輸入 new_size"<<endl;
	cin>>new_size;  //輸入新陣列大小 
    change_size(arr, size, new_size); // 
    print_arr(arr, new_size);  // Size has changed, print the new array.
}
