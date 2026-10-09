#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void displayError(string message);
string inputStudentId();
string inputStudentName();
int inputNumberOfSubjects();
int inputCreditHours(int subjectNumber);
double inputFeePerCreditHour();
int inputMaxCreditHours();
double calculateTotalFee(int totalCreditHours, double feePerCreditHour);
void displayRegistrationResult(string studentId, string studentName,int numSubject, int totalCreditHours,double totalFee, bool successful);


int main() {
    string studentId = inputStudentId();

    string studentName = inputStudentName();

    int numSubject = inputNumberOfSubjects();

    int totalCreditHours = 0;

    for (int i = 1; i <= numSubject; i++) {
        int creditHours = inputCreditHours(i);

        if (creditHours < 0) {
            return 0;
        }

        totalCreditHours += creditHours;
    }

    double feePerCreditHour = inputFeePerCreditHour();

    if (feePerCreditHour < 0) {
        return 0;
    }

    int maxCreditHours = inputMaxCreditHours();

    if (maxCreditHours < 0) {
        return 0;
    }

    bool successful = totalCreditHours <= maxCreditHours;

    double totalFee = 0;

    if (successful) {
        totalFee = calculateTotalFee(
            totalCreditHours,
            feePerCreditHour
        );
    }

    displayRegistrationResult(
        studentId,
        studentName,
        numSubject,
        totalCreditHours,
        totalFee,
        successful
    );

    return 0;
}


void displayError(string message) {
    cout << "\n=========================================" << endl;
    cout << "Error: " << message << endl;
    cout << "=========================================" << endl;
}


string inputStudentId() {
    string studentId;

    cout << "Enter your Student ID: ";
    getline(cin, studentId);

    if (studentId.find_first_not_of(" \t") == string::npos) {
        displayError("Student ID cannot be empty.");
        return "";
    }

    return studentId;
}


string inputStudentName() {
    string studentName;

    cout << "Enter your Student Name: ";
    getline(cin, studentName);

    if (studentName.find_first_not_of(" \t") == string::npos) {
        displayError("Student Name cannot be empty.");
        return "";
    }

    return studentName;
}


int inputNumberOfSubjects() {
    int numSubject;

    cout << "Enter your Number of Subjects: ";
    cin >> numSubject;

    if (cin.fail() || numSubject <= 0) {
        displayError("Number of subjects must be a positive number.");
        return -1;
    }

    return numSubject;
}


int inputCreditHours(int subjectNumber) {
    int creditHours;

    cout << "Enter Credit Hours for Subject "
         << subjectNumber << ": ";
    cin >> creditHours;

    if (cin.fail() || creditHours <= 0) {
        displayError(
            "Credit hours for each subject must be a positive number."
        );
        return -1;
    }

    return creditHours;
}



double inputFeePerCreditHour() {
    double feePerCreditHour;

    cout << "Enter Fee per Credit Hour: RM ";
    cin >> feePerCreditHour;

    if (cin.fail() || feePerCreditHour <= 0) {
        displayError(
            "Fee per credit hour must be a positive number."
        );
        return -1;
    }

    return feePerCreditHour;
}


int inputMaxCreditHours() {
    int maxCreditHours;

    cout << "Enter Maximum Permitted Credit Hours: ";
    cin >> maxCreditHours;

    if (cin.fail() || maxCreditHours <= 0) {
        displayError(
            "Maximum permitted credit hours must be a positive number."
        );
        return -1;
    }

    return maxCreditHours;
}


double calculateTotalFee(int totalCreditHours, double feePerCreditHour) {
    return totalCreditHours * feePerCreditHour;
}


void displayRegistrationResult(
    string studentId,
    string studentName,
    int numSubject,
    int totalCreditHours,
    double totalFee,
    bool successful
) {
    cout << fixed << setprecision(2);

    cout << "\n\n=================================" << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Student ID: " << studentId << endl;
    cout << "Number of Subjects: " << numSubject << endl;
    cout << "Total Credit Hours: " << totalCreditHours << endl;

    if (successful) {
        cout << "Total Tuition Fee: RM " << totalFee << endl;
        cout << "Registration Status: Successful" << endl;
    }
    else {
        cout << "Registration Status: Unsuccessful" << endl;
    }

    cout << "=================================" << endl;
}
