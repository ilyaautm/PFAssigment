#include <iostream>
#include <iomanip>
using namespace std;

// PROTOTYPE FUNGSI 
//1. hafiz part(1)
void getUserInput(double &basicSalary, double &overtimeHours, double &overtimeRate, double &allowances);
//2. mawan part(1)
double calculateEarnings(double basicSalary, double overtimeHours, double overtimeRate, double allowances);
//3. cindy part(1)
double calculateDeductions(double basicSalary, double grossSalary);
//4. ilyaa part(1)
void displayOutput(double grossSalary, double totalDeductions, double netSalary);


// MAIN FUNCTION
int main() {
    double basic, otHours, otRate, allow;
    char choice;

    do {
        cout << "---------------------------------------" << endl;
        cout << "       Payroll Management System       " << endl;
        cout << "---------------------------------------" << endl;

        // masuk funtion hafiz masuk funtion input user(2)
        getUserInput(basic, otHours, otRate, allow);
        // masuk funtion mawan kira pendapatan user(2)
        double grossSalary = calculateEarnings(basic, otHours, otRate, allow);
        // masuk funtion cindy kira deduction user(2)
        double totalDeductions = calculateDeductions(basic,grossSalary);

        // Semakan jika jumlah potongan melebihi gaji kasar
        if (totalDeductions > grossSalary) {
            cout << "---------------------------------------" << endl;
            cout << "Error: \nTotal deductions (" << totalDeductions 
                 << ") exceed total gross salary (" << grossSalary 
                 << ").\nNet salary cannot be negative." << endl;
            cout << "---------------------------------------" << endl;
        } else {
            double netSalary = grossSalary - totalDeductions;

            // masuk funtion ilyaa display output user(2)
            displayOutput(grossSalary, totalDeductions, netSalary);
        }

        // semakan pengulangan program (re-calculate validation)
        do {
            cout << "Do you want to calculate again? (Y/N): ";
            cin >> choice;

            if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
                cout << "---------------------------------------" << endl;
                cout << "Invalid input! Please enter 'Y/y' or 'N/n' only." << endl;
                cout << "---------------------------------------" << endl;
            }
        } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    cout << "---------------------------------------" << endl;
    cout << "              Thank You                " << endl;
    cout << "---------------------------------------" << endl;

    return 0;
}


// hafiz punya funtion(3)
void getUserInput(double &basicSalary, double &overtimeHours, double &overtimeRate, double &allowances) {
    cout << "Enter Basic Salary: ";
    cin >> basicSalary;
    cout << "Enter Overtime Hours: ";
    cin >> overtimeHours;
    cout << "Enter Overtime Rate: ";
    cin >> overtimeRate;
    cout << "Enter Allowances: ";
    cin >> allowances;

    // ulang minta input jika user memasukkan nilai negatif
    while (basicSalary < 0 || overtimeHours < 0 || overtimeRate < 0 || allowances < 0) {
        cout << "----------------------------------" << endl;
        cout << "Error: \nInput values cannot be negative." << endl;
        cout << "----------------------------------" << endl;
        cout << "Please re-enter valid inputs:\n";

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        cout << "Enter Overtime Hours: ";
        cin >> overtimeHours;
        cout << "Enter Overtime Rate: ";
        cin >> overtimeRate;
        cout << "Enter Allowances: ";
        cin >> allowances;
    }
}
// mawan punya funtion(3)
double calculateEarnings(double basicSalary, double overtimeHours, double overtimeRate, double allowances){
   double overtimePay = overtimeHours * overtimeRate;
   double grossSalary = basicSalary + overtimePay + allowances;
        
   return grossSalary;
}
// cindy punya funtion(3)
double calculateDeductions(double basicSalary, double grossSalary){
  double epf = basicSalary * 0.11;
  double sosco = 25.00;
  double incomeTax = grossSalary * 0.05;
  double totalDeductions = epf + sosco + incomeTax;
  return totalDeductions;
}

//ilyaa punya funtion(3)
void displayOutput(double grossSalary, double totalDeductions, double netSalary) {
    cout << fixed << setprecision(2);
    cout << "Gross Salary     : RM " << grossSalary << endl;
    cout << "Total Deductions : RM " << totalDeductions << endl;
    cout << "Net Salary       : RM " << netSalary << endl;
    cout << "---------------------------------------" << endl;
}
