#include "FlightsStats.h"
#include "FlightsInfo.h"

void getStats(const FlightsInfo& info, FlightsStats& result, bool by_destination) {
    if (result.stats != nullptr) {
        delete[] result.stats;
        result.stats = nullptr;
        result.size = 0;
    }
    FlightStat* temporary_data = new FlightStat[info.flights];
    int unique_counter = 0;

    for (int i = 0; i < info.flights; ++i) {
        Departure& departure = info.flights_info[i];
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

    result.stats = new FlightStat[unique_counter];
    result.size = unique_counter;

    for (int i = 0; i < result.size; ++i) {
        result.stats[i] = temporary_data[i];
    }

    delete[] temporary_data;
}