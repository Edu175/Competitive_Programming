#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=105;

vector<ii>g[MAXN];


int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	set<ll>st;
	fore(i,0,n)st.insert(i);
	priority_queue<ii>pq;
	vector<ll>d(n,-1);
	d[n-1]=0;
	pq.push({0,n-1});
	vector<string>res;
	string s(n,'1');
	vector<ll>ans;
	while(SZ(pq)&&s[0]=='1'){
		auto [ds,x]=pq.top(); pq.pop();
		ds=-ds;
		if(d[x]<ds)continue;
		res.pb(s);
		ans.pb(d[x]);
		s[x]='0';
		for(auto [y,w]:g[x]){
			ll nd=d[x]+w;
			if(d[y]==-1||nd<d[y]){
				d[y]=nd;
				pq.push({-nd,y});
			}
		}
	}
	if(d[0]==-1){
		cout<<"inf\n";
		return 0;
	}
	// res.pop_back(); d.pop_back();
	cout<<ans.back()<<" "<<SZ(ans)-1<<"\n";
	fore(i,1,SZ(res)){
		cout<<res[i]<<" "<<ans[i]-ans[i-1]<<"\n";
	}
}