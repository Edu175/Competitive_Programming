#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=5e4+5;

ll uf[MAXN],val[MAXN];

ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
void uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	assert(x!=y);
	val[x]=gcd(val[x],val[y]);
	uf[x]+=uf[y],uf[y]=x;
}

vv get(ll n){
	vv ds;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0)ds.pb(i),ds.pb(n/i);
		if(i*i==n)ds.pop_back();
	}
	return ds;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,n)uf[i]=-1,val[i]=0;
		vv a(n);
		vector<ii> sa;
		ll mn=0;
		fore(i,0,n){
			cin>>a[i],sa.pb({a[i],i});
			if(a[i]<a[mn])mn=i;
		}
		ll ig=1; fore(i,0,n-1)ig&=a[i]==a[i+1];
		if(ig){
			cout<<k<<" "<<k*(k+1)/2<<"\n";
			continue;
		}
		sort(ALL(sa));
		reverse(ALL(sa));
		vv vis(n);
		vv d(n);
		for(auto [v,i]:sa){
			ll acum=0;
			if(i&&vis[i-1])uf_join(i-1,i),acum=abs(a[i]-a[i-1]);
			if(i<n-1&&vis[i+1])uf_join(i+1,i),acum=gcd(acum,abs(a[i]-a[i+1]));
			ll p=uf_find(i);
			val[p]=gcd(val[p],acum);
			d[i]=val[p];
			// cout<<i<<": "<<d[i]<<"\n";
			vis[i]=1;
		}
		ll res0=0,res1=0;
		for(auto dv:get(d[mn])){
			ll x=dv-a[mn];
			if(x<=0||x>k)continue;
			// cout<<"\n\n";
			ll fg=1;
			fore(i,0,n){
				fg&=d[i]%(a[i]+x)==0;
				// cout<<i<<": "<<a[i]+x<<" "<<d[i]<<": "<<d[i]%(a[i]+x)<<"\n";
			}
			if(fg)res0++,res1+=x;
			// cout<<x<<": "<<fg<<" x\n";
		}
		cout<<res0<<" "<<res1<<"\n";
	}
	return 0;
}