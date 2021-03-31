#include <iostream>
using namespace std;


int kill(int k) {
    // index enemies start with k
    int iRes      = k;
    bool bProceed = true;

    while(bProceed) {
        bProceed = false;
        int iCount    = 0;
        int iTotal    = k*2;
        while (iTotal > k) { // k amount || while bad guy still there
            iCount = (iCount + iRes) % iTotal;
            if ( iCount < k) { // k index || first bad guy
                bProceed = true;
                break;
            }
            else
                iTotal--;
        }
        if (bProceed)
            iRes++;
    }
    return iRes+1;
}


int main() {
    int k;
    while (cin >> k, k)
        cout << kill(k) << endl;
    return 0;
}