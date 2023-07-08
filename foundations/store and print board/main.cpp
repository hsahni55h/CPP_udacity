#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1, 0}};



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



    return 0;
}