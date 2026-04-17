#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ii u={1,1};
vv ps;
void fact(ll d){
	ps.clear();
	for(ll i=2; i*i<=d; i++)if(!(d%i)) {
		ps.pb(i);
		while(!(d%i)) d/=i;
	}
	if(d>1) ps.pb(d);
}
const ll INF=2e9;
map<ii,ll> m;
ll dst(ii x){
	if(!m.count(x)) return m[x]=INF;
	return m[x];
}
typedef pair<ll,ii> nd;
void dijkstra(ii x){
	m.clear();
	m[x]=0;
	priority_queue<nd> pq;
	pq.push({0,x});
	while(SZ(pq)){
		x=pq.top().snd; 
		ll ds=-pq.top().fst,a=x.fst,d=x.snd;pq.pop();
		if(dst(x)!=ds) continue;
		if(dst(u)<=ds) continue;
		if(a==1||d==1) {
			m[u]=min(m[u],ds+a-1);
			continue;
		}
		ll y,del,dy;
		for(auto &p:ps)if(!(d%p)){
			ll r1=a%p, r2=p-r1;
			dy=d/p;
			if(a<p) y=1,del=a-1;
			else y=(a-r1)/p,del=r1+1;
			if(dst({y,dy})>ds+del){
				m[{y,dy}]=ds+del;
				pq.push({-ds-del,{y,dy}});
			}
			
			y=(a+r2)/p,del=r2+1;
			if(dst({y,dy})>ds+del){
				m[{y,dy}]=ds+del;
				pq.push({-ds-del,{y,dy}});
			}
		}		
	}
}
int main(){
	JET 
	ll _; cin>>_; while(_--){
		ll a,b; cin>>a>>b; if(a>b) swap(a,b);
		ll d=b-a;
		fact(d);
		dijkstra({a,d});
		cout<<dst(u)<<"\n";
	}
	return 0;
}