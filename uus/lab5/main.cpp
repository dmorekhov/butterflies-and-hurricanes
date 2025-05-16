#include "FlightsManager.h"
#include <conio.h>

int main() {
    FlightsManager manager;

    int select_point;
    while (true) {
        cout << "1: Array input" << endl;
        cout << "2: Array output" << endl;
        cout << "3: Add flight to the array" << endl;
        cout << "4: Delete flight from the array" << endl;
        cout << "5: Get stats by destination" << endl;
        cout << "6: Get stats by destination" << endl;
        cout << "7: Print stats" << endl;
        cout << "8: Find" << endl;
        cout << "9. Print search result" << endl;
        cout << "10: Save to file" << endl;
        cout << "11: Information sort" << endl;
        cout << "12: Statistics sort" << endl;
        cout << "13: Searcher sort" << endl;
        cout << "14: Copy constructor for manager" << endl;
        cout << "15: Manager print" << endl;
        cout << "16: Exit" << endl;
        cout << "Your choice (1-16): ";

        cin >> select_point;

        switch (select_point) {
        case 1: {
            manager.readFile();
            getch();
            break;
        }
        case 2: {
            manager.informationPrint();
            getch();
            break;
        }
        case 3: {
            manager.addFlight();
            getch();
            break;
        }
        case 4: {
            manager.informationPrint();
            int ID;
            cout << "Enter flight ID to delete: "; cin >> ID;
            manager.removeFlight(ID);
            getch();
            break;
        }
        case 5: {
            manager.makeStats(true);
            cout << "Made destinations list" << endl;
            getch();
            break;
        }
        case 6: {
            manager.makeStats(false);
            cout << "Made plane list" << endl;
            getch();
            break;
        }
        case 7: {
            manager.statisticsPrint();
            getch();
            break;
        }
        case 8: {
            cout << "What do you want to find?" << endl;
            char choice;
            cout << "Plane[P], Destination[D], Cost range[C]: ";
            cin >> choice;
            manager.searchPlane(choice);
            getch();
            break;
            }
        case 9: {
                manager.searchPrint();
                getch();
                break;
        }
        case 10: {
            cout << "What do you want to save?" << endl;
            char choice;
            cout << "Information[I], Statistics[S], Finder[F], All[A]: ";
            cin >> choice;
            manager.managerWrite(choice);
            getch();
            break;
        }
        case 11: {
            cout << "What do you want to sort information by?" << endl;
            char choice;
            cout << "Plane[P], Cost[C], Year[Y], Date[D]: ";
            cin >> choice;
            manager.sortInformation(choice);
            getch();
            break;
        }
        case 12: {
            cout << "What do you want to sort statistics by?" << endl;
            char choice;
            cout << "Price[P], Categories[C]: ";
            cin >> choice;
            manager.sortStatistics(choice);
            getch();
            break;
        }
        case 13: {
            cout << "What do you want to sort search results by?" << endl;
            char choice;
            cout << "Plane[P], Cost[C], Date[Y], Destination[D]: ";
            cin >> choice;
            manager.sortSearch(choice);
            getch();
            break;
        }
        case 14: {
            FlightsManager copy_manager(manager);
            cout << "Current copy manager" << endl;
            cout << manager << endl;
            cout << "New copy manager" << endl;
            cout << copy_manager << endl;
        }
        case 15: {
            cout << manager << endl;
            getch();
            break;
        }
        case 16: {
            cout << "Bye!" << endl;
            exit(0);
        }
        default:
            cout << "Invalid Choice!" << endl;
            getch();
            break;
        }
    }
}