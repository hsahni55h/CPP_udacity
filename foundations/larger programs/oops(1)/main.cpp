
// // Code with Objects

// #include <iostream>
// #include <string>
// using std::string;
// using std::cout;

// // The Car class
// class Car {
//   public:
//     // Method to print data.
//     void PrintCarData() 
//     {
//         cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
//     }
    
//     // Method to increment the distance travelled.
//     void IncrementDistance() 
//     {
//         distance++;
//     }
    
//     // Class/object attributes
//     string color;
//     int distance = 0;
//     int number;
// };

// int main() 
// {
//     // Create class instances for each car.
//     Car car_1, car_2, car_3;

//     // Set each instance's color.
//     car_1.color = "green";
//     car_2.color = "red";
//     car_3.color = "blue";

//     // Set each instance's number.
//     car_1.number = 1;
//     car_2.number = 2;
//     car_3.number = 3;

//     // Increment car_1's position by 1.
//     car_1.IncrementDistance();

//     // Print out the position and color of each car.
//     car_1.PrintCarData();
//     car_2.PrintCarData();
//     car_3.PrintCarData();

// }

// Adding a Constructor


#include <iostream>
#include <string>
using std::string;
using std::cout;

class Car {
  public:
    void PrintCarData() 
    {
        cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }

    void IncrementDistance() 
    {
        distance++;
    }
    
    // Adding a constructor here:
    Car(string c, int n) 
    {
        // Setting the class attributes with
        // The values passed into the constructor.
        color = c;
        number = n;
    }
    
    string color;
    int distance = 0;
    int number;
};

int main() 
{
    // Create class instances for each car.
    Car car_1 = Car("green", 1);
    Car car_2 = Car("red", 2);
    Car car_3 = Car("blue", 3);

    // Increment car_1's position by 1.
    car_1.IncrementDistance();

    // Print out the position and color of each car.
    car_1.PrintCarData();
    car_2.PrintCarData();
    car_3.PrintCarData();
}
