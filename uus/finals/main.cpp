#include "FlightsSearcher.h"
#include <conio.h>

int main() {
    FlightsSearcher manager;

    int select_point;
    while (true) {
        cout << "Information handler" << endl;
        cout << "1: Array input" << endl;
        cout << "2: Array output" << endl;
        cout << "3: Add flight to the array" << endl;
        cout << "4: Delete flight from the array" << endl << endl;;

        cout << "Statistics handler" << endl;
        cout << "5: Get stats by destination" << endl;
        cout << "6: Get stats by plane" << endl;
        cout << "7: Print stats" << endl << endl;

        cout << "Searcher handler" << endl;
        cout << "8: Find" << endl;
        cout << "9: Print search result" << endl << endl;

        cout << "Saving and sorting" << endl;
        cout << "10: Save to file" << endl;
        cout << "11: Information sort" << endl;
        cout << "12: Statistics sort" << endl;
        cout << "13: Searcher sort" << endl;
        cout << "14: Copy constructor for manager" << endl << endl;
        cout << "0: Exit" << endl << endl;
        cout << "Your choice (1-14): ";

        cin >> select_point;

        switch (select_point) {
        case 1: {
            manager.inputFile();
            getch();
            break;
        }
        case 2: {
            manager.FlightsInfo::print();
            getch();
            break;
        }
        case 3: {
            manager.addFlight();
            getch();
            break;
        }
        case 4: {
            manager.FlightsInfo::print();
            int ID;
            cout << "Enter flight ID to delete: "; cin >> ID;
            manager.deleteFlight(ID);
            getch();
            break;
        }
        case 5: {
            manager.getStats(true);
            cout << "Made destinations list" << endl;
            getch();
            break;
        }
        case 6: {
            manager.getStats(false);
            cout << "Made plane list" << endl;
            getch();
            break;
        }
        case 7: {
            manager.FlightsStats::print();
            getch();
            break;
        }
        case 8: {
            cout << "What do you want to find?" << endl;
            char choice;
            cout << "Plane[P], Destination[D], Cost range[C]: ";
            cin >> choice;
            manager.find(choice);
            getch();
            break;
            }
        case 9: {
            manager.FlightsSearcher::print();
            getch();
            break;
        }
        case 10: {
            cout << "What do you want to save?" << endl;
            char choice;
            cout << "Information[I], Statistics[S], Finder[F], All[A]: ";
            cin >> choice;
            switch(toupper(choice)) {
                case 'I': {
                    manager.FlightsInfo::write();
                    break;
                }
                case 'S': {
                    manager.FlightsStats::write();
                    break;
                }
                case 'F': {
                    manager.FlightsSearcher::write();
                    break;
                }
                case 'A': {
                    manager.FlightsInfo::write();
                    manager.FlightsStats::write();
                    manager.FlightsSearcher::write();
                    break;
                } default: {
                    cout << "Invalid choice" << endl;
                    break;
                }
            }
            getch();
            break;
        }
        case 11: {
            cout << "What do you want to sort information by?" << endl;
            char choice;
            cout << "Plane[P], Cost[C], Year[Y], Date[D]: ";
            cin >> choice;
            manager.sortInfo(choice);
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
            manager.sortFinder(choice);
            getch();
            break;
        }
        case 14: {
            FlightsSearcher copy_manager(manager);
            cout << "Current copy manager" << endl;
            manager.FlightsInfo::print();
            manager.FlightsStats::print();
            manager.FlightsSearcher::print();
            cout << "New copy manager" << endl;
            copy_manager.FlightsInfo::print();
            copy_manager.FlightsStats::print();
            copy_manager.FlightsSearcher::print();
            getch();
            break;
        }
        case 0: {
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