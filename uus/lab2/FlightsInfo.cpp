#include "FlightsInfo.h"

#include <algorithm>
#include <iomanip>
#include <fstream>

FlightsInfo::FlightsInfo() : flights_info(nullptr), flights(0) {}

FlightsInfo::FlightsInfo(const FlightsInfo& another_data) : flights(another_data.flights),
    flights_info(another_data.flights > 0 ? new Departure[another_data.flights] : nullptr) {

    if (another_data.flights < 0) {
        flights_info = nullptr;
        throw invalid_argument("FlightsInfo::FlightsInfo");
    }
    for (int i = 0; i < flights; ++i) {
        flights_info[i] = another_data.flights_info[i];
    }
}

FlightsInfo::~FlightsInfo() {
    delete[] flights_info;
}

void FlightsInfo::resize(int new_length) {
    if (new_length < 0) {
        cout << "Bad length" << endl;
        return;
    }

    if (new_length == flights) {
        cout << "Same length" << endl;
        return;
    }

    Departure* new_flights = new Departure[new_length];
    // memcpy(new_flights, flights, sizeof(Departure) * flights);
    int element_copy = min(new_length, flights);
    for (int i = 0; i < element_copy; i++) {
        new_flights[i] = flights_info[i];
    }

    if (flights_info) {
        delete[] flights_info;
    }
    flights = new_length;
    flights_info = new_flights;
}


void FlightsInfo::addFlight(const Departure& flight) {
    resize(flights + 1);
    flights_info[flights - 1] = flight;
}

void FlightsInfo::deleteFlight(int& flight_number) {
    if (flight_number < 1 || flight_number > flights) {
        cout << "Bad flight number" << endl;
        return;
    }

    for (int index = flight_number - 1; index < flights - 1; ++index) {
            flights_info[index] = flights_info[index + 1];
    }
    int change = flights - 1;
    resize(change);
}

void FlightsInfo::printFlights() {
    cout << " " << string(104, '_') << endl;
    cout << "| " << left << setw(6) << "Number"
         << "| " << setw(20) << "Plane Name"
         << "| " << setw(12) << "Ticket Price"
         << "| " << setw(20) << "Destination"
         << "| " << setw(30) << "Arrival Date and Time" << "      |" << endl;
    cout << "|" << string(103, '_') << "|" << endl;

    for (int i = 0; i < flights; ++i) {
        cout << "| " << left << setw(6) << i + 1
        << "| " << setw(20) << flights_info[i].plane
        << "| " << setw(12) << flights_info[i].cost
        << "| " << setw(20) << flights_info[i].destination
        << "| " << setw(2) << flights_info[i].date.day << "."
        << setw(2) << flights_info[i].date.month << "."
        << setw(4) << flights_info[i].date.year << " "
        << setw(2) << flights_info[i].date.hour << ":"
        << setw(2) << setfill('0') << flights_info[i].date.minute
        << setfill(' ') << "                   |" << endl;
        cout << " " << string(104, '-') << endl;
    }
}

void FlightsInfo::inputFile() {
    string file_name;
    cout << "Enter file name: ";
    cin >> file_name;

    ifstream file(file_name.c_str());
    if (file.fail()) {
        cout << file_name << " could not be opened" << endl;
        return;
    }

    int line_counter = 0;
    Departure temp;
    while (true) {
        file >> temp.plane >> temp.destination >> temp.cost >> temp.date.year >> temp.date.month >>
        temp.date.day >> temp.date.hour >> temp.date.minute;
        if (file.fail()) {
            break;
        }
        ++line_counter;
    }
    if (line_counter > flights || line_counter <= 0) {
        cout << file_name << " doesn't fit. Resize" << endl;
        resize(line_counter);

    }
    file.close();
    file.clear();

    file.open(file_name.c_str());
    if (file.fail()) {
        cout << file_name << " could not be opened" << endl;
        return;
    }
    flights = line_counter;
    for (int i = 0; i < flights; ++i) {
        file >> flights_info[i].plane >> flights_info[i].destination >> flights_info[i].cost >> flights_info[i].date.year >>
        flights_info[i].date.month >> flights_info[i].date.day >> flights_info[i].date.hour >> flights_info[i].date.minute;
    }

    file.close();
    cout << file_name << " file successfully read" << endl;
}

void FlightsInfo::outputFile() {
    ofstream file;
    string file_name;
    cout << "Enter the file name: ";
    cin >> file_name;
    file.open(file_name, ios_base::app);
    if (!file.is_open()) {
        cout << "Can't open file" << endl;
        return;
    }
    file << " " << string(104, '_') << endl;
    file << "| " << left << setw(6) << "Number"
         << "| " << setw(20) << "Plane Name"
         << "| " << setw(12) << "Ticket Price"
         << "| " << setw(20) << "Destination"
         << "| " << setw(30) << "Arrival Date and Time" << "      |" << endl;
    file << "|" << string(103, '_') << "|" << endl;

    for (int i = 0; i < flights; ++i) {
        file << "| " << left << setw(6) << i + 1
        << "| " << setw(20) << flights_info[i].plane
        << "| " << setw(12) << flights_info[i].cost
        << "| " << setw(20) << flights_info[i].destination
        << "| " << setw(2) << flights_info[i].date.day << "."
        << setw(2) << flights_info[i].date.month << "."
        << setw(4) << flights_info[i].date.year << " "
        << setw(2) << flights_info[i].date.hour << ":"
        << setw(2) << setfill('0') << flights_info[i].date.minute
        << setfill(' ') << "                   |" << endl;
        file << " " << string(104, '-') << endl;
    }

    file.close();
    cout << file_name << " file has been written" << endl;
}


bool compareNamesUtil(Departure& flight1, Departure& flight2) {
    string name1 = flight1.plane;
    string name2 = flight2.plane;
    transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) { return toupper(c); });
    transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) { return toupper(c); });
    return name1 < name2;
}

void FlightsInfo::sortName() {
    sort(flights_info, flights_info + flights, compareNamesUtil);
}


bool compareYearsUtil(Departure& flight1, Departure& flight2) {
    return flight1.date.year < flight2.date.year;
}

void FlightsInfo::sortYear() {
    sort(flights_info, flights_info + flights, compareYearsUtil);
}

bool compareMoneyUtil(Departure& flight1, Departure& flight2) {
    return flight1.cost < flight2.cost;
}

void FlightsInfo::sortCost() {
    sort(flights_info, flights_info + flights, compareMoneyUtil);
}

bool compareDatesUtil(Departure& flight1, Departure& flight2) {
    if (flight1.date.year != flight2.date.year) {
        return flight1.date.year < flight2.date.year;
    }
    if (flight1.date.month != flight2.date.month) {
        return flight1.date.month < flight2.date.month;
    }
    if (flight1.date.day != flight2.date.day) {
        return flight1.date.day < flight2.date.day;
    }
    if (flight1.date.hour != flight2.date.hour) {
        return flight1.date.hour < flight2.date.hour;
    }
    return flight1.date.minute < flight2.date.minute;
}

void FlightsInfo::sortDate() {
    sort(flights_info, flights_info + flights, compareDatesUtil);
}


