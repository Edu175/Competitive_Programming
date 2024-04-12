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
const ll MAXN=305,MAXK=90005;

ll n;
vector<ll> g[MAXN];
ll mat[MAXN],us[MAXN];

bool match(ll x){
	if(us[x])return 0;
	us[x]=1;
	for(auto y:g[x]){
		if(mat[y]==-1||match(mat[y])){
			mat[y]=x; return 1;
		}
	}
	return 0;
}

ll max_matching(){
	mset(mat,-1);
	ll res=0;
	fore(i,0,n){
		mset(us,0);
		if(match(i))res++;
	}
	return res;
}

bool leq(set<ll>&a, set<ll>&b){
	for(auto i:a)if(!b.count(i))return 0;
	return 1;
}

int main(){FIN;
	cin>>n;
	vector<vector<string>>a(n);
	map<string,ll>mp;
	fore(i,0,n){
		ll m; cin>>m;
		a[i].resize(m);
		fore(j,0,m)cin>>a[i][j],mp[a[i][j]]=-1;
	}
	ll k=0;
	for(auto &i:mp)i.snd=k++;
	vector<set<ll>>b(n);
	fore(i,0,n)fore(j,0,SZ(a[i]))b[i].insert(mp[a[i][j]]);
	fore(i,0,n)fore(j,0,n){
		if(b[i]==b[j]&&!(i<j))continue;
		if(leq(b[i],b[j]))g[i].pb(j);
	}
	ll res=n-max_matching();
	cout<<res<<"\n";
	return 0;
}
