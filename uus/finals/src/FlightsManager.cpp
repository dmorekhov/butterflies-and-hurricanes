#include "FlightsManager.h"

FlightsManager::FlightsManager() = default;

FlightsManager::FlightsManager(FlightsManager& another) : information(another.information),
                                statistics(another.statistics), searcher(another.searcher) {}

FlightsManager::~FlightsManager() = default;

FlightsManager& FlightsManager::operator=(const FlightsManager& another) {
    if (this != &another) {
        information = another.information;
        statistics = another.statistics;
        searcher = another.searcher;
    }
    return *this;
}

void FlightsManager::readFile() {
    information.inputFile();
}

void FlightsManager::informationPrint() {
    cout << information << endl;
}

void FlightsManager::statisticsPrint() {
    cout << statistics << endl;
}

void FlightsManager::searchPrint() {
    cout << searcher << endl;
}

void FlightsManager::addFlight() {
    information.addFlight();
}

void FlightsManager::removeFlight(int& flight_index) {
    information.deleteFlight(flight_index);
}

void FlightsManager::makeStats(bool by_destination)
{
    statistics.getStats(by_destination);
}

void FlightsManager::searchPlane(char& symbol) {
    switch (toupper(symbol)) {
        case 'P': {
            string plane_name;
            cout << "Enter the name of the plane you want to search for: ";
            cin >> plane_name;
            plane_name[0] = toupper(plane_name[0]);
            // findFlightsByPlane(information, searcher, plane_name);
            break;
        }
        case 'D': {
            string destination_name;
            cout << "Enter the destination name you want to search for: ";
            cin >> destination_name;
            destination_name[0] = toupper(destination_name[0]);
            // findFlightsByDestination(information, searcher, destination_name);
            break;
        }
        case 'C': {
            double min_cost;
            double max_cost;
            cout << "Enter cost range" << endl;
            cout << "Enter minimum cost: ";
            cin >> min_cost;
            cout << "Enter maximum cost: ";
            cin >> max_cost;
            // findFlightByCostRange(information, searcher, min_cost, max_cost);
            break;
        }
        default: {
            cout << "Wrong input!" << endl;
            break;
        }
    }
}

void FlightsManager::sortInformation(char& choice) {
    switch (toupper(choice)) {
        case 'P': {
                information.sortName();
                cout << "Information was sorted by plane names" << endl;
                break;
        }
        case 'C': {
            information.sortCost();
            cout << "Information was sorted by cost" << endl;
            break;
        }
        case 'Y': {
            information.sortYear();
            cout << "Information was sorted by year" << endl;
            break;
        }
        case 'D': {
            information.sortDate();
            cout << "Information was sorted by date" << endl;
            break;
        }
        default: {
            cout << "Wrong input!" << endl;
            break;
        }
    }
}

void FlightsManager::sortStatistics(char& choice) {
    switch (toupper(choice)) {
        case 'P': {
            statistics.sortPrices();
            cout << "Statistics was sorted by price" << endl;
            break;
        }
        case 'C': {
            statistics.sortCategories();
            cout << "Statistics was sorted by categories" << endl;
            break;
        }
        default: {
            cout << "Wrong input!" << endl;
            break;
        }
    }
}

void FlightsManager::sortSearch(char& choice) {
    switch (toupper(choice)) {
    case 'P': {
            searcher.sortByPlane();
            cout << "Search results were sorted by plane names" << endl;
        }
    case 'C': {
            searcher.sortByCost();
            cout << "Search results were sorted by cost" << endl;
        }
    case 'Y': {
            searcher.sortByDate();
            cout << "Search results were sorted by date" << endl;
        }
    case 'D': {
            searcher.sortByDestination();
            cout << "Search results were sorted by destination" << endl;
        }
    default: {
            cout << "Wrong input!" << endl;
        }
    }
}

void FlightsManager::managerWrite(char& choice) {
    switch (toupper(choice)) {
        case 'I': {
            // information.outputFile();
            break;
        }
        case 'S': {
            // statistics.writeFile();
            break;
        }
        case 'F': {
            // searcher.fileWrite();
            break;
        }
        case 'A': {
            cout << "Information save" << endl;
            // information.outputFile();
            cout << "Statistics save" << endl;
            // statistics.writeFile();
            cout << "Search results save" << endl;
            // searcher.fileWrite();
            break;
        }
    }
}


ostream& operator<<(ostream& os, const FlightsManager& mngr) {
    os << "=== Information ===" << endl;
    os << mngr.information << endl;
    os << "=== Statistics ===" << endl;
    os << mngr.statistics << endl;
    os << "=== Search ===" << endl;
    os << mngr.searcher << endl;
    return os;
}
