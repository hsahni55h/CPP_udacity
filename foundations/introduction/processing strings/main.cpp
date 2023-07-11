/*
Streaming ints from a string with istringstream
In C++ strings can be streamed into temporary variables, similarly to how files can be streamed into strings. 
Streaming a string allows us to work with each character individually.

One way to stream a string is to use an input string stream object istringstream from the <sstream> header.

Once an istringstream object has been created, parts of the string can be streamed and stored using the "extraction operator": >>. 
The extraction operator will read until whitespace is reached or until the stream fails. Execute the following code to see how this works:
*/

//---------------------------------------------------------------
// #include <iostream>
// #include <sstream>
// #include <string>

// int main()
// {
//     std::string a("199 2 3");
//     std::istringstream myStream(a);
//     int n;
//     myStream >> n;
//     std::cout << n << "\n";
// }

//---------------------------------------------------------------

/*
The istringstream object can also be used as a boolean to determine if the last extraction operation failed - 
this happens if there wasn't any more of the string to stream, for example. 
If the stream still has more characters, you are able to stream again. See the following code for an example of using the istringstream this way:
*/

// #include <iostream>
// #include <sstream>
// #include <string>
// using namespace std;

// int main()
// {
//     string a("199 2 3");
//     istringstream myStream(a);
//     int n;

//     // Testing to see if the stream was successful and printing results.
//     // while (myStream)
//     // {
//     //     myStream >> n;
//     //     if (myStream)
//     //     {
//     //         cout << "That stream was successful: " << n << "\n";
//     //     }
//     //     else
//     //     {
//     //         cout << "That stream was NOT successful"
//     //                   << "\n";
//     //     }
//     // }

//     /*
//     GP - VIMP *****
//     The extraction operator >> writes the stream to the variable on the right of the operator and returns the istringstream object, 
//     so the entire expression my_stream >> n is an istringstream object and can be used as a boolean! 
//     Because of this, a common way to use istringstream is to use the entire extraction expression in a while loop as follows:
//     */

//     while (myStream >> n)
//     {
//         cout << "That stream was successful: " << n << "\n";
//     }

//     cout << "The stram has failed."
//               << "\n";

//     return 0;
// }


//---------------------------------------------------------------

/*
Strings with Mixed Types
In the stream example above, the string contained only whitespaces and characters which could be converted to ints. 
If the string has mixed types, more care is needed to process the string. 
In the following example, the type char is used, which is a type that can hold only a single ASCII character.
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string b("1,2,3");

    istringstream my_stream(b);

    char c;
    int n;

    while (my_stream >> n >> c)
    {
        cout << "That stream was successful: " << n << " " << c << "\n";
    }
    cout << "The stream has failed";
}

/*
In that example, notice that the 3 was not printed! The expression:

my_stream >> n >> c
tried to stream an int followed by a char. Since there was no char after the 3, the stream failed and the while loop exited.
*/

//---------------------------------------------------------------