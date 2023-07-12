#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};


//--------------------------------------------------------------------------

vector<State> ParseLine(string line) 
{
    istringstream dataline(line);
    int n;
    char c;
   
    vector<State> row;
    while (dataline >> n >> c && c == ',') 
    {      
      row.push_back(n == 0 ? State::kEmpty : State::kObstacle);
    }
    return row;
}

//--------------------------------------------------------------------------

vector<vector<State>> ReadBoardFile(string path) 
{
  ifstream myfile (path);
  vector<vector<State>> board{};
 
  if (myfile) 
  {
    string line;
    while (getline(myfile, line)) 
    {
 
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

//--------------------------------------------------------------------------

// TODO: Write the Search function stub here.
// Write a Search stub which takes a board grid 
// and two length 2 int arrays as arguments. The int 
// arrays represent the start and goal coordinates 
// for the search. The function should print ""No path found!" 
// and return an empty std::vector<vector<State>>. 
// The function will later return the board with a path 
// from the start to the goal. In main(), call Search with a start 
// of {0, 0} and a goal of {4, 5}. Store the results in the
// variable solution. Pass solution to PrintBoard.

vector<vector<State>> Search (vector<vector<State>> board, int start[2], int goal[2])
{
    cout << " No path found!" << "\n";
    vector<vector<State>> v = {{}};
    return v;
}

//--------------------------------------------------------------------------

string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "⛰️  ";
    default:
        return "0  ";
    }
}

//--------------------------------------------------------------------------

void PrintBoard(vector<vector<State>> board) 
{
    cout << "PRINTING BOARD \n";
    cout << "board = \n";
    for (auto v : board)
    {
        for (auto i : v)
        {
          cout << CellString(i);
        }
        cout << "\n";
    }

}

//--------------------------------------------------------------------------

int main() 
{
    // TODO: Declare 2D "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
    vector<vector<State>> board = ReadBoardFile("board file/board");
    int start [2] = {0, 0};
    int goal [2] = {4, 5};
    // TODO: Call Search with "board", "init", and "goal". Store the results in the variable "solution".
    vector<vector<State>> path = Search (board, start, goal);
    // TODO: Change the following line to pass "solution" to PrintBoard.
    PrintBoard(path);
}