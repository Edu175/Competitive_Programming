#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;


string go(string s, ll k){
	vector<ii>r;
	ll l=0;
	fore(i,0,SZ(s)){
		if(i==SZ(s)-1||s[i]!=s[i+1]){
			r.pb({l,i+1});
			l=i+1;
		}
	}
	if(k>=SZ(r)-1)return "";
	swap(r[k],r[k+1]);
	string a;
	for(auto [l,e]:r)a+=s.substr(l,e-l);
	return a;
}

ll bfs(string s, string to){
	if(s==to)return 0;
	set<string>vis;
	queue<pair<ll,string>>q;
	q.push({0,s}); vis.insert(s);
	while(SZ(q)){
		auto [d,s]=q.front(); q.pop();
		ll i=0;
		while(1){
			auto y=go(s,i++);
			if(!SZ(y))break;
			if(vis.count(y))continue;
			vis.insert(y);
			q.push({d+1,y});
			if(y==to)return d+1;
		}
	}
	return -1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string a,b; cin>>a>>b;
		cout<<bfs(a,b)<<"\n";
	}
	return 0;
}
