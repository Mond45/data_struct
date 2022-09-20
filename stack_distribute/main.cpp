#include <iostream>
#include <vector>
#include "stack.h"
#include "student.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  CP::stack<int> s;
  for (int i = 1; i <= n; ++i)
  {
    s.push(i);
  }
  vector<vector<int>> v = s.distribute(k);
  for (int i = 0; i < k; i++)
  {
    cout << i << ": ";
    for (auto &x : v[i])
      cout << x << " ";
    cout << endl;
  }
}
