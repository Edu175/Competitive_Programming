#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;

vector<ii> dron;
vector<ii> lados;
vv choca;

int main(){
	JET
	int n; cin>>n;	
	dron.resize(n);
	lados.resize(n);
	choca.resize(n);
	fore(i,0,n) cin>>dron[i].fst>>dron[i].snd;
	fore(i,0,n) lados[i]={i-1,i+1};
	priority_queue<pair<ld,ii>> pq;
	fore(i,1,n){
		if(dron[i].snd==dron[i-1].snd) continue;
		ld t=(ld)((ld)dron[i-1].fst-(ld)dron[i].fst)/(ld)((ld)dron[i].snd-(ld)dron[i-1].snd);
		if(t>0) pq.push({-t,{i-1,i}});
	}
	while(SZ(pq)){
		ii pos=pq.top().snd;
		pq.pop();
		int i=pos.fst;
		int j=pos.snd;
		if(choca[i]||choca[j]) continue;
		choca[i]=1;
		choca[j]=1;
		int x=lados[i].fst;
		int y=lados[j].snd;
		if(x!=-1) lados[x].snd=y;
		if(y!=n) lados[y].fst=x;
		if(x==-1 || y==n) continue;
		ld t=(ld)((ld)dron[x].fst-(ld)dron[y].fst)/(ld)((ld)dron[y].snd-(ld)dron[x].snd);
		if(t>0) pq.push({-t,{x,y}});
	}
	vv v;
	fore(i,0,n){
		if(!choca[i]) v.pb(i);
	}
	cout<<SZ(v)<<"\n";
	for(auto x:v) cout<<x+1<<" ";
	cout<<"\n";
}