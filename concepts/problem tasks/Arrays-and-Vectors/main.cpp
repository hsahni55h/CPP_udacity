/*  Write a C++ program as follows:
    
    Declare 2 empty vectors of integers named
    vector1 and vector 2, respectively.
    
    Add 10 and 20 to vector1 dynamically using push_back
    Display the elements in vector1 using the at() method as well as its size using the size() method
    
    Add 100 and 200 to vector2 dynamically using push_back
    Display the elements in vector2 using the at() method as well as its size using the size() method

    Declare an empty 2D vector called vector_2d
    Remember, that a 2D vector is a vector of vector<int>
    
    Add vector1 to vector_2d dynamically using push_back
    Add vector2 to vector_2d dynamically using push_back
    
    Display the elements in vector_2d using the at() method
    
    Change vector1.at(0) to 1000
    
    Display the elements in vector_2d again using the at() method
    
    Display the elements in vector1 
    
    What did you expect? Did you get what you expected? What do you think happended?
*/
    
#include <iostream>
#include<vector>


using namespace std;

int main() {
    
    // your solution goes here
    vector <int> vector_1{};
    vector <int> vector_2{};
    
    //cout << "\nEnter a value to add to the vector: ";
    //int vec_add {0};
    //cin >> vec_add;
    
    vector_1.push_back(10);
    
    //cout << "\nEnter another value to add to the vector: ";
    //cin >> vec_add;
    
    vector_1.push_back(20);

    cout << "\nValues are now: " << endl;
    
    cout << vector_1.at(0) << endl;
    cout << vector_1.at(1) << endl;
    cout << "\nThere are now " << vector_1.size() << " values in the vector" << endl;

    //--------------------------------------------------------------------------
    
     vector_2.push_back(100);
     vector_2.push_back(200);

    cout << "\nValues are now: " << endl;
    
    cout << vector_2.at(0) << endl;
    cout << vector_2.at(1) << endl;
    cout << "\nThere are now " << vector_2.size() << " values in the vector" << endl;
    
    //----------------------------------------------------------------------------


     vector <vector<int>> vector_2d;

    vector_2d.push_back(vector_1);
    vector_2d.push_back(vector_2);

    cout << "\nThe elements in the 2D vector are :" << endl;
    cout << vector_2d[0][0] << endl;
    cout << vector_2d[0][1] << endl;
    cout << vector_2d[1][0] << endl;
    cout << vector_2d[1][1] << endl;

    cout << "\nvector_2d:" << endl;
    cout << vector_2d.at(0).at(0) << "  " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << "  " << vector_2d.at(1).at(1) << endl;

    //------------------------------------------------------------------------------


    vector_1.at(0)=1000;

    //-----------------------------------------------------------------------------


    cout << "\nvector_2d:" << endl;
    cout << vector_2d.at(0).at(0) << "  " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << "  " << vector_2d.at(1).at(1) << endl;


    //-----------------------------------------------------------------------------

    cout << "\nValues are now: " << endl;
    
    cout << vector_1.at(0) << endl;
    cout << vector_1.at(1) << endl;
    cout << "\nThere are now " << vector_1.size() << " values in the vector" << endl;

    
    cout << endl;
    return 0;
}

