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
const ll MAXN=1e5+5;
struct Trie{
	ll tr[MAXN][26],qidx;
	Trie(){mset(tr,-1);qidx=0;}
	ll add(ll x, char c){
		auto &res=tr[x][c-'a'];
		if(res!=-1)return res;
		return res=++qidx;
	}
	void add_string(string s){
		ll x=0;
		for(auto c:s)x=add(x,c);
	}
	bool query(string s){
		ll x=0;
		for(auto c:s){
			x=tr[x][c-'a'];
			if(x==-1)return 0;
		}
		return 1;
	}
};

int main(){FIN;
	ll q; cin>>q;
	Trie nor,rev;
	ll wh=0;
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			string s; cin>>s;
			(wh?rev:nor).add_string(s);
			reverse(ALL(s));
			(wh?nor:rev).add_string(s);
		}
		if(ty==2){
			string s; cin>>s;
			cout<<(wh?rev:nor).query(s)<<"\n";
		}
		if(ty==3)wh^=1;
	}
	return 0;
}
