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
	vv nl(n,n);
	nl[k]=n-1;
	ll x=a[k],i=0;
	while(x!=k){
		nl[x]=i++;
		x=p[x];
	}
	imp(nl);
	ll flag=1;
	fore(i,0,n)if(nl[i]==n&&(a[i]||b[i]))flag=0;
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	nl[k]=i++;
	auto lam=[&](ll i, ll j){return nl[i]<nl[j];};
	fore(i,0,n)p[i]=nl[p[i]];
	fore(i,0,n)q[i]=nl[q[i]];
	n=i;
	auto redef=[&](vv &a){
		sort(ALL(a),lam);
		a.resize(n);
	};
	redef(a);
	redef(b);
	redef(p); // useless
	redef(q);
	ll res=0;
	auto move=[&](ll i){
		res++;
		a[p[i]]+=a[i]; a[i]=0;
		b[q[i]]+=b[i]; b[i]=0;
	};
	for(ll i=n-2;i>=0;i--)if(q[i]<i&&b[i])move(i);
	fore(i,0,n-1)if(a[i]||b[i])move(i);
	
	cout<<res<<"\n";
	return 0;
}
