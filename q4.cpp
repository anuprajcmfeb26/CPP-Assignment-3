#include <iostream>
using namespace std;

class DivideByZero {};

int divide(int a, int b)
{
    if (b == 0)
    {
        throw DivideByZero();
    }

    return a / b;
}

int main()
{
    int x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    try
    {
        try
        {
            int result = divide(x, y);
            cout << "Result = " << result << endl;
        }
        catch (DivideByZero)
        {
            cout << "Inner catch: Division by zero detected" << endl;
            throw;   // rethrow to outer catch
        }
    }
    catch (DivideByZero)
    {
        cout << "Outer catch: Exception handled here" << endl;
    }

    return 0;
}