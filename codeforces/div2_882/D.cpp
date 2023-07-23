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

ll oper(ll a, ll b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<ll>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	/*void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=a[i];
		for(int s=1<<(32-__builtin_clz(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(int i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}*/
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(int l, int r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	string s; cin>>s;
	ll a[n],c=0;
	fore(i,0,n)a[i]=s[i]-'0',c+=a[i];
	vector<ll>p;
	set<ll>pos;
	fore(i,0,n)pos.insert(i);
	fore(i,0,m){
		ll l,r; cin>>l>>r; l--;
		vector<ll>del;
		for(auto it=pos.lower_bound(l);it!=pos.end()&&*it<r;it++)
			p.pb(*it),del.pb(*it);
		for(auto i:del)pos.erase(i);
		del.clear();
	}
	//imp(p);
	vector<ll>id(n,-1);
	fore(i,0,SZ(p))id[p[i]]=i;
	//imp(id);
	STree st(SZ(p));
	fore(i,0,n){
		if(id[i]!=-1)st.upd(id[i],a[i]);
	}
	while(q--){
		ll x; cin>>x; x--;
		if(a[x])c--,a[x]=0;
		else c++,a[x]=1;
		if(id[x]!=-1)st.upd(id[x],a[x]);
		ll res=min((ll)SZ(p),c)-st.query(0,min((ll)SZ(p),c));
		//cout<<x<<" "<<c<<": "<<min((ll)SZ(p),c)<<"-"<<st.query(0,min((ll)SZ(p),c))<<": "<<min((ll)SZ(p),c)-st.query(0,min((ll)SZ(p),c))<<"\n";
		//fore(i,0,SZ(p))cout<<st.query(i,i+1)<<" ";
		//cout<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
