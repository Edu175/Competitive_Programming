#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

string rainbow="VROYGBI";
map<char,ll>mp;

vector<ll> go(vector<ll>a, ll k){ // k is a power of 7
	ll n=SZ(a);
	vector<ll>b(n);
	fore(i,0,n)b[i]=(a[i]+a[(i-k%n+n)%n])%7;
	return b;
}

int main(){FIN;
	fore(i,0,7)mp[rainbow[i]]=i;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n){
		char c; cin>>c;
		a[i]=mp[c];
	}
	ll r; cin>>r;
	ll pot=1;
	while(r){
		fore(i,0,r%7)a=go(a,pot);
		pot*=7;
		r/=7;
	}
	fore(i,0,n)cout<<rainbow[a[i]];
	cout<<"\n";
	return 0;
}
