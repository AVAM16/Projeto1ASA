#include <iostream>
#include <list>
#include <vector>
#include <array>

using namespace std;

unsigned int _N, _M;
vector<int> _path;
vector<vector<int>> _possibleSquares;

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
  for (unsigned int a = 0; a < _N; a++) {
    int height = _N - a;
    for (int i = 0; i < _path[a]; i++) {
      for (int b = height; b > 1; b--) {

      }
    }
  }
}

boolean squareOverlap(vector<int> Square1, vector <int> Square2){
  int i = Square1.at(0);
  int j = Square1.at(1);
  int Size = Square1.at(2);
  int i2 = Square2.at(0);
  int j2 = Square2.at(1);
  int Size2 = Square2.at(2);
  while(i < i + Size){
    while(j < j + Size){
      if(i2 <= i < i2 + Size2 & j2 <= j < j2 + Size2){
        return false;
      }
      j++;
    }
    i++;
  }
  return true;
}


int main()
{
  readGraph();
  findAllPossibleSquares();
  return 0;
}
