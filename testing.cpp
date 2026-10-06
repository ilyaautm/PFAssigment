#include <iostream>
#include <iomanip>
using namespace std;

// -------------------------------------------------------------
// PROTOTYPE FUNGSI
// -------------------------------------------------------------
void getUserInput(double &basicSalary, double &overtimeHours, double &overtimeRate, double &allowances);

// Fungsi pengiraan dipecahkan satu demi satu
double calculateOvertimePay(double overtimeHours, double overtimeRate);
double calculateGrossSalary(double basicSalary, double overtimePay, double allowances);
double calculateEPF(double basicSalary);
double calculateSOCSO();
double calculateIncomeTax(double grossSalary);
double calculateTotalDeductions(double epf, double socso, double incomeTax);
double calculateNetSalary(double grossSalary, double totalDeductions);

void displayOutput(double grossSalary, double totalDeductions, double netSalary);

// -------------------------------------------------------------
// MAIN FUNCTION
// -------------------------------------------------------------
int main() {
    double basic, otHours, otRate, allow;
    char choice;

    do {
        cout << "---------------------------------------" << endl;
        cout << "       Payroll Management System       " << endl;
        cout << "----------------------------------------" << endl;

        // 1. INPUT: Dapatkan input daripada user
        getUserInput(basic, otHours, otRate, allow);

        // 2. CALCULATION: Jalankan pengiraan satu demi satu
        double otPay = calculateOvertimePay(otHours, otRate);
        double grossSalary = calculateGrossSalary(basic, otPay, allow);
        
        double epf = calculateEPF(basic);
        double socso = calculateSOCSO();
        double incomeTax = calculateIncomeTax(grossSalary);
        
        double totalDeductions = calculateTotalDeductions(epf, socso, incomeTax);

        // Semakan jika deduction lebih besar dari gross salary
        if (totalDeductions > grossSalary) {
            cout << "---------------------------------------" << endl;
            cout << "Error: \nTotal deductions (" << totalDeductions 
                 << ") exceed total gross salary (" << grossSalary 
                 << ").\nNet salary cannot be negative." << endl;
            cout << "---------------------------------------" << endl;
        } else {
            double netSalary = calculateNetSalary(grossSalary, totalDeductions);
            
            // 3. OUTPUT: Paparkan hasil keputusan
            displayOutput(grossSalary, totalDeductions, netSalary);
        }

        // Tanya user nak re-calculate atau tak
        cout << "Do you want to calculate again? (Y/N): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    cout << "---------------------------------------" << endl;
    cout << "              Thank You                " << endl;
    cout << "---------------------------------------" << endl;

    return 0;
}

// -------------------------------------------------------------
// 1. FUNGSI INPUT
// -------------------------------------------------------------
void getUserInput(double &basicSalary, double &overtimeHours, double &overtimeRate, double &allowances) {
    cout << "Enter Basic Salary: ";
    cin >> basicSalary;
    cout << "Enter Overtime Hours: ";
    cin >> overtimeHours;
    cout << "Enter Overtime Rate: ";
    cin >> overtimeRate;
    cout << "Enter Allowances: ";
    cin >> allowances;

    // Jika ada input negatif, minta user masuk semula sampai betul
    while (basicSalary < 0 || overtimeHours < 0 || overtimeRate < 0 || allowances < 0) {
        cout << "---------------------------------------" << endl;
        cout << "Error: \nInput values cannot be negative." << endl;
        cout << "---------------------------------------" << endl;
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

// -------------------------------------------------------------
// 2. FUNGSI-FUNGSI PENGIRAAN (Satu Demi Satu)
// -------------------------------------------------------------

// Kira bayaran OT
double calculateOvertimePay(double overtimeHours, double overtimeRate) {
    return overtimeHours * overtimeRate;
}

// Kira Gaji Kasar (Gross Salary)
double calculateGrossSalary(double basicSalary, double overtimePay, double allowances) {
    return basicSalary + overtimePay + allowances;
}

// Kira EPF (11% daripada basic salary)
double calculateEPF(double basicSalary) {
    return basicSalary * 0.11;
}

// Kira SOCSO (Kadar tetap RM 25.00)
double calculateSOCSO() {
    return 25.00;
}

// Kira Cukai Pendapatan (5% daripada gross salary)
double calculateIncomeTax(double grossSalary) {
    return grossSalary * 0.05;
}

// Kira Jumlah Potongan (Total Deductions)
double calculateTotalDeductions(double epf, double socso, double incomeTax) {
    return epf + socso + incomeTax;
}

// Kira Gaji Bersih (Net Salary)
double calculateNetSalary(double grossSalary, double totalDeductions) {
    return grossSalary - totalDeductions;
}

// -------------------------------------------------------------
// 3. FUNGSI OUTPUT
// -------------------------------------------------------------
void displayOutput(double grossSalary, double totalDeductions, double netSalary) {
    cout << fixed << setprecision(2);
    cout << "Gross Salary     : RM " << grossSalary << endl;
    cout << "Total Deductions : RM " << totalDeductions << endl;
    cout << "Net Salary       : RM " << netSalary << endl;
    cout << "---------------------------------------" << endl;
}
