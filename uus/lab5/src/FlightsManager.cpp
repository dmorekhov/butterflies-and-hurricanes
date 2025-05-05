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

void FlightsManager::informationPrint() {
    cout << information << endl;
}


ostream& operator<<(ostream& os, const FlightsManager& mngr) {
    os << mngr.information << endl;
    os << mngr.statistics << endl;
    os << mngr.searcher << endl;
    return os;
}