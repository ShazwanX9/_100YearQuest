#include <iostream>
using namespace std;

int main() {

    __int16 p, e, i, d, // 2 bytes (32,767)
            phy, emo, inl,
            info = 0;
    const __int16 max = 21253;

    // //You will be given a number of cases.
    // int cases;
    // cin >> cases;
    int* days;

    while ( cin >> p >> e >> i >> d 
            && (p!=-1 && e!=-1 && i!=-1 &&  d!=-1)          // The end of input is indicated by a line in which p = e = i = d = -1.
            && (p<=365 && e<=365 && i<=365 &&  d<=365) ) {  // All values are non-negative and at most 365

        phy = 23+p, emo = 28+e, inl = 33+i;

        while (!(phy == emo && phy == inl && emo == inl) && phy < max) {
            while (phy < emo || phy < inl)
                phy += 23;
            while (emo < phy || emo < inl)
                emo += 28;
            while (inl < phy || inl < emo)
                inl += 33;
        }

        int* temp = days;
        delete days;
        days = new int[info+1];
        for (int k = 0; k < info; k++)
            days[k] = temp[k];
        delete temp;
        days[info] = (phy <= max && phy > 0) ? phy-d : -1;

        info++;
    }
    for (int i = 0; i < info; i++) {
        cout << "Case " << i+1 << ": the next triple peak occurs in ";
        if (days[i]+1)
            cout << days[i] << " days";
        else
            cout << "DNE or Cant Compute correcty";
        cout << '.' << endl;
    }
    // Use the plural form ``days'' even if the answer is 1. 

    return 0;
}