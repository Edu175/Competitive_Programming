#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll red(ll x){while(x>=3)x-=3;while(x<0)x+=3;return x;}
void reduce(vector<vector<ll> >& x){
	int n=x.size(),m=x[0].size();
	int i=0,j=0;
	while(i<n&&j<m){
		int l=i;
		fore(k,i+1,n)if(abs(x[k][j])>abs(x[l][j]))l=k;
		if(abs(x[l][j])==0){j++;continue;}
		if(l!=i){swap(x[i],x[l]);}
		for(int k=m-1;k>=j;k--)x[i][k]=red(x[i][k]*x[i][j]);
		fore(k,0,n){
			if(k==i)continue;
			for(int l=m-1;l>=j;l--)x[k][l]=red(x[k][l]-x[k][j]*x[i][l]);
		}
		i++; j++;
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<vv> g(n,vv(n,-1));
		vector<vv> a;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u][v]=g[v][u]=i;
			if(w!=-1){
				vv r(m+1); r[i]=1; r[m]=w-1;
				a.pb(r);
			}
		}
		fore(i,0,n)fore(j,i+1,n)fore(k,j+1,n){
			ll x=g[i][j];
			ll y=g[j][k];
			ll z=g[k][i];
			if(x!=-1&&y!=-1&&z!=-1){
				vv r(m+1);
				r[x]=r[y]=r[z]=1;
				a.pb(r);
			}
		}
		if(SZ(a))reduce(a);
		ll bad=0;
		fore(i,0,SZ(a)){
			if(count(ALL(a[i]),0)==m&&a[i].back())bad=1;
		}
		if(bad){
			cout<<"-1\n";
			continue;
		}
		vv ans(m,-1);
		// cerr<<"a:\n";
		// for(auto r:a)show(r)
		for(ll i=SZ(a)-1;i>=0;i--){
			ll c=a[i][m];
			vv all;
			fore(j,0,m)if(a[i][j]){
				if(ans[j]==-1)all.pb(j);
				else c=red(c-a[i][j]*ans[j]);
			}
			if(!SZ(all))continue;
			fore(j,1,SZ(all))ans[all[j]]=0;
			ll wh=all[0];
			ans[wh]=red(c*a[i][wh]);
		}
		for(auto &i:ans)if(i==-1)i=0;
		fore(i,0,m)cout<<ans[i]+1<<" ";;cout<<"\n";
	}
	return 0;
}