
// #include <iostream>

// using namespace std;

// int main() {
    
//     enum Direction {
//         left, right, up, down
//     };
    
//     Direction heading {left};
    
//     switch (heading) {
//         case left:
//             cout << "Going left" << endl;
//             break;
//         case right:
//             cout << "Going right" << endl; 
//             break;
//         default:
//             cout << "OK" << endl;
//     }
    
//     cout <<  endl;
//     return 0;
// }


//-------------------------------------------------------------------------------


#include <iostream>
using namespace std;

int main()
{
    enum class Direction {kUp, kDown, kLeft, kRight};

    Direction a = Direction::kUp;
    // Direction b = Direction::kDown;

    switch (a) {
      case Direction::kUp : cout << "Going up!" << "\n";
        break;
      case Direction::kDown : cout << "Going down!" << "\n";
        break;
      case Direction::kLeft : cout << "Going left!" << "\n";
        break;
      case Direction::kRight : cout << "Going right!" << "\n";
        break;
    }
}