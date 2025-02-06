#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
const ll BIAS=10;

int main(){FIN;
	ll N,V; cin>>N>>V;
	ll n=rng()%N+1;
	cout<<n<<"\n";
	string s="RULD";
	ll prev=0;
	fore(i,0,n){
		ll cur=rng()%BIAS==0;
		vv all;
		fore(i,0,4)if(i!=prev&&i!=(prev^2))all.pb(i);
		cur=all[cur];
		cout<<s[cur]<<" "<<rng()%V+1<<"\n";
		prev=cur;
	}
	return 0;
}
