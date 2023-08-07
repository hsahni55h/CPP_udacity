#include<iostream>
#include<cstring>
using namespace std;


void reverse_string(char* str)
{
    int l;
    char *begin_ptr, *end_ptr, temp;

    l = strlen(str);

    begin_ptr = str;
    end_ptr = str + l -1;

    for (int i = 0; i < (l-1)/2; i++)
    {
        temp = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = temp;
        begin_ptr++;
        end_ptr--;
    }

}


int main()
{
    char str[100] = "Geeks for Geeks";
    cout<<"Original string: "<< str << endl;

    reverse_string(str);

    printf("Reverse of the string: %s\n", str);
 
  return 0;
}