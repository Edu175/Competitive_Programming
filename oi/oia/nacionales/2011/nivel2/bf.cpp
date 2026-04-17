#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 101;
const int INF = 1e9+5;

map<int,int> w[MAXN];
bitset<MAXN> done;
int maxi = 0, maxiW = INF;

int divide(int x, int cnt) {
    if (x < MAXN && w[x][1] >= cnt) {w[x][1] -= cnt; return cnt;}
    else {
        int dif = (x >= MAXN ? cnt : cnt-w[x][1]);
        return (cnt-dif)+divide(x>>1,dif<<1);
    }
}

void fastscan (int &x) {
    int c; x = 0;
    while((c=getchar_unlocked()) < '0' && c > '9');
    for(;c>='0' && c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

int main() {
    //freopen("movil.in","r",stdin);
    //freopen("movil.out","w",stdout);
    int n; fastscan(n);

    bool cond = false;
    forn(i,n) {int x; fastscan(x); w[x][1]++; if (x) cond = true;}
    if (!n || !cond) {printf("no se puede"); return 0;}

    forsn(i,1,MAXN)
        if (w[i][1] && !done[i])
            for (int j = i; j < MAXN; j<<=1) {
                done[j] = true;

                int target = 1, cnt = 0, used = 0;
                for (auto k = w[j].rbegin(); k != w[j].rend(); k++) {
                    cnt += k->snd;
                    used += k->snd*k->fst;

                    while (cnt >= target) {
                        int targetUsed = used-((cnt-target)*k->fst);
                        if (targetUsed > maxi) {maxi = targetUsed; maxiW = target*j;}
                        else if (targetUsed == maxi && target*j < maxiW) maxiW = target*j;
                        target <<= 1;
                    }
                }

                if ((j<<1) < MAXN) {
                    int usedNow = 0, cntNow = 0;
                    for (auto k = w[j].rbegin(); k != w[j].rend(); k++)  {
                        bool add = false;
                        if (cntNow) {
                            add = true;
                            w[j<<1][usedNow+k->fst]++;
                            cntNow = usedNow = 0;
                        }

                        cntNow += k->snd-(int)add;
                        usedNow += (k->snd*k->fst)-(k->fst*(int)add);

                        int toBeAdded = (cntNow>>1); if(!toBeAdded) continue;
                        int toBeUsed = ((usedNow-((cntNow&1)*k->fst))/toBeAdded);
                        usedNow = (cntNow&1)*k->fst; cntNow &= 1;
                        w[j<<1][toBeUsed] += toBeAdded;
                    }
                }
            }


    int maxiWW = divide(maxiW,1);

    printf("%d %d %d",maxi,maxiW,maxiWW); // test

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
