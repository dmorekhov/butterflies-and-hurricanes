#include "FlightsInfo.h"
#include "FlightsSearcher.h"

void findFlightsByDestination(const FlightsInfo& info, FlightsSearcher& result, const string& dest) {
    result.clear();

    for (int i = 0; i < info.flights; ++i) {
        const Departure& dep = info.flights_info[i];
        if (dep.destination == dest) {
            result.add(dep);
        }
    }
}

void findFlightsByPlane(const FlightsInfo& info, FlightsSearcher& result, const string& plane) {
    result.clear();

    for (int i = 0; i < info.flights; ++i) {
        const Departure& dep = info.flights_info[i];
        if (dep.plane == plane) {
            result.add(dep);
        }
    }
}
void findFlightByCostRange(const FlightsInfo& info, FlightsSearcher& result, double min, double max) {
    result.clear();

    for (int i = 0; i < info.flights; ++i) {
        const Departure& dep = info.flights_info[i];
        if (dep.cost >= min && dep.cost <= max) {
            result.add(dep);
        }
    }
}
