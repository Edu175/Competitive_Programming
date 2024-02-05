#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,MAXM=2*MAXN;

pair<ii,ll> a[MAXN];
vector<ll> ran[MAXM];
ll m;
ll dp[MAXM];

ll f(ll x){
	ll &res=dp[x];
	if(res!=-1)return res;
	if(x==m)return res=0;
	res=f(x+1);
	for(auto i:ran[x])res=max(res,a[i].snd+f(a[i].fst.snd));
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>c;
	fore(i,0,n){
		ll l,r,w; cin>>l>>r>>w; l--;
		c.pb(l),c.pb(r);
		a[i]={{l,r},w};
	}
	sort(ALL(c));
	vector<ll>co;
	for(auto i:c)if(!SZ(co)||co.back()!=i)co.pb(i);
	fore(i,0,n){
		ll &l=a[i].fst.fst,&r=a[i].fst.snd;
		l=lower_bound(ALL(co),l)-co.begin();
		r=lower_bound(ALL(co),r)-co.begin();
		ran[l].pb(i);
	}
	/*imp(co);
	fore(i,0,n){
		cout<<"["<<a[i].fst.fst<<","<<a[i].fst.snd<<")"<<a[i].snd<<" ";
	}
	cout<<"\n";*/
	m=SZ(co);
	mset(dp,-1);
	cout<<f(0)<<"\n";
	return 0;
}

