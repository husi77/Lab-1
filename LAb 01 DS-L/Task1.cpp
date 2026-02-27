#include <iostream>
using namespace std;


class Course {
public:
    virtual int duration()  = 0;
    virtual ~Course() {};
};


class OnlineCourse : public Course {
private:
    int weeks;
    int hoursPerWeek;
public:
    OnlineCourse(int w, int h) {
        weeks = w;
        hoursPerWeek = h;
    }

    int duration()   {
        return weeks * hoursPerWeek;
    }
};

class OfflineCourse : public Course {
private:
    int months;
    int hoursPerDay;
public:
    OfflineCourse(int m, int h) {
        months = m;
        hoursPerDay = h;
    }

    int duration()   {
     
        return months * 30 * hoursPerDay;
    }
};

int main() {
    OnlineCourse oec(9, 5);   
    OfflineCourse offc(5, 9); 

    cout << "Online Course Duration: " << oec.duration() << " hours" << endl;
    cout << "Offline Course Duration: " << offc.duration() << " hours" << endl;

    return 0;
}