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
// rank queries

ll oper(ll a, ll b){return a+b;}
#define NEUT 0
struct STree{
	ll n; vector<ll>t;
	STree(ll n):n(n),t(2*n+5,NEUT){}
	/*void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=a[i];
		for(ll s=1ll<<(64-__builtin_clzll(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(ll i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}*/
	void upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
const ll MAXN=2e5+5;
vector<ii>qs[MAXN];
vector<ll> ans;
vector<ll> us[MAXN];
ll qidx=-1;
ll add(ll t, ll k){
	ans.pb(0); qidx++;
	qs[t].pb({k,qidx});
	return qidx;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		ll a[n];
		map<ll,ll>id;
		fore(i,0,n)cin>>a[i],id[a[i]]=-1;
		ll j=0;
		for(auto &i:id)i.snd=j++;
		fore(i,0,n)a[i]=id[a[i]];
		ll b[q];
		fore(i,0,q){
			ll k; cin>>k>>b[i]; k--; b[i]--;
			us[i].pb(add(k,a[k]+1));
			us[i].pb(add(k+1,a[k]+1));
			us[i].pb(add(n,a[k]+1));
		}
		STree st(n);
		fore(i,0,n+1){
			for(auto j:qs[i]){
				ans[j.snd]=st.query(j.fst,n);
			}
			st.upd(a[i],1);
		}
		fore(i,0,q){
			ll q0=ans[us[i][0]],q1=ans[us[i][1]],q2=ans[us[i][2]];
			ll c=q0,d=q2-q1;
			//cout<<i<<": "<<q0<<" "<<q1<<" "<<q2<<": "<<c<<" "<<d<<"\n";
			ll x=0,res=n;
			if(c>d)swap(c,d);
			x=d-b[i];
			if(x>=c)res=min(res,x);
			x=(c+d-b[i]+1)/2;
			if(x<=c)res=min(res,x);
			cout<<res<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
