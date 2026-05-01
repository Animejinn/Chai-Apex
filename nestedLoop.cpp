#include <iostream>
using namespace std;

int main() {
  char alpha;
  int num;
  int choice;
  int n;
  cout << "Enter number of rows!" << endl;
  cin >> n;

  cout << "Do you want a number or character to be shown?" << endl;
  cout << "1.Number" << endl;
  cout << "2.Character" << endl;
  cin >> choice;

  switch (choice) {
  case 1:
    cout << "Enter the number you want to start with!" << endl;
    cin >> num;
    break;
  case 2:
    cout << "Enter the character you want to start with!" << endl;
    cin >> alpha;
    break;
  default:
    cout << "Invalid choice!" << endl;
  }

  for (int i = 0; i < n; i++) {
    if (choice == 1) {
      int num;

    } else if (choice == 2) {
      char alpha;
    }
    for (int j = 0; j < n; j++) {
      if (choice == 1) {
        cout << num << " ";
        num++;
      } else if (choice == 2) {
        cout << alpha << " ";
        alpha+=1;
      }
    }
    cout << endl;
  }
}