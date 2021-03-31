#include <iostream>
using namespace std;

int main() {

    float salary, sum = 0.0f;
    for (int i = 0; i < 12; i++) {
        cin >> salary;
        sum += salary;
    }
    cout << '$' << sum/12 << endl;

    return 0;
}