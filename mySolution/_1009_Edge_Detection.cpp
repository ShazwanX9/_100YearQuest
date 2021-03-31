#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// A brute force solution that attempts 
// to compute an output value for every 
// individual pixel will likely fail due 
// to space or time constraints.

int absolute(int n) {
    return (n < 0) ? -n : n;
}

struct data{
    int pix;
    int val;
};

int getPix(int index, vector<data> input) {
    int count = 0;
    int tot = 0;
    while ( tot < index )
        tot += input[count++].val;
    return input[count-1].pix;
}

int getVal(int index, int width, int totVal, vector<data> input) {
    int curPix = getPix(index, input);
    int row = (index - 1) / width;
    int col = (index - 1) % width;
    int maxVal = 0;

    for (int ver = row - 1; ver <= row + 1; ver++) {
        for (int hor = col - 1; hor <= col + 1; hor++) {
            int surPos = ver * width + hor;
            if (ver < 0 || hor < 0 || hor >= width || surPos >= totVal || surPos == index - 1) 
                continue;
            int surPix = getPix(surPos+1, input);
            if  (maxVal < absolute(surPix - curPix) )
                maxVal = absolute(surPix - curPix);
        }
    }
    return maxVal;
}

bool comp(const data res1, const data res2) {
    return res1.pix < res2.pix;
}

int main() {

    int width;

    while (cin >> width, width) {
        vector<data> input;
        vector<data> result;
        int totalVal = 0, dataCount = 0, resCount = 0;
        int pix, val;

        while (cin >> pix >> val, (pix && val) ) {
            data temp;
            dataCount++;
            temp.pix = pix;
            temp.val = val;
            totalVal += val;
            input.push_back(temp);
        }

        int curPos = 1;
        for (int i = 0; i <= dataCount; i++) {
            int row = (curPos - 1) / width;
            int col = (curPos - 1) % width;
            for (int ver = row - 1; ver <= row + 1; ver ++) {
               for (int hor = col - 1; hor <= col + 1; hor ++) {
                    int surPos = width * ver + hor;
                    if (ver < 0 ||hor < 0 || hor >= width || surPos >= totalVal) continue;

                    data temp;
                    temp.pix = surPos+1;
                    temp.val = getVal(surPos+1, width, totalVal, input);
                    
                    result.push_back(temp);
                    resCount++;
               }
            }
            curPos += input[i].val;
        }

        sort(result.begin(), result.begin() + resCount, comp);

        cout << endl << width << endl;
        data tempData = result[0];

        for (int i = 0; i < resCount; i++) {
            if (result[i].val == tempData.val) continue;
            cout << tempData.val << " " << result[i].pix - tempData.pix << endl;
            tempData = result[i];            
        }
        cout << tempData.val << " " << resCount - tempData.pix + 1 << endl;
        cout << "0 0" << endl << endl;

        input.clear();
        result.clear();
    }
    // cout << width << endl;
    cout << "0" << endl;

    return 0;
}