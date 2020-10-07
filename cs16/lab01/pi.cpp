#include <iostream>

using namespace std;

int main()
{
    while(true)
    {
        cout << "Enter the value of the parameter 'n' in the Leibniz formula ";
        cout << "(or -1 to quit):" << endl;
        int n = 0;
        cin >> n;
        if (cin.fail() || n <= -1)
        {
            break;
        }
        n += 1;
        double prime, multiplier = -1;
        double total = 0.0;
        for(double i = 0.0; i < n; i++)
        {
            prime = 2*i + 1;
            multiplier *= -1;
            total += (multiplier * 1 / prime) + 0.0;
            //cout << multiplier << " *" << " 1 / " << prime << endl;
        }
        total *= 4;
        cout << "The approximate value of pi using " << n << " terms is: " << total << endl;
    }
    return 0;
}
