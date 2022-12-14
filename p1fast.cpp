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
map<vector<int>,unsigned long long> Map;

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
    }
    else{
      a = -1;
    }
  }
  return possibleSquares;
}

int maxValue(vector<int> path){
  int value;
  value = *max_element(path.begin(), path.end());
  for(int i = path.size(); i > 0;i--){
    if(path[i-1] == value){
      return i-1;
    }
  }
  return -1;
}

void addToMap(vector<int> path,unsigned long long combinations){
  Map.insert(pair<vector<int>,unsigned long long>(path,combinations));
}

unsigned long long encontraNoMapa(vector<int> path){
  if(Map.find(path) != Map.end()){
    return Map[path];
  }
  return -1;
}

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
        for(int h : path2){
          k+=h;
        }
        if(k == 0){
          counter++;
          return counter;
        }
        k=0;
      }
      unsigned long long aux1 = encontraNoMapa(path2);
      if((int) aux1 == -1){
        unsigned long long aux2 = findOptions(path2);
        counter += aux2;
        addToMap(path2,aux2);
      }
      else{
        counter += aux1;
      }
      path2 = path;
    }
  }
  return counter;
}


int main()
{
  unsigned long long counter;
  using namespace std::chrono;
  readGraph();
  counter = findOptions(_path);
  cout << counter << endl;
  return 0;
}
