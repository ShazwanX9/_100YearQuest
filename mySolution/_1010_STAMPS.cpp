#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct data{
    int iClient;
    int type;
    bool tie;
    vector <int> vStamps;
};

void compute(vector <int>& vStamps, data& dRes, int val) {
    bool proceed;

    for (int j = 0; j < vStamps.size(); j++) {
        for (int k = 0; k < vStamps.size(); k++) {
            for (int l = 0; l < vStamps.size(); l++) {
                for (int m = 0; m < vStamps.size(); m++) {
                    if ( vStamps[m]+vStamps[l]+vStamps[k]+vStamps[j] == val ) {
                        proceed = true;

                        if (m != l && m != k && m != j && l != k && l != j && j != k) {
                            dRes = { val, 4, false, {vStamps[m], vStamps[l], vStamps[k], vStamps[j]} };
                            return;
                        }
                        else if (m == l && m == k && m == j && l == k && l == j && j == k)
                            dRes = { val, 1, false, {vStamps[m], vStamps[l], vStamps[k], vStamps[j]} };
                        else if (
                            m == l && m != k && m != j && l != k && l != j && j != k ||
                            m != l && m == k && m != j && l != k && l != j && j != k ||
                            m != l && m != k && m == j && l != k && l != j && j != k ||
                            m != l && m != k && m != j && l == k && l != j && j != k ||
                            m != l && m != k && m != j && l != k && l == j && j != k ||
                            m != l && m != k && m != j && l != k && l != j && j == k 
                            ) {
                                dRes = { val, 3, false, {vStamps[m], vStamps[l], vStamps[k], vStamps[j]} };
                                return;
                            }
                        else
                            dRes = { val, 2, false, {vStamps[m], vStamps[l], vStamps[k], vStamps[j]} };

                    }
                }
            }
        }
    }

    for (int j = 0; j < vStamps.size(); j++) {
        for (int k = 0; k < vStamps.size(); k++) {
            for (int l = 0; l < vStamps.size(); l++) {
                if ( vStamps[j]+vStamps[l]+vStamps[k] == val ) {
                    proceed = true;

                    if (j != l && j != k && l != k) {
                        dRes = { val, 3, false, {vStamps[j], vStamps[l], vStamps[k]} };
                        return;
                    }
                    else if (j == l && j == k && l == k)
                        dRes = { val, 1, false, {vStamps[j], vStamps[l], vStamps[k]} };
                    else {
                        dRes = { val, 2, false, {vStamps[j], vStamps[l], vStamps[k]} };
                        break;
                    }

                }
            }
        }
    }


    for (int j = 0; j < vStamps.size(); j++) {
        for (int k = 0; k < vStamps.size(); k++) {
            if ( vStamps[j]+vStamps[k] == val ) {
                proceed = true;

                if (j != k) {
                    dRes = { val, 2, false, {vStamps[j], vStamps[k]} };
                    return;
                }
                else
                    dRes = { val, 1, false, {vStamps[j], vStamps[k]} };

            }
        }
    }
        

    for (int j = 0; j < vStamps.size(); j++) {
        if (vStamps[j] == val) {
            dRes = { val, 1, false, {vStamps[j]} };
            return;
        }
    }

    if (!proceed)
        dRes = { val, -1, false, {} };
    return;
}

void compare(vector <data>& vClient, int& id, int& measure) {

    vector <int> tempA;
    vector <int> tempB;

    for (int i = 0; i < vClient[id].vStamps.size(); i++) {
        if (vClient[id].vStamps[i])
            tempA.push_back(vClient[id].vStamps[i]);
    }
    for (int i = 0; i < vClient[measure].vStamps.size(); i++) {
        if (vClient[measure].vStamps[i])
            tempB.push_back(vClient[measure].vStamps[i]);
    }

    if (tempA.size() < tempB.size())
        vClient[measure].tie = true;
    else {
        vClient[id].tie = true;
        id = measure;
    }

}




int main() {

    int iStamp, iClient;
    vector <int> vStamps;
    vector <data> vClient;

    while  (cin >> iStamp, iStamp)    vStamps.push_back(iStamp);
    while  (cin >> iClient, iClient)  vClient.push_back( {iClient, {}} );  

    sort(vStamps.begin(), vStamps.end(), greater <>());

    for (int i = 0; i < vClient.size(); i++)
        compute(vStamps, vClient[i], vClient[i].iClient);

    for (int i = 1; i <= 4; i++) {
        int id = -1;
        for (int j = 0; j < vClient.size(); j++) {
            if (vClient[j].type == i) {
                if (id == -1) {
                    id = j;
                    continue;
                }
                compare(vClient, id, j);
            }
        }
    }



    for (int i = 0; i < vClient.size(); i++) {
        cout << vClient[i].iClient;

        if (vClient[i].type != -1)
            cout << " (" << vClient[i].type << "): ";
        else
            cout << " ---- ";

        if (vClient[i].type == -1)
            cout << "none";
        else if ( vClient[i].tie)
            cout << "tie";
        else {
            sort(vClient[i].vStamps.begin(), vClient[i].vStamps.end());

            for (int j = 0; j < vClient[i].vStamps.size(); j++)
                if (vClient[i].vStamps[j])
                    cout << vClient[i].vStamps[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
