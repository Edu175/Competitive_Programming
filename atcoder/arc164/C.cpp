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
const ll INF=1e16;

#define oper max
ii NEUT ={-INF,-1};
struct STree{
	int n; vector<ii>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	/*void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=a[i];
		for(int s=1<<(32-__builtin_clz(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(int i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}*/
	void upd(int p, ii v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ii query(int l, int r){
		ii res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll n; cin>>n;
	ll a[n][2];
	fore(i,0,n)cin>>a[i][0]>>a[i][1];
	ll s[n]={};
	ll res=0;
	STree st(n);
	fore(i,0,n)st.upd(i,{a[i][0]-a[i][1],i});
	fore(i,0,n){
		ii x=st.query(0,n);
		st.upd(x.snd,{-x.fst,x.snd}),s[x.snd]^=1;
		x=st.query(0,n);
		//cout<<x.fst<<","<<x.snd<<endl;
		res+=a[x.snd][s[x.snd]];
		st.upd(x.snd,NEUT);
	}
	cout<<res<<"\n";
	return 0;
}
