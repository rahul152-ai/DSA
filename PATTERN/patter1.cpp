#include <iostream>
using namespace std;
void pattern1(int n)
{
    // numbers of row in pattern
    for (int row = 0; row < n; row++)
    {
        // numbers of column in pattern ;
        for (int column = 0; column < n; column++)
        {
            cout << "* ";
        }
        // adding new line
        cout << endl;
    }
}
void pattern2(int n)
{
    // outer loop for numbers of row;
    for (int row = 0; row < n; row++)
    {
        // loops for numbers of column in each row;
        for (int column = 0; column <= row; column++)
        {
            cout << "* ";
        }
        // for new line;
        cout << endl;
    }
}

// pattern 3 solution

void pattern3(int n)
{
    // outer loop for numbers of row;
    for (int row = 0; row < n; row++)
    {
        // loops for numbers of column in each row;
        for (int column = 0; column < n - row; column++)
        {
            cout << "* ";
        }
        // for new line;
        cout << endl;
    }
}

// solution of question pattern 4;
void pattern4(int n)
{
    // outer loop for numbers of row;
    for (int row = 1; row <= n; row++)
    {
        // loops for numbers of column in each row;
        for (int column = 1; column <= n - row + 1; column++)
        {
            cout << column << " ";
        }
        // for new line;
        cout << endl;
    }
}
// solution of question pattern 5;

void pattern5(int n)
{
    // outer loop for numbers of row;
    for (int row = 0; row < 2 * n; row++)
    {
        // number of column in each row;
        int totalcolumn = (row > n) ? 2 * n - row : row;
        // loops for column in each row;
        for (int column = 0; column < totalcolumn; column++)
        {
            cout << "* ";
        }
        // for new line;
        cout << endl;
    }
}

// solution of question 6
void pattern6(int n)
{
    // loops for row
    for (int row = 0; row < n; row++)
    {

        for (int space = 0; space < n - row - 1; space++)
        {
            cout << " ";
        }
        for (int column = 0; column <= row; column++)
        {
            cout << "*";
        }

        cout << endl;
    }
}
// SOLUTION OF QUESTION 7
void pattern7(int n)
{
    // loops for number of row
    for (int row = 0; row < n; row++)
    {
        // loops for space
        for (int space = 0; space < row; space++)
        {
            cout << " ";
        }
        // loops for star
        for (int column = 0; column < n - row; column++)
        {
            cout << "*";
        }
        cout << endl;
    }
} // question number 8
void pattern8(int n)
{
    // loops for row
    for (int row = 0; row < n; row++)
    {

        for (int space = 0; space < n - row - 1; space++)
        {
            cout << " ";
        }
        for (int column = 0; column <= row; column++)
        {
            cout << "*";
        }
        for (int column2 = 1; column2 <= row; column2++)
        {
            cout << "*";
        }

        cout << endl;
    }
}
//question number 9
void pattern9 (int n)
{
  // loops for number of row
  for (int row = 0; row < n; row++)
    {
      // loops for space
      for (int space = 0; space < row; space++)
	{
	  cout << " ";
	}
      // loops for star
      for (int column = 0; column < n - row; column++)
	{
	  cout << "*";
	}
      // loops for left star
      for (int column2 =1; column2 <n-row; column2++)
	{
	  cout << "*";
	}
      cout << endl;
    }
}
//question number 10
//question number 10
void pattern10(int n)
{
    // loops for row
    for (int row = 0; row < n; row++)
    {

        for (int space = 0; space < n - row - 1; space++)
        {
            cout << " ";
        }
        for (int column = 0; column <= row; column++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    pattern8(n);
    return 0;
}