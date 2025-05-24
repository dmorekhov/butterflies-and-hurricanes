#include "FlightsSearcher.h"

#include <algorithm>
#include <iostream>
#include <fstream>

FlightsSearcher::FlightsSearcher() : results(nullptr), count(0) {}

FlightsSearcher::FlightsSearcher(const FlightsSearcher& another) : FlightsStats(another), count(another.count),
    results(another.count > 0 ? new Departure[another.count] : nullptr) {

    if (another.count < 0) {
        results = nullptr;
        throw invalid_argument("FlightsSearcher can't be null");
    }
    for (int i = 0; i < count; i++) {
        results[i] = another.results[i];
    }
}

FlightsSearcher::~FlightsSearcher() {
    if (results != nullptr) {
        delete[] results;
    }
}

void FlightsSearcher::clear() {
    if (results != nullptr) {
        delete[] results;
        count = 0;
        results = nullptr;
    }
}

void FlightsSearcher::add(const Departure& departure) {
    Departure* temporary = new Departure[count + 1];
    for (int i = 0; i < count; ++i) {
        temporary[i] = results[i];
    }
    temporary[count] = departure;
    delete[] results;
    results = temporary;
    count++;
}

void FlightsSearcher::write() {
    cout << "Enter file name: ";
    string file_name;
    cin >> file_name;

    ofstream outfile(file_name, ios_base::app);
    if (!outfile.is_open()) {
        cout << "File could not be opened";
        return;
    }

    outfile << *this << endl;

    outfile.close();
    cout << "File " << file_name << " written successfully." << endl;
}

void FlightsSearcher::sortByDate() {
    sort(results, results + count);
}

bool compDestinationUtil(const Departure& a, const Departure& b) {
    return a.destination < b.destination;
}

void FlightsSearcher::sortByDestination() {
    sort(results, results + count, compDestinationUtil);
}

bool compCostUtil(const Departure& a, const Departure& b) {
    return a.cost < b.cost;
}

void FlightsSearcher::sortByCost() {
    sort(results, results + count, compCostUtil);
}

bool compPlaneUtil(const Departure& a, const Departure& b) {
    return a.plane < b.plane;
}

void FlightsSearcher::sortByPlane() {
    sort(results, results + count, compPlaneUtil);
}

FlightsSearcher& FlightsSearcher::operator=(const FlightsSearcher& another) {
    if (this != &another) {
        delete[] results;
        count = another.count;
        results = new Departure[count];
        for (int i = 0; i < count; ++i) {
            results[i] = another.results[i];
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, const FlightsSearcher& result) {
    if (result.count ==  0) {
        os << "No flights found";
        return os;
    }

    os << "=== Search result " << result.count << " elements ===" << endl;
    const int id_width = 4;
    const int name_width = 18;
    const int dest_width = 18;
    const int price_width = 10;
    const int date_width = 16;
    string line = "+" + string(id_width + 2, '-') + "+"
                        + string(name_width + 2, '-')
                        + "+" + string(dest_width + 2, '-')
                        + "+" + string(price_width + 2, '-')
                        + "+" + string(date_width + 2, '-') + "+" + '\n';
    os << line;
    os << "| " << left << setw(id_width) << "ID" << " | "
        << setw(name_width) << "Plane" << " | "
        << setw(dest_width) << "Destination" << " | "
        << setw(price_width) << "Price" << " | "
        << setw(date_width) << "Date" << " |" << endl;
    os << line;

    for (int i = 0; i < result.count; ++i) {
        os << "| " << left << setw(id_width) << i + 1 << " " << result.results[i];
        os << line;
    }
    os << "=======================" << endl;
    return os;
}

void FlightsSearcher::find(const char& choice) {
    switch (toupper(choice)) {
        case 'P': {
            string plane_name;
            cout << "Enter the name of the plane you want to search for: ";
            cin >> plane_name;
            plane_name[0] = toupper(plane_name[0]);
            findFlightsByPlane(plane_name);
            break;
        }
        case 'D': {
            string destination_name;
            cout << "Enter the destination name you want to search for: ";
            cin >> destination_name;
            destination_name[0] = toupper(destination_name[0]);
            findFlightsByDestination(destination_name);
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
            findFlightByCostRange(min_cost, max_cost);
            break;
        }
        default: {
            cout << "Wrong input!" << endl;
            break;
        }
    }
}

void FlightsSearcher::findFlightsByDestination(const string& dest) {
    clear();
    for (int i = 0; i < flights; ++i) {
        const Departure& dep = flights_info[i];
        if (dep.destination == dest) {
            add(dep);
        }
    }
}

void FlightsSearcher::findFlightsByPlane(const string& plane) {
    clear();
    for (int i = 0; i < flights; ++i) {
        const Departure& dep = flights_info[i];
        if (dep.plane == plane) {
            add(dep);
        }
    }
}

void FlightsSearcher::findFlightByCostRange(const double& min, const double& max) {
    clear();
    for (int i = 0; i < flights; ++i) {
        const Departure& dep = flights_info[i];
        if (dep.cost >= min && dep.cost <= max) {
            add(dep);
        }
    }
}

void FlightsSearcher::print() {
    cout << *this << endl;
}

void FlightsSearcher::sortFinder(const char& choice) {
    switch (toupper(choice)) {
        case 'P': {
            sortByPlane();
            cout << "Search results were sorted by plane names" << endl;
            break;
        }
        case 'C': {
            sortByCost();
            cout << "Search results were sorted by cost" << endl;
            break;
        }
        case 'Y': {
            sortByDate();
            cout << "Search results were sorted by date" << endl;
            break;
        }
        case 'D': {
            sortByDestination();
            cout << "Search results were sorted by destination" << endl;
            break;
        }
        default: {
            cout << "Wrong input!" << endl;
            break;
        }
    }
}
