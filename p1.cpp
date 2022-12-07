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
      for (int b = min(height, length - i); b > 1; b--) {
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(i);
        temp.push_back(b);
        _possibleSquares.push_back(temp);
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
  if (m1 > m2 + (Size2-1) || m2 > m1 + (Size1 - 1)){
    return 0;
  }
  if (n1 + (Size1 - 1) < n2 || n2 + (Size2 - 1) < n1){
    return 0;
  }
  return 1;
}

int countOptionsRecursive(vector<vector<int>> auxiliarvector, vector<int> Square,int j){
  bool l = true;
  int i = 1;
  int k = 0;
  vector<vector<int>> _auxiliarvector2;
  for(vector<int> SquareTemp : auxiliarvector){
    _auxiliarvector2.push_back(SquareTemp);
  }
  _auxiliarvector2.push_back(Square);
  for(vector<int> Square1: _possibleSquares){
    if(j <= k){
      for(vector<int> Square2: _auxiliarvector2){
        //cout << Square1.at(0) << Square1.at(1) << Square1.at(2) << endl;
        //cout << Square2.at(0) << Square2.at(1) << Square2.at(2) << endl;
        if(squareOverlap(Square2,Square1) == 1){
          l = false;
          //cout << "errou" << endl;
          break;
        }
        else{
          //cout << "acertou" << endl;
          l = true;
        }
      }
      if(l){
        j++;
        i += countOptionsRecursive(_auxiliarvector2,Square1,j);
      }
    }
    k++;
    l = true;
  }
  return i;
}

int countOptions(){
  int i = 1;
  int j = 0;
  vector<vector<int>> _auxiliarvector;
  for(vector<int> Square1: _possibleSquares){
    _auxiliarvector.clear();
    _auxiliarvector.push_back(Square1);
    j++;
    //cout << j << endl;
    i += countOptionsRecursive(_auxiliarvector,Square1,j);
  }
  return i;
}




int main()
{
  readGraph();
  findAllPossibleSquares();
  int i = countOptions();
  cout << i << endl;
  //vector<int> v1 = _possibleSquares.at(1);
  //vector<int> v2 = _possibleSquares.at(7);
  //cout << squareOverlap(v2, v1) << endl;
  return 0;
}
