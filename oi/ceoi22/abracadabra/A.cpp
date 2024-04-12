#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ceoi=b;i<ceoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto kdjfhg:v)cout<<kdjfhg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

ll ft[MAXN],arr[MAXN];
ll n;
void upd(ll i, ll v){
	//cout<<"new "<<i<<" "<<v<<"\n";
	arr[i]+=v;
	for(i++;i<=MAXN;i+=i&-i)ft[i]+=v;
}
ll get_sum(ll i){ // )
	ll res=0;
	for(;i;i-=i&-i)res+=ft[i];
	return res;
}
/*ii find(ll x){ //upperbound on prefix sums, (pos,remainder)
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(get_sum(m+1)>x)r=m-1;
		else l=m+1;
	}
	r=x-get_sum(l);
	//cout<<"find "<<x<<": "<<l<<","<<r<<endl;
	//fore(i,0,n)cout<<arr[i]<<" ";;cout<<endl;
	return {l,r};
}*/
ii find(ll x){
	ll p=0;
	for(ll k=19;k>=0;k--)if(ft[p+(1ll<<k)]<=x){
		p+=1ll<<k;
		x-=ft[p];
	}
	return {p,x};
}
int main(){
	ll q; cin>>n>>q;
	vector<ll>a(n),p(n);
	fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
	vector<vector<ii>>qs(n+5);
	vector<ll>ans(q);
	fore(_,0,q){
		ll t,i; cin>>t>>i; i--;
		t=min(t,n+3);
		qs[t].pb({i,_});
	}
	vector<ll>nx(n);
	for(ll i=n-1;i>=0;i--)
		for(nx[i]=i+1;nx[i]!=n&&a[i]>=a[nx[i]];nx[i]=nx[nx[i]]);
	ll mx=0;
	fore(i,0,n){
		mx=max(mx,a[i]);
		if(a[i]==mx)upd(a[i],nx[i]-i);
	}
	//fore(i,0,n)cout<<nx[i]<<" ";;cout<<"\n";
	fore(t,0,n+5){
		//cout<<"time "<<t<<endl;
		for(auto [i,_]:qs[t]){
			auto [x,r]=find(i);
			ans[_]=a[p[x]+r];
		}
		auto [x,r]=find(n/2);
		if(r==0)continue; //x==i
		ll z=arr[x];
		upd(x,-z+r);
		//cout<<nx[p[x]]<<")\n";
		for(ll i=p[x]+r;i<p[x]+z;i=nx[i])upd(a[i],min(nx[i],p[x]+z)-i);
	}
	fore(_,0,q)cout<<ans[_]+1<<"\n";
	return 0;
}
