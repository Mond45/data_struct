#include <vector>
#include <stack>

using namespace std;

int eval_postfix(const vector<pair<int, int>> &v)
{
    // first == 0 -> operator
    // op 0+ 1- 2* 3/
    stack<int> s;
    for (auto &p : v)
    {
        if (p.first == 1)
        {
            s.push(p.second);
        }
        else
        {
            int a, b;
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            if (p.second == 0)
                s.push(a + b);
            else if (p.second == 1)
                s.push(a - b);
            else if (p.second == 2)
                s.push(a * b);
            else if (p.second == 3)
                s.push(a / b);
        }
    }
    return s.top();
}