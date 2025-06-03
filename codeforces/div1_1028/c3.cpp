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
const ld EPS=1e-6;
const ld EPSI=1e-18;

struct node{
	ld p;
	ll s,mn;
	ii par;
	node(ld p, ll s, ll mn):p(p),s(s),mn(mn),par({s,mn}){};
};
bool operator<(const node &a, const node &b){return a.p<b.p;}
// const ll MAXM=4005,MAXH=401,MAXS=MAXH*20;

ll n,m;
ld p;
// map<ll,ll> dp[MAXS][MAXM]; // s,m,mn
ld dijkstra(node s){
	vector<node> prox,now;
	now.pb(s);
	ld win=0;
	ld skipped=0;
	fore(i,0,m+1){
		cout<<"round "<<i<<"\n";
		sort(ALL(now),[&](const node &a, const node &b){
			return a.par<b.par;
		});
		auto _now=now; now.clear();
		for(auto i:_now){
			if(SZ(now)&&now.back().par==i.par)now.back().p+=i.p;
			else now.pb(i);
		}
		for(auto x:now){
			if(x.p<=EPSI){
				skipped+=x.p;
				continue;
			}
			cout<<x.mn<<" "<<x.s<<": "<<x.p<<"\n";
			if(x.mn==0&&x.s==0){
				win+=x.p;
				continue;
			}
			if(x.mn>0){
				prox.pb((node){x.p*p,x.s,x.mn-1}); // shinea
				ll si,mni;
				if(x.s>0)si=x.s-1,mni=x.mn;
				else si=n-1,mni=x.mn-1;
				prox.pb((node){x.p*(1-p),si,mni}); // no shinea
			}
			else {
				prox.pb((node){x.p*p,x.s,x.mn}); // shinea
				prox.pb((node){x.p*(1-p),x.s-1,x.mn}); // no sh
			}
		}
		swap(prox,now);
		prox.clear();
	}
	assert(skipped<EPS);
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
		auto res=dijkstra((node){1,sum,mn});
		cout<<fixed<<setprecision(15)<<res<<"\n";
		
	}
	return 0;
}
