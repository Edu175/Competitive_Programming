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

string a={'a'};
string f(ll x, string a){
	if(x&1)swap(a[0],a[1]),swap(a[2],a[3]);
	if(x&2)swap(a[0],a[2]),swap(a[1],a[3]);
	return a;
}
map<string,set<ll>>mp;
void solve(){
	if(SZ(a)==4){
		string s=a;
		fore(x,0,4)s=min(s,f(x,a));
		fore(x,0,4)if(f(x,s)==s)mp[s].insert(x);
	}
	else {
		fore(i,0,4){
			a.pb('a'+i);
			solve();
			a.pop_back();
		}
	}
}

int main(){FIN;
	solve();
	for(auto i:mp){
		cout<<i.fst<<": "; imp(i.snd);
	}
	return 0;
}
