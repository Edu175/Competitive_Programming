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


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n<26){
			fore(i,0,n)cout<<char('a'+i);
			cout<<"\n";
			continue;
		}
		ll k=n/2;
		string s=string(k-1,'b')+"a"+string(k,'b');
		if(SZ(s)<n)s.pb('c');
		cout<<s<<"\n";
	}
	return 0;
}
