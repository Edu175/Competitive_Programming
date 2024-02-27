#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto skjdhf:v)cout<<skjdhf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")

set<ll>did;
vector<ll> divs(ll n){
	if(did.count(n))return {};
	vector<ll> ret;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0)ret.pb(i),ret.pb(n/i),did.insert(i),did.insert(n/i);
		if(i*i==n)ret.pop_back();
	}
	return ret;
}
ll P=110;
ll n,mx,C;
bool pasa(ll l){
	return (n>3*((mx+l-1)/l)||l>=C);
}
int main(){FIN;
	ll sd; srand(15645);
	cin>>n;
	vector<ll>a;
	set<ll>st;
	fore(i,0,n){
		ll x; cin>>x;
		if(!st.count(x))a.pb(x);
		st.insert(x);
	}
	n=SZ(a);
	C=*st.begin()/4+1;
	//cout<<C<<"\n";
	if(n<=3){
		cout<<C*(C-1)/2<<"\n";
		return 0;
	}
	random_shuffle(ALL(a));
	ll res=0;
	mx=*prev(st.end());
	set<ll>can;
	if(n<P){
		fore(i,0,n)fore(j,i+1,n)
			for(auto d:divs(abs(a[i]-a[j])))if(!pasa(d))can.insert(d);
		for(auto l:can){
			set<ll>st;
			fore(i,0,n){
				st.insert(a[i]%l);
				if(SZ(st)>3)break;
			}
			if(SZ(st)<=3)res+=l;
		}
		cout<<res<<"\n";
	}
	else{
		fore(l,1,C){
			if(pasa(l))break;
			set<ll>st;
			fore(i,0,n){
				st.insert(a[i]%l);
				if(SZ(st)>3)break;
			}
			if(SZ(st)<=3)res+=l;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
