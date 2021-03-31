#include <iostream>
using namespace std;

int main() {

    float c;
    while (cin >> c && c != 0.0f) {
        int card;
        if (c >= 0.01f && c <= 5.20f) {
            float calculation_length = 0.5f;
            for (card = 1; calculation_length < c; card++)
                calculation_length += 1.0/(card+2);
        }

        cout << card << " card(s)" << endl;
        // (card-1) ? cout << "s" << endl : cout << endl;
    }

    return 0;
}