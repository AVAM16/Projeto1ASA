#include <iostream>
#include <list>
#include <vector>
#include <array>

using namespace std;

unsigned int _N, _M;
vector<int> _path;
vector<array<int, 3>> _possibleSquares;

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

int countOptionsRecursive(vector<array<int, 3>> auxiliarvector, array<int, 3> Square,int j){
  bool l = true;
  int i = 1;
  int k = 0;
  auxiliarvector.push_back(Square);
  for(array<int, 3> Square1: _possibleSquares){
    if(j <= k){
      j++;
/*       cout << Square1.at(0) << Square1.at(1) << Square1.at(2) << endl; */
      for(array<int, 3> Square2: auxiliarvector){
        if(squareOverlap(Square2,Square1) == 1){
          l = false;
          break;
        }
        else{
        }
      }
      if(l){
        /* cout << "acertou" << endl;
        cout << Square1.at(0) << Square1.at(1) << Square1.at(2) << endl; */
        i += countOptionsRecursive(auxiliarvector,Square1,j);
      }
    }
    k++;
    l = true;
  }
  auxiliarvector.pop_back();
  return i;
}

int countOptions(){
  int i = 0;
  int j = 0;
  vector<array<int, 3>> _auxiliarvector;
  for(int p : _path){
    if(p != 0){
      i=1;
      break;
    }
  }
  for(array<int,3> Square1: _possibleSquares){
    j++;
    i += countOptionsRecursive(_auxiliarvector,Square1,j);
  }
  return i;
}




int main()
{
  readGraph();
  findAllPossibleSquares();
  cout << _possibleSquares.size() << endl;
  int i = countOptions();
  cout << i << endl;
  //vector<int> v1 = _possibleSquares.at(1);
  //vector<int> v2 = _possibleSquares.at(7);
  //cout << squareOverlap(v2, v1) << endl;
  return 0;
}
