#include <iostream>
#include <vector>
#include <array>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;

unsigned int _N, _M;
vector<int> _path; 

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

unsigned long long findOptions(vector<int> path){
  int x = 0;
  int k = 0;
  unsigned long long counter = 0;
  vector<int> path2(path);
  vector<array<int,3>> squares = findAllPossibleSquaresPoint(x, path[x], path);
  vector<array<int,3>> aux;
  if(squares.size() != 0){
    for (array<int,3> square : squares) {
      cout << square[0] << square[1] << square[2] << endl;
      for(int i = 0;i < square[2];i++){
        int aux = path[x-i] - square[2];
        path2.at(x-i-k) = aux;
        if(path2.at(x-i-k) == 0){
          if(path2.size() == 1){
            cout << "finish" << endl;
            counter++;
          }
          else{
            path2.erase(path2.begin());
            k += 1;
          }
        }   
      }
      counter += findOptions(path2);
      path2 = path;
      k=0;
    }
  }
  if(path2.size() != 1 && path2.at(0) == 0){
    path2.erase(path2.begin());
    counter += findOptions(path2);
  }
  return counter;
}


// int countOptionsRecursive(vector<array<int, 3>> auxiliarvector, array<int, 3> Square,int j){
//   bool l = true;
//   int i = 1;
//   int k = 0;
//   auxiliarvector.push_back(Square);
//   for(array<int, 3> Square1: _possibleSquares){
//     if(j <= k){
//       j++;
//       for(array<int, 3> Square2: auxiliarvector){
//         if(squareOverlap(Square2,Square1) == 1){
//           l = false;
//           break;
//         }
//         else{
//         }
//       }
//       if(l){
//         i += countOptionsRecursive(auxiliarvector,Square1,j);
//       }
//     }
//     k++;
//     l = true;
    
//   }
//   auxiliarvector.pop_back();
//   return i;
// }

// int countOptions(){
//   int i = 0;
//   int j = 0;
//   vector<array<int, 3>> _auxiliarvector;
//   _auxiliarvector.reserve(_N * _M);
//   for(array<int,3> Square1: _possibleSquares){
//     j++;
//     i += countOptionsRecursive(_auxiliarvector,Square1,j);
//   }
//   if (i == 0) {
//     for(int p : _path){
//       if(p != 0){
//         return 1;
//       }
//     }
//     return 0;
//   }
//   i += 1;
//   return i;
// }




int main()
{
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
