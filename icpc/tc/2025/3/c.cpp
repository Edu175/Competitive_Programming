#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const int MAXN=8e5+5;

int tr[MAXN][26];

vector<int> ida[MAXN],idb[MAXN]; int qidx=1;
int fa[MAXN],D[MAXN];

int add(int x, char c){
	auto &res=tr[x][c-'a'];
	if(res!=-1)return res;
	res=qidx++;
	fa[res]=x;
	D[res]=D[x]+1;
	return res;
}

int main(){
	JET
	mset(tr,-1); fa[0]=-1;
	// vv a;
	// int h;
	// cout<<sizeof(a)<<"\n";
	// cout<<sizeof(h)<<"\n";
	auto add_string=[&](string s, ll idx, ll ty){
		int x=0;
		for(auto i:s)x=add(x,i);
		(ty?idb:ida)[x].pb(idx);
	};
	ll n; cin>>n;
	vector<string>a(n),b(n);
	fore(i,0,n)cin>>a[i],add_string(a[i],i,0);
	fore(i,0,n)cin>>b[i],add_string(b[i],i,1);
	ll res=0;
	vector<ii>ans;
	for(ll x=qidx-1;x>=0;x--){
		while(SZ(ida[x])&&SZ(idb[x])){
			ll i=ida[x].back(),j=idb[x].back();
			ans.pb({i,j});
			res+=D[x];
			ida[x].pop_back(),idb[x].pop_back();
			// for(ll y=x;y!=-1;y=fa[y])
			// 	ida[y].pop_back(),idb[y].pop_back();
		}
		if(SZ(ida[x])){
			assert(x);
			for(auto i:ida[x])ida[fa[x]].pb(i);
			ida[x].clear();
		}
		if(SZ(idb[x])){
			assert(x);
			for(auto i:idb[x])idb[fa[x]].pb(i);
			idb[x].clear();
		}
	}
	cout<<res<<"\n";
	
	for(auto i:ans)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	
	return 0;
}