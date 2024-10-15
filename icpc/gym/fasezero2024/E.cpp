#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=105;
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	ll n; cin>>n;
	vector<ii>ed[n+1];
	vector<ll>q(n+1);
	vector<ll>c[n+1];
	ll flag=1;
	ll mn=n+5;
	fore(i,0,n+1){
		ll m; cin>>m;
		ed[i].resize(m);
		q[i]=n;
		uf_init();
		fore(j,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			ed[i][j]={u,v};
			q[i]-=uf_join(u,v);
		}
		mn=min(mn,q[i]);
		vector<ll>vis(n);
		fore(j,0,n){
			ll x=uf_find(j);
//			cout<<i<<" "<<x<<"\n";
			if(!vis[x])c[i].pb(-uf[x]),vis[x]=1;
		}
		sort(ALL(c[i]));
//		cout<<i<<": "<<q[i]<<" | "; imp(c[i]); cout<<endl;
		if(m)flag=0;
	}
	if(flag){
		cout<<n+1<<"\n";
		fore(i,0,n+1){
			if(i)cout<<" ";
			cout<<1;
		}
		cout<<"\n";
		return 0;
	}
	ll k=0;
	fore(i,0,n+1)if(q[i]==mn){
		k=max(k,c[i][0]);
	}
	vector<ll>res={k+1};
	fore(i,0,n)if(q[i]==mn&&c[i][0]!=k)res=c[i],res[0]=k;
	cout<<SZ(res)<<"\n";
	fore(i,0,SZ(res)){
		if(i)cout<<" ";
		cout<<res[i];
	}
	cout<<"\n";
	return 0;
}
