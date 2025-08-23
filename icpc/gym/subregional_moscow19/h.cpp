#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,0),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
};

int main(){
    JET
	ll n,q; cin>>n>>q;
	set<ll>ab,ce;
	string s; cin>>s;
	vv a(n);
	fore(i,0,SZ(s)){
		if(s[i]=='('){
			ab.insert(i);
			a[i]=0;
		}
		else {
			ce.insert(i);
			a[i]=1;
		}
	}
	STree st(n);
	fore(i,0,n)st.upd(i,a[i]);
	auto cambio=[&](ll i){
		if(a[i])ce.erase(i),ab.insert(i);
		else ab.erase(i),ce.insert(i);
	};
	while(q--){
		ll i,j; cin>>i>>j; i--,j--;
		if(a[i]!=a[j]){
			cambio(i);
			cambio(j);
			
			swap(a[i],a[j]);
			
			st.upd(i,a[i]);
			st.upd(j,a[j]);
		}
		ll k=*ce.begin(),r=*prev(ab.end());
		ll cant=st.query(k,r);
		if(cant>=k+2)cout<<"Yes\n";
		else cout<<"No\n";
	}
    return 0;
}