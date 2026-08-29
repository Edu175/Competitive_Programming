#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
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
		vector<char> ty(n);
		vv a(n);
		fore(i,0,n){
			cin>>ty[i]>>a[i];
			if(ty[i]=='p')a[i]--;
		}
		vv vis(n);
		fore(i,0,n)if(ty[i]=='p')vis[a[i]]=1;
		vv lib;
		fore(i,0,n)if(!vis[i])lib.pb(i);
		// cerr<<"lib: "<<lib<<"\n";
		vv p(n,-1);
		STree st(n);
		fore(i,0,n)st.upd(i,1);
		auto cuan=[&](vv ind, ll u){
			ll ret=ind.back()?a[ind.back()-1]:0;
			// cerr<<"ret "<<ret<<"\n";
			ll k=SZ(ind);
			vv vals(k);
			vals[0]=u;
			fore(i,1,k)vals[i]=a[ind[i]];
			fore(i,0,k){
				ll v=vals[i];
				st.upd(v,-1);
				ll cur=st.query(v+1,n);
				// cerr<<v<<": "<<cur<<"\n";
				ret+=cur;
			}
			for(auto v:vals)st.upd(v,1);
			return ret;
		};
		auto det=[&](vv ind){
			for(auto i:ind)if(ty[i]=='p')p[i]=a[i];
			ll s=ind[0];
			if(ty[s]=='p'){
				for(auto i:ind){
					assert(st.query(p[i],p[i]+1)==1);
					st.upd(p[i],-1);
				}
				return;
			}
			// cerr<<"det "<<ind<<":\n";
			// fore(i,0,n)cerr<<st.t[i+n]<<" ";;cerr<<"\n";
			ll l=-1,r=SZ(lib);
			while(r-l>1){
				ll m=(l+r)/2;
				if(cuan(ind,lib[m])<=a[s])r=m;
				else l=m;
			}
			ll u=lib[r];
			// cerr<<a[s]<<" a[s]\n";
			// cerr<<"cuan "<<u<<": "<<cuan(ind,u)<<"\n";
			// cerr<<"cuan "<<u-1<<": "<<cuan(ind,u-1)<<"\n";
			// cerr<<"= "<<u<<"\n\n";
			assert(cuan(ind,u)==a[s]);
			p[s]=u;
			for(auto i:ind){
				assert(st.query(p[i],p[i]+1)==1);
				st.upd(p[i],-1);
			}
		};
		vv bl;
		for(ll i=n-1;i>=0;i--){
			bl.pb(i);
			if(!i||ty[i-1]=='s'){
				det(bl);
				bl.clear();
			}
		}
		for(auto i:p)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
