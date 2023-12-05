#include <iostream>
#include <string>

using namespace std;

int gcd(int m, int n) {
  if (m % n == 0) {
    return n;
  } else {
    return gcd(n, m % n);
  }
}

void evenAndOddCount(int value) {
  static int evenCount = 0;
  static int oddCount = 0;
  if (value == 0) {
    cout << "Number of even digits: " << evenCount << endl;
    cout << "Number of odd digits: " << oddCount << endl;
    return;
  }

  int lastDigit = value % 10;
  if (lastDigit % 2 == 0) {
    evenCount++;
  } else {
    oddCount++;
  }
  evenAndOddCount(value / 10);
}

void reverseDisplay(const string &s) {
  if (s.length() == 0) {
    return;
  } else {
    reverseDisplay(s.substr(1));
    cout << s[0];
  }
}

int count(const string &s, char a) {
  if (s.empty()) {
    return 0;
  }
  if (s.back() == a) {
    return 1 + count(s.substr(0, s.length() - 1), a);
  } else {
    return count(s.substr(0, s.length() - 1), a);
  }
}

int productDigits(int n) {
  if (n < 10) {
    return n;
  } else {
    return n % 10 * productDigits(n / 10);
  }
}

void reverseDisplay(const string &s, int high) {
  if (high < 0) {
    return;
  } else {
    cout << s[high];
    reverseDisplay(s, high - 1);
  }
}

int findSmallest(int arr[], int size) {
  if (size == 1) {
    return arr[0];
  } else {
    return min(arr[size - 1], findSmallest(arr, size - 1));
  }
}

int sumArray(int arr[], int size) {
  if (size <= 0) {
    return 0;
  }
  return sumArray(arr, size - 1) + arr[size - 1];
}

int main() {
  int choice;
  int num, num2, result;
  string str;
  int arr[5];
  int size;
  string inputString;
  char targetChar;

  do {
    cout << "1. GCD" << endl;
    cout << "2. Even and Odd Count" << endl;
    cout << "3. Reverse Display" << endl;
    cout << "4. Count Occurences of a Character" << endl;
    cout << "5. Product of Digits" << endl;
    cout << "6. String Reverse Display" << endl;
    cout << "7. Find the Smallest Element in Array" << endl;
    cout << "8. Sum of Elements in Array" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter two integers: ";
      cin >> num >> num2;
      result = gcd(num, num2);
      cout << "The GCD of " << num << " and " << num2 << " is " << result
           << endl;
      break;
    case 2:
      cout << "Enter an integer: ";
      cin >> num;
      evenAndOddCount(num);
      break;
    case 3:
      cout << "Enter a string: ";
      cin >> str;
      reverseDisplay(str);
      cout << endl;
      break;
    case 4:
      cout << "Enter a string: ";
      cin.ignore();
      getline(cin, inputString);
      cout << "Enter a character: ";
      cin >> targetChar;
      cout << "Occurrences: " << targetChar << ": "
           << count(inputString, targetChar) << endl;
      break;
    case 5:
      cout << "Enter an integer: ";
      cin >> num;
      result = productDigits(num);
      cout << "Product: " << result << endl;
      break;
    case 6:
      cout << "Enter a string: ";
      cin >> str;
      reverseDisplay(str, str.length() - 1);
      cout << endl;
      break;
    case 7:
      cout << "Enter 5 integers: ";
      for (int i = 0; i < 5; i++) {
        cin >> arr[i];
      }
      result = findSmallest(arr, 5);
      cout << "Smallest: " << result << endl;
      break;
    case 8:
      cout << "Enter size of array: ";
      cin >> size;
      cout << "Enter " << size << " integers: ";
      for (int i = 0; i < size; i++) {
        cin >> arr[i];
      }
      result = sumArray(arr, size);
      cout << "Sum: " << result << endl;
      break;
    case 9:
      return 0;
    default:
      break;
    }
  } while (choice != 9);
  return 0;
}
