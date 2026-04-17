#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,INF=1e18;

vv g[MAXN];
vv dfs(ll x){ // tam 3
	vector<vv> got;
	for(auto y:g[x])got.pb(dfs(y));
	ll no=0,m=SZ(got);
	vector<ii> mej;
	fore(i,0,m)no+=got[i][0],mej.pb({got[i][2]-got[i][0],i});
	sort(ALL(mej)); reverse(ALL(mej));
	if(SZ(mej)>3)mej.resize(3);
	vv res(3,-INF);
	res[0]=res[2]=no;
	if(SZ(mej)>=3){
		ll uso=-INF;
		fore(i,0,m){
			ll cur=no,cnt=0;
			fore(j,0,3)if(cnt<2){
				if(mej[j].snd!=i)cur+=mej[j].fst,cnt++;
			}
			assert(cnt==2);
			cur+=got[i][1]-got[i][0];
			uso=max(uso,cur);
		}
		uso++;
		res[0]=max(res[0],uso);
	}
	if(SZ(mej)>=2){
		ll cur=mej[0].fst+mej[1].fst+no;
		res[1]=max(res[1],cur);
	}
	return res;
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb(i);
	}
	auto res=dfs(0);
	cout<<res[2]<<"\n";
	return 0;
}