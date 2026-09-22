#include <iostream>
#include <string>
using namespace std;

//function variables
int processRegistration();
void displayError(string message);
string inputStudentId(string studentId);
string inputStudentName(string studentName);
int inputNumberOfSubjects(int numSubject);
int inputCreditHours(int subjectNumber);
double inputFeePerCreditHour(double feePerCreditHour);
int inputMaxCreditHours(int maxCreditHours);
double calculateTotalFee(int totalCreditHours, double feePerCreditHour);

// Main Body
int main() {
    return processRegistration();
}

// Function Category: Input Functions

void displayError(string message) {
    cout << "=========================================" << endl;
    cout << "Error: " << message << endl;
    cout << "=========================================" << endl;
} //Error message display function

string inputStudentId(string studentId) {
    cout << "Enter your Student ID: ";
    getline(cin, studentId);
    if (studentId.empty()) {
        displayError("Student ID cannot be empty.");
        return "";
    }
    return studentId;
} //Student ID input function

string inputStudentName(string studentName) {
    cout << "Enter your Student Name: ";
    getline(cin, studentName);
    if (studentName.empty()) {
        displayError("Student Name cannot be empty.");
        return "";
    }
    return studentName;
} //Student Name input function

int inputNumberOfSubjects(int numSubject) {
    cout << "Enter your Number of Subjects: ";
    cin >> numSubject;
    if (cin.fail() || numSubject <= 0) {
        displayError("Number of subjects must be a positive number.");
        return -1;
    }
    return numSubject;
} //Number of subjects input function

int inputCreditHours(int subjectNumber) {
    int creditHours;
    cout << "Enter Credit Hours for Subject " << subjectNumber << ": ";
    cin >> creditHours;
    if (cin.fail() || creditHours <= 0) {
        displayError("Credit hours for each subject must be a positive number.");
        return -1;
    }
    return creditHours;
} //Credit hours input function

double inputFeePerCreditHour(double feePerCreditHour) {
    cout << "Enter Fee per Credit Hour: RM ";
    cin >> feePerCreditHour;
    if (cin.fail() || feePerCreditHour <= 0) {
        displayError("Fee per credit hour must be a positive number.");
        return -1;
    }
    return feePerCreditHour;
} //Fee per credit hour input function

int inputMaxCreditHours(int maxCreditHours) {
    cout << "Enter Maximum Permitted Credit Hours: ";
    cin >> maxCreditHours;
    if (cin.fail() || maxCreditHours <= 0) {
        displayError("Maximum permitted credit hours must be a positive number.");
        return -1;
    }
    return maxCreditHours;
} //Maximum permitted credit hours input function

double calculateTotalFee(int totalCreditHours, double feePerCreditHour) {
    return totalCreditHours * feePerCreditHour;
} //Total fee calculation function

int processRegistration() {
    string studentId = inputStudentId("");
    if (studentId.empty()) {
        return 0;
    }

    string studentName = inputStudentName("");
    if (studentName.empty()) {
        return 0;
    }

    int numSubject = inputNumberOfSubjects(0);
    if (numSubject < 0) {
        return 0;
    }

    double feePerCreditHour;
    int maxCreditHours;
    int totalCreditHours = 0;
    double totalFee;

    int creditHours[10];
    for (int i = 0; i < numSubject; ++i) {
        creditHours[i] = inputCreditHours(i + 1);
        if (creditHours[i] < 0) {
            return 0;
        }
        totalCreditHours += creditHours[i];
    }

    feePerCreditHour = inputFeePerCreditHour(0);
    if (feePerCreditHour < 0) {
        return 0;
    }

    maxCreditHours = inputMaxCreditHours(0);
    if (maxCreditHours < 0) {
        return 0;
    }

    if (totalCreditHours <= maxCreditHours) {
        totalFee = calculateTotalFee(totalCreditHours, feePerCreditHour);

        cout << "\n\n\n\n=================================" << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Student ID: " << studentId << endl;
        cout << "Number of Subjects: " << numSubject << endl;
        cout << "Total Credit Hours: " << totalCreditHours << endl;
        cout << "Total tuition fee: RM " << totalFee << endl;
        cout << "Registration Status: Successful" << endl;
        cout << "=================================" << endl;
    } else {
        cout << "=========================================" << endl;
        cout << "Your Registration Status is Unsuccessful." << endl;
        cout << "=========================================" << endl;
    }

    return 0;
} //Registration process function