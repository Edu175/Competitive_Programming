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

string encode(ll x){
	string r;
	while(x>0)r.pb('a'+x%25),x/=25;
	return r;
}

ll decode(string s){
	ll x=0;
	reverse(ALL(s));
	for(auto i:s)x=x*25+i-'a';
	return x;
}

void first(){
	ll n; cin>>n;
	vv a(n);
	string s;
	fore(i,0,n)cin>>a[i],s+=encode(a[i])+"z";
	cout<<s<<"\n";
}
void second(){
	string s; cin>>s;
	vv a;
	string tmp;
	for(auto i:s){
		if(i=='z'){
			a.pb(decode(tmp));
			tmp.clear();
		}
		else tmp.pb(i);
	}
	ll n=SZ(a);
	cout<<n<<"\n";
	imp(a);
}
int main(){FIN;
	string ty; cin>>ty;
	if(ty=="first")first();
	else second();
	return 0;
}
