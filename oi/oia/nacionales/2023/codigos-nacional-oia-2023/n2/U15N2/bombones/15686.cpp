#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#ifdef PROBANDO_JIJIJIAJAJAJA
#include <iostream>
#endif

using namespace std;

bool simulate(int boxAmountDesired, int amountPerBoxDesired, vector<int> amountOfEach)
{
    if (boxAmountDesired <= 0) {
        return false;
    }
    int boxesMade = 0;
    vector<int> amountRemaining = amountOfEach;
    for (size_t i = 0; i < boxAmountDesired; i++)
    {
        vector<bool> isInside(amountOfEach.size(), false);
        int uniquesInside = 0;
        for (size_t j = 0; j < amountOfEach.size() && uniquesInside < amountPerBoxDesired; j++)
        {
            if (isInside[j] || amountRemaining[j] <= 0)
            {
                continue;
            }
            uniquesInside++;
            isInside[j] = true;
            amountRemaining[j]--;
        }
        if (uniquesInside < amountPerBoxDesired) {
            break;
        }
        if (uniquesInside >= amountPerBoxDesired)
        {
            boxesMade++;
        }
    }
    return boxesMade >= boxAmountDesired;
}

bool pred(const int &a)
{
    return a == 1;
}

long long bombones(int amountPerBoxDesired, vector<int> &amountOfEach)
{
    if (amountPerBoxDesired > amountOfEach.size())
    {
        return 0;
    }
    long long maxPossible = 0;
    for (auto amount : amountOfEach)
    {
        maxPossible += amount;
    }

    if (amountPerBoxDesired == 1)
    {
        return maxPossible;
    }

    if (all_of(amountOfEach.begin(), amountOfEach.end(), pred))
    {
        return maxPossible / amountPerBoxDesired;
    }

    long long lo = -1;
    long long hi = maxPossible;
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (simulate(mid, amountPerBoxDesired, amountOfEach))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    float res = roundf(((float)hi + (float)lo) / 2.0);
    return res < 0 ? 0 : res;
}