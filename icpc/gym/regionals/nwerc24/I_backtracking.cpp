#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef __int128 xl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef array<array<ll,3>,3> mat;
vector<vector<vv>> base={
	{{0, 2, 1},
	{2, 1, 0},
	{1, 0, 2}},

	{{1, 0, 2},
	{2, 1, 0},
	{0, 2, 1}},

	{{1, 1, 1},
	{1, 1, 1},
	{1, 1, 1}},

	{{1, 2, 0},
	{0, 1, 2},
	{2, 0, 1}},

	{{2, 0, 1},
	{0, 1, 2},
	{1, 2, 0}}
};
const ll MX=60;
set<mat> all[MX];
mat cur;
void gen(ll p, ll s){
	if(p==SZ(base)){all[s].insert(cur);return;}
	fore(c,0,MX){
		ll si=s+c*3;
		if(si>=MX)break;
		fore(i,0,3)fore(j,0,3)cur[i][j]+=c*base[p][i][j];
		gen(p+1,si);
		fore(i,0,3)fore(j,0,3)cur[i][j]-=c*base[p][i][j];
	}
}

const ll MAXV=1e6+5;
int cr[MAXV]; // -1 if prime
vv ps;
vector<vv> pot;
const ll MAXN=1e18+128;
void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0){
		for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
		vv cur={1};
		while(cur.back()<MAXN)cur.pb(cur.back()*i);
		ps.pb(i);
		pot.pb(cur);
	}
}
vv byn;
ll found=0;
void anota(ll n){
	// que sean distintos los numeros
	set<ll> st;
	fore(i,0,3)fore(j,0,3)st.insert(cur[i][j]);
	if(SZ(st)<9)return;
	byn.pb(n);
	found++;
}
ll ant=0;
void f(ll ind, ll n){
	assert(ind<SZ(ps));
	ll p=ps[ind];
	if(clock()-ant>CLOCKS_PER_SEC){
		cerr<<p<<" "<<n<<": "<<found<<"\n";
		fore(i,0,3)fore(j,0,3)cout<<cur[i][j]<<" \n"[j==2];
		cout<<"\n";
		ant=clock();
	}
	xl m=n;
	ll p3=p*p*p;
	if(m*p3>=MAXN){ // no pruebes ponerlo en 0 para ningun p
		anota(n);
		return;
	}
	fore(c,0,60){
		if(m>=MAXN)break;
		for(auto w:all[c]){
			fore(i,0,3)fore(j,0,3)cur[i][j]*=pot[ind][w[i][j]];
			f(ind+1,m);
			fore(i,0,3)fore(j,0,3)cur[i][j]/=pot[ind][w[i][j]];
		}
		m*=p;
	}
}
int main(){
	JET
	init_sieve();
	gen(0,0);
	fore(i,0,3)fore(j,0,3)cur[i][j]=1;
	f(0,1);
	cerr<<"sz "<<SZ(byn)<<"\n";
	sort(ALL(byn));
	ll q; cin>>q;
	while(q--){
		ll n; cin>>n;
		cout<<upper_bound(ALL(byn),n)-byn.begin()<<"\n";
	}
	return 0;
}