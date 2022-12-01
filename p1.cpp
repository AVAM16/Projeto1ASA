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
  for (unsigned int a = 0; a < _N - 1; a++) {
    int height = _N - a;
    int length = _path.at(a);
    for (int i = 0; i < length - 1; i++) {
      for (int b = height; b > 1; b--) {
        if (length - i >= b) {
          vector<int> temp;
          temp.push_back(a);
          temp.push_back(i);
          temp.push_back(b);
          _possibleSquares.push_back(temp);
        }
      }
    }
  }
}

int squareOverlap(vector<int> Square1, vector <int> Square2)
{
  int n1 = Square1.at(0);
  int m1 = Square1.at(1);
  int Size1 = Square1.at(2);
  int n2 = Square2.at(0);
  int m2 = Square2.at(1);
  int Size2 = Square2.at(2);
  for (int i = n1; i < n1 + Size1; i++) {
    for (int j = m1; j < m1 + Size1; j++) {
      if (i <= n2 + Size2 && i >= n2 && j <= m2 + Size2 && j >= m2) {
        return 1;
      }
    }
  }
  return 0;
}
/*
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
*
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
*/

int main()
{
  readGraph();
  findAllPossibleSquares();
  return 0;
}
