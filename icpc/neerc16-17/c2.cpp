#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define snd second
#define fst first
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=500*500/2+5,MAXM=MAXN*4;

vector<int> g[MAXN];
int n,m;
int mt[MAXN],mt2[MAXN],ds[MAXN];
bool bfs(){
	queue<int>q;
	mset(ds,-1);
	fore(i,0,n)if(mt2[i]<0)ds[i]=0,q.push(i);
	bool r=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(auto y:g[x]){
			if(mt[y]>=0&&ds[mt[y]]<0)ds[mt[y]]=ds[x]+1,q.push(mt[y]);
			else if(mt[y]<0)r=1;
		}
	}
	return r;
}
bool dfs(int x){
	for(auto y:g[x])if(mt[y]<0||ds[mt[y]]==ds[x]+1&&dfs(mt[y])){
		mt[y]=x;mt2[x]=y;
		return 1;
	}
	ds[x]=1<<30;
	return 0;
}
ll mm(){
	ll r=0;
	mset(mt,-1); mset(mt2,-1);
	while(bfs()){
		fore(i,0,n)if(mt2[i]<0)r+=dfs(i);
	}
	return r;
}
ll h,w;
ll cv(ll i, ll j){
	return (w*i+j)/2;
}
ll dir(ii x, ii y){
	return ii({x.fst+1,x.snd})==y;
}
int main(){JET
	#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>h>>w;
	fore(i,0,h)fore(j,0,w)if((i+j)%2==0){
		ll x=cv(i,j);
		if(i&&j<w-1)g[x].pb(cv(i-1,j));
		if(j&&i<h-1)g[x].pb(cv(i,j-1));
		if(i<h-1&&j<w-1)g[x].pb(cv(i+1,j));
		if(j<w-1&&i<h-1)g[x].pb(cv(i,j+1));
	}
	n=(h*w+1)/2,m=h*w/2;
	mm();
	// fore(i,0,n){
	// 	cout<<i<<": ";
	// 	for(auto y:g[i])cout<<y<<" ";;cout<<" con "<<mt[i]<<"\n";
	// }
	// fore(i,0,n)cout<<mt2[i]<<" ";;cout<<"\n";
	
	vector<ii> acv[h*w];
	fore(i,0,h)fore(j,0,w){
		acv[cv(i,j)].pb({i,j});
	}
	fore(i,0,h*w){
		auto &v=acv[i];
		if(!SZ(v))continue;
		if((v[0].fst+v[0].snd)%2)swap(v[0],v[1]);
	}
	vector<pair<ii,ll>>res;
	fore(i,0,n)if(mt2[i]!=-1){
		ii x=acv[i][0],y=acv[mt2[i]][1];
		// cout<<"elijo "<<x<<" "<<y<<'\n';
		if(x>y)swap(x,y);
		res.pb({x,dir(x,y)});
	}
	sort(ALL(res),[&](pair<ii,ll>a, pair<ii,ll>b){
		// ll sa=a.fst.fst+a.fst.snd,sb=b.fst.fst+b.fst.snd;
		// if(sa==sb){
		// 	if(a.snd==1&&b.snd==1)return a.fst.snd<b.fst.snd;
		// 	return a.fst.fst<b.fst.fst;
		// }
		// return sa<sb;
		if(a.snd==1&&b.snd==1&&
		abs(a.fst.fst-b.fst.fst)==1&&abs(a.fst.snd-b.fst.snd)==1)
			return a.fst.snd<b.fst.snd;
		return a.fst<b.fst;
	});
	cout<<SZ(res)<<"\n";
	for(auto [i,lsidh]:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	
	return 0;
 }