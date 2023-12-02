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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vector<ll>>a(n),c(n);
		vector<ll> m(n),l(n),r(n);
		map<ll,vector<ii>>mp;
		vector<ll> sum(n);
		set<ll>val;
		ll sl=0,sr=0;
		fore(i,0,n){
			cin>>m[i]>>l[i]>>r[i];
			sl+=l[i];
			sr+=r[i];
			a[i].resize(m[i]);
			c[i].resize(m[i]);
			fore(j,0,m[i]){
				cin>>a[i][j];
				val.insert(a[i][j]);
			}
			fore(j,0,m[i]){
				cin>>c[i][j];
				sum[i]+=c[i][j];
				mp[a[i][j]].pb({c[i][j],i});
			}
		}
		ll res=-1;
		fore(v,sl,sr+1)if(!val.count(v)){
			res=0;
			//cout<<"no esta "<<v<<"\n";
			break;
		}
		if(res!=-1){
			cout<<res<<"\n";
			continue;
		}
		for(auto v:val){
			if(v<sl)continue;
			ll am=sr,resi=0;
			for(auto [q,i]:mp[v]){
				am-=r[i];
				ll u=min(r[i],sum[i]-q);
				if(u<l[i])resi+=l[i]-u,u=l[i];
				am+=u;
				//cout<<i<<" "<<u<<"\n";
			}
			if(v>am)resi+=v-am;
			//cout<<v<<": "<<am<<" "<<resi<<"\n";
			if(res==-1||resi<res)res=resi;
		}
		assert(res!=-1);
		cout<<res<<"\n";
	}
	return 0;
}
