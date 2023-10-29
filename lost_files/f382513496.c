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

int main(){FIN;
	string s; cin>>s;
	ll n; cin>>n;
	string t;
	fore(i,0,61)t.pb('0'+((n&(1ll<<i))!=0));
	reverse(ALL(t));
	reverse(ALL(s));
	while(SZ(s)<61)s.pb('0');
	reverse(ALL(s));
	//cout<<s<<"\n"<<t<<"\n";
	//cout<<SZ(s)<<"\n"<<SZ(t)<<"\n";
	ll p=62,q=61;
	fore(i,0,SZ(s)){
		if(p==62&&s[i]=='1'&&t[i]=='0')p=i;
		if(q==61&&s[i]=='0'&&t[i]=='1')q=i;
	}
	string res;
	ll flag=1;
	//cout<<q<<" "<<p<<"\n";
	if(p<q){
		ll u=-1;
		fore(i,0,p)if(s[i]=='?'&&t[i]=='1')u=i;
		if(u==-1){
			flag=0;
			cout<<"-1\n";
			return 0;
		}
		s[u]='0'; q=u;
	}
	fore(i,0,SZ(s)){
		char c=s[i];
		if(s[i]=='?'){
			if(i<q)c=t[i];
			else c='1';
		}
		res.pb(c);
	}
	ll x=0;
	fore(i,0,SZ(res))x+=(ll(res[i]-'0')<<(SZ(res)-1-i));
	//cout<<res<<"\n";
	cout<<x<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
