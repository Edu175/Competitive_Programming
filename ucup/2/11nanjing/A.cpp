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
const ll MAXN=4005;

// 2n x 2 m

ll n,m;

ll cv(ll di, ll dj){
	di+=n-1,dj+=m-1;
	return di*2*m+dj;
}
typedef bitset<MAXN> mask;
vector<ii> dir={{0,1},{-1,0},{0,-1},{1,0}};

vector<string> a;
bool allowed(ll i, ll j){
	return i>=0&&i<n&&j>=0&&j<m&&a[i][j]=='.';
}
vector<ii> nod;
vector<vv> vis;
void dfs(ll i, ll j){
	vis[i][j]=1;
	nod.pb({i,j});
	for(auto [di,dj]:dir){
		ll ni=i+di,nj=j+dj;
		if(allowed(ni,nj)&&!vis[ni][nj])dfs(ni,nj);
	}
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<mask> b(n*m);
		a=vector<string>(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)fore(j,0,m)if(a[i][j]=='.'){
			vis=vector<vv>(n,vv(m));
			nod.clear();
			dfs(i,j);
			for(auto [ni,nj]:nod){
				ll di=ni-i,dj=nj-j;
				b[m*i+j][cv(di,dj)]=1;
				// cout<<i<<","<<j<<": "<<di<<","<<dj<<"\n";
			}
		}
		vv is(n*m);
		fore(i,0,n)fore(j,0,m){
			ll pos=i*m+j;
			is[pos]=a[i][j]=='.';
			// if(is[pos]){
			// 	cout<<pos<<": "<<i<<","<<j<<": ";
			// 	fore
			// }
		}
		ll res=0;
		fore(i,0,n*m)if(is[i]){
			auto &b1=b[i];
			ll good=1;
			fore(j,0,n*m)if(is[j]&&i!=j){
				auto &b2=b[j];
				if((b1&b2)==b1){ // b1 es submascara
					good=0;
					break;
				}
			}
			// if(good){
			// 	cout<<"good "<<i/m<<" "<<i%m<<"\n";
			// }
			res+=good;
		}
		cout<<res<<"\n";
	}
	return 0;
}