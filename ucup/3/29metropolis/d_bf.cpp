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

bool good(vv s){
	if(!s.back()&&!s.end()[-2])return 1;
	return 0;
}

ll n;
set<vv> vis;
bool flag=0;
void dfs(vv s){
	if(good(s)){flag=1;return;}
	if(vis.count(s))return;
	vis.insert(s);
	fore(i,0,n)if((s[i]&1)&&i+2<n){ // solo swap
		auto si=s;
		swap(si[i+1],si[i+2]);
		si[i]^=2;
		dfs(si);
		if(flag)return;
	}
	fore(i,0,n)if((s[i]&1)&&i+2<n){ // mato s[i]
		auto si=s;
		if(si[i]&2)swap(si[i+1],si[i+2]);
		si[i]=0;
		dfs(si);
		if(flag)return;		
	}
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		string s; cin>>s;
		flag=0;
		vis.clear();
		vv a;
		fore(i,0,n)a.pb(s[i]-'0');
		dfs(a);
		if(flag)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
