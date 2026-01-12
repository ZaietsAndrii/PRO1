#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int idn;
    string name;
    double mark;        // The mark is a value between 0 and 10, or -1 that represents NP
    bool repeater;
};

void information(const vector<Student>& stu, double& min, double& max, double& avg){
    int lenght = stu.size();
    int stuPassedExam = 0;
    double mark = 0.0;
    bool found = false;
    for (int i = 0; i < lenght; i++)
    {
        double stuMark = stu[i].mark;
        if (stuMark != -1.0 && stu[i].repeater == false)
        {
            if (!found) {
                min = max = stuMark;
                found = true;
            } else {
                if (stuMark > max) max = stuMark;
                if (stuMark < min) min = stuMark;
            }
            mark += stuMark;
            stuPassedExam += 1;
        }    
    }
    if (stuPassedExam == 0)
    {
        min = -1.0;
        max = -1.0;
        avg = -1.0;
    }
    else{
        avg = mark / stuPassedExam;
    }
}
