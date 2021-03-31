#include <iostream>
#include <vector>
using namespace std;

int main() {

    int a, b, c, d, e, f;
    vector <bool> vResult;
    while (cin >> a >> b >> c >> d >> e >> f, a || b || c || d || e || f) {
        int iMarble[6] = {a%2, b%2, c%2, d%2, e%2, f%2};
        int iCount = 0, iTotal = 0;
        for (int i = 0; i < 6; i++) {
            if (iMarble[i]) {
                iCount++;
                iTotal += i+1;
            }
        }
        if ( iCount < 3 || iTotal%2 )
            vResult.push_back(0);
        else
            vResult.push_back(1);
    }

    for (int i = 0; i < vResult.size(); i++) {
        cout << endl
             << "Collection #" << i+1 << ':' << endl
             << "Can";
        if (!vResult[i])
            cout << "'t";
        cout << " be devided." << endl;
    }
    cout << endl;

    return 0;
}