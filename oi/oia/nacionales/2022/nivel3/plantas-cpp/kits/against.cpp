#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 3e5+5;

int FT_l[MAXN], FT_r[MAXN];

void setFT (int *FT, int p, int v) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int *FT, int p) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

long long plantas(vector<int> &h) {
    int n = (int)h.size();

    vector<ii> posic;
    forn(i,n) posic.pb({h[i], i});
    sort(all(posic));

    ll rta = 0;
    int l = 0, r = n-1;
    forn(i,n) {
        int curr_pos = posic[i].snd
            - getFT(FT_r, posic[i].snd-1) 
            + getFT(FT_l, n) - getFT(FT_l, posic[i].snd);
        int dist_l = curr_pos-l;
        int dist_r = r-curr_pos;

        // cerr << dist_l << ' ' << dist_r << ' ' << posic[i].fst << endl;

        if (dist_l < dist_r) rta += dist_l, l++, setFT(FT_l, posic[i].snd, 1);
        else rta += dist_r, r--, setFT(FT_r, posic[i].snd, 1);
    }

    return rta;
}
