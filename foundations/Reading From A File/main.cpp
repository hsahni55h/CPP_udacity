#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream my_file;
    my_file.open("board file/board");
    
    if (my_file) 
    {
      cout << "The file stream has been created!" << "\n";
    }    
}