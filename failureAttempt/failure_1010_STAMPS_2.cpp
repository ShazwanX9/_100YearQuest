#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct data{
    int iClient;
    int type;
    vector <int> vStamps;
};

bool isInside(vector <int>& vRef, int val) {
    for (int i = 0; i < vRef.size(); i++)
        if (val == vRef[i])
            return true;
    return false;
}

void compute(vector <int>& vStamps, data& dRes, int val) {
    for (int j = 0; j < vStamps.size(); j++) {
        for (int k = 0; k < vStamps.size(); k++) {
            for (int l = 0; l < vStamps.size(); l++) {
                for (int m = 0; m < vStamps.size(); m++) {
                    if ( vStamps[m]+vStamps[l]+vStamps[k]+vStamps[j] == val && !( isInside(vStamps, vStamps[m]+vStamps[l]+vStamps[k]+vStamps[j]) ) ) {
                        if (m != l && m != k && m != j && l != k && l != j && j != k)
                            dRes = { val, 4, {vStamps[m], vStamps[l], vStamps[k], vStamps[j]} };
                        else if (m == l && m == k && m == j && l == k && l == j && j == k)
                            dRes = { val, 1, {vStamps[m], vStamps[l], vStamps[k], vStamps[j]} };
                        else if (
                            m == l && m != k && m != j && l != k && l != j && j != k ||
                            m != l && m == k && m != j && l != k && l != j && j != k ||
                            m != l && m != k && m == j && l != k && l != j && j != k ||
                            m != l && m != k && m != j && l == k && l != j && j != k ||
                            m != l && m != k && m != j && l != k && l == j && j != k ||
                            m != l && m != k && m != j && l != k && l != j && j == k 
                            )
                            dRes = { val, 3, {vStamps[m], vStamps[l], vStamps[k], vStamps[j]} };
                        else
                            dRes = { val, 2, {vStamps[m], vStamps[l], vStamps[k], vStamps[j]} };
                        return;
                    }
                }
            }
        }
    }

    for (int j = 0; j < vStamps.size(); j++) {
        for (int k = 0; k < vStamps.size(); k++) {
            for (int l = 0; l < vStamps.size(); l++) {
                if ( vStamps[j]+vStamps[l]+vStamps[k] == val && !( isInside(vStamps, vStamps[j]+vStamps[l]+vStamps[k]) ) ) {
                    if (j != l && j != k && l != k)
                        dRes = { val, 3, {vStamps[j], vStamps[l], vStamps[k]} };
                    else if (j == l && j == k && l == k)
                        dRes = { val, 1, {vStamps[j], vStamps[l], vStamps[k]} };
                    else
                        dRes = { val, 2, {vStamps[j], vStamps[l], vStamps[k]} };
                    return;
                }
            }
        }
    }


    for (int j = 0; j < vStamps.size(); j++) {
        for (int k = 0; k < vStamps.size(); k++) {
            if ( vStamps[j]+vStamps[k] == val && !( isInside(vStamps, vStamps[j]+vStamps[k]) ) ) {
                if (j != k)
                    dRes = { val, 2, {vStamps[j], vStamps[k]} };
                else
                    dRes = { val, 1, {vStamps[j], vStamps[k]} };
                return;
            }
        }
    }
        

    for (int j = 0; j < vStamps.size(); j++) {
        if (vStamps[j] == val) {
            dRes = { val, 1, {vStamps[j]} };
            return;
        }
    }

    dRes = { val, -1, {} };
    return;
}

int test(vector <int>& vtest) {
    vtest.push_back(1);
    return 1;
}


int main() {

    int iStamp, iClient;
    vector <int> vStamps;
    vector <data> vClient;

    vStamps = {1, 2, 3};
    vClient.push_back( { 7, 0, {} } );
    vClient.push_back( { 4, 0, {} } );

    // vStamps = {1, 1, 0};
    // vClient.push_back( { 6, 0, {} } );
    // vClient.push_back( { 2, 0, {} } );
    // vClient.push_back( { 3, 0, {} } );

    // while  (cin >> iStamp, iStamp)    vStamps.push_back(iStamp);
    // while  (cin >> iClient, iClient)  vClient.push_back( {iClient, {}} );  

    sort(vStamps.begin(), vStamps.end(), greater <>());

    // for (int i = 0; i < vClient.size(); i++)
    //  cout << vClient[i].iClient << ':';

    for (int i = 0; i < vClient.size(); i++)
        compute(vStamps, vClient[i], vClient[i].iClient);

    int prevType;
    for (int i = 0; i < vClient.size(); i++) {
        cout << vClient[i].iClient;

        if (vClient[i].type != -1)
            cout << " (" << vClient[i].type << "): ";
        else
            cout << " ---- ";

        if (vClient[i].type == -1)
            cout << "none";
        else if ( vClient[i].type == prevType )
            cout << "tie";
        else {
            sort(vClient[i].vStamps.begin(), vClient[i].vStamps.end());
            // remove(vClient[i].vStamps.begin(), vClient[i].vStamps.end(), 0);
            for (int j = 0; j < vClient[i].vStamps.size(); j++)
                if (vClient[i].vStamps[j])
                    cout << vClient[i].vStamps[j] << " ";
        }

        cout << endl;
        prevType = vClient[i].type;
    }

    return 0;
}
