#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll B=30;
unordered_map<ll,ll>dp;

ll mex(vector<ll>&a){
	ll n=SZ(a)+3;
	vector<ll>app(n);
	for(auto i:a)app[i]=1;
	fore(i,0,n)if(!app[i])return i;
	assert(0);
}

ll f(ll mk){
	if(dp.count(mk))return dp[mk];
	ll &res=dp[mk];
	if(mk<=1)return res=0;
	vector<ll>a;
	fore(k,1,B){
		ll mki=(mk&((1ll<<k)-1))|(mk>>k);
		if(mk!=mki)a.pb(f(mki));
	}
	res=mex(a);
	// cout<<"f "<<mk<<": "<<res<<"\n";
	return res;
}
vector<ii>fact(ll n){
	vector<ii>ret;
	for(ll i=2;i*i<=n;i++){
		ll c=0;
		while(n%i==0)c++,n/=i;
		if(c)ret.pb({i,c});
	}
	if(n>1)ret.pb({n,1});
	return ret;
}
int main(){
	JET
	unordered_map<ll,ll>mp;
	ll n; cin>>n;
	fore(i,0,n){
		ll x; cin>>x;
		for(auto i:fact(x)){
			mp[i.fst]|=1ll<<i.snd;
		}
	}
	ll res=0;
	for(auto i:mp){
		ll v=f(i.snd);
		res^=v;
		// cout<<i.fst<<", "<<i.snd<<": "<<v<<"\n";
	}
	// cout<<res<<" res\n";
	if(res)cout<<"Mojtaba"<<"\n";
	else cout<<"Arpa\n";
	return 0;
}

/*
f 3: 1
f 6: 2
17, 6: 2
2 res
Mojtaba




*/