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

int main(){FIN;
	ll t; cin>>t;
	fore(__,0,t){
		cout<<"Case #"<<__+1<<": ";
		ll n,k,m; cin>>n>>k>>m;
		vector<set<ll>> sts(m);
		vector<vv> a(m);
		vector<vector<ii>> pos(n);
		fore(i,0,m){
			ll li; cin>>li;
			a[i].resize(li);
			fore(j,0,SZ(a[i])){
				ll x; cin>>x; x--;
				a[i][j]=x;
				pos[x].pb({i,j});
				sts[i].insert(j);
			}
		}
		vv d(n,-1);
		auto visit=[&](ll x){
			for(auto [i,j]:pos[x])sts[i].erase(j);
		};
		queue<ll> q;
		d[0]=0; visit(0); q.push(0);
		while(SZ(q)){
			auto x=q.front(); q.pop();
			for(auto [i,j]:pos[x]){
				auto &st=sts[i];
				// cout<<x<<": "<<i<<","<<j<<": ";
				// imp(st)
				// imp(a[i])
				// cout<<endl;
				vv out;
				for(auto it=st.lower_bound(j);it!=st.end()&&*it-j<=k;it++){
					ll y=a[i][*it];
					if(d[y]!=-1)continue;
					assert(d[y]==-1);
					d[y]=d[x]+1;
					out.pb(y);
					// visit(y);
					q.push(y);
				}
				for(auto i:out)visit(i);
			}
		}
		ll sum=0;
		fore(i,0,n)sum+=d[i]*(i+1);
		// fore(i,0,n)cerr<<d[i]<<" ";;cerr<<"\n";
		cout<<sum<<"\n";
	}
	return 0;
}
