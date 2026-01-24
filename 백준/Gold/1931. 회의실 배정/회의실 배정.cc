#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting
{
    int start;
    int end;
    Meeting(int s, int e) : start(s), end(e) {};
};

bool compar(const Meeting &a, const Meeting &b)
{
    if (a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Meeting> I;
    I.reserve(N);

    for (int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;
        I.emplace_back(s, e);
    }

    sort(I.begin(), I.end(), compar);

    int ans = 0;
    int last_end = 0;
    for (const auto &m : I)
    {
        if (m.start >= last_end)
        {
            ans++;
            last_end = m.end;
        }
    }
    cout << ans;
    return 0;
}