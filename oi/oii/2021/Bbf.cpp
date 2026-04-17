#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkjgh:v)cout<<dkjgh<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=4e6+5;

ll ans[MAXN];
vector<ll> pr[MAXN];
void init_sieve(){
	fore(i,2,MAXN)if(!SZ(pr[i]))for(ll j=i;j<MAXN;j+=i)pr[j].pb(i);
}
ll n;
vector<ll>p,a,b,c;
ll res=0;
void num(ll x, ll y){
	ll resi=0,ig=0;
	
}
void f(ll x, ll y, ll w, ll j){
	if(j==SZ(p)){num(x,y);return;}
	if(j==SZ(p))w=1,j=0;
	if(!w){
		fore(i,0,c[j]+1){
			if(x>n)break;
			a.pb(i);
			f(x,y,w,j+1);
			a.pop_back();
			x*=p[j];
		}
	}
	else {
		fore(i,0,c[j]+1){
			if(y>n||min(c[j],a[j])+min(c[j],i)>c[j])break;
			b.pb(i);
			f(x,y,w,j+1);
			b.pop_back();
			y*=p[j];
		}
	}
}

int main(){FIN;
	mset(ans,-1);
	init_sieve();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll &res=ans[n];
		if(res!=-1){
			cout<<res<<"\n";
			continue;
		}
		p=pr[n];
		c.resize(SZ(p));
		ll ni=n;
		fore(i,0,SZ(p))while(ni%p[i]==0){c[i]++;ni/=p[i];}
		res=0;
		f(1,1,0,0);
		cout<<res<<"\n";
	}
	return 0;
}
