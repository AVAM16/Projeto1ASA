#include <iostream>
#include <vector>
#include <array>
#include <ctime>
#include <ratio>
#include <chrono>
#include <bits/stdc++.h>
#include <map>

using namespace std;

unsigned int _N, _M;
vector<int> _path; 
map<vector<int>,int> Map = {};

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

vector<array<int,3>> findAllPossibleSquaresPoint(int n, int m, vector<int> path)
{
  vector<array<int,3>> possibleSquares;
  int height = path.size() - n;
  int length = path[n] - m;
  for (int b = min(height, length); b > 0; b--) {
    array<int, 3> temp;
    temp[0] = n;
    temp[1] = m;
    temp[2] = b;
    possibleSquares.push_back(temp);
  }
  return possibleSquares;
}

vector<array<int,3>> findAllPossibleSquaresPoint2(int n, int m, vector<int> path)
{
  vector<array<int,3>> possibleSquares;
  if(path.size()==1 && path[0] == 0){
    return {};
  }
  int a = 1;
  while (a > 0){
    if(path[n-(a-1)] >= m+1 && path[n-(a-1)] >= a){
      array<int, 3> temp;
      temp[0] = n;
      temp[1] = m;
      temp[2] = a;
      possibleSquares.push_back(temp);
      a++;
      cout << "noice: " << temp[0] << temp[1] << temp[2] << endl;
      
    }
    else{
      a = -1;
    }
  }
  return possibleSquares;
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

int maxValue(vector<int> path){
  int value;
  value = *max_element(path.begin(), path.end());
  for(int i = path.size(); i > 0;i--){
    if(path[i-1] == value){
/*       cout << value << "  oi  " << i-1 << endl; */
      return i-1;
    }
  }

  return 124;
}

/* void addToMap(vector<int> path,int combinations){
  Map.insert(pair<vector<int>,int>(path,combinations));
}

int encontraNoMapa(vector<int> path){
  if(Map[path] != 0){
    return Map[path];
  }
  return -1;
} */

unsigned long long findOptions(vector<int> path){
  int x = 0;
  int k = 0;
  unsigned long long counter = 0;
  vector<int> path2(path);
  x = maxValue(path);
  vector<array<int,3>> squares = findAllPossibleSquaresPoint2(x, path[x]-1, path);
  vector<array<int,3>> aux;
  if(squares.size() != 0){
    for (array<int,3> square : squares) {
      for(int i = 0;i < square[2];i++){
        int aux = path[x-i] - square[2];
        path2.at(x-i) = aux;
        for(int j : path2){
          cout << j;
        }
        cout << endl;
        cout << "i: " << i << " x: " << x << " path do x: " << path[x] << endl;
        for(int h : path2){
          k+=h;
        }
        if(k == 0){
          counter++;
          cout << "finish" << endl;
          return counter;
        }
        k=0;
      }
      int aux = findOptions(path2);
      counter += aux;
      path2 = path;
    }
  }
  return counter;
}


int main()
{
  //map<int, int> gquiz1;
  // insert elements in random order
  /* gquiz1.insert(pair<int, int>(1, 40));
  gquiz1.insert(pair<int, int>(2, 30));
  gquiz1.insert(pair<int, int>(3, 60));
  gquiz1.insert(pair<int, int>(4, 20));
  gquiz1.insert(pair<int, int>(5, 50));
  gquiz1.insert(pair<int, int>(6, 50));
  cout << gquiz1[7] << endl;  */
 /*  findAllPossibleSquaresPoint2(2,2,{2,2,3,2}); */
  unsigned long long counter;
  using namespace std::chrono;
  readGraph();
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  counter = findOptions(_path);
  cout << counter << endl;
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  std::cout << "It took me " << time_span.count() << " seconds.";
  std::cout << std::endl;
  return 0;
}
