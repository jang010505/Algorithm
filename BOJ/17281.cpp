#include <cstdio>
#include <algorithm>

using namespace std;

int hitter[50][9], visit[9], hitorder[9], MAX = 0, n;

int scorecount()
{
    int score = 0, hit = 0;
    for (int i = 0; i < n; i++)
    {
        int outcount = 0, base1 = 0, base2 = 0, base3 = 0;
        while (outcount != 3)
        {
            if (hitter[i][hitorder[hit]] == 0)
                outcount++;
            else if (hitter[i][hitorder[hit]] == 1)
            {
                if (base3)
                {
                    score++;
                    base3 = 0;
                }
                if (base2)
                {
                    base3 = 1;
                    base2 = 0;
                }
                if (base1)
                {
                    base2 = 1;
                    base1 = 0;
                }
                base1 = 1;
            }
            else if (hitter[i][hitorder[hit]] == 2)
            {
                if (base3)
                {
                    score++;
                    base3 = 0;
                }
                if (base2)
                {
                    score++;
                    base2 = 0;
                }
                if (base1)
                {
                    base3 = 1;
                    base1 = 0;
                }
                base2 = 1;
            }
            else if (hitter[i][hitorder[hit]] == 3)
            {
                if (base3)
                {
                    score++;
                    base3 = 0;
                }
                if (base2)
                {
                    score++;
                    base2 = 0;
                }
                if (base1)
                {
                    score++;
                    base1 = 0;
                }
                base3 = 1;
            }
            else if (hitter[i][hitorder[hit]] == 4)
            {
                if (base3)
                {
                    score++;
                    base3 = 0;
                }
                if (base2)
                {
                    score++;
                    base2 = 0;
                }
                if (base1)
                {
                    score++;
                    base1 = 0;
                }
                score++;
            }
            hit = (hit + 1) % 9;
        }
    }
    return score;
}

void order(int count)
{
    if (count == 3)
    {
        order(count + 1);
        return;
    }
    if (count == 9)
    {
        MAX = max(MAX, scorecount());
        return;
    }
    for (int i = 0; i < 9; i++)
    {
        if (!visit[i] && count != 3)
        {
            visit[i] = 1;
            hitorder[count] = i;
            order(count + 1);
            visit[i] = 0;
        }
    }
    return;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 9; j++)
            scanf("%d", &hitter[i][j]);
    visit[0] = 1;
    hitorder[3] = 0;
    order(0);
    printf("%d", MAX);
    return 0;
}