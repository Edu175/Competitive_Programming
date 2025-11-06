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

ll n,m;
vv used;

bool can(vector<vv> a, ll w){
	vv mn(n);
	vector<vv> pos(n,vv(m));
	fore(i,0,n){
		fore(j,0,SZ(a[i]))pos[i][a[i][j]]=j;
	}
	fore(i,0,n)mn[i]=pos[i][w];
	vv cant(m);
	fore(x,0,m)if(!used[x]&&x!=w){
		fore(i,0,n)cant[x]+=pos[i][x]<mn[i];
	}
	vv vis(m);
	vis[w]=1;
	while(1){
		ll did=0;
		fore(x,0,m)if(!used[x]&&!vis[x]&&cant[x]<=n/2){
			vis[x]=1;
			fore(i,0,n){
				ll &j=mn[i],t=pos[i][x];
				while(t<j)cant[a[i][--j]]--;
			}
			did=1;
		}
		if(!did)break;
	}
	fore(i,0,m)if(!vis[i]&&!used[i])return 0;
	return 1;
}

vector<vv> saca(vector<vv> a, ll x){
	fore(i,0,SZ(a)){
		auto &v=a[i];
		v.erase(find(ALL(v),x));
	}
	return a;
}

int main(){
	JET
	cin>>m>>n;
	vector<string> pals;
	vector<vector<string>> _a(n,vector<string>(m)); 
	fore(i,0,n){
		fore(j,0,m){
			string x; cin>>x;
			_a[i][j]=x;
			if(!i)pals.pb(x);
		}
	}
	sort(ALL(pals));
	auto get_idx=[&](string s){return lower_bound(ALL(pals),s)-pals.begin();};
	string _s; cin>>_s;
	ll w=get_idx(_s);
	vector<vv> a(n,vv(m));
	fore(i,0,n)fore(j,0,m)a[i][j]=get_idx(_a[i][j]);
	used=vv(m);
	if(!can(a,w)){
		cout<<"*\n";
		return 0;
	}
	vv res;
	fore(j,0,m){
		ll done=0,did=0;
		fore(x,0,m)if(!used[x]){
			ll cnt=0;
			fore(i,0,n)cnt+=a[i][0]==x;
			ll good=(cnt>n/2)==(x==w);
			used[x]=1;
			if(x!=w)good&=can(saca(a,x),w);
			if(good){
				res.pb(x);
				a=saca(a,x);
				if(x==w){
					fore(y,0,m)if(!used[y])res.pb(y);
					done=1;
				}
				did=1;
				break;
			}
			else used[x]=0;
			
		}
		assert(did);
		if(done)break;
	}
	for(auto i:res)cout<<pals[i]<<" ";;cout<<"\n";
	return 0;
}