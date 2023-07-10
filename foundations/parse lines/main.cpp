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


// TODO: Change the return type of ReadBoardFile.
vector<vector<int>> ReadBoardFile(string path) 
{
  ifstream myfile (path);
  // TODO: Declare an empty board variable here with
  // type vector<vector<int>>.
  vector<vector<int>> board;

  if (myfile) 
  {
    string line;
    while (getline(myfile, line)) 
    {
       // TODO: Replace the "cout" code with a call to ParseLine 
      // for each line and push the results of ParseLine to the 
      // back of the board.
      vector<int> dataline = ParseLine(line);
      board.push_back(dataline);
    }
  }
  // TODO: Return the board variable.
  return board;
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


void PrintVector(std::vector<int> v) 
{
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


int main() 
{
  // TODO: Store the output of ReadBoardFile in the "board" variable.
  vector<vector<int>> board = ReadBoardFile("board file/board");
  // TODO: Uncomment PrintBoard below to print "board".
  PrintBoard(board);
}
