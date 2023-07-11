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
vector<vector<State>> Search (vector<vector<State>> board, int start[2], int goal[2])
{
    cout << " No path found!" << "\n";
    vector<vector<State>> v = {{}};
    return v;
}

//--------------------------------------------------------------------------

/*
Write a Heuristic function which takes four ints 
as arguments. The ints represent two pairs of 2D 
coordinates: (x1, y1, x2, y2). The function 
should return an int which is the Manhattan Distance 
from one coordinate to the other: ∣x2 − x1∣ + ∣y2 − y1∣
*/
int Heuristic(int x1, int y1, int x2, int y2)
{
    float distance;
    distance = abs(x2 - x1) + abs(y2 - y1);
    return distance;
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

void TestHeuristic() 
{
  cout << "----------------------------------------------------------" << "\n";
  cout << "Heuristic Function Test: ";
  if (Heuristic(1, 2, 3, 4) != 4) 
  {
    cout << "failed" << "\n";
    cout << "\n" << "Heuristic(1, 2, 3, 4) = " << Heuristic(1, 2, 3, 4) << "\n";
    cout << "Correct result: 4" << "\n";
    cout << "\n";
  } 
  else if (Heuristic(2, -1, 4, -7) != 8) 
  {
    cout << "TestHeuristic Failed" << "\n";
    cout << "\n" << "Heuristic(2, -1, 4, -7) = " << Heuristic(2, -1, 4, -7) << "\n";
    cout << "Correct result: 8" << "\n";
    cout << "\n";
  } 
  else 
  {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
}

//--------------------------------------------------------------------------

int main() 
{
    vector<vector<State>> board = ReadBoardFile("1.board");
    int start [2] = {0, 0};
    int goal [2] = {4, 5};
    vector<vector<State>> path = Search (board, start, goal);
    PrintBoard(path);
    TestHeuristic();
}