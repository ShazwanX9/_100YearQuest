#include <iostream>
using namespace std;

// enum keypad {
//     A = 2, B = 2, C = 2, 
//     D = 3, E = 3, F = 3, 
//     G = 4, H = 4, I = 4, 
//     J = 5, K = 5, L = 5, 
//     M = 6, N = 6, O = 6, 
//     P = 7, R = 7, S = 7, 
//     T = 8, U = 8, V = 8, 
//     W = 9, X = 9, Y = 9, 
// };

/*
int next_key(int prevKey, char ref) {
    switch (ref)
    {
        case 65:
        case 66:
        case 67:
            return (prevKey + 2)*10;
        case 68:
        case 69:
        case 70:
            return (prevKey + 3)*10;
        case 71:
        case 72:
        case 73:
            return (prevKey + 4)*10;
        case 74:
        case 75:
        case 76:
            return (prevKey + 5)*10;
        case 77:
        case 78:
        case 79:
            return (prevKey + 6)*10;
        case 80:
        case 82:
        case 83:
            return (prevKey + 7)*10;
        case 84:
        case 85:
        case 86:
            return (prevKey + 8)*10;
        case 87:
        case 88:
        case 89:
            return (prevKey + 9)*10;
        default: //prevKey
            return (prevKey + ref-48)*10;

    }
}
*/

char next_key(char ref) {
    switch (ref)
    {
        case 65:
        case 66:
        case 67:
            return 50;
        case 68:
        case 69:
        case 70:
            return 51;
        case 71:
        case 72:
        case 73:
            return 52;
        case 74:
        case 75:
        case 76:
            return 53;
        case 77:
        case 78:
        case 79:
            return 54;
        case 80:
        case 82:
        case 83:
            return 55;
        case 84:
        case 85:
        case 86:
            return 56;
        case 87:
        case 88:
        case 89:
            return 57;
        default: //prevKey
            return ref; // (prevKey + ref-48)*10;

    }
}

void selectionSort(string a[], int n) {
   int i, j, min;
   string temp;
   for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
   }
}

int main() {
    // The first line of the input specifies the 
    // number of telephone numbers in the directory 
    // (up to 100,000) as a positive integer alone on the line.
    unsigned int n;
    cin >> n;
    // int nums[n];     // 4 bytes
    string number[n];   // 8 bytes

    for (int i = 0; i < n; i++) {
        // INPUT
        string input;
        cin >> input;

        // COMPUTE
        // int num = 0;
        string check = "";
        int location = 0;

        for (int j = 0; j < input.length(); j++) {
            if (input[j] != '-') {
                // num = next_key(num, input[j]);
                char key = next_key(input[j]);
                check += key;
                location++;
                if (location == 3)
                    check += '-';
            }
        }
        // nums[i] = num/10;
        number[i] = check;
    }

    // OUTPUT
    cout << endl;
    string check;
    bool duplicates = false;
    string* refNumber = number;
    selectionSort(refNumber, n);
    for (int i = 0; i < n; i++) {
        int counter = 0;
        check = refNumber[i];
        if (check == "-1")
            continue;
        for (int j = 0; j < n; j++) {
            if (refNumber[j] == check) {
                duplicates = true;
                refNumber[j] = "-1";
                counter++;
            }
        }
        if (duplicates && counter > 1)
            cout << check << " " << counter << endl;
    }
    if (!duplicates)
        cout << "No duplicates." << endl;

    return 0;
}