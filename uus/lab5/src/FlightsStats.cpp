#include "FlightsStats.h"

#include <algorithm>
#include <fstream>
#include <iostream>

FlightsStats::FlightsStats() : stats(nullptr), size(0) {
    cout << "hi" << endl;
}

FlightsStats::FlightsStats(const FlightsStats& another) : size(another.size),
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

void FlightsStats::writeFile() {
    cout << "Enter file name: ";
    string filename;
    cin >> filename;

    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cout << "File could not be opened" << endl;
        return;
    }
    outfile << "=== Flights statistic ===" << endl;
    outfile << "Categories: " << size << endl;

    for (int i = 0; i < size; ++i) {
        FlightStat stat = stats[i];
        double average_cost = stat.count > 0 ? stat.total_cost / stat.count : 0;
        outfile << i + 1 << ". " << stat.category << ": " << stat.count << " flights" << endl;
        if (stat.count > 0) {
            outfile << "Average cost: " << fixed << setprecision(2) << average_cost;
        }
        outfile << endl;
    }
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
    os << "-------------------------------------------------------" << endl;
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
