#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void ReadBoardFile(string file) 
{
    ifstream my_file;
    my_file.open(file);

    if (my_file) 
    {
        cout << "The file stream has been created!" << "\n";
        string line;
        
        while (getline(my_file, line)) 
        {
            cout << line << "\n";
        }
    }
}


int main() 
{
    ReadBoardFile("board file/board");
}

