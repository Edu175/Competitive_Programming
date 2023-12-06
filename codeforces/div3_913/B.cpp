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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		vector<ll>a,b;
		fore(i,0,SZ(s)){
			if(s[i]=='b'){
				if(SZ(a))a.pop_back();
			}
			else if(s[i]=='B'){
				if(SZ(b))b.pop_back();
			}
			else if(s[i]>='a'&&s[i]<='z')a.pb(i);
			else b.pb(i);
		}
		vector<ll>c;
		for(auto i:a)c.pb(i);
		for(auto i:b)c.pb(i);
		sort(ALL(c));
		for(auto i:c)cout<<s[i];
		cout<<"\n";
	}
	return 0;
}
