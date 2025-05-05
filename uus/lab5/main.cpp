#include "FlightsManager.h"
#include <conio.h>

int main() {
    FlightsManager manager;

    int select_point;
    while (true) {

        cout << "1: Array input" << endl;
        cout << "2: Array output" << endl;
        cout << "3: Array text output" << endl;
        cout << "4: Add flight to the array" << endl;
        cout << "5: Delete flight from the array" << endl;
        cout << "6: Get stats by destination" << endl;
        cout << "7: Get stats by plane" << endl;
        cout << "8: Print stats" << endl;
        cout << "9: Stats file save" << endl;
        cout << "10: Find by destination" << endl;
        cout << "11: Find by plane" << endl;
        cout << "12: Find by cost range" << endl;
        cout << "13. Print search result" << endl;
        cout << "14: Save search result to file" << endl;
        cout << "15: Array sort by name" << endl;
        cout << "16: Array sort by date" << endl;
        cout << "17: Array sort by year" << endl;
        cout << "18: Array sort by cost" << endl;
        cout << "19: Stats sort by names" << endl;
        cout << "20: Stats sort by average price" << endl;
        cout << "21: Search result sort by date" << endl;
        cout << "22: Search result sort by cost" << endl;
        cout << "23: Search result sort by destination" << endl;
        cout << "24: Search result sort by plane" << endl;
        cout << "25: Copy constructor for stats" << endl;
        cout << "26: Copy constructor for searcher" << endl;
        cout << "27: Exit" << endl;
        cout << "Your choice (1-27): ";
        cin >> select_point;

        switch (select_point)
        {
        case 1: {
//                flights_information.inputFile();
        }
            getch();
            break;
        case 2: {
                manager.informationPrint();
        }
            getch();
            break;
        case 3: {
//                flights_information.outputFile();
        }
            getch();
            break;
        case 4: {
//                Departure new_flight;
//                cout << "Enter new plane name: ";
//                cin >> new_flight.plane;
//                cout << "Enter plane destination: ";
//                cin >> new_flight.destination;
//                cout << "Enter flight cost: ";
//                cin >> new_flight.cost;
//                cout << "Enter departure date" << endl;
//                cout << "Year: "; cin >> new_flight.date.year;
//                cout << "Month: "; cin >> new_flight.date.month;
//                cout << "Day: "; cin >> new_flight.date.day;
//                cout << "Hour: "; cin >> new_flight.date.hour;
//                cout << "Minute: "; cin >> new_flight.date.minute;
//                flights_information.addFlight(new_flight);
        }
            getch();
            break;
        case 5: {
//                cout << flights_information;
//                int ID;
//                cout << "Enter flight ID to delete: "; cin >> ID;
//                flights_information.deleteFlight(ID);
        }
            getch();
            break;
        case 6:
            {
//                getStats(flights_information, flights_stats, true);
            }
//            cout << "Made destinations list" << endl;
            getch();
            break;
        case 7:
            {
//                getStats(flights_information, flights_stats, false);
            }
//            cout << "Made plane list" << endl;
            getch();
            break;
        case 8:
            {
//                cout << flights_stats << endl;
            }
            getch();
            break;
        case 9:
            {
//                flights_stats.WriteFile();
            }
            getch();
            break;
        case 10:
            {
//                cout << "Enter destination: ";
//                string dest;
//                cin >> dest;
//                dest[0] = toupper(dest[0]);
//                findFlightsByDestination(flights_information, flights_searcher, dest);
//                cout << "Flights found" << endl;
            }
            break;
        case 11:
            {
//                cout << "Enter plane name: ";
//                string plane;
//                cin >> plane;
//                plane[0] = toupper(plane[0]);
//                findFlightsByPlane(flights_information, flights_searcher, plane);
//                cout << "Flights found" << endl;
            }
            break;
        case 12:
            {
//                cout << "Enter cost range." << endl;
//                double min_cost;
//                cout << "Enter minimum cost: "; cin >> min_cost;
//                double max_cost;
//                cout << "Enter maximum cost: "; cin >> max_cost; cin >> max_cost;
//                findFlightByCostRange(flights_information, flights_searcher, min_cost, max_cost);
//                cout << "Flights found" << endl;
            }
            break;
        case 13:
            {
//                cout << flights_searcher << endl;
            }
            getch();
            break;
        case 14:
            {
//                flights_searcher.fileWrite();
            }
            break;
        case 15: {
//                cout << "Array was sorted by names" << endl;
//                flights_information.sortName();
//                getch();
        }
            getch();
            break;
        case 16: {
//                cout << "Array was sorted by date" << endl;
//                flights_information.sortDate();
//                getch();
        }
            getch();
            break;
        case 17:
            {
//                cout << "Array was sorted by year" << endl;
//                flights_information.sortYear();
            }
            getch();
            break;
        case 18:
            {
//                cout << "Array was sorted by cost" << endl;
//                flights_information.sortCost();
            }
            getch();
            break;
        case 19:
            {
//                flights_stats.sortCategories();
//                cout << "Stats were sorted by categories" << endl;
            }
            getch();
            break;
        case 20:
            {
//                flights_stats.sortPrices();
//                cout << "Stats were sorted by average price" << endl;
            }
            getch();
            break;
        case 21:
            {
//                flights_searcher.sortByDate();
//                cout << "Search result sorted by date" << endl;
            }
            getch();
            break;
        case 22:
            {
//                flights_searcher.sortByCost();
//                cout << "Search result sorted by cost" << endl;
            }
        case 23:
            {
//                flights_searcher.sortByDestination();
//                cout << "Search result sorted by destination" << endl;
            }
            getch();
            break;
        case 24:
            {
//                flights_searcher.sortByPlane();
//                cout << "Search result sorted by plane" << endl;
            }
            getch();
            break;
        case 25:
            {
//                FlightsStats copy_flights_stats(flights_stats);
//                cout << copy_flights_stats << endl;
            }
            getch();
            break;
        case 26:
            {
//                FlightsSearcher copy_flights_searcher(flights_searcher);
//                cout << copy_flights_searcher << endl;
            }
            getch();
            break;
        case 27:
            cout << "Bye!" << endl;
            exit(0);
        default:
            cout << "Invalid Choice!" << endl;
            getch();
            break;
        }
    }
}