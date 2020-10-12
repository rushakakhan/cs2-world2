#include <iostream>
using std::cin;
using std::cout;

int countUppercase(char array[], int numItems)
{
  int rangeStart = 0 + 'A'; // int equivalent of A
  int rangeEnd = rangeStart + 25; // int equivalent of Z
  int count = 0;
  for (int i = 0; i < numItems; i++) {
    int current = array[i]; // getting the int equivalent of the current char
    if (current >= rangeStart && current <= rangeEnd) {
      count++;
    }
  }
  return count;
}

int main() 
{
  const int TEST_ARRAY_1_SIZE = 10;
  char testArray1[TEST_ARRAY_1_SIZE] = {'A', 'H', 'e', 'y', 'W', 'o', 'r' , 'l', 'd', 'Z'};
  int upCount = countUppercase(testArray1, TEST_ARRAY_1_SIZE);
  cout << "testArray1 has " << upCount << " uppercase\n";
}