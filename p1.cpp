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

int squareOverlap(vector<int> Square1, vector <int> Square2){
  int i = Square1.at(0);
  int j = Square1.at(1);
  int Size = Square1.at(2);
  int i2 = Square2.at(0);
  int j2 = Square2.at(1);
  int Size2 = Square2.at(2);
  while(i < i + Size){
    while(j < j + Size){
      if(i2 <= i < i2 + Size2 & j2 <= j < j2 + Size2){
        return -1;
      }
      j++;
    }
    i++;
  }
  return 0;
}

int countOptions(){
  int i = 0;
  int j = 0;
  vector<vector<int>> _auxiliarvector;
  for(vector<int> Square1: _possibleSquares){
    _auxiliarvector.push_back(Square1);
    j++;
    i += countOptionsRecursive(_auxiliarvector,Square1,j) +1;
  }
  i++;
  return i;
}

int countOptionsRecursive(vector<vector<int>> auxiliarvector, vector<int> Square,int j){
  bool l;
  int i = 0;
  int k = 0;
  vector<vector<int>> _auxiliarvector2;
  _auxiliarvector2.push_back(Square);
  for(vector<int> Square1: _possibleSquares){
    if(j> k){
      k++;
    }
    else{
      for(vector<int> Square2: _auxiliarvector2){
        if(squareOverlap(Square1,Square2)){
          l = false;
          break;
        }
        else{
          l = true;
        }
      }
      if(l){
        j++;
        i += countOptionsRecursive(_auxiliarvector2,Square1,j) +1;
      }
    }
  }
  i+=1;
  return i;
}


int main()
{
  readGraph();
  findAllPossibleSquares();
  return 0;
}
