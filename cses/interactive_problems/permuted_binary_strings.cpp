#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll QUERIES=0;
string ask(string s){
	assert(++QUERIES<=10);
	cout<<"? "<<s<<endl;
	string ret; cin>>ret;
	return ret;
}

int main(){FIN;
	ll n; cin>>n;
	vv p(n);
	fore(j,0,10){
		string s(n,'.');
		fore(i,0,n)s[i]='0'+(i>>j&1);
		auto t=ask(s);
		fore(i,0,n)p[i]|=ll(t[i]-'0')<<j;
	}
	cout<<"! ";
	for(auto i:p)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}