#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::abs;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;
using namespace std;


// TODO: Add kStart and kFinish enumerators to the State enum.
enum class State
{
    kEmpty,
    kObstacle,
    kClosed,
    kPath,
    kStart,
    kFinish
};

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

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

/**
 * Compare the F values of two cells.
 */
bool Compare(vector<int> node1, vector<int> node2)
{
    if ((node1[2] + node1[3]) > (node2[2] + node2[3]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//--------------------------------------------------------------------------

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v)
{
    sort(v->begin(), v->end(), Compare);
}

//--------------------------------------------------------------------------

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
        return "⛰️   ";
    case State::kPath:
        return "🚗   ";
    // TODO: Add cases to return "🚦   " for kStart
    // and "🏁   " for kFinish.
    case State::kStart:
        return "🚦   ";
    case State::kFinish:
        return "🏁   ";
    default:
        return "0   ";
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
// TODO: Write CheckValidCell here. Check that the
// cell is on the grid and not an obstacle (i.e. equals kEmpty).
bool CheckValidCell(int x, int y, vector<vector<State>> &grid)
{
    bool on_grid_x = (x >= 0 && x < grid.size());
    bool on_grid_y = (y >= 0 && y < grid.size());

    if (on_grid_x && on_grid_y)
    {
        return grid[x][y] == State::kEmpty;
    }
    else
    {
        return false;
    }

}

//--------------------------------------------------------------------------
/** 
 * Expand current nodes's neighbors and add them to the open list.
 */
// TODO: ExpandNeighbors(arguments) {

// TODO: Get current node's data.

// TODO: Loop through current node's potential neighbors.

// TODO: Check that the potential neighbor's x2 and y2 values are on the grid and not closed.

// TODO: Increment g value, compute h value, and add neighbor to open list.

// } TODO: End the function

void ExpandNeighbors(const vector<int> &current,  int goal[2], vector<vector<int>> &open, vector<vector<State>> &grid)
{
    int x1 = current[0];
    int y1 = current[1];
    int g1 = current[2];
    for (int i = 0; i < 4; i++)
    {
        int x2 = x1 + delta[i][0];
        int y2 = y1 + delta[i][1];

        // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
        if (CheckValidCell(x2, y2, grid))
        {
            // Increment g value and add neighbor to open list.
            int g2 = g1 + 1;
            int h2 = Heuristic(x2, y2, goal[0], goal[1]);
            AddToOpen(x2, y2, g2, h2, open, grid);
        }
    }
}

//--------------------------------------------------------------------------

vector<vector<State>> Search (vector<vector<State>> board, int start[2], int goal[2])
{
    vector<vector<int>> open{};
    int x = start[0];
    int y = start[1];
    int g = 0;
    int h = Heuristic(x, y, goal[0], goal[1]);
    AddToOpen(x, y, g, h, open, board);

    // TODO: while open vector is non empty {
    // TODO: Sort the open list using CellSort, and get the current node.

    // TODO: Get the x and y values from the current node,
    // and set grid[x][y] to kPath.

    // TODO: Check if you've reached the goal. If so, return grid.

    //} // TODO: End while loop

    while(open.size() > 0)
    {
        CellSort(&open);
        auto current = open.back();
        open.pop_back();
        x = current[0];
        y = current[1];
        board[x][y] = State::kPath;
        
        if(x == goal[0] && y == goal[1])
        {
            // TODO: Set the init grid cell to kStart, and
            // set the goal grid cell to kFinish before returning the grid.
            board[start[0]][start[1]] = State::kStart;
            board[goal[0]][goal[1]] = State::kFinish;
            return board;
        }
        // If we're not done, expand search to current node's neighbors.
        ExpandNeighbors(current, goal, open, board);
    }

    // We've run out of new nodes to explore and haven't found a path.

    cout << " No path found!" << "\n";
    vector<vector<State>> v = {{}};
    return v;
}
//------------------------------TESTS--------------------------------------------

void PrintVector(vector<int> v)
{
    cout << "{ ";
    for (auto item : v)
    {
        cout << item << " ";
    }
    cout << "}"
         << "\n";
}

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
                               {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};
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
    return;
}

void TestCompare()
{
    cout << "----------------------------------------------------------"
         << "\n";
    cout << "Compare Function Test: ";
    vector<int> test_1{1, 2, 5, 6};
    vector<int> test_2{1, 3, 5, 7};
    vector<int> test_3{1, 2, 5, 8};
    vector<int> test_4{1, 3, 5, 7};
    if (Compare(test_1, test_2))
    {
        cout << "failed"
             << "\n";
        cout << "\n"
             << "a = ";
        PrintVector(test_1);
        cout << "b = ";
        PrintVector(test_2);
        cout << "Compare(a, b): " << Compare(test_1, test_2) << "\n";
        cout << "Correct answer: 0"
             << "\n";
        cout << "\n";
    }
    else if (!Compare(test_3, test_4))
    {
        cout << "failed"
             << "\n";
        cout << "\n"
             << "a = ";
        PrintVector(test_3);
        cout << "b = ";
        PrintVector(test_4);
        cout << "Compare(a, b): " << Compare(test_3, test_4) << "\n";
        cout << "Correct answer: 1"
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

void TestSearch()
{
    cout << "----------------------------------------------------------"
         << "\n";
    cout << "Search Function Test: ";
    int init[2]{0, 0};
    int goal[2]{4, 5};
    auto board = ReadBoardFile("board file/board");

    std::cout.setstate(std::ios_base::failbit); // Disable cout
    auto output = Search(board, init, goal);
    std::cout.clear(); // Enable cout

    vector<vector<State>> solution{{State::kStart, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                   {State::kPath, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                   {State::kPath, State::kObstacle, State::kEmpty, State::kClosed, State::kClosed, State::kClosed},
                                   {State::kPath, State::kObstacle, State::kClosed, State::kPath, State::kPath, State::kPath},
                                   {State::kPath, State::kPath, State::kPath, State::kPath, State::kObstacle, State::kFinish}};

    if (output != solution)
    {
        cout << "failed"
             << "\n";
        cout << "Search(board, {0,0}, {4,5})"
             << "\n";
        cout << "Solution board: "
             << "\n";
        PrintVectorOfVectors(solution);
        cout << "Your board: "
             << "\n";
        PrintVectorOfVectors(output);
        cout << "\n";
    }
    else
    {
        cout << "passed"
             << "\n";
    }
    return;
}

void TestCheckValidCell()
{
    cout << "----------------------------------------------------------"
         << "\n";
    cout << "CheckValidCell Function Test: ";
    vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kClosed, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};

    if (CheckValidCell(0, 0, grid))
    {
        cout << "failed"
             << "\n";
        cout << "\n"
             << "Test grid is: "
             << "\n";
        PrintVectorOfVectors(grid);
        cout << "Cell checked: (0, 0)"
             << "\n";
        cout << "\n";
    }
    else if (!CheckValidCell(4, 2, grid))
    {
        cout << "failed"
             << "\n";
        cout << "\n"
             << "Test grid is: "
             << "\n";
        PrintVectorOfVectors(grid);
        cout << "Cell checked: (4, 2)"
             << "\n";
        cout << "\n";
    }
    else
    {
        cout << "passed"
             << "\n";
    }
}

void TestExpandNeighbors()
{
    cout << "----------------------------------------------------------"
         << "\n";
    cout << "ExpandNeighbors Function Test: ";
    vector<int> current{4, 2, 7, 3};
    int goal[2]{4, 5};
    vector<vector<int>> open{{4, 2, 7, 3}};
    vector<vector<int>> solution_open = open;
    solution_open.push_back(vector<int>{3, 2, 8, 4});
    solution_open.push_back(vector<int>{4, 3, 8, 2});
    vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kClosed, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};
    vector<vector<State>> solution_grid = grid;
    solution_grid[3][2] = State::kClosed;
    solution_grid[4][3] = State::kClosed;
    ExpandNeighbors(current, goal, open, grid);
    CellSort(&open);
    CellSort(&solution_open);
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
    int start[2]{0, 0};
    int goal[2]{4, 5};
    auto board = ReadBoardFile("board file/board");
    auto path = Search(board, start, goal);
    PrintBoard(path);
    // Tests
    TestHeuristic();
    TestAddToOpen();
    TestCompare();
    TestSearch();
    TestCheckValidCell();
    TestExpandNeighbors();
}