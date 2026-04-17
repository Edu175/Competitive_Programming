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

    vector<char> seen;
    vector<vector<int>> tree;

    void dfs(int i) {
        seen[i] = true;
        for(int j : g[i]) if(!seen[j]) {
            tree[i].pb(j);
            tree[j].pb(i);
            dfs(j);
        }
    }

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

        tree.resize(n);
        seen.resize(n, 0);
        forn(i, n) if(!seen[i]) dfs(i);
    }
    int con_quien_comercio(vector<int> &controlados) {
        for(int &i: controlados) --i;

        set<int> control;
        for(int i : controlados) control.insert(i);
        for(int i : controlados) {
            for(int j : tree[i]) if(!control.count(j)) return j;
        }
        return -2;
    }
};

Coso coso;

int n = -1;
void tablero(int N, vector<int> &A, vector<int> &B) {

    // assert(SZ(A) == SZ(B));
    // int m = SZ(A);
    // n = N;

    // assert(1 <= n);
    // assert(n <= 200000);
    // assert(1 <= m);
    // assert(m <= 500000);

    // set<pair<int, int>> seen;
    // forn(i, m) {
    //     assert(1 <= A[i]);
    //     assert(A[i] <= n);
    //     assert(1 <= B[i]);
    //     assert(B[i] <= n);
    //     assert(A[i] != B[i]);
    //     assert(seen.insert(mp(min(A[i], B[i]), max(A[i], B[i]))).second);
    // }
    coso = Coso(N, A, B);
}

int suma = 0;
int con_quien_comercio(vector<int> &controlados) {
    // assert(SZ(controlados) != 0);
    // set<int> cs;
    // for(int c : controlados) {
    //     assert(1 <= c);
    //     assert(c <= n);
    //     assert(cs.insert(c).second);
    // }
    // suma += SZ(controlados);
    // assert(suma <= 500000);
    return coso.con_quien_comercio(controlados) + 1;
}


#ifndef EVAL
#include "../graders/grader.cpp"
#endif