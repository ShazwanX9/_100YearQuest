#include <iostream>
using namespace std;

// #include <sstream>
// string input;
// do {
//     getline(cin, input);
//     stringstream output (input);
//     output >> a >> b;
// } while ( a <= 0 || b > 10 );

int main() {
    int a, b;
    while ( a <= 0 || b > 10 )
        cin >> a >> b;
    cout << a+b << endl;
    return 0;
}