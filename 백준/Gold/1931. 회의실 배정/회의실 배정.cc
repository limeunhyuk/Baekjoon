#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pair
{
    int start;
    int end;
};

bool compar(Pair x, Pair y)
{
    if (x.end == y.end)
        return x.start < y.start;
    return x.end < y.end;
}

int main()
{
    int N;
    Pair I[100010];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &I[i].start, &I[i].end);
    }

    sort(I, I + N, compar);

    int ans = 0;
    int fend = 0;
    for (int i = 0; i < N; i++)
    {
        if(I[i].start >= fend){
            ans++;
            fend = I[i].end;
        }
    }
    printf("%d", ans);
    return 0;
}