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
const ll INF=1e10; 

#define oper max
#define NEUT 0
struct STree{
	int n; vector<ll>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=a[i];
		for(int s=1<<(32-__builtin_clz(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(int i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}
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
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		vector<ll>a(n);
		fore(i,0,n)a[i]=s[i]-'0';
		vector<ll>sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		vector<STree>ls(n+1,STree(n+1)),rs(n+1,STree(n+1));
		vector<ii> ch[n+1];
		fore(s,0,n)fore(e,s+1,n+1){
			ll ki=e-s-(sp[e]-sp[s]);
			ch[ki].pb({s,e});
		}
		fore(i,0,n+1){
			if(i)ls[i]=ls[i-1],rs[i]=rs[i-1];
			for(auto [s,e]:ch[i]){
				ls[i].upd(s,e-s);
				rs[i].upd(e,e-s);
			}
		}
		vector<ll> mxd(n+1);
		mxd[0]=max(ls[k].query(0,n),rs[k].query(0,n+1));
		fore(l0,1,n+1){
			ll &res=mxd[l0];
			res=-INF;
			fore(s,0,n){
				ll e=s+l0;
				if(e>n)break;
				ll ki=k-(sp[e]-sp[s]);
				if(sp[e]-sp[s]>k)continue;
				res=max({res,ls[ki].query(e,n),rs[ki].query(0,s+1)});
				//cout<<s<<","<<e<<": "<<ki<<" "<<res<<"\n";
			}
		}
		//imp(mxd);
		fore(j,1,n+1){
			ll res=0;
			fore(l0,0,n+1)res=max(res,l0*j+mxd[l0]);
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
