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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-7;

struct node{
	ld p;
	ll s,m,mn;
};
bool operator<(const node &a, const node &b){return a.p<b.p;}
// const ll MAXM=4005,MAXH=401,MAXS=MAXH*20;

ll n,m;
ld p;
// map<ll,ll> dp[MAXS][MAXM]; // s,m,mn
ld dijkstra(node s){
	// fore(i,0,n*MAXH)fore(j,0,m+3)dp[i][j].clear();
	// #define dis(a) dp[a.s][a.m][a.mn]
	// dis(s)=1;
	priority_queue<node>pq;
	// vector<node> prox,now;
	// now.pb(s);
	ld acum=0,win=0;
	pq.push(s);
	while(SZ(pq)||1-acum>=EPS){
		auto x=pq.top(); pq.pop();
		cout<<x.p<<": "<<x.mn<<" "<<x.s<<" "<<x.m<<"\n";
		// if(x.p==0)continue;
		if(x.mn==0&&x.s==0){
			acum+=x.p;
			win+=x.p;
			continue;
		}
		if(x.m==m){
			acum+=x.p;
			continue;
		}
		if(x.mn>0){
			pq.push((node){x.p*p,x.s,x.m+1,x.mn-1}); // shinea
			ll si,mni;
			if(x.s>0)si=x.s-1,mni=x.mn;
			else si=n-1,mni=x.mn-1;
			pq.push((node){x.p*(1-p),si,x.m+1,mni}); // no shinea
		}
		else {
			pq.push((node){x.p*p,x.s,x.m+1,x.mn}); // shinea
			pq.push((node){x.p*(1-p),x.s-1,x.m+1,x.mn}); // no shinea
		}
	}
	return win;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll pp; cin>>n>>m>>pp;
		p=ld(pp)/100.0;
		cout<<p<<"\n";
		ll mn=405;
		ll sum=0;
		fore(i,0,n){
			ll h; cin>>h; h--;
			mn=min(mn,h);
			sum+=h;
		}
		sum-=mn*n;
		auto res=dijkstra((node){1,sum,0,mn});
		cout<<fixed<<setprecision(15)<<res<<"\n";
		
	}
	return 0;
}
