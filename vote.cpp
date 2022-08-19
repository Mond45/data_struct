#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;
    int n, k;
    cin >> n >> k;
    map<string, int> votes;
    while (n--)
    {
        string name;
        cin >> name;
        votes[name]++;
    }
    if (votes.size() <= k)
    {
        using pt = map<string, int>::value_type;
        cout << min_element(votes.begin(), votes.end(),
                            [](const pt &a, const pt &b)
                            {
                                return a.second < b.second;
                            })
                    ->second;
    }
    else
    {
        vector<int> vote_cnt;
        for (auto &v : votes)
        {
            vote_cnt.push_back(v.second);
        }
        sort(vote_cnt.begin(), vote_cnt.end(), greater<int>());
        cout << vote_cnt[k - 1];
    }
}