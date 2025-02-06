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
// charlestrat for the win

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		ll ls=-1,fp=-1;
		fore(i,0,n){
			if(s[i]=='s')ls=i;
			if(s[i]=='p'&&fp==-1)fp=i;
		}
		ll flag=1;
		if(fp!=-1&&ls!=-1&&(fp<ls||(ls&&fp<n-1)))cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
