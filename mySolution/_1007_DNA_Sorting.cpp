#include <iostream>
using namespace std;

int bubbleSortStep(string ref, int n) {
    int step = 0;
    int i, j; 
    char temp;

    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++) 
            if (ref[j] > ref[j+1]) {
                temp = ref[j];
                ref[j] = ref[j+1];
                ref[j+1] = temp;
                step++;
            }  

    return step;
}

void bubbleSortBoth(string ref[], int res[], int n) {
    int i, j, tempInt; 
    string tempString;

    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++) 
            if (res[j] > res[j+1]) {

                tempString = ref[j];
                ref[j] = ref[j+1];
                ref[j+1] = tempString;

                tempInt = res[j];
                res[j] = res[j+1];
                res[j+1] = tempInt;

            }  

}

int main() {

    int n, m;
    while (n <= 0 || n > 50 || m <= 0 || m > 100)
        cin >> n >> m;

    string  dna[m];
    string  cal[m];
    int     res[m];

    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        dna[i] = input;
        cal[i] = input;
    }

    for (int i = 0; i < m; i++)
        res[i] = bubbleSortStep(cal[i], n);

    for (int i = 0; i < m; i++)
        cal[i] = dna[i]; //reinit 
    bubbleSortBoth(cal, res, m);

    cout << endl;
    for (int i = 0; i < m; i++)
        cout << cal[i] << endl;

    return 0;
}