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

ll lis(vv a){
	vv v;
	for(auto i:a){
		ll p=lower_bound(ALL(v),i)-v.begin();
		if(p>=SZ(v))v.pb(i);
		else v[p]=i;
	}
	return SZ(v);
}

int main(){FIN;
	ll n,k; cin>>n>>k; k--;
	vv a(n),b(n),p(n),q(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	fore(i,0,n)cin>>p[i],p[i]--;
	fore(i,0,n)cin>>q[i],q[i]--;
	vv ida(n,-1),vis(n);
	ll x=p[k],cnt=0,did=0;
	// cout<<"cyc a\n";
	while(x!=k){
		did|=a[x]>0;
		if(did)ida[x]=cnt++;
		// cout<<x<<" "<<did<<"\n";
		x=p[x];
	}
	ll res=cnt; did=0;
	x=q[k];
	vv vec;
	// cout<<"cyc b\n";
	while(x!=k){
		did|=b[x]>0;
		if(did&&ida[x]!=-1)vec.pb(ida[x]);
		res+=did;
		// cout<<x<<" "<<did<<"\n";
		vis[x]=1;
		x=q[x];
	}
	// cout<<res<<" before\n";
	// imp(vec)
	res-=lis(vec);
	ll flag=1;
	fore(i,0,n)if(i!=k){
		flag&=(!a[i]||ida[i]!=-1);
		flag&=(!b[i]||vis[i]);
	}
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	cout<<res<<"\n";
	return 0;
}
