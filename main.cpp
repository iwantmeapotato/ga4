#include<iostream>
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
  const int size = 20;
  int arr[size] = {27, 4, 84, 26, 9, 24, 45, 8, 20, 61, 5, 27, 3, 37, 42, 71, 92, 28, 74, 69};

  HashTable rizkismissing(size);
  for (int i = 0; i < size; i++) {
    rizkismissing.add(arr[i]);
  }
  rizkismissing.print();
  cout <<  rizkismissing.search(19);

  return 0;
}
