#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=305;
vector<int> g[MAXN];

int mat[MAXN]; bool vis[MAXN];
int match(int x){
	if(vis[x])return 0;
	vis[x]=1;
	for(auto y:g[x])if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
	return 0;
}

ll max_matching(int n){
	mset(mat,-1);
	ll res=0;
	fore(i,0,n)mset(vis,0),res+=match(i);
	return res;
}

set<ll> operator&(set<ll>&a, set<ll>&b){
	set<ll>c;
	for(auto i:b)if(a.count(i))c.insert(i);
	return c;
}
int main(){
	ET
	ll n; cin>>n;
	map<string,ll>mp;
	vector<string>hs;
	fore(i,0,n){
		string s; cin>>s;
		mp[s]=i;
		hs.pb(s);
	}
	set<ll> st[n];
	vv fr(n);
	ll q; cin>>q;
	while(q--){
		ll m,j; cin>>m>>j; j--;
		set<ll> v;
		fore(i,0,m){
			string s; cin>>s;
			v.insert(mp[s]);
		}
		if(!SZ(st[j]))st[j]=v;
		else st[j]=st[j]&v;
		for(auto i:v)fr[i]=max(fr[i],j);
	}
	ll a[n][n];
	fore(i,0,n)fore(j,0,n)a[i][j]=1;
	fore(i,0,n){
		fore(j,fr[i],n)if(!SZ(st[j])||st[j].count(i)){
			// cout<<i<<" -> "<<j<<"\n";
			g[i].pb(j);
		}
	}
	// first set are horses
	// second set are positions
	ll mm=max_matching(n);
	// cerr<<mm<<endl;
	assert(mm==n);
	fore(i,0,n){
		ll w=mat[i];
		assert(w>=0);
		cout<<hs[w]<<" ";
		// cout<<w<<"\n";
	}
	cout<<"\n";
}