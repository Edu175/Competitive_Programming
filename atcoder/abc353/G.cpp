#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef ll node;
const ll INF=3e18;
#define oper max
#define NEUT -INF
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
//		cout<<"upd "<<p<<" "<<v<<"\n";
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
	ll n,c; cin>>n>>c;
	ll m; cin>>m;
	vector<ii>a(m+1);
	a[0]={0,0};
	fore(i,1,m+1)cin>>a[i].fst>>a[i].snd,a[i].fst--;
	STree men(n),may(n);
	ll res=0;
	for(ll i=m;i>=0;i--){
		res=a[i].snd;
		ll go0=men.query(0,a[i].fst)-c*a[i].fst,
		   go1=may.query(a[i].fst,n)+c*a[i].fst;
		res+=max({go0,go1,(ll)0});
		men.upd(a[i].fst,c*a[i].fst+res);
		may.upd(a[i].fst,-c*a[i].fst+res);
//		cout<<i<<" "<<a[i].fst<<","<<a[i].snd<<": "<<go0<<" "<<go1<<": "<<res-a[i].snd<<" +"<<a[i].snd<<" = "<<res<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
