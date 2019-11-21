#include<iostream>
#include<fstream>
#include<ctime>
#define MAX_NUMS 20
using namespace std;

class HashTable {
public:
    int *arr, size, count = 0;
    HashTable(int size) : size(size), arr(new int[size]) {
    }

    int gethash(int value) {
      return value % 20;
    }

    void add(int val) {
      int hash = gethash(val);
      if (count > size) { cout << "\nfull"; return; }
      cout << hash << "<--\n";
      if (arr[hash] == 0) arr[hash] = val;
      else {
        int index = hash + 1;
        while (index != hash) {
          if (arr[index] == 0) {
            arr[index] = val;
            break;
          }
          index++;
          index %= size;
        }

        cout << "COLLISION\n";
      }
      count++;
    }

    bool search(int value) {
      int hash = gethash(value);
      if (arr[hash] == value) return true;
      int index = hash + 1;
      while(index != hash) {
        if (arr[index] == value) return true;
        index++;
      }
      return false;
    }

    bool remove(int val) {
      int hash = gethash(val);

      if (arr[hash] == val) {
        arr[hash] = 0;
        return true;
      }

      int index = hash + 1;
      while(index != hash) {
        if (arr[index] == val) {
          arr[index] = 0;
          return true;
        }
        index++;
        index %= size;
      }
      return false;
    }

    void print() {
      for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
      }
    }

};

int main() {

  ifstream ifs("numbers.txt");
  int numbers[MAX_NUMS] = { 0 };

  for (int i = 0; i < MAX_NUMS; i++) {
    ifs >> numbers[i];
  }

  HashTable table(MAX_NUMS);

  clock
  for (int i = 0; i < MAX_NUMS; i++) {
    table.add(numbers[i]);
  }

  table.print();

  return 0;
}
