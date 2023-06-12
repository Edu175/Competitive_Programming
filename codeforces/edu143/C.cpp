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
ll oper(ll a, ll b){return a+b;}
#define NEUT 0
struct STree{
	ll n; vector<ll>t;
	STree(ll n):n(n),t(2*n+5,NEUT){}
	void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=a[i];
		for(ll s=1ll<<(64-__builtin_clzll(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(ll i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vector<ll> sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+b[i-1];
		vector<pair<ll,ll>> p,q;
		fore(i,0,n){
			ll lwb=lower_bound(ALL(sp),a[i]+sp[i])-sp.begin();
			lwb--;
			p.pb({lwb,a[i]-(sp[lwb]-sp[i])});
			q.pb({lwb,i});
			//cout<<i<<": "<<p[i].fst<<","<<p[i].snd<<"\n";
		}
		sort(ALL(q));
		vector<ll>id(n),fo(n+1,-1),s(n+1);
		ll j=0;
		fore(i,0,n){
			//cout<<q[i].fst<<","<<q[i].snd<<" ";
			id[q[i].snd]=i;
			s[q[i].fst]+=p[q[i].snd].snd;
			fore(h,j,q[i].fst+1)fo[h]=i;
			j=q[i].fst+1;
		}
		fore(h,j,n+1)fo[h]=n;
		/*cout<<"\n";
		imp(id);
		imp(fo);
		imp(s);*/
		STree st(n);
		vector<ll>res(n);
		fore(i,0,n){
			st.upd(id[i],1);
			ll l=st.query(0,fo[i]);
			ll r=st.query(0,fo[i+1]);
			res[i]+=b[i]*(i+1-r);
			//cout<<i<<": "<<l<<","<<r<<" "<<res[i]<<" ";
			res[i]+=s[i];
			//cout<<res[i]<<"\n";
		}
		imp(res);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
