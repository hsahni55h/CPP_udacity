#include <iostream>
#include <vector>
// using std::vector;
// using std::cout;


using namespace std;
int main()
{
    vector<int> a = {0, 1, 2, 3, 4};
    // Add some code here to access and print elements of a.
    cout << "a = \n";
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n\n";



    vector<vector<int>> b = {{1, 1, 2, 3},
                                       {2, 1, 2, 3},
                                       {3, 1, 2, 3}};

    cout << "b = \n";
    for (size_t i = 0; i < b.size(); i++)
    {
        for (size_t j = 0; j < b[0].size(); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";


    

    // Range based for loop
    cout << "RANGE BASED FOR LOOP \n";
    cout << "b = \n";
    for (auto v : b)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}