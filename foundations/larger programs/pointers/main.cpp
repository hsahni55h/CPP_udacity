/* Accessing a Memory Address
Each variable in a program stores its contents in the computer's memory, and each chunk of the memory has an address number. 
For a given variable, the memory address can be accessed using an ampersand in front of the variable. 
*/

#include <iostream>
using std::cout;

int main() {
    int i = 5;
    int j = 6;
    
    // Print the memory addresses of i and j
    cout << "The address of i is: " << &i << "\n";
    cout << "The address of j is: " << &j << "\n";
}

/* Storing a Memory Address (int type)
Once a memory address is accessed, you can store it using a pointer. 
A pointer can be declared by using the * operator in the declaration.
*/

#include <iostream>
using std::cout;

int main() 
{
    int i = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_i = &i;
    
    // Print the memory addresses of i and j
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
}

/* Getting an Object Back from a Pointer Address
Once you have a pointer, you may want to retrieve the object it is pointing to. 
In this case, the * symbol can be used again. 
This time, however, it will appear on the right hand side of an equation or in front of an already-defined variable, 
so the meaning is different. 
In this case, it is called the "dereferencing operator", and it returns the object being pointed to.

*/

#include <iostream>
using std::cout;

int main() 
{
    int i = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_i = &i;
    
    // Print the memory addresses of i and j
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
    cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << "\n";
}


//------------------------------------------------------

#include <iostream>
using std::cout;

int main() {
    int i = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_i = &i;
    
    // Print the memory addresses of i and j
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
    
    // The value of i is changed.
    i = 7;
    cout << "The new value of the variable i is                     : " << i << "\n";
    cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << "\n";
}

//-----------------------Pointers to Other Object Types-------------------------------

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() 
{
    vector<int> v {1, 2, 3};
    
    // Declare and initialize a pointer to the address of v here:
    vector<int> *pointer_to_v = &v;
    for (int a: v) {
        cout << a << "\n";
    }
    
    // Dereference your pointer to v and print the int at index 0 here:
    cout << "The first element of v is:  "  << (*pointer_to_v)[0] << "\n";
}

//--------------------Passing Pointers to a Function----------------------------------


#include <iostream>
using std::cout;

void AddOne(int* j)
{
    // Dereference the pointer and increment the int being pointed to.
    (*j)++;
}

int main() 
{
    int i = 1;
    cout << "The value of i is: " << i << "\n";
    
    // Declare a pointer to i:
    int* pi = &i;
    AddOne(pi);
    cout << "The value of i is now: " << i << "\n";
}

//--------------------Returning a Pointer from a Function----------------------------------


#include <iostream>
using std::cout;

int* AddOne(int& j) 
{
    // Increment the referenced int and return the
    // address of j.
    j++;
    return &j;
}

int main() 
{
    int i = 1;
    cout << "The value of i is: " << i << "\n";
    
    // Declare a pointer and initialize to the value
    // returned by AddOne:
    int* my_pointer = AddOne(i);
    cout << "The value of i is now: " << i << "\n";
    cout << "The value of the int pointed to by my_pointer is: " << *my_pointer << "\n";
}