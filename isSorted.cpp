#include <iostream>
using std::cin;
using std::cout;

bool isSorted(int array[], int numItems)
{
  int current = array[0];
  for (int i = 1; i < numItems; i++) {
    if (array[i] > current || array[i] == current) {
      current = array[i];
    } else {
      return false;
    }
  }
  return true;
}

int main() 
{
  const int TEST_ARRAY_1_SIZE = 7;
  int testArray1[TEST_ARRAY_1_SIZE] = {4, 2, 4, 5, 6, 7, 8};
  cout << "isSorted returned " << isSorted(testArray1, TEST_ARRAY_1_SIZE) << " for TEST_1\n";

  const int TEST_ARRAY_2_SIZE = 7;
  int testArray2[TEST_ARRAY_2_SIZE] = {2, 3, 4, 5, 6, 7, 8};
  cout << "isSorted returned " << isSorted(testArray2, TEST_ARRAY_2_SIZE) << " for TEST_2\n";
}