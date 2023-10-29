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

vector<ll>op;

string mod(string s, ll x){
	op.pb(x);
	string ret;
	fore(i,0,x)ret.pb(s[i]);
	ret+="01";
	fore(i,x,SZ(s))ret.pb(s[i]);
	//if(SZ(op)<10)cout<<"mod "<<s<<" "<<x<<": "<<ret<<"\n";;
	return ret;
}

ll f(string s/*, ll l*/){
	//if(SZ(op)<10)cout<<"f "<<s<<"\n";
	if(SZ(op)>300)return 0;
	fore(i,0,SZ(s)/2){
		if(s[i]!=s[SZ(s)-1-i])continue;
		if(s[i]=='0')return f(mod(s,SZ(s)-i/*,i*/));
		else return f(mod(s,i)/*,i*/);
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vector<ll>c(2);
		for(auto i:s)c[i-'0']++;
		op.clear();
		//cout<<c[0]<<" "<<c[1]<<"\n";
		if(c[0]!=c[1]||!f(s)){
			cout<<"-1\n";
		}
		else {
			cout<<SZ(op)<<"\n";
			imp(op);
		}
	}
	return 0;
}
