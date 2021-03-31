#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct coin {
    char letter;
    bool status;
    char pos;
};

int main() {

    int cases = 1;
    // cin >> cases;
    vector <coin> coin65;
    for (int i = 0; i < 11; i++)
        coin65.push_back({ char(65+i), false, '-' });


    for (int i = 0; i < cases; i++) {
        for (int j = 0; j < 3; j++) {
            string sRef, sLeft, sRight, sBalance;
            getline(cin, sRef);
            stringstream ssRef(sRef);
            ssRef >> sLeft;
            ssRef >> sRight;
            ssRef >> sBalance;

            for (int k = 0; k < 4; k++) {
                if (sBalance == "even") {
                    coin65 [char(sLeft[k]) - 65] = { sLeft[k], true, '-' };
                    coin65 [char(sRight[k]) - 65] = { sRight[k], true, '-' };
                }
                else if (sBalance == "up") {
                    if (!coin65 [char(sLeft[k]) - 65].status)
                        coin65 [char(sLeft[k]) - 65] = { sLeft[k], false, 'd' };
                    if (!coin65 [char(sRight[k]) - 65].status)
                      coin65 [char(sRight[k]) - 65] = { sRight[k], false, 'u' };
                }
                else if (sBalance == "down") {
                    if (!coin65 [char(sLeft[k]) - 65].status)
                        coin65 [char(sLeft[k]) - 65] = { sLeft[k], false, 'u' };
                    if (!coin65 [char(sRight[k]) - 65].status)
                        coin65 [char(sRight[k]) - 65] = { sRight[k], false, 'd' };
                }
            }
        }

        for (int j = 0; j < coin65.size(); j++) {
            if ( !coin65[j].status ) {
                cout << coin65[j].letter << " is the counterfeit coin and it is ";
                if ( coin65[j].pos == 'u' )
                    cout << "light" << endl;
                else if ( coin65[j].pos == 'd' )
                    cout << "heavy" << endl;
            }
        }


    }

    return 0;
}