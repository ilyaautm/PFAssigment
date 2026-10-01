#include <iostream>
#include <iomanip>
using namespace std;

// PROTOTYPE FUNGSI 
//1. hafiz part(1)

//2. mawan part(1)

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

        // Semakan pengulangan program (Re-calculate validation)
        do {
            cout << "Do you want to calculate again? (Y/N): ";
            cin >> choice;

            if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
                cout << "---------------------------------------" << endl;
                cout << "Invalid input! Please enter 'Y' or 'N' only." << endl;
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



// mawan punya funtion(3)



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
