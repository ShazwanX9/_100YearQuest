#include <iostream>
using namespace std;

int main() {
    long double PI = 3.1415926535897932l;
    int n;
    cin >> n;
    int year[n];

    for (int i = 0; i < n; i++) {
        float a, b;
        cin >> a >> b;
        float r = (a > b) ? a : b;
        year[i] = (r*r/2 * PI) / 50 + 1;
    }

    for (int i = 0; i < n; i++)
        cout << "Property " << i+1 << ": This property will begin eroding in year "<< year[i] << '.' << endl;
    cout << "END OF OUTPUT." << endl;

    return 0;
}