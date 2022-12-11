#include <iostream>
#include <vector>
#include <array>

using namespace std;

unsigned int _N, _M;
vector<int> _path;
vector<array<int, 3>> _possibleSquares;
vector<vector<array<int,3>> * > powerSet = vector<vector<array<int,3>>*>();

void readGraph()
{
  cin >> _N >> _M;
  for (size_t i = 0; i < _N; i++)
  {
    int a;
    cin >> a;
    _path.push_back(a);
  }
}

void findAllPossibleSquares()
{
  for (unsigned int a = 0; a < _N - 1; a++) {
    int height = _N - a;
    int length = _path.at(a);
    for (int i = 0; i < length - 1; i++) {
      for (int b = min(height, length - i); b > 1; b--) {
        array<int, 3> temp;
        temp[0] = a;
        temp[1] = i;
        temp[2] = b;
        _possibleSquares.push_back(temp);
      }
    }
  }
}

int squareOverlap(array<int, 3> Square1, array<int, 3> Square2)
{
  int n1 = Square1.at(0);
  int m1 = Square1.at(1);
  int Size1 = Square1.at(2);
  int n2 = Square2.at(0);
  int m2 = Square2.at(1);
  int Size2 = Square2.at(2);
  if (m1 > m2 + (Size2-1) || m2 > m1 + (Size1 - 1)){
    return 0;
  }
  if (n1 + (Size1 - 1) < n2 || n2 + (Size2 - 1) < n1){
    return 0;
  }
  return 1;
}


int countOptions(){
  int i = 0;
  vector<array<int,3>> *emptyArray = new vector<array<int,3>>();
  powerSet.push_back(emptyArray);

  for (array<int,3> square : _possibleSquares) {
    int a;
    for (vector<array<int,3>> *aux : powerSet){
      for (array<int,3> square2 : *aux){
        if (squareOverlap(square, square2) == 1){
          a = 1;
          break;
        }
      }
      if(a == 0) {
        vector<array<int,3>> *auxiliary = new vector<array<int,3>>();
        auxiliary = aux;
        auxiliary->push_back(square);
        powerSet.push_back(auxiliary);
        i ++;
      }
    }
  }   

  if (i == 0) {
    for(int p : _path){
      if(p != 0){
        return 1;
      }
    }
    return 0;
  }
  i += 1;
  return i;
}




int main()
{
  readGraph();
  findAllPossibleSquares();
  int i = countOptions();
  cout << i << endl;
  return 0;
}
