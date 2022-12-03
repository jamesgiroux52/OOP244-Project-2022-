#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>
#include "Parking.h"
#include "Utils.h"

using namespace std;
using namespace sdds;
void runParking(long numSpots = 10);
void Datafile(bool restore = false);
int main(int argc, char* argv[]) {
    if (argc > 1) {
        long numberOfSpots = strtol(argv[1], nullptr, 10);
        if (numberOfSpots > 0 && numberOfSpots <= 100)
            runParking(numberOfSpots);
        else
            runParking();
    } else runParking();
    
    Datafile();

    return 0;
}
void runParking(long numSpots) {
    Parking P("ParkingData.csv", numSpots);
    P.run();
}
void Datafile(bool restore) {
    char ch;
    ifstream file("ParkingData.csv");
    cout << endl << "Content of Data File - (ParkingData.csv)" << endl << endl;
    cout << "FORMAT:" << endl;
    cout << "type,spot,plate,make_model,carwash or sidecar 0-false, 1 - true" << endl;
    cout << "---------------------------------------------------------------" << endl;
    if (file.get(ch)) cout << char(ch);
    if (file.eof()) cout << setw(40) << "Empty File - Empty Lot" << endl;
    else {
        while (file.get(ch)) {
            cout << char(ch);
        }
    }
    cout << "---------------------------------------------------------------" << endl;
    if (restore) {
        cout << "Restore data file to original values? (y)es/(n)o: ";
        file.close();
        if (cin.get() == 'y') {
            char ch;
            file.open("ParkingData.csv.bak");
            ofstream fout("ParkingData.csv");
            while (file) {
                ch = file.get();
                if (file) fout.put(ch);
            }
            file.close();
            fout.close();
            cout << "Data file restored to orginal values." << endl;
        } else {
            cout << "Restoration aborted!" << endl;
        }
    }
}

