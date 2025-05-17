#include "FlightsSearcher.h"

#include <algorithm>
#include <iostream>
#include <fstream>

FlightsSearcher::FlightsSearcher() : results(nullptr), count(0) {}

FlightsSearcher::FlightsSearcher(const FlightsSearcher& another) : count(another.count),
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

void FlightsSearcher::fileWrite() {
    cout << "Enter file name: ";
    string file_name;
    cin >> file_name;

    ofstream outfile(file_name);
    if (!outfile.is_open()) {
        cout << "File could not be opened";
        return;
    }
    outfile << "=== Search result " << count << " elements ===" << endl;
    for (int i = 0; i < count; ++i) {
        outfile << i + 1 << ". " << results[i] << endl;
    }
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
    for (int i = 0; i < result.count; ++i) {
        os << i + 1 << ". " << result.results[i] << endl;
    }
    os << "=======================" << endl;
    return os;
}