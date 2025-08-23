#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll r,c;
const int maxl = 40;
char a[maxl][maxl];
ll res[maxl][maxl];
ll k = 0;
string palabra;

void f(string &aux, int x, int y){
	if(x<0 || x>=r) return;
	if(y<0 || y>=c) return;
	aux.pb(a[x][y]);
}

void process(int x, int y){
	ll p = SZ(palabra);
	string aux = "";
	fore(i,0,p) f(aux,x,y+i);
	sort(ALL(aux));
	if(aux == palabra) fore(i,0,p) res[x][y+i] |= (1<<k);
	aux = "";
	fore(i,0,p) f(aux,x+i,y+i);
	sort(ALL(aux));
	if(aux == palabra) fore(i,0,p) res[x+i][y+i] |= (1<<k);
	aux = "";
	fore(i,0,p) f(aux,x+i,y);
	sort(ALL(aux));
	if(aux == palabra) fore(i,0,p) res[x+i][y] |= (1<<k);
	aux = "";
	fore(i,0,p) f(aux,x+i,y-i);
	sort(ALL(aux));
	if(aux == palabra) fore(i,0,p) res[x+i][y-i] |= (1<<k);
	return;
}

void solve(){
	sort(ALL(palabra));
	fore(i,0,r)fore(j,0,c) process(i,j);
}

int main(){
	JET
	cin>>r>>c;
	fore(i,0,r)fore(j,0,c) cin>>a[i][j];
	ll n; cin>>n;
	fore(i,0,n){
		k = i;
		cin>>palabra;
		solve();
	}
	ll rta = 0;
	fore(i,0,r)fore(j,0,c) if(__builtin_popcount(res[i][j]) > 1) rta++;
	cout<<rta<<"\n";
	return 0;
}