#include <iostream>
#include <string>
#include <math.h>

/* Kurosh Kuchekali
10 September 2022 */

using namespace std;

int main()
{
    //all neccessary variables initalized
    double cost;
    double miles;
    double gasPrice;
    double resale;
    double mpg;
    double gallons;
    double totalGas;

    cout << "Enter the car's price:\n";
    cin >> cost;

    cout << "Enter the car's MPG:\n";
    cin >> mpg;

    cout << "Enter the estimated miles driven per year:\n";
    cin >> miles;

    cout << "Please enter current gas price:\n";
    cin >> gasPrice;

    cout << "Please enter estimated resale price of the car after 5 years:\n";
    cin >> resale;

    //First, computes the total number of miles driven over 5 years
    miles = miles * 5;

    //Calculates the total gallons of gas to be used on the total cost of gas
    //over 5 years
    gallons = miles/mpg;
    totalGas = gallons * gasPrice;

    //Calculates the total cost of the car over 5 years
    cost = (cost - resale) + totalGas;

    printf("Over a period of 5 years, your car will cost a total of $%.2lf", cost);

    return 0;
}