#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashFunction {
private:
  uint32_t compressKey(const string &key) {
    uint32_t hashcode = 5381;
    for (char ch : key) {
      char normalizedChar = tolower(ch);
      hashcode = ((hashcode << 5) + hashcode) + normalizedChar;
    }
    return hashcode;
  }

public:
  int hash(const string &key, int tableSize) {
    uint32_t hashcode = compressKey(key);
    return hashcode % tableSize;
  }

  void testHashFunction() {
    string keys[] = {"9242064424678123", "9NJGDHQQV8E", "ALTEBUERIO"};
    int tableSize = 15;

    cout << "Key\t\t\tHashed Index\n";
    cout << "---------------------------------\n";

    for (const string &key : keys) {
      cout << key << "\t\t" << hash(key, tableSize) << '\n';
    }
  }

  int resolveCollision(int hashIndex, int tableSize, int attempt) {
    return (hashIndex + attempt) % tableSize;
  }

  void demonstrateCollision() {
    int tableSize = 15;
    string key1 = "collision1";
    string key2 = "COLLISION1";

    int hash1 = hash(key1, tableSize);
    int hash2 = hash(key2, tableSize);

    cout << "\nCollision Example:\n";
    cout << "Key: " << key1 << " -> Hash Index: " << hash1 << '\n';
    cout << "Key: " << key2 << " -> Hash Index: " << hash2 << '\n';

    if (hash1 == hash2) {
      cout << "Collision detected! Resolving...\n";
      for (int attempt = 1; attempt < tableSize; ++attempt) {
        int newHash = resolveCollision(hash1, tableSize, attempt);
        cout << "Attempt " << attempt << ": New Hash Index -> " << newHash << '\n';
        if (newHash != hash1) {
          cout << "Collision resolved at index: " << newHash << '\n';
          break;
        }
      }
    }
  }

  int main() {
    testHashFunction();
    demonstrateCollision();
    return 0;
  }
};