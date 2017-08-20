/**
   There are a number of syntax errors in the following program.
   Locate all errors, fix them, run the program and save its output.

   Mega Putra
*/

// */ What is wrong with this program? /*
/* What is wrong with this program? */ //Error 1: Asterisk placement

//#include <iostream>;
//Error 2: Removed semicolon at the end of statement
#include <iostream>

//using namespace std
//Error 3: missing semicolon
using namespace std;

int main()
//}
//Error 4: Wrong side of curly bracket
{

	//int a, b, c \\ three integers
	int a, b, c; // three integers
	//Error 5: missing semicolon and wrong slash sign

    // a = 3
    // b = 4
    //c = a + b
    //Error 6: missing semicolon at the end of statement
    a = 3;
    b = 4;
    c = a + b;

    //Cout << a << "+" << b << " = " << C << endl;
    //return0;
    //Error 7: Capital on "Cout" is removed since C++ is a case sensitive language
    //Error 8: space between "return" and "0"
    cout << a << "+" << b << " = " << c << endl;
    return 0;
}
//{
//Error 7: Wrong side of curly bracket
/*********************************************************************************
3+4 = 7
*/
