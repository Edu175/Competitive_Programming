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

ll f(string s){
	ll res=0;
	fore(i,0,SZ(s)){
		if(s[i]=='1')res++,i+=2;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		ll res=0;
		fore(l,0,n)fore(r,l+1,n+1){
			string str;
			fore(i,l,r)str.pb(s[i]);
			res+=f(str);
		}
		cout<<res<<"\n";
	}
	return 0;
}
