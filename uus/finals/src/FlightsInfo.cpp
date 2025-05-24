#include "FlightsInfo.h"

#include <algorithm>
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

void FlightsInfo::resize(const int new_length) {
    if (new_length < 0) {
        cout << "Bad length" << endl;
        return;
    }

    if (new_length == flights) {
        cout << "Same length" << endl;
        return;
    }

    Departure* new_flights = new Departure[new_length];
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

void FlightsInfo::addFlight() {
    Departure new_flight;
    cout << "Enter new plane name: ";
    cin >> new_flight.plane;
    cout << "Enter plane destination: ";
    cin >> new_flight.destination;
    cout << "Enter flight cost: ";
    cin >> new_flight.cost;
    cout << "Enter departure date" << endl;
    cout << "Year: "; cin >> new_flight.date.year;
    cout << "Month: "; cin >> new_flight.date.month;
    cout << "Day: "; cin >> new_flight.date.day;
    cout << "Hour: "; cin >> new_flight.date.hour;
    cout << "Minute: "; cin >> new_flight.date.minute;
    new_flight.destination[0] = toupper(new_flight.destination[0]);
    new_flight.plane[0] = toupper(new_flight.plane[0]);
    resize(flights + 1);
    flights_info[flights - 1] = new_flight;
}

void FlightsInfo::deleteFlight(const int& flight_number) {
    if (flight_number < 1 || flight_number > flights) {
        cout << "Bad flight number" << endl;
        return;
    }

    for (int index = flight_number - 1; index < flights - 1; ++index) {
        flights_info[index] = flights_info[index + 1];
    }
    int change = flights - 1;
    resize(change);

    cout << "Flight No " << flight_number << " deleted" << endl;
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
    file >> *this;

    file.close();
    cout << file_name << " file successfully read" << endl;
}

void FlightsInfo::write() {
    ofstream file;
    string file_name;

    cout << "Enter the file name: ";
    cin >> file_name;
    file.open(file_name, ios_base::app);

    if (!file.is_open()) {
        cout << "Can't open file" << endl;
        return;
    }

    file << *this << endl;

    file.close();
    cout << file_name << " file has been written" << endl;
}


bool compareNamesUtil(Departure& flight1, Departure& flight2) {
    string name1 = flight1.plane;
    string name2 = flight2.plane;
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

bool compareCostUtil(Departure& flight1, Departure& flight2) {
    return flight1.cost < flight2.cost;
}

void FlightsInfo::sortCost() {
    sort(flights_info, flights_info + flights, compareCostUtil);
}

void FlightsInfo::sortDate() {
    sort(flights_info, flights_info + flights);
}

void FlightsInfo::sortInfo(const char& choice) {
    switch (toupper(choice)) {
        case 'P': {
            sortName();
            cout << "Information was sorted by plane names" << endl;
            break;
        }
        case 'C': {
            sortCost();
            cout << "Information was sorted by cost" << endl;
            break;
        }
        case 'Y': {
            sortYear();
            cout << "Information was sorted by year" << endl;
            break;
        }
        case 'D': {
            sortDate();
            cout << "Information was sorted by date" << endl;
            break;
        }
        default: {
            cout << "Wrong input!" << endl;
            break;
        }
    }
}

ostream& operator<<(ostream& out, const FlightsInfo& info) {
    if (info.flights == 0) {
        out << "No flights found" << endl;
        return out;
    }
    const int id_width = 8;
    const int name_width = 18;
    const int dest_width = 18;
    const int price_width = 10;
    const int date_width = 16;

    string line = "+" + string(id_width + 2, '-')
                    + string(name_width + 2, '-')
                    + "+" + string(dest_width + 2, '-')
                    + "+" + string(price_width + 2, '-')
                    + "+" + string(date_width + 2, '-') + "+" + '\n';

    out << line;
    out << "| " << left << setw(id_width) << "ID" << "| "
        << setw(name_width) << "Plane" << " | "
        << setw(dest_width) << "Destination" << " | "
        << setw(price_width) << "Price" << " | "
        << setw(date_width) << "Date" << " |" << endl;
    out << line;

    for (size_t i = 0; i < info.flights; ++i) {
        const Departure& current_flight = info.flights_info[i];
        out << "| " << left << setw(id_width) << i + 1 << current_flight;
        out << line;
    }

    return out;
}

istream& operator>>(istream& is, FlightsInfo& info) {
    int line_counter = 0;
    Departure temp;

    streampos begin = is.tellg();

    while (true) {
        is >> temp.plane >> temp.destination >> temp.cost >> temp.date.year >> temp.date.month >>
        temp.date.day >> temp.date.hour >> temp.date.minute;
        if (is.fail()) {
            break;
        }
        ++line_counter;
    }
    if (!is.eof()) {
        is.clear();
        is.seekg(begin);
        cerr << "File data error" << endl;
        return is;
    }

    is.clear();
    is.seekg(begin);

    delete[] info.flights_info;
    info.flights = line_counter;
    info.flights_info = new Departure[info.flights];

    for (int i = 0; i < info.flights; ++i) {
        string temp_plane;
        string temp_destination;
        is >> temp_plane >> temp_destination >> info.flights_info[i].cost >> info.flights_info[i].date.year >>
        info.flights_info[i].date.month >> info.flights_info[i].date.day >> info.flights_info[i].date.hour >> info.flights_info[i].date.minute;
        temp_plane[0] = toupper(temp_plane[0]);
        info.flights_info[i].plane = temp_plane;
        temp_destination[0] = toupper(temp_destination[0]);
        info.flights_info[i].destination = temp_destination;
    }
    return is;
}

FlightsInfo& FlightsInfo::operator=(const FlightsInfo& another_data) {
    if (this != &another_data) {
        Departure* temp_flights = nullptr;
        if (another_data.flights > 0) {
            temp_flights = new Departure[another_data.flights];
            for (int i = 0; i < another_data.flights; ++i) {
                temp_flights[i] = another_data.flights_info[i];
            }
        }
        delete[] flights_info;
        flights_info = temp_flights;
        flights = another_data.flights;
    }
    return *this;
}

void FlightsInfo::print() {
    cout << *this << endl;
}
