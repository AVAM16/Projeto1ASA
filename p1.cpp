#include <iostream>
#include <list>
#include <vector>
#include <array>

using namespace std;

unsigned int _N, _M;
vector<int> _path;
vector<array<int,3>> _possibleSquares;

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

int main()
{
  readGraph();
  findAllPossibleSquares();
  return 0;
}
