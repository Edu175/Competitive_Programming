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
typedef int ll;
typedef pair<ll,ll> ii;
const ll MOD=10007;

set<string> did,st;

void f(string s, ll k){
	if(did.count(s))return;
	did.insert(s);
	if(k==0){
		string t=s;
		reverse(ALL(t));
		if(t==s)st.insert(s);
		return;
	}
	ll n=SZ(s);
	fore(e,0,n+1){
		string l,r;
		fore(i,0,e)l.pb(s[i]);
		fore(i,e,n)r.pb(s[i]);
		l.pb('.');
		fore(j,0,26){
			l[e]='a'+j;
			f(l+r,k-1);
		}
	}
}

int main(){FIN;
	string a; cin>>a;
	ll k; cin>>k;
	ll n=SZ(a);
	f(a,k);
	cout<<SZ(st)%MOD<<"\n";
	//imp(st);
	return 0;
}
