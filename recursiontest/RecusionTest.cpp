
#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string str, int start, int end) {
  // TODO: Implement the base case
  // TODO: Implement the recursive case
  if (start >= end) {
    return true;
  }
  // If characters at start and end do not match
  if (str[start] != str[end]) {
    return false;
  }
  // Recursive call
  return isPalindromea(str, start + 1, end - 1);
}

string makeNormal(const string& str) {
  string normalized;
  for (char ch : str) {
    if (isalnum(ch)) {
      normalized += tolower(ch);
    }
  }
  return normalized;
}
int main() {
  string input;

  // Input from the user
  cout << "Enter a string: ";
  getline(cin, input);

  // Write a function to ignore all the nonalphabetic characters in the string.
  string normal = makeNormal(input);
  // Call the recursive function and display the result
  if (isPalindrome(normal, 0, normal.length() - 1)) {
    cout << "The string is a palindrome." << endl;
  } else {
    cout << "The string is not a palindrome." << endl;
  }

  return 0;
}

// Recursive function to check if a string is a palindrome
