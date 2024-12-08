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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,k; cin>>n>>k; k--;
	vv a(n),b(n),p(n),q(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	fore(i,0,n)cin>>p[i],p[i]--;
	fore(i,0,n)cin>>q[i],q[i]--;
	deque<ll> ind;
	ll x=p[k];
	vv vis(n);
	while(x!=k){
		ind.push_front(x);
		vis[x]=1;
		x=p[x];
	}
	x=q[k];
	ll did=0;
	while(x!=k){
		did|=vis[x];
		if(!vis[x]){
			if(did)ind.pb(x);
			else ind.push_front(x);
		}
		vis[x]=1;
		x=q[x];
	}
	ind.pb(k);
	vis[k]=1;
	fore(i,0,n)if(!vis[i])ind.pb(i);
	vv nl(n,n);
	fore(i,0,SZ(ind))nl[ind[i]]=i;
	imp(ind);
	ll flag=1;
	fore(i,0,n)if(!vis[i]&&(a[i]||b[i]))flag=0;
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	// vv per(n); iota(ALL(per),0);
	// auto lam=[&](ll i, ll j){return nl[i]<nl[j];};
	// sort(ALL(per),lam);
	fore(i,0,n)p[i]=nl[p[i]];
	fore(i,0,n)q[i]=nl[q[i]];
	// n=SZ(ind);
	auto redef=[&](vv &a){
		vv b(n);
		fore(i,0,SZ(a))b[nl[i]]=a[i];
		a=b;
	};
	redef(a);
	redef(b);
	redef(p); // useless
	redef(q);
	imp(q)
	imp(a)
	imp(b)
	ll res=0;
	auto move=[&](ll i){
		res++;
		cout<<"move "<<i<<"\n";
		a[p[i]]+=a[i]; a[i]=0;
		b[q[i]]+=b[i]; b[i]=0;
		imp(a)
		imp(b)
	};
	for(ll i=nl[k]-1;i>=0;i--)if(q[i]<i&&b[i])move(i);
	fore(i,0,nl[k])if(a[i]||b[i])move(i);
	cout<<"after\n";
	fore(i,0,n)flag&=((a[i]+b[i]>0)==(i==nl[k]));
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	cout<<res<<"\n";
	return 0;
}
