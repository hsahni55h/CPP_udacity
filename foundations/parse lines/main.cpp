#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// TODO: Add the ParseLine function here.
vector<int> ParseLine(string line) 
{
    istringstream my_stream(line);

    vector<int> dataLine;
    char c;
    int n;

    while (my_stream >> n >> c)
    {
      dataLine.push_back(n);
    }
    return dataLine;

}


void ReadBoardFile(string path) 
{
  ifstream myfile (path);
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      cout << line << "\n";
    }
  }
}

void PrintBoard(vector<vector<int>> board) 
{
    cout << "PRINTING BOARD \n";
    cout << "board = \n";
    for (auto v : board)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

}

void PrintVector(std::vector<int> v) {
  std::cout << "{ ";
  for (auto item : v) {
    std::cout << item << " ";
  }
  std::cout << "}" << "\n";
}

void TestParseLine() {
  std::cout << "----------------------------------------------------------" << "\n";
  std::cout << "TestParseLine: ";
  std::string line = "0,1,0,0,0,0,";
  std::vector<int> solution_vect{0,1,0,0,0,0};
  std::vector<int> test_vect;
  test_vect = ParseLine(line);
  if (test_vect != solution_vect) {
    std::cout << "failed" << "\n";
    std::cout << "\n" << "Test input string: " << line << "\n";
    std::cout << "Your parsed line: ";
    PrintVector(test_vect);
    std::cout << "\n";
  } else {
    std::cout << "passed" << "\n";
  }
  std::cout << "----------------------------------------------------------" << "\n";
  return;
}

int main() {
  ReadBoardFile("board file/board");
  TestParseLine(); // For testing.
  // Leave commented out.
  // PrintBoard(board);
}