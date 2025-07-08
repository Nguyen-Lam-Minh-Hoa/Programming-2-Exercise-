#include <iostream>

using namespace std;

class Time {
private: 
    int hours;
    int minutes;
    int seconds;

    // function to convert the seconds/minutes
    void normalize_time() {

        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }

        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }

        //24-hours format
        hours %= 24;
    }
public:
    // default constructor for form 00:00:00
    Time():hours(0), minutes(0), seconds(0) {}

    //Parameterized constructor
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        // call normalize function if the input is not in the form
        normalize_time();
    }

    //overloaded +operator
    Time operator+(const Time& t) {
        Time result;
        result.hours = this->hours + t.hours;
        result.minutes = this->minutes + t.minutes;
        result.seconds = this->seconds + t.seconds;
        result.normalize_time(); //normalize the result
        return result; 
    }

        // overload >operator
    bool operator>(const Time& t) {
        if (hours > t.hours) { //compare hours
            return true;
        }
        if (hours == t.hours && minutes > t.minutes) { // if hours equal compare minutes
            return true;
        }
        if (hours == t.hours && minutes == t.minutes && seconds > t.seconds) { // if hours and minutes equal, compare seconds
            return true;
        }
        return false;
    }

    //overloded =operator
    Time& operator=(const Time& t) {
        //stop self assignment
        if (this != &t) {
            hours = t.hours;
            minutes = t.minutes;
            seconds = t.seconds;
        }
        return *this;
    }
    // function to display time in hh:mm:ss
    void display() const {
        printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    } 
};

//main function
int main() {
    Time t_1(10, 50, 30); //set t_1 to 10h,50m,30s
    Time t_2(2, 20, 40); //set t_2 to 2h, 20m. 40s

    Time t_3;
    t_3 = t_1 + t_2;

    cout << "t_1 = "; t_1.display();
    cout << "t_2 = "; t_2.display();
    cout << "t_3 = t_1 + t_2 = "; t_3.display();

    //compare t_1 and t_2
    if ( t_1 > t_2) {
        cout << "t_1 is greater than t_2\n";
    }
    else {
        cout << "t_2 is greater than t_1\n";
    }

    return 0;
}