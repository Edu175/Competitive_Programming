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
	string s; cin>>s;
	ll n=SZ(s);
	set<string>st;
	fore(i,0,n)fore(j,i+1,n+1){
		string h;
		fore(k,i,j)h.pb(s[k]);
		st.insert(h);
	}
	cout<<SZ(st)<<"\n";
	return 0;
}
