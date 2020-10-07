#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

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
        //cout << fixed;
        //cout << setprecision(3);
        total = round(4000.0*total)/1000.0;
        if(total == (int)total) {
            string tot = to_string((int)total) + (string)(".000");
            cout << "The approximate value of pi using " << n << " terms is: " << tot << endl;
        } else {
            cout << "The approximate value of pi using " << n << " terms is: " << total << endl;
        }
    }
    return 0;
}
