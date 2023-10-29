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
const ll MAXN=2e5+5,K=20;//K such that 2^k>n
#define oper max
ll st[K][1ll<<K];ll n;
void st_init(ll *a){
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(ll s,ll e){
	ll k=63-__builtin_clzll(e-s);
	return oper(st[k][s],st[k][e-(1ll<<k)]);
}
map<ll,vector<ll>>pos;
set<ll>res;
ll a[MAXN];
void f(ll l, ll r){
	if(r-l<2)return;
	ll m=st_query(l,r);
	ll s=lower_bound(ALL(pos[m]),l)-pos[m].begin();
	ll e=lower_bound(ALL(pos[m]),r)-pos[m].begin();
	if(e-s>1){
		res.insert(0);
		vector<ll>v;
		v.pb(l-1);
		fore(i,s,e)v.pb(pos[m][i]);
		v.pb(r);
		fore(i,1,SZ(v)-1)f(v[i-1]+1,v[i+1]);
		return;
	}
	ll p=pos[m][s];
	//cout<<l<<" "<<r<<" | "<<s<<" "<<e<<" "<<p<<" "<<m<<"\n";
	fore(i,p+1,r)res.insert(a[p]-st_query(p+1,i+1));
	fore(i,l,p)res.insert(a[p]-st_query(i,p));
	f(l,p),f(p+1,r);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		if(n<1.5e5){
			pos.clear(); res.clear();
			fore(i,0,n)cin>>a[i],pos[a[i]].pb(i);
			//for(auto i:pos){cout<<i.fst<<": ";imp(i.snd);}
			st_init(a);
			f(0,n);
			cout<<SZ(res)<<"\n";
			continue;	
		}
		ll ar[n];
		res.clear();
		set<ll>st;
		fore(i,0,n)cin>>a[i],ar[i]=a[i],st.insert(a[i]);
		if(SZ(st)<n)res.insert(0);
		reverse(ar,ar+n);
		ll l[n],r[n];
		fore(i,0,n){
			r[i]=lower_bound(a+i+1,a+n,a[i])-a;
			l[i]=n-1-(lower_bound(ar+n-i,ar+n,a[i])-ar);
		}
		//imp(l);
		//imp(r);
		fore(i,0,n){
			for(ll j=i-1;j>=0&&a[j]<a[i];j=l[j]){
				res.insert(a[i]-a[j]);
			}
			for(ll j=i+1;j<n&&a[j]<a[i];j=r[j]){
				res.insert(a[i]-a[j]);
			}
		}
		cout<<SZ(res)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
