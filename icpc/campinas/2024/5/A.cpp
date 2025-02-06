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

typedef ll node;
#define oper min
#define NEUT 1e15
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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
	ll n; cin>>n;
	vector<ii> a(n);
	vector<ll> ais(n);
	ll sum=0;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd,sum+=a[i].snd;
	sort(ALL(a));
	fore(i,0,n)ais[i]=a[i].fst;
	STree goc(n),goa(n);
	ll res=0;
	for(ll i=n-1;i>=0;i--){
		ll p=lower_bound(ALL(ais),a[i].fst+a[i].snd+1)-ais.begin();
		res=min(goc.query(i+1,p),goa.query(p,n)-a[i].fst-a[i].snd);
		if(i==n-1)res=0;
		goa.upd(i,res+a[i].fst);
		goc.upd(i,res);
		//cout<<i<<": "<<a[i].fst<<","<<a[i].snd<<": "<<res<<"\n";
	}
	//cout<<sum<<"\n";
	cout<<res+sum<<"\n";
	return 0;
}
