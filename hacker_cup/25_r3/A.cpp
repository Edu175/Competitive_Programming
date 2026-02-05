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
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		// cerr<<"\n";
		ll n,k; cin>>n>>k;
		// cerr<<n<<" "<<k<<"\n";
		ll tot=n*(n+1)/2;
		// construccion tot/k techo patches
		vector<vv> a(n);
		fore(i,0,n)a[i]=vv(i+1,-1);
		ll i=0,j=0;
		ll cnt=0;
		while(i<n&&i+1<k-1){
			fore(_,0,k){
				if(i==n)break;
				a[i][j--]=cnt;
				if(j==-1)i++,j=i;
			}
			cnt++;
		}
		// cout<<"done primera pasada\n";
		// fore(i,0,n){
		// 	for(auto v:a[i])cout<<(v==-1?"-":to_string(v))<<" ";
		// 	cout<<endl;
		// }
		i=j=n-1;
		while(j>=0){
			// cout<<"color "<<cnt<<":\n";//<<i<<" "<<j<<endl;
			ll did=0;
			fore(_,0,k){
				if(j<0)break;
				while(a[i][j]!=-1){
					i++;
					if(i==n)j--,i=j;
					if(j<0)break;
				}
				if(j<0)break;
				// cout<<i<<" "<<j<<endl;
				a[i++][j]=cnt;
				did=1;
				if(i>=n)j--,i=j;
			}
			cnt+=did;
		}
		// fore(i,0,n){
		// 	for(auto v:a[i])cout<<(v==-1?"-":to_string(v))<<" ";
		// 	cout<<endl;
		// }
		fore(i,0,n)for(auto v:a[i])assert(v!=-1);
		// cout<<cnt<<endl;
		assert(cnt==(tot+k-1)/k);
		
		// coloreo greedy
		vector<vv> ans(n);
		fore(i,0,n)ans[i]=vv(i+1,-1);
		vector<vector<vector<ii>>> g(n,vector<vector<ii>>(n));
		auto add=[&](ll a, ll b, ll c, ll d){
			g[a][b].pb({c,d});
			g[c][d].pb({a,b});
		};
		fore(i,0,n)fore(j,0,i+1){
			if(i+1<n)add(i,j,i+1,j);
			if(j)add(i,j,i,j-1);
		}
		set<ll> st;
		vector<ii> nod;
		vector<vv> vis(n,vv(n));
		auto dfs=[&](ll i, ll j, auto &&dfs)-> void {
			if(vis[i][j])return;
			// cout<<"dfs "<<i<<" "<<j<<"\n";
			vis[i][j]=1;
			nod.pb({i,j});
			for(auto [x,y]:g[i][j]){
				if(a[i][j]==a[x][y]){
					if(ans[x][y]==-1)dfs(x,y,dfs);
				}
				else if(ans[x][y]!=-1)st.insert(ans[x][y]);
			}
		};
		fore(i,0,n)fore(j,0,i+1)if(!vis[i][j]){
			// cout<<"patch\n";
			dfs(i,j,dfs);
			ll mex=0; while(st.count(mex))mex++;
			for(auto [i,j]:nod)ans[i][j]=mex;
			nod.clear(); st.clear();
		}
		
		assert(cnt==(tot+k-1)/k);
		cout<<cnt<<"\n";
		fore(i,0,n){
			fore(j,0,SZ(ans[i])){
				assert(ans[i][j]<26);
				cout<<char(ans[i][j]+'a');
			}
			cout<<"\n";
		}
	}
	return 0;
}
