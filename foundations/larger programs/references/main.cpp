#include <iostream>
using std::cout;

int main() 
{
    int i = 1;
    
    // Declare a reference to i.
    int& j = i;
    // cout << "The value of j is: " << j << "\n";
    
    // Change the value of i.
    i = 5;
    // cout << "The value of i is changed to: " << i << "\n";
    // cout << "The value of j is now: " << j << "\n";
    
    // Change the value of the reference.
    // Since reference is just another name for the variable,
    // th
    j = 7;
    // cout << "The value of j is now: " << j << "\n";
    // cout << "The value of i is changed to: " << i << "\n";
    
    j = i;
    // cout << "The value of j is now: " << j << "\n";
    // cout << "The value of i is changed to: " << i << "\n";
    
    int k;
    k = 9;
    j = k;
    // cout << "The value of i is changed to: " << i << "\n";
    // cout << "The value of j is changed to: " << j << "\n";
    // cout << "The value of k is changed to: " << k << "\n";
    
    i = k;
    // cout << "The value of i is changed to: " << i << "\n";
    // cout << "The value of j is changed to: " << j << "\n";
    // cout << "The value of k is changed to: " << k << "\n";
    
    j = 'A';
    cout << "The value of i is changed to: " << i << "\n";
    cout << "The value of j is changed to: " << j << "\n";
    cout << "The value of k is changed to: " << k << "\n";
    
    
    
    
    
}