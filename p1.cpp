#include <iostream>
#include <list>
#include <vector>

using namespace std;

unsigned int _N, _M;
vector<int> _path;
list<vector<int>>* _possibleSquares;

void readGraph()
{
  cin >> _N >> _M;
  _path.resize(_N);
  for (size_t i = 0; i < _N; i++)
  {
    int a;
    cin >> a;
    _path[i] = a;
  }
}

void findAllPossibleSquares()
{
}

int main()
{
  readGraph();
  findAllPossibleSquares();
  return 0;
}
