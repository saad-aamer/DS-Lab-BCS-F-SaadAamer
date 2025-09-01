#include <iostream>
using namespace std;

class city {
    string city_name;
    int days;
    int times;
    double** temp;
public:
    city() : city_name(""), days(0), times(0), temp(nullptr) {}

    city(string name, int d, int t, double** readings) 
        : city_name(name), days(d), times(t) {
        temp = new double*[days];
        for (int i = 0; i < days; i++) {
            temp[i] = new double[times];
            for (int j = 0; j < times; j++) {
                temp[i][j] = readings[i][j];
            }
        }
    }

    city(const city& other) {
        city_name = other.city_name;
        days = other.days;
        times = other.times;
        if (days > 0 && times > 0) {
            temp = new double*[days];
            for (int i = 0; i < days; i++) {
                temp[i] = new double[times];
                for (int j = 0; j < times; j++) {
                    temp[i][j] = other.temp[i][j];
                }
            }
        } else {
            temp = nullptr;
        }
    }

    city& operator=(const city& other) {
        if (this == &other) return *this;
        for (int i = 0; i < days; i++) {
            delete[] temp[i];
        }
        delete[] temp;
        city_name = other.city_name;
        days = other.days;
        times = other.times;
        if (days > 0 && times > 0) {
            temp = new double*[days];
            for (int i = 0; i < days; i++) {
                temp[i] = new double[times];
                for (int j = 0; j < times; j++) {
                    temp[i][j] = other.temp[i][j];
                }
            }
        } else {
            temp = nullptr;
        }
        return *this;
    }

    void display() {
        cout << "City: " << city_name << endl;
        cout << "Temperature readings:" << endl;
        for (int i = 0; i < days; i++) {
            cout << "Day " << i + 1 << ": ";
            for (int j = 0; j < times; j++) {
                cout << temp[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dailyAverage() {
        cout << endl << "Daily Average Temperatures for " << city_name << ":" << endl;
        for (int i = 0; i < days; i++) {
            double sum = 0;
            for (int j = 0; j < times; j++) {
                sum += temp[i][j];
            }
            cout << "Day " << i + 1 << " Average: " << sum / times << endl;
        }
    }

    void hottestAndColdest() {
        int hottestDay = 0, coldestDay = 0;
        double hottestAvg = -1e9, coldestAvg = 1e9;
        for (int i = 0; i < days; i++) {
            double sum = 0;
            for (int j = 0; j < times; j++) {
                sum += temp[i][j];
            }
            double avg = sum / times;
            if (avg > hottestAvg) {
                hottestAvg = avg;
                hottestDay = i;
            }
            if (avg < coldestAvg) {
                coldestAvg = avg;
                coldestDay = i;
            }
        }
        cout << endl << "Hottest Day in " << city_name << ": Day " << hottestDay + 1 << " (Avg Temp = " << hottestAvg << ")" << endl;
        cout << "Coldest Day in " << city_name << ": Day " << coldestDay + 1 << " (Avg Temp = " << coldestAvg << ")" << endl;
    }

    ~city() {
        if (temp) {
            for (int i = 0; i < days; i++) {
                delete[] temp[i];
            }
            delete[] temp;
        }
    }
};

int main() {
    int days = 3, times = 3;

    double** readings = new double*[days];
    for (int i = 0; i < days; i++) {
        readings[i] = new double[times];
    }

    readings[0][0] = 30.5; readings[0][1] = 32.0; readings[0][2] = 31.5;
    readings[1][0] = 28.0; readings[1][1] = 27.5; readings[1][2] = 29.0;
    readings[2][0] = 35.0; readings[2][1] = 36.5; readings[2][2] = 34.5;

    city c1("Karachi", days, times, readings);

    c1.display();
    c1.dailyAverage();
    c1.hottestAndColdest();

    for (int i = 0; i < days; i++) {
        delete[] readings[i];
    }
    delete[] readings;

    return 0;
}
