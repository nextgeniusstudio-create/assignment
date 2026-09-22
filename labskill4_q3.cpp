#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Converts a mark into a grade string and grade point 
void calculateGrade(int mark, string &grade, double &point) {
    if (mark >= 90 && mark <= 100)      { grade = "A+"; point = 4.00; }
    else if (mark >= 80 && mark <= 89)  { grade = "A";  point = 4.00; }
    else if (mark >= 75 && mark <= 79)  { grade = "A-"; point = 3.67; }
    else if (mark >= 70 && mark <= 74)  { grade = "B+"; point = 3.33; }
    else if (mark >= 65 && mark <= 69)  { grade = "B";  point = 3.00; }
    else if (mark >= 60 && mark <= 64)  { grade = "B-"; point = 2.67; }
    else if (mark >= 55 && mark <= 59)  { grade = "C+"; point = 2.33; }
    else if (mark >= 50 && mark <= 54)  { grade = "C";  point = 2.00; }
    else if (mark >= 45 && mark <= 49)  { grade = "C-"; point = 1.67; }
    else if (mark >= 40 && mark <= 44)  { grade = "D+"; point = 1.33; }
    else if (mark >= 35 && mark <= 39)  { grade = "D";  point = 1.00; }
    else if (mark >= 30 && mark <= 34)  { grade = "D-"; point = 0.67; }
    else                                { grade = "E";  point = 0.00; }
}

// Prints the grade & point result for one course
void printCourseResult(int courseNum, const string &grade, double point) {
    cout << "Course " << courseNum << " grade is " << grade << endl;
    cout << "Course " << courseNum << " point is " << point << endl;
}

// Prints the final summary
void printSummary(double totalCredit, double totalPoint, double cpa) {
    cout << "\n-------------------------Result-------------------------" << endl;
    cout << "Your total credit for this current semester: " << totalCredit << endl;
    cout << "Your total course point for this current semester: " << totalPoint << endl;
    cout << "Your CPA for this current semester: " << cpa << endl;
    cout << "--------------------------------------------------------" << endl;
}

int main() {
    int mark, credit;
    int numcourse = 1;
    double point;
    double totalc = 0;
    double totalp = 0;
    double cpa = 0;
    string grade;
    char choice = 'Y';

    cout << fixed << setprecision(2);

    while (choice == 'Y' || choice == 'y') {
        cout << "Enter course " << numcourse << " mark: ";
        cin  >> mark;
        cout << "Enter course " << numcourse << " credit: ";
        cin  >> credit;

        calculateGrade(mark, grade, point);

        point = credit * point;
        totalc += credit;
        totalp += point;

        printCourseResult(numcourse, grade, point);

        cout << "Add more course?(Y-yes/N-no): ";
        cin  >> choice;
        numcourse++;
    }

    cpa = totalp / totalc;
    printSummary(totalc, totalp, cpa);

    return 0;
}