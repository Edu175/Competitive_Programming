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
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll res=0;
		res+=s[0]=='u';
		res+=s.back()=='u';
		s[0]=s.back()='s';
		fore(i,0,SZ(s))if(s[i]=='u'){
			if(i&&s[i-1]=='u')s[i]='s',res++;
		}
		cout<<res<<"\n";
	}
	return 0;
}
