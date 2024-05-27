#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

string cv(ll x){
	string s=to_string(x);
	return string(2-SZ(s),'0')+s;
}

int main(){FIN;
	ll e,v; cin>>e>>v;
	ll t=(e*60)/v;
	t%=60*24;
	ll h=19,m=0;
	h+=t/60;
	h%=24;
	m+=t%60;
	cout<<cv(h)<<":"<<cv(m)<<"\n";
	return 0;
}
