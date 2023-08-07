#include<iostream>
using namespace std;

void reverse_array(int array[], int start, int end)
{
    while (start < end)
    {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--; 
    }
}


void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] <<" ";
    }
    cout << endl;
}


int main()
{
    int arr[] = {1,2,3,4,5,6};
    
    int n = sizeof(arr) / sizeof(arr[0]); 

    print_array(arr, n);

    reverse_array(arr, 0, n-1);

    cout<< "reversed array is" << endl;

    print_array(arr,6);

}