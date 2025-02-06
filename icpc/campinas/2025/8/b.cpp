#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

void tra(string &s){
	vv to(26,-1);
	ll cnt=0;
	for(auto &i:s){
		ll &c=to[i-'A'];
		if(c==-1)c=cnt++;
		i='A'+c;
	}
}

int main(){
	JET
	ll n; cin>>n;
	map<string,ll>mp;
	ll res=0;
	fore(i,0,n){
		string s; cin>>s;
		tra(s);
		res+=mp[s]++;
	}
	cout<<res<<"\n";
	return 0;
}