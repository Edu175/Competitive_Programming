#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for (int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXE = 4e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXE)));

struct range {
    int l,r,id;

    bool operator< (const range &o) const { // sort by ending first
        if (r != o.r) return r < o.r;
        if (l != o.l) return l < o.l;
        return id < o.id;
    }
};

struct mon {
    int x;

    mon operator+ (const mon &o) const {
        return {max(x,o.x)};
    }
};

vi coords;
vector<range> tickets;
mon ST[2*MAXST], lazy[2*MAXST];
int L[2*MAXST], R[2*MAXST];

void pass_lazy (int i) { // si agrego una cantidad, el maximo sube o baja igualmente
    ST[i].x += lazy[i].x;

    int top = 2*MAXST;
    if (2*i < top) lazy[2*i].x += lazy[i].x;
    if (2*i+1 < top) lazy[2*i+1].x += lazy[i].x;

    lazy[i].x = 0;
}

void update_st (int i, int v, int bl, int br) {
    pass_lazy(i);
    if (L[i] >= br || R[i] <= bl) return;
    if (L[i] >= bl && R[i] <= br) {
        lazy[i].x += v;
        pass_lazy(i);
        return;
    }

    update_st(2*i,v,bl,br);
    update_st(2*i+1,v,bl,br);
    ST[i] = ST[2*i] + ST[2*i+1];
}

void update (int &x, vi &arr) {
    x = lower_bound(all(arr),x)-arr.begin();
}

int monorriel(int C, vector<int> &a, vector<int> &b, vector<int> &reservas) {
    int n = (int)a.size();
    forn(i,n) coords.pb(a[i]), coords.pb(b[i]);
    sort(all(coords));
    coords.erase(unique(all(coords)),coords.end());
    forn(i,n) update(a[i],coords), update(b[i],coords);

    forn(i,n) tickets.pb({a[i],b[i],i});
    sort(all(tickets)); // sort by ending first

    forn(i,MAXST) L[i+MAXST] = R[i+MAXST] = i, ++R[i+MAXST];
    dforsn(i,1,MAXST) {
        ST[i] = ST[2*i] + ST[2*i+1];
        L[i] = L[2*i], R[i] = R[2*i+1];
    }

    vi rta(n,0);
    int reserved = 0;

    forn(i,n) {
        range aux = tickets[i];
        update_st(1,1,aux.l,aux.r);
        if (ST[1].x > C) update_st(1,-1,aux.l,aux.r);
        else rta[aux.id] = 1, ++reserved;
    }

    reservas = rta;
    return reserved;
}

int main(){
	int c,m; cin>>c>>m;
	vector<int> a(m),b(m),res(m);
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
	}
	cout<<monorriel(c,a,b,res)<<"\n";
	for(int i=0;i<m;i++)cout<<res[i]<<" ";
	cout<<"\n";
	return 0;
}
