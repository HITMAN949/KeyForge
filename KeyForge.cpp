#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

string generateStrongPassword(int length) {
  const string lowercase = "abcdefghijklmnopqrstuvwxyz";
  const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const string digits = "0123456789";
  const string symbols = "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";

  string charPool = lowercase + uppercase + digits + symbols;

  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> charDist(0, charPool.size() - 1);

  string password;
  for (int i = 0; i < length; ++i) {
    password += charPool[charDist(generator)];
  }

  return password;
}

int main() {
  int passwordLength;

  cout << "Enter the desired password length (minimum 8 characters recommended): ";
  cin >> passwordLength;

  if (passwordLength < 1) {
    cerr << "Error: Password length must be at least 1 character." << endl;
    return 1;
  }

  string strongPassword = generateStrongPassword(passwordLength);

  cout << "Generated strong password: " << strongPassword << endl;

  return 0;
}

