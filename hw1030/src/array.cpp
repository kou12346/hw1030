#include<iostream>
using namespace std;
int *change_size(int *&arr, int size, int new_size) {
    int *new_arr = new int[new_size]; //�s���}�C 
    int *recycler = arr; //�ª��}�C 
    copy(arr, arr + size, new_arr); //�ª��ƻs��s�� 
    int num=size; //�°}�C�j�p
 
    while(num<new_size){
    	num+=2; //���°}�C�j�p�p��s�}�C�j�p�A�s�}�C����=�°}�C����+2 size+=2 
	}
	
	for(int i=size-1;i<num;i++){
		new_arr[i]=i+1;   //��s�}�C�����Ű}�C��J�Ʀr 
	}
    delete[] recycler; //�R���°}�C 
    arr = new_arr;  
    return arr;
}
void print_arr(int *arr,int size){   //��X�}�C�禡 
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
    
	cout<<"��J new_size"<<endl;
	cin>>new_size;  //��J�s�}�C�j�p 
    change_size(arr, size, new_size); // 
    print_arr(arr, new_size);  // Size has changed, print the new array.
}
