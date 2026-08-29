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
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n,k;
string s;

string a;
ll f(){
	if(SZ(a)==n){
		ll z=SZ(s),fg=0;
		fore(i,0,n){
			if(i+z<=n)fg|=a.substr(i,z)==s;
		}
		return fg;
	}
	ll res=0;
	fore(i,0,k){
		a.pb('a'+i);
		res+=f();
		a.pop_back();
	}
	return res;
}

int main(){FIN;
	cin>>n>>k>>s;
	cout<<f()<<"\n";
	return 0;
}
