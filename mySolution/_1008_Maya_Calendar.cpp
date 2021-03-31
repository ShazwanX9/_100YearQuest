#include <iostream>
#include <sstream>
using namespace std;

int main() {

    int MayaMonthsSize = 19, TzolkinDaysSize = 20;
    string MayaMonths[] = {
        "pop", "no", "zip", "zotz", "tzec", 
        "xul", "yoxkin", "mol", "chen", "yax", 
        "zac", "ceh", "mac", "kankin", "muan", 
        "pax", "koyab", "cumhu", "uayet" 
    };

    string TzolkinDays[] = {
        "imix", "ik", "akbal", "kan", "chicchan", 
        "cimi", "manik", "lamat", "muluk", "ok", 
        "chuen", "eb", "ben", "ix", "mem", 
        "cib", "caban", "eznab", "canac", "ahau"
    };

    int n, day, year;

    cin >> n;
    cin.sync();
    cin.clear();

    string date, month;
    string dates[n], result[n];


    for (int i = 0; i < n; i++) {
        getline(cin, date);
        dates[i] = date;
        stringstream check(date);
        
        // Extract Maya Data
        check >> day;
        check >> month >> month; //twice to throw dot
        check >> year;
        
        int index = -1;
        for (int i = 0; i < MayaMonthsSize; i++)
            if (MayaMonths[i] == month) {
                index = i;
                break;
            }
        
        int totalDay = index*20+day+(year*365); // 365 = 20*18+5

        // Compute Tzolkin Data 
        // ( actually month is day and vice versa 
        //   but nvmind that refer datatypes )
        day     = totalDay%13+1;
        month   = TzolkinDays[totalDay%20];
        year    = totalDay/260; // 260 = 13*20
        result[i] = (to_string(day) + " " + month + " " + to_string(year));
    }
    cout << endl 
         << n << endl;
    for (int i = 0; i < n; i++)
        cout << result[i] << endl;
    cout << endl;

    
    return 0;
}
