#include "FlightsStats.h"

#include <algorithm>
#include <fstream>
#include <iostream>

FlightsStats::FlightsStats() : stats(nullptr), size(0) {}

FlightsStats::FlightsStats(const FlightsStats& another) : FlightsInfo(another), size(another.size),
                stats(another.size > 0 ? new FlightStat[another.size] : nullptr) {
    if (another.size < 0) {
        stats = nullptr;
        throw invalid_argument("Invalid FlightsStats");
    }
    for (int i = 0; i < another.size; i++) {
        stats[i] = another.stats[i];
    }
}

FlightsStats::~FlightsStats() {
    if (stats != nullptr) {
        delete[] stats;
        stats = nullptr;
        size = 0;
    }
}

FlightsStats& FlightsStats::operator=(const FlightsStats& another) {
    if (this != &another) {
        delete[] stats;
        size = another.size;
        stats = new FlightStat[size];
        for (int i = 0; i < size; i++) {
            stats[i] = another.stats[i];
        }
    }
    return *this;
}

void FlightsStats::write() {
    cout << "Enter file name: ";
    string filename;
    cin >> filename;

    ofstream outfile(filename, ios_base::app);
    if (!outfile.is_open()) {
        cout << "File could not be opened" << endl;
        return;
    }

    outfile << *this << endl;

    outfile.close();
    cout << "File " << filename <<  " written successfully" << endl;
}

bool compareAveragePrices(const FlightStat& first, const FlightStat& second) {
    double average_first = first.count > 0 ? first.total_cost / first.count : 0;
    double average_second = second.count > 0 ? second.total_cost / second.count : 0;
    return average_first < average_second;
}

bool compareCategory(const FlightStat& first, const FlightStat& second) {
    return first.category < second.category;
}

void FlightsStats::sortPrices() {
    sort(stats, stats + size, compareAveragePrices);
}

void FlightsStats::sortCategories() {
    sort(stats, stats + size, compareCategory);
}

ostream& operator<<(ostream& os, const FlightsStats& flights_stats) {
    if (flights_stats.size == 0) {
        os << "No flights";
        return os;
    }

    string line = "+" + string(20 + 2, '-')
                    + "+" + string(10 + 2, '-')
                    + "+" + string(15 + 2, '-')
                    + "+" + '\n';
    os << "+-----------------------------------------------------+" << endl;
    os << "| " << left << setw(20) << "Category" << " | "
              << right << setw(10) << "Count" << " | "
              << setw(15) << "Average Cost" << " |" << endl;
    os << line;
    for (int i = 0; i < flights_stats.size; i++) {
        os << flights_stats.stats[i];
        os << line;
    }

    return os;
}

void FlightsStats::getStats(bool by_destination) {
    if (stats != nullptr) {
        delete[] stats;
        stats = nullptr;
        size = 0;
    }

    FlightStat* temporary_data = new FlightStat[flights];
    int unique_counter = 0;

    for (int i = 0; i < flights; ++i) {
        Departure& departure = flights_info[i];
        string choose_category = by_destination ? departure.destination : departure.plane;

        bool found = false;
        for (int j = 0; j < unique_counter; ++j) {
            if (temporary_data[j].category == choose_category) {
                ++temporary_data[j].count;
                temporary_data[j].total_cost += departure.cost;
                found = true;
                break;
            }
        }
        if (!found) {
            temporary_data[unique_counter++] = {choose_category, 1, departure.cost};
        }
    }

    stats = new FlightStat[unique_counter];
    size = unique_counter;

    for (int i = 0; i < size; ++i) {
        stats[i] = temporary_data[i];
    }
    delete[] temporary_data;
}

void FlightsStats::print() {
    cout << *this << endl;
}

void FlightsStats::sortStatistics(const char& choice) {
    switch (toupper(choice)) {
        case 'P': {
            sortPrices();
            cout << "Statistics was sorted by price" << endl;
            break;
        }
        case 'C': {
            sortCategories();
            cout << "Statistics was sorted by categories" << endl;
            break;
        }
        default: {
            cout << "Wrong input!" << endl;
            break;
        }
    }
}
