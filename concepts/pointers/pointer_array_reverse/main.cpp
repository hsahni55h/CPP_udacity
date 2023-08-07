#include<iostream>
using namespace std;


void reverse_array(int array[], int size);

void swap(int *a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

void reverse_array(int array[], int size)
{
    int *pointer1 = array;
    int *pointer2 = array + size -1;

    while (pointer1 < pointer2)
    {
        swap(pointer1, pointer2);
        pointer1++;
        pointer2--; 
    }
}

void print_array(int* array, int size)
{
    int *array_size = array + size;
    int *position = array;

    for (position = array; position < array_size; position++)
    {
        cout << *position <<" ";
    }
    cout << endl;
}
 

int main()
{
    int arr[] = {1,2,3,4,5,6};
    
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    cout << "original array" << endl;
    print_array(arr, n);

    reverse_array(arr, n);
    cout<< "reversed array is" << endl;
    print_array(arr,6);

    return 0;

}