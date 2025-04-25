#include "FlightsInfo.h"
#include <conio.h>

int main() {
    FlightsInfo flights_information;

    int select_point;
    while (true) {

        cout << "1: Array input" << endl;
        cout << "2: Array output" << endl;
        cout << "3: Array text output" << endl;
        cout << "4: Add flight to the array" << endl;
        cout << "5: Delete flight from the array" << endl;
        cout << "6: Array sort by name" << endl;
        cout << "7: Array sort by date" << endl;
        cout << "8: Array sort by year" << endl;
        cout << "9: Array sort by cost" << endl;
        cout << "10: Exit" << endl;
        cout << "Your choice (1-10): ";
        cin >> select_point;

        switch (select_point) {
        case 1: {
                flights_information.inputFile();
            }
            getch();
            break;
        case 2: {
                cout << flights_information;
            }
            getch();
            break;
        case 3: {
                flights_information.outputFile();
            }
            getch();
            break;
        case 4: {
                Departure new_flight;
                cout << "Enter new plane name: ";
                cin >> new_flight.plane;
                cout << "Enter plane destination: ";
                cin >> new_flight.destination;
                cout << "Enter flight cost: ";
                cin >> new_flight.cost;
                cout << "Enter departure date" << endl;
                cout << "Year: "; cin >> new_flight.date.year;
                cout << "Month: "; cin >> new_flight.date.month;
                cout << "Day: "; cin >> new_flight.date.day;
                cout << "Hour: "; cin >> new_flight.date.hour;
                cout << "Minute: "; cin >> new_flight.date.minute;
                flights_information.addFlight(new_flight);
            }
            getch();
            break;
        case 5: {
                cout << flights_information;
                int ID;
                cout << "Enter flight ID to delete: "; cin >> ID;
                flights_information.deleteFlight(ID);
            }
            getch();
            break;
        case 6: {
                cout << "Array was sorted by names" << endl;
                flights_information.sortName();
                getch();
            }
            getch();
            break;
        case 7: {
                cout << "Array was sorted by date" << endl;
                flights_information.sortDate();
                getch();
            }
            getch();
            break;
        case 8:
            {
                cout << "Array was sorted by year" << endl;
                flights_information.sortYear();
            }
            getch();
            break;
        case 9:
            {
                cout << "Array was sorted by cost" << endl;
                flights_information.sortCost();
            }
            getch();
            break;
        case 10:
            cout << "Bye!" << endl;
            exit(0);
        default:
            cout << "Invalid Choice!" << endl;
            getch();
            break;
        }
    }

}