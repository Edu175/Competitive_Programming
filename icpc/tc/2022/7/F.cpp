#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef __int128 ll;
typedef long long llg;
const ll MOD=1000000009;

vector<ll> fact(ll x){
	vector<ll>v;
	if(x==1)v.pb(0); 
	for(ll i=2; i*i<=x; i++){
		ll count=0;
		while(x%i==0){
			count++;
			x/=i;
		}
		if(count)v.pb(count);
	}
	if(x>1)v.pb(1);
	return v;
}

ll exp(ll a, ll e){
	ll res=1;
	if(e%2){
		res=a;
	}
	if(e>1){
		ll ab=exp(a,e/2);
		res=res*ab%MOD*ab%MOD;
	}
	res%=MOD;
	if(a==0)return 0;
	return res;
}

int main(){FIN;
	long long ki,di,mi; cin>>ki>>di>>mi;
	ll k=ki,m=mi,d=di;
	if(m==d){
		cout<<1;
		return 0;
	}
	vector<ll> cexp;
	if(m%d==0)cexp=fact(m/d);
	else {
		cout<<0;
		return 0;
	}
	//imp(cexp);
	ll res=1;
	for(auto i:cexp){
		res*=exp(i+1,k)-2*exp(i,k)%MOD+exp(i-1,k);
		//cout<<exp(i+1,k)-2*exp(i,k)%MOD+(i-1)*(i-1)<<"\n";
		//res*=exp(i+1,k-2)%MOD;
		//res%=MOD;
		//res*=4;
		res%=MOD;
		res+=MOD;
		res%=MOD;
	}
	cout<<llg(res);
	return 0;
}
