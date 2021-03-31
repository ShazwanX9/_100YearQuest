#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// A brute force solution that attempts 
// to compute an output value for every 
// individual pixel will likely fail due 
// to space or time constraints.


bool isInside(int cw, int len) {
    return (cw >= 0 && cw < len) ? true : false;
}

int absolute(int n) {
    return (n < 0) ? -n : n;
}


int RLE(int val[], int x) {
    int max = absolute(val[0] - x);

    for (int i = 0; i < 8; i++)
        if (absolute(val[i] - x) > max)
            max = absolute(val[i] - x);
    return max;
}

/*
int main() {

    int width, pixel, amount;
    int area = 0;
    vector<int> pixels, data;

    if (cin >> width) {
        int dataCounter = 0;

        while (cin >> pixel >> amount && !(pixel == 0 && amount == 0)) {
                pixels.resize(dataCounter+1);
                data.resize(dataCounter+1);

                pixels[dataCounter]   = pixel;
                data[dataCounter]     = amount;
                area               += amount;
                dataCounter++;
        }

        area /= width;
        int coImg[area][width], img[area][width];

        int counter = 0;
        dataCounter = 0;
        int check = data[dataCounter];

        for (int i = 0; i < area; i++) {
            for (int j = 0; j < width; j++) {
                counter++;
                coImg[i][j] = pixels[dataCounter];
                if (counter >= check) {
                    dataCounter++;
                    check = data[dataCounter];
                    counter = 0;
                }
            }
        }


        // DISPLAYING THE QUESTIONS;
        for (int i = 0; i < area; i++) {
            for (int j = 0; j < width; j++)
                cout << coImg[i][j] << " ";
            cout << endl;
        }

        int max = 0;
        int around[8];

        for (int i = 0; i < area; i++) {
            for (int j = 0; j < width; j++) {
                counter = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (isInside(i+k, area) && isInside(j+l, width))
                            around[counter++] = coImg[i+k][j+l];
                    }
                }
                while (counter < 8)
                    around[counter++] = coImg[i][j];
                img[i][j] = RLE(around, coImg[i][j]);
            }
        }

        // DISPLAYING THE ANSWER;
        for (int i = 0; i < area; i++) {
            for (int j = 0; j < width; j++)
                cout << img[i][j] << " ";
            cout << endl;
        }

        counter = 0;
        dataCounter = 0;
        cout << endl << width << endl;
        int checkCoor = img[0][0];

        for (int i = 0; i < area; i++) {
            for (int j = 0; j < width; j++, counter++) {
                if (img[i][j] != checkCoor) {
                    cout << checkCoor << " " << counter << endl;
                    counter = 0;
                    checkCoor = img[i][j];
                }
            }
        }
        cout << checkCoor << " " << counter << endl;
    }
    return 0;
}
*/

int getValue(int index, vector<int> data, vector<int> pixels) {
    int counter = 0;
    int val = data[0];
    while ( val <= index)
        val += data[++counter];
    return pixels[counter];
}

/*
int main() {

    int width, pixel, amount;
    vector<int> pixels, data, result;

    while (cin >> width && width) {
        int area = 0;

        while (cin >> pixel >> amount && !(pixel == 0 && amount == 0)) {
                pixels.push_back(pixel);
                data.push_back(amount);
                area += amount;
        }

        cout << endl;
        result.resize(area);

        for (int i = 0; i < area; i++) {
            int row = i/width;
            int col = i%width;

            for (int ver = row-1; ver <= row+1; ver++) {
                for (int hor = col-1; hor <= col+1; hor++) {
                    if ( isInside(width*ver+hor, area) && hor >= 0 && hor < width)
                        if ( absolute( getValue(width*ver+hor, data, pixels) - getValue(i, data, pixels) ) > result[i])
                            result[i] = absolute( getValue(width*ver+hor, data, pixels) - getValue(i, data, pixels) );
                }
            }
        }

        int count   = 1;
        int out     = result[0];
        result.push_back(-1); // eof

        for (int i = 1; i < result.size(); i++, count++) {
            if (result[i] != out) {
                cout << out << " " << count << endl;
                out = result[i];
                count = 0;
            }
        }
        cout << 0 << " " << 0 << endl;
    }
    return 0;
}
*/


