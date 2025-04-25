#include "FlightsInfo.h"


FlightsInfo::FlightsInfo() {}

FlightsInfo::~FlightsInfo() {
    delete[] flights;
}

void FlightsInfo::addFlight(Departure& flight) {
    if (amount_of_flights < MAX_FLIGHTS) {
        flights[amount_of_flights] = flight;
        ++amount_of_flights;
    } else {
        cout << "Flight list is full" << endl;
    }
}

void FlightsInfo::deleteFlight(int& index) {
    if (index >= amount_of_flights || index < 0) {
        cout << "Flight index out of range" << endl;
        return;
    }
    cout << "Confirmed deleting flight " << index << " Y/N" << endl;
    char confirm;
    cin >> confirm;
    if (confirm == 'Y' || confirm == 'y') {
        cout << "Deleting flight " << index << endl;
        for (int i = index - 1; i < amount_of_flights - 1; ++i) {
            flights[i] = flights[i + 1];
        }
        --amount_of_flights;
    } else {
        cout << "Cancel" << endl;
    }
}

void FlightsInfo::output() {
    cout << " " << string(104, '_') << endl;
    cout << "| " << left << setw(6) << "Number"
         << "| " << setw(20) << "Plane Name"
         << "| " << setw(12) << "Ticket Price"
         << "| " << setw(20) << "Destination"
         << "| " << setw(30) << "Arrival Date and Time" << "      |" << endl;
    cout << "|" << string(103, '_') << "|" << endl;

    for (int i = 0; i < amount_of_flights; ++i) {
        cout << "| " << left << setw(6) << i + 1
        << "| " << setw(20) << flights[i].plane
        << "| " << setw(12) << flights[i].cost
        << "| " << setw(20) << flights[i].arrival_place
        << "| " << setw(2) << flights[i].departure_date.day << "."
        << setw(2) << flights[i].departure_date.month << "."
        << setw(4) << flights[i].departure_date.year << " "
        << setw(2) << flights[i].departure_date.hour << ":"
        << setw(2) << setfill('0') << flights[i].departure_date.minute
        << setfill(' ') << "                   |" << endl;
        cout << " " << string(104, '-') << endl;
    }
}

bool compareNamesUtil(Departure& flight1, Departure& flight2) {
    string plane_1;
    string plane_2;
    for (auto& i : flight1.plane) {
        plane_1 += tolower(i);
    }
    for (auto& i : flight2.plane) {
        plane_2 += tolower(i);
    }
    return plane_1 < plane_2;
}

void FlightsInfo::sortName() {
    sort(flights, flights + amount_of_flights, compareNamesUtil);
}

    bool compareYearsUtil(Departure& flight1, Departure& flight2) {
        return flight1.departure_date.year < flight2.departure_date.year;
    }

void FlightsInfo::sortYear() {
    sort(flights, flights + amount_of_flights, compareYearsUtil);
}

bool compareDatesUtil(Departure& flight1, Departure& flight2) {
    if (flight1.departure_date.year != flight2.departure_date.year) {
        return flight1.departure_date.year < flight2.departure_date.year;
    }
    if (flight1.departure_date.month != flight2.departure_date.month) {
        return flight1.departure_date.month < flight2.departure_date.month;
    }
    if (flight1.departure_date.day != flight2.departure_date.day) {
        return flight1.departure_date.day < flight2.departure_date.day;
    }
    if (flight1.departure_date.hour != flight2.departure_date.hour) {
        return flight1.departure_date.hour < flight2.departure_date.hour;
    }
    return flight1.departure_date.minute < flight2.departure_date.minute;
}

void FlightsInfo::sortDate() {
    sort(flights, flights + amount_of_flights, compareDatesUtil);
}

bool compareCostsUtil(Departure& flight1, Departure& flight2) {
    return flight1.cost < flight2.cost;
}

void FlightsInfo::sortCost() {
    sort(flights, flights + amount_of_flights, compareCostsUtil);
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
        file >> temp.plane >> temp.arrival_place >> temp.cost >> temp.departure_date.year >> temp.departure_date.month >>
        temp.departure_date.day >> temp.departure_date.hour >> temp.departure_date.minute;
        if (file.fail()) {
            break;
        }
        ++line_counter;
    }
    if (line_counter > MAX_FLIGHTS || line_counter <= 0) {
        cout << file_name << " doesn't fit" << endl;
        file.close();
        return;
    }
    file.close();
    file.clear();

    file.open(file_name.c_str());
    if (file.fail()) {
        cout << file_name << " could not be opened" << endl;
        return;
    }
    amount_of_flights = line_counter;
    for (int i = 0; i < amount_of_flights; ++i) {
        file >> flights[i].plane >> flights[i].arrival_place >> flights[i].cost >> flights[i].departure_date.year >>
        flights[i].departure_date.month >> flights[i].departure_date.day >> flights[i].departure_date.hour >> flights[i].departure_date.minute;
    }

    file.close();
    cout << file_name << " successfully read" << endl;
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

    for (int i = 0; i < amount_of_flights; ++i) {
        file << "| " << left << setw(6) << i + 1
        << "| " << setw(20) << flights[i].plane
        << "| " << setw(12) << flights[i].cost
        << "| " << setw(20) << flights[i].arrival_place
        << "| " << setw(2) << flights[i].departure_date.day << "."
        << setw(2) << flights[i].departure_date.month << "."
        << setw(4) << flights[i].departure_date.year << " "
        << setw(2) << flights[i].departure_date.hour << ":"
        << setw(2) << setfill('0') << flights[i].departure_date.minute
        << setfill(' ') << "                   |" << endl;
        file << " " << string(104, '-') << endl;
    }
    file.close();

    cout << "File has been written" << endl;
}