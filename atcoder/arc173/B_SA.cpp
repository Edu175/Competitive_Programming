#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
string cv(ii i){return to_string(i.fst)+","+to_string(i.snd);}
ii pen(ii a, ii b){
	ii r={b.snd-a.snd,b.fst-a.fst};
	ll g=gcd(r.fst,r.snd);
	r.fst/=g,r.snd/=g;
	if(r.snd<0)r.snd*=-1,r.fst*=-1;
	if(r.snd==0)r.fst=abs(r.fst);
	// cout<<"pen "<<cv(a)<<" "<<cv(b)<<": "<<cv(r)<<"\n";
	return r;
}
const ll MAXN=305;
ii a[MAXN];
bool col[MAXN][MAXN][MAXN];
ll s[MAXN];
set<ll>h[MAXN];
ll n;
ll r=0;
bool cost(ll i){
	if(i>=n/3)return 0;
	return col[*h[i].begin()][*next(h[i].begin())][*next(next(h[i].begin()))];
}
void change(ll i, ll j){
	r-=cost(s[i])+cost(s[j]);
	h[s[i]].erase(i); h[s[j]].erase(j);
	swap(s[i],s[j]);
	h[s[i]].insert(i); h[s[j]].insert(j);
	r+=cost(s[i])+cost(s[j]);
}
ll SA(){
	fore(i,0,n)s[i]=i/3;
	srand(175);
	random_shuffle(s,s+n);
	fore(i,0,n)h[s[i]].insert(i);
	fore(i,0,n/3)r+=cost(i);
	ll best=r;
	double t=1e5;
	while(clock()<=1.9*CLOCKS_PER_SEC){
		ll i=rand()%n,j=rand()%n;
		ll _r=r;
		change(i,j);
		if(r<best)best=r;
		if(!(r<_r||exp((_r-r)/t)>=(double)rand()/RAND_MAX))change(i,j);
		t*=0.99999;
	}
	cerr<<t<<"\n";
	return n/3-best;
}
const ll MOD=269979449;
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
ii rec(ii a, ii b){
	ii r=pen(a,b);
	ll m=(r.fst+MOD)%MOD*fpow(r.snd,MOD-2)%MOD;
	ll c=(a.snd-m*a.fst%MOD+MOD)%MOD;
	if(r.snd==0)c=MOD+a.fst;
	return {m,c};
}
int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	fore(i,0,n)fore(j,0,n)if(i!=j)fore(k,0,n)if(k!=i&&k!=j){
		col[i][j][k]=pen(a[i],a[j])==pen(a[j],a[k]);
		//cout<<i<<" "<<j<<" "<<k<<": "<<col[i][j][k]<<"\n";
	}
	map<ii,set<ll>>mp;
	ll c=0;
	fore(i,0,n)fore(j,0,n)if(i!=j){
		mp[rec(a[i],a[j])].insert(i);
	}
	for(auto i:mp)c=max(c,(ll)SZ(i.snd));
	ll res=n/3;
	if(c/2>n-c)res=n-c;
	res=min(res,SA());
	cout<<res<<"\n";
	return 0;
}
