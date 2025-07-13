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
	ll n; cin>>n;
	string s; cin>>s;
	vv oc(26);
	for(auto i:s){
		if('A'<=i&&i<='Z')i-='A'-'a';
		oc[i-'a']++;
	}
	ll fg=1;
	fore(i,0,26)fg&=oc[i]>0;
	if(fg)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}