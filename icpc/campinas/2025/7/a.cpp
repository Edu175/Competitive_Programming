#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<ii> rans={{0,n}};
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		if(u>v)swap(u,v);
		rans.pb({u,v});
	}
	m++;
	vv h(n+1,-1);
	sort(ALL(rans),[&](ii a, ii b){
			return a.snd-a.fst<b.snd-b.fst;});
	fore(i,0,SZ(rans))h[rans[i].snd]=i;
	set<ii>st;
	vector<vv> dp(n,vv(2));
	vector<vv>g;
	vector<vector<vv>>sub;
	vv sums;
	fore(i,0,SZ(rans)){
		auto [s,e]=rans[i];
		vv nod;
		// cout<<i<<": "<<rans[i].fst<<","<<rans[i].snd<<": ";
		for(auto it=st.lower_bound({s,-1});it!=st.end()&&it->fst<e;it=st.erase(it))nod.pb(h[it->snd]);
		g.pb(nod);
		ll m=SZ(nod);
		// for(auto y:nod)cout<<rans[y].fst<<","<<rans[y].snd<<" ";
		// cout<<"| ";
		ll sum=e-s;
		for(auto y:nod)sum-=rans[y].snd-rans[y].fst;
		sum=sum&1;
		sums.pb(sum);
		vector<vv> dp2(m+1,vv(2));
		dp2[m][1]=1; // o INF?
		for(ll i=m-1;i>=0;i--)fore(od,0,2){
			auto &res=dp2[i][od];
			ll go0=dp2[i+1][od]+dp[nod[i]][0];
			ll go1=dp2[i+1][od^1]+dp[nod[i]][1];
			res=min(go0,go1);
		}
		fore(od,0,2)dp[i][od]=dp2[0][sum^od]+!od;
		// cout<<sum<<": "<<dp[i][0]<<" "<<dp[i][1]<<"\n";
		sub.pb(dp2);
		st.insert({rans[i]});
	}
	
	vv ele(m),col(m);
	auto build=[&](ll x){
		// cout<<"build "<<x<<": ";
		// cout<<col[x]<<" "<<ele[x]<<endl;
		auto nod=g[x];
		ll m=SZ(nod);
		auto dp2=sub[x];
		auto sum=sums[x];
		ll od=ele[x],color=col[x];
		od^=sum;
		// auto ans=dp[x][od]-!ele[x];
		fore(i,0,m){
			auto &res=dp2[i][od];
			auto y=nod[i];
			ll dif=rans[y].fst-(i?rans[nod[i-1]].snd:rans[x].fst);
			color^=dif&1;
			col[y]=color;
			ll go0=dp2[i+1][od]+dp[y][0];
			ll go1=dp2[i+1][od^1]+dp[y][1];
			// cout<<i<<": "<<res<<": "<<go0<<" "<<go1<<endl;
			if(res==go0){
				ele[y]=0;
			}
			else {
				assert(res==go1);
				ele[y]=1;
				color^=1;
				od^=1;
			}
			res=min(go0,go1);
		}
	};
	ll x=m-1;
	ll res=dp[x][0]-1;
	ele[x]=0; col[x]=0;
	for(ll i=m-1;i>=0;i--)build(i);
	vv ans(n,-1);
	fore(i,0,m){
		ans[rans[i].fst]=col[i];
		ans[(rans[i].snd)%n]=col[i]^ele[i];
	}
	fore(i,1,n)if(ans[i]==-1)ans[i]=ans[i-1]^1;
	ll my=0;
	fore(i,0,m){
		auto [s,e]=rans[i];
		my+=ans[s]==ans[e%n];
		assert((ans[s]!=ans[(e)%n])==(ele[i]));
	} my--;
	cout<<res<<"\n";
	for(auto i:ans)cout<<i<<" ";;cout<<"\n";
	// cout<<endl;
	fore(i,0,n)my+=ans[i]==ans[(i+1)%n],assert(ans[i]==0||ans[i]==1);
	// cerr<<my<<" my"<<endl;
	assert(my==res);
	return 0;
}
/*
6 1
2 3

0
0 1 2 3 2 3 

a: a.cpp:112: int main(): Assertion `ans[i]==0||ans[i]==1' failed.


*/