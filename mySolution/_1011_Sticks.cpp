#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool test(vector <int> test, int val) {


    for (int i = 0; i < test.size(); i++) {
        if (test[i] == val) 
            test[i] = 0;
        if (test[i] >  val)
            return false;
    }
    sort(test.begin(), test.end(), greater <>());

    int iTemp = 0;
    for (int i = 0; i < test.size(); i++) {

        if (iTemp + test[i] <= val) {
            iTemp = iTemp + test[i];
            test[i] = 0;
        }
        if (iTemp == val) {
            i     = 0;
            iTemp = 0;
        }
    }

    for (int i = 0; i < test.size(); i++)
        if (test[i])
            return false;

    return true;
}


int main() {

    int iNumStick;

    while (cin >> iNumStick, iNumStick) {
        vector <int> vSticks;
        int iSum = 0, iRes = 0;

        for (int i = 0; i < iNumStick; i++) {
            int iLenght;
            cin >> iLenght;
            iSum += iLenght;
            vSticks.push_back(iLenght);
        }

        for (int i = vSticks[0]; i <= iSum; i++) {
            if (iSum % i) continue;
            else if ( test(vSticks, i) ) {
                iRes = i;
                break;
            }
        }

        cout << iRes << endl;
    }

    return 0;
}