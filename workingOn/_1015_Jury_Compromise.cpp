#include <iostream>
#include <vector>
using namespace std;


struct selection {
    int iCandidate;
    int iJury;
};

int main() {

    int m, n;
    vector <selection> cases;
    while ( cin >> n >> m, (n && m)) {

        if (n > 1 && n <= 200
        && m > 1 && m <= 20
        && m <= n) continue;

        cases.push_back( {n, m} );
    }

    

    return 0;
}