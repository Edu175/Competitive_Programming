#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" ";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

set<ll> encode(set<ll>s, ll n){
	set<ll>r;
	ll c=0;
	fore(i,0,n){
		if(s.count(i))c++;
		else {
			if(c)r.insert(i),c--;
			else {
				auto lwb=s.lower_bound(i);
				if(lwb==s.end())break;
				else i=*lwb-1;
			}
		}
	}
	fore(i,0,n){
		if(!c)break;
		if(r.count(i)||s.count(i))continue;
		r.insert(i),c--;
	}
	//cout<<"encode "; imp(s); cout<<"--> "; imp(r); cout<<"\n";
	return r;
}

set<ll> rev(set<ll>s, ll n){
	set<ll>st;
	for(auto i:s)st.insert(n-1-i);
	return st;
}

set<ll> decode(set<ll>s, ll n){
	return rev(encode(rev(s,n),n),n);
}

int main(){FIN;
	ll r,q; cin>>r>>q;
	while(q--){
		ll n,k; cin>>n>>k;
		set<ll>s;
		fore(i,0,k){
			ll x; cin>>x; x--;
			s.insert(x);
		}
		set<ll>ret;
		if(r==1)ret=encode(s,n);
		else ret=decode(s,n);
		ll j=0;
		for(auto i:ret){
			if(j)cout<<" ";
			cout<<i+1;
			j++;
		}
		cout<<"\n";
	}
	return 0;
}
