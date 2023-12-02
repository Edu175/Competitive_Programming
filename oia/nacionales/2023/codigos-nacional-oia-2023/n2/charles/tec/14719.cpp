#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) dforsn(i,0,n)
#define fore(i,s,n) forsn(i,s,n)

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define ALL(x) (x).begin(),(x).end()
#define SZ(x) int((x).size())
#define DBG(x) cout<<#x<<" = "<<(x)<<endl

template<class x> ostream& operator<<(ostream & out, vector<x> v){
    out<<"[ ";
    for(auto y : v) out<<y<<" ";
    out<<"]";
    return out;
}

struct Coso {
    int n;
    vector<vector<int>> g;
    Coso(){}

    vector<int> control;
    int idx;

    Coso(int N, vector<int> &A, vector<int> &B) {
        n = N;
        g.resize(n);
        assert(SZ(A) == SZ(B));
        forn(i, SZ(A)) {
            assert(A[i]-1 >= 0 && A[i]-1 < n);
            assert(B[i]-1 >= 0 && B[i]-1 < n);
            assert(A[i] != B[i]);
            g[A[i]-1].pb(B[i]-1);
            g[B[i]-1].pb(A[i]-1);
        }

        control.resize(n, idx=0);
    }

    int con_quien_comercio(vector<int> &controlados) {
        for(int &i: controlados) --i;

        ++idx;
        for(int i : controlados) control[i] = idx;
        for(int i : controlados) {
            for(int j : g[i]) {
                if(control[j] != idx) return j;
            }
        }
        return -2;
    }
};

Coso coso;

void tablero(int N, vector<int> &A, vector<int> &B) {
    coso = Coso(N, A, B);
}

int con_quien_comercio(vector<int> &controlados) {
    return coso.con_quien_comercio(controlados) + 1;
}


#ifndef EVAL
#include "../graders/grader.cpp"
#endif