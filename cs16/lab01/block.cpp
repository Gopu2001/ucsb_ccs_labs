#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        cout << "Enter number of rows and columns:" << endl;
        int rows, columns;
        cin >> rows;
        cin >> columns;
        if (cin.fail() || rows == 0 || columns == 0)
        {
            break;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << "X.";
            }
            cout << endl;
        }
    }
    return 0;
}
