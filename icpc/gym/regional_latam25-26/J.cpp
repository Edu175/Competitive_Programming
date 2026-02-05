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

int main(){FIN;
	vector<string> ps={"ha","boooo","bravo"};
	vv vals={1,-1,3};
	string s; cin>>s;
	ll res=0;
	fore(i,0,SZ(s)){
		fore(j,0,3){
			auto p=ps[j];
			if(SZ(p)>SZ(s)-i)continue;
			res+=(s.substr(i,SZ(p))==p)*vals[j];
		}
	}
	cout<<res<<"\n";
	return 0;
}