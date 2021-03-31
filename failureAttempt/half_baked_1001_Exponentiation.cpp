#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    long double result;
    double R;
    int n;

    while ( cin >> R >> n )
        if ( (R > 0 && R < 100) && (n > 0 && n <= 25) ) {

            result = R;
            if (result)
                for (int i = 1; i < n; i++)
                    result*=R;

            cout << fixed;
            (result - int(result)) ?
                cout << result : cout << int(result);
            cout << endl;
        }

    return 0;
}