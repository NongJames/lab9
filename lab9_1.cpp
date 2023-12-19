#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double initialLoan, interestRate, paymentPerYear;

    cout << "Enter initial loan: ";
    cin >> initialLoan;

    cout << "Enter interest rate per year (%): ";
    cin >> interestRate;

    cout << "Enter amount you can pay per year: ";
    cin >> paymentPerYear;

    cout << left << setw(13) << "EndOfYear#"
         << setw(13) << "PrevBalance"
         << setw(13) << "Interest"
         << setw(13) << "Total"
         << setw(13) << "Payment"
         << setw(13) << "NewBalance" << endl;

    double prevBalance = initialLoan;
    int year = 1;

    while (prevBalance > 0) {
        double interest = (prevBalance * interestRate) / 100;
        double total = prevBalance + interest;
        double payment = (total <= paymentPerYear) ? total : paymentPerYear;

        cout << left << setw(13) << year
             << fixed << setprecision(2)
             << setw(13) << prevBalance
             << setw(13) << interest
             << setw(13) << total
             << setw(13) << payment;

        prevBalance = total - payment;
        cout << setw(13) << prevBalance << endl;

        year++;
    }

    return 0;
}
