#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using namespace std;


enum class State {kEmpty, kObstacle, kClosed};


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

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open, vector<vector<State>> &grid)
{
    vector<int> node = {x, y, g, h};
    open.push_back(node);
    grid[x][y] = State::kClosed;

}


//--------------------------------------------------------------------------


int Heuristic(int x1, int y1, int x2, int y2)
{
    float distance;
    distance = abs(x2 - x1) + abs(y2 - y1);
    return distance;
}

//--------------------------------------------------------------------------

vector<vector<State>> Search (vector<vector<State>> board, int start[2], int goal[2])
{
    // Create the vector of open nodes.
    vector<vector<int>> open{};
    int x = start[0];
    int y = start[1];
    int g = 0;
    int h = Heuristic(x, y, goal[0], goal[1]);

    // TODO: Use AddToOpen to add the starting node to the open vector.
    AddToOpen(x, y, g, h, open, board);

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

//------------------------------TESTS--------------------------------------------

void PrintVectorOfVectors(vector<vector<int>> v)
{
    for (auto row : v)
    {
        cout << "{ ";
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << "}"
             << "\n";
    }
}

void PrintVectorOfVectors(vector<vector<State>> v)
{
    for (auto row : v)
    {
        cout << "{ ";
        for (auto col : row)
        {
            cout << CellString(col) << " ";
        }
        cout << "}"
             << "\n";
    }
}

void TestHeuristic()
{
    cout << "----------------------------------------------------------"
         << "\n";
    cout << "Heuristic Function Test: ";
    if (Heuristic(1, 2, 3, 4) != 4)
    {
        cout << "failed"
             << "\n";
        cout << "\n"
             << "Heuristic(1, 2, 3, 4) = " << Heuristic(1, 2, 3, 4) << "\n";
        cout << "Correct result: 4"
             << "\n";
        cout << "\n";
    }
    else if (Heuristic(2, -1, 4, -7) != 8)
    {
        cout << "TestHeuristic Failed"
             << "\n";
        cout << "\n"
             << "Heuristic(2, -1, 4, -7) = " << Heuristic(2, -1, 4, -7) << "\n";
        cout << "Correct result: 8"
             << "\n";
        cout << "\n";
    }
    else
    {
        cout << "passed"
             << "\n";
    }
    return;
}

void TestAddToOpen()
{
    cout << "----------------------------------------------------------"
         << "\n";
    cout << "AddToOpen Function Test: ";
    int x = 3;
    int y = 0;
    int g = 5;
    int h = 7;
    vector<vector<int>> open{{0, 0, 2, 9}, {1, 0, 2, 2}, {2, 0, 2, 4}};
    vector<vector<int>> solution_open = open;
    solution_open.push_back(vector<int>{3, 0, 5, 7});
    vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kClosed, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};
    vector<vector<State>> solution_grid = grid;
    solution_grid[3][0] = State::kClosed;
    AddToOpen(x, y, g, h, open, grid);
    if (open != solution_open)
    {
        cout << "failed"
             << "\n";
        cout << "\n";
        cout << "Your open list is: "
             << "\n";
        PrintVectorOfVectors(open);
        cout << "Solution open list is: "
             << "\n";
        PrintVectorOfVectors(solution_open);
        cout << "\n";
    }
    else if (grid != solution_grid)
    {
        cout << "failed"
             << "\n";
        cout << "\n";
        cout << "Your grid is: "
             << "\n";
        PrintVectorOfVectors(grid);
        cout << "\n";
        cout << "Solution grid is: "
             << "\n";
        PrintVectorOfVectors(solution_grid);
        cout << "\n";
    }
    else
    {
        cout << "passed"
             << "\n";
    }
    cout << "----------------------------------------------------------"
         << "\n";
    return;
}

//--------------------------------------------------------------------------


int main() 
{
    // vector<vector<State>> board = ReadBoardFile("board file/board");
    // vector<vector<State>> path = Search (board, start, goal);
    int start [2] = {0, 0};
    int goal [2] = {4, 5};
    auto board = ReadBoardFile("board file/board");
    auto path = Search(board, start, goal);
    PrintBoard(path);
    // Tests
    TestHeuristic();
    TestAddToOpen();
}