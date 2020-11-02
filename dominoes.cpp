#include <iostream>

using namespace std;

// Domino Struct
struct domino
{
  int top;
  int bottom;
};

domino dominos[28];

void createDoubleSixSet(domino dominoArray[])
{
  int count = 28 - 1;
  for (int i = 0; i <= 6; i++) { // row number loop and equivalent bottom number
    for (int j = 0; j <= i; j++) { // Top number loop
      domino currDom = {j, i};
      dominoArray[count] = currDom;
      count--;
    }
  }
}

void printHalfDomino (int num) {
  switch (num) {
    case 0:
      cout << "|       |" << endl;
      cout << "|       |" << endl;
      cout << "|       |" << endl;
      break;
    case 1:
      cout << "|       |" << endl;
      cout << "|   *   |" << endl;
      cout << "|       |" << endl;
      break;
    case 2:
      cout << "|     * |" << endl;
      cout << "|       |" << endl;
      cout << "| *     |" << endl;
      break;
    case 3: 
      cout << "|     * |" << endl;
      cout << "|   *   |" << endl;
      cout << "| *     |" << endl;
      break;
    case 4:
      cout << "| *   * |" << endl;
      cout << "|       |" << endl;
      cout << "| *   * |" << endl;
      break;
    case 5:
      cout << "| *   * |" << endl;
      cout << "|   *   |" << endl;
      cout << "| *   * |" << endl;
      break;
    case 6: 
      cout << "| *   * |" << endl;
      cout << "| *   * |" << endl;
      cout << "| *   * |" << endl;
      break; 
  }
}

void printDomino (domino dom) {
  int top = dom.top;
  int bottom = dom.bottom;
  cout << "+-------+" << endl;
  printHalfDomino(top);
  cout << "+-------+" << endl;
  printHalfDomino(bottom);
  cout << "+-------+" << endl;
}

void sortDominosByBottom (domino dominoArray[], int arraySize) {
  int start = 0;
  int end = arraySize - 1;
  for (int i = start + 1; i <= end; i++) {
    for (int j = i; j > start && dominoArray[j-1].bottom > dominoArray[j].bottom; j--) {
      domino temp = dominoArray[j-1];
      dominoArray[j-1] = dominoArray[j];
      dominoArray[j] = temp;    
    }
  }
}
void sortDominosByTop (domino dominoArray[], int arraySize) {
  int start = 0;
  int end = arraySize - 1;
  for (int i = start + 1; i <= end; i++) {
    for (int j = i; j > start && dominoArray[j-1].top > dominoArray[j].top; j--) {
      domino temp = dominoArray[j-1];
      dominoArray[j-1] = dominoArray[j];
      dominoArray[j] = temp;    
    }
  }
}

int main() 
{
  createDoubleSixSet(dominos);
  for (int i = 0; i < 28; i++) {
    cout << "Domino " << i + 1 << endl;
    printDomino(dominos[i]);
  }
  sortDominosByBottom(dominos, 28);
  for (int i = 0; i < 28; i++) {
    cout << "Domino " << i + 1 << endl;
    printDomino(dominos[i]);
  }
  return 0;
}