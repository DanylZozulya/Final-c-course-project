#include "DataBase.h"

Date ParseDate(const string& date) {
    istringstream date_stream(date);
    bool ok = true;

    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok) {
        throw logic_error("Wrong date format: " + date);
    }
    return {year, month, day};
}


int main() {
    try {
        Database db;

        string command_line;
        while (getline(cin, command_line)) {
            stringstream ss(command_line);

            string command;
            ss >> command;

            if (command == "Add") {

                string date_str, event;
                ss >> date_str >> event;
                const Date date = ParseDate(date_str);
                db.AddEvent(date, event);

            } else if (command == "Del") {

                string date_str;
                ss >> date_str;
                string event;
                if (!ss.eof()) {
                    ss >> event;
                }
                const Date date = ParseDate(date_str);
                if (event.empty()) {
                    const int count = db.DeleteDate(date);
                    cout << "Deleted " << count << " events" << endl;
                } else {
                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                }

            } else if (command == "Find") {

                string date_str;
                ss >> date_str;
                const Date date = ParseDate(date_str);
                for (const string& event : db.Find(date)) {
                    cout << event << endl;
                }

            } else if (command == "Print") {

                db.Print();

            } else if (!command.empty()) {

                throw logic_error("Unknown command: " + command);

            }
        }
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
