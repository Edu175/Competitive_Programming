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

struct Fenwick {
    vector<int> ft;
    Fenwick(int n=0): ft(n+2, 0) {}
    void add(int n, int k) {
        for(int i = n+2; i < SZ(ft); i += i&-i) ft[i] += k;
    }
    int get(int n) {
        int res = 0;
        for(int i = n+1; i; i -= i&-i) res += ft[i];
        return res;
    }
    int getr(int a, int b) {
        return get(b) - get(a);
    }
};

vector<vector<int>> g;
vector<int> s, e;
int tmp = 0;
void dfs(int node) {
    s[node] = tmp++;
    for(int ch : g[node]) dfs(ch);
    e[node] = tmp++;
}

Fenwick inner, outer;
vector<char> wifi;

void setit(int n, int k) {
    wifi[n] = k == 1;
    inner.add(s[n], k);
    outer.add(s[n], k);
    outer.add(e[n], -k);
}

bool enablewifi(int n) {
    if(wifi[n]) return false;
    int adentro = inner.getr(s[n], e[n]);
    int afuera = outer.get(s[n]);
    if(adentro != 0 || afuera != 0) return false;
    setit(n, 1);
    return true;
}

bool disablewifi(int n) {
    if(!wifi[n]) return false;
    setit(n, -1);
    return true;
}

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    int n = SZ(padre)+1;
    g.resize(n);
    s.resize(n);
    e.resize(n);
    wifi.resize(n);
    inner = Fenwick(2*n);
    outer = Fenwick(2*n);
    forn(i, n-1) g[padre[i]].pb(i+1);
    dfs(0);
    int q = SZ(tipo);
    vector<char> wifi;
    vector<int> res(q);
    forn(i, q) {
        int t = tipo[i];
        int k = nodo[i];
        if(t == 0) res[i] = enablewifi(k);
        else res[i] = disablewifi(k);
    }
    return res;
}
