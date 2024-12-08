#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

ll good(string &s){ // dado que s es random
	map<string,ll>mp;
	ll n=SZ(s);
	fore(i,0,n)fore(j,1,min(25ll,n-i))mp[s.substr(i,j)]++;
	// impr(mp);
	for(auto &i:mp)if(!(i.snd&1))return 0;
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll k=min(26ll,n);
		if((n+k)&1)k--;
		vv c(k);
		ll sum=0;
		fore(i,0,k){
			c[i]=n/k;
			if(c[i]%2==0)c[i]--;
			sum+=c[i];
		}
		ll r=n-sum;
		assert(!(r&1));
		// cout<<sum<<"\n";
		fore(i,0,r/2)c[i]+=2,sum+=2;
		string s;
		fore(i,0,k)s+=string(c[i],'a'+i);
		// cout<<k<<" k "<<sum<<" sum\n";;
		// imp(c)
		// cout<<s<<"\n";
		// return 0;
		while(!good(s))shuffle(ALL(s),rng);//,cout<<s<<"\n";
		cout<<s<<"\n";
	}
	return 0;
}
