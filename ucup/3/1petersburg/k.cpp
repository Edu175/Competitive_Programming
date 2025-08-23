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

ll f(string s1){
	reverse(ALL(s1));
	fore(i,0,3) s1.pop_back();
	reverse(ALL(s1));
	return stoll(s1);
}

int main(){FIN;
	string s;
	map<ll,vv> mp;
	while(getline(cin,s)){
		// cout<<SZ(s)<<endl;
		string s1 = "", aux = "";
		ll n;
		vv ss;
		int i = 0;
		while(s[i] != ':') s1.pb(s[i++]);
		i+=2;
		n = f(s1);
		while(1){
			while(i<SZ(s) && s[i]!=',')aux.pb(s[i++]);
			i+=2;
			if(SZ(aux))ss.pb(f(aux));
			else break;
			aux = "";
		}
		for(auto s1 : ss)mp[s1].pb(n);
	}
	for(auto [s1,v] : mp){
		cout<<"CS-"<<s1<<": ";
		for(auto x:v){
			cout<<"CS-"<<x;
			if(x!=v.back())cout<<", ";
		}
		cout<<"\n";
	}
	return 0;
}
