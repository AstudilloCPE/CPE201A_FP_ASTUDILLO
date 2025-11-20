#include <iostream>
#include <string>
using namespace std;
int main() {
 string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
 int dayNumber;
 while (true) {
 cout << "Enter a Number to determine the Day (0 - 6): ";
 cin >> dayNumber;
 if (dayNumber >= 0 || dayNumber < 7) {
 cout << "Day: " << days[dayNumber] << endl;
 } else {
 cout << "Invalid input." << endl;
 break;
 }
 }
 return 0;
}

