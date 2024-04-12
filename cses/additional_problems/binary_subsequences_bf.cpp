#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

string bin(ll x, ll k){
	string s;
	while(k--)s.pb('0'+(x&1)),x/=2;
	return s;
}

vector<string> get_all(string x){
	set<string>st;
	fore(mk,1,1ll<<SZ(x)){
		string s;
		fore(i,0,SZ(x))if((mk>>i)&1)s.pb(x[i]);
		st.insert(s);
	}
	vector<string>r;
	for(auto i:st)r.pb(i);
	return r;
}
ll get_all_sz(string x){
	set<string>st;
	fore(mk,1,1ll<<SZ(x)){
		string s;
		fore(i,0,SZ(x))if((mk>>i)&1)s.pb(x[i]);
		st.insert(s);
	}
	return SZ(st);
}

vector<string> find(ll n){
	ll k=1;
	while(1){
		vector<string>r;
		fore(x,0,1ll<<k){
			if(get_all_sz(bin(x,k))==n)r.pb(bin(x,k));
		}
		if(SZ(r))return r;
		k++;
	}
}

int main(){FIN;
	ll n; cin>>n;
	for(auto i:find(n)){
		cout<<i<<"\n";
	}
	cout<<"\n";
	for(auto i:get_all(find(n)[0]))cout<<i<<"\n";
	return 0;
}
