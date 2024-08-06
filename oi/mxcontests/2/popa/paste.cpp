#include "popa.h"
#include<bits/stdc++.h>
using namespace std;

int solve(int N, int* Left, int* Right)
{
    int test_query = query(0,0,0,0);

    for(int i=0;i<N;i++)
    {
        Left[i]=-1;
        Right[i]=-1;
    }
    return 0;
}

void test(int N) {
    int* Left = new int[N];
    int* Right = new int[N];

    int root = solve(N, Left, Right);
    cout << "Root: " << root << endl;

    for (int i = 0; i < N; i++) {
        cout << Left[i] << " " << Right[i] << endl;
    }
}
