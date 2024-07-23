#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ii NEUT={1e16,0};
ii oper(ii a, ii b){
	return(ii({min(a.fst,b.fst),max(a.snd,b.snd)}));
}
bool can(ii a){
	return a.fst==a.snd;
}
struct STree{
	ll n; vector<ii>t;
	STree(ll n):n(n),t(2*n+5,NEUT){}
	void upd(ll p, ii v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ii query(ll l, ll r){
		ii res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
int main(){
	JET
	string s; cin>>s;
	STree ST(SZ(s));
	fore(i,0,SZ(s)){
		ST.upd(i,ii({s[i],s[i]}));
	}
	int q; cin>>q;
	fore(i,0,q){
		ll l,r;
		cin>>l>>r; l--;
		if(can(ST.query(l,r)) && l!=r-1)cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}

