#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

#define ppc __builtin_popcountll

ll n;
ll a[MAXN];
ll res=0;

vector<ii> getran(ll l, ll r){
	assert(r-l>=1);
	vector<ii>ret;
	ll mn=a[l],mx=a[l];
	fore(i,l,r){
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
		ret.pb({mn,mx});
	}
	return ret;
}

ll sums[65];

void f(ll l, ll r, ll bo){
	if(r-l<=1)return;
	ll m=(l+r+bo)/2;
	
	auto R=getran(m,r);
	reverse(a+l,a+m);
	auto L=getran(l,m);
	reverse(a+l,a+m);
	
	// cerr<<l<<","<<r<<" "<<m<< ":\n";
	// for(auto i:L)cerr<<i.fst<<","<<i.snd<<" ";;cerr<<"\n";
	// for(auto i:R)cerr<<i.fst<<","<<i.snd<<" ";;cerr<<"\n";
	
	ll po=0;
	ll cur=0;
	for(auto [mn,mx]:L){
		while(po<SZ(R) && mn+bo<=R[po].fst && R[po].snd<mx)po++;
		if(ppc(mn)==ppc(mx))cur+=po;
	}
	
	auto actu=[&](ll i, ll w){ // i es la pos de R
		sums[ppc(R[i].snd)]+=w;
		// cout<<"actu "<<i<<" "<<w<<"\n";
	};
	
	ll s=0,e=0;
	ll cur2=0;
	for(auto [mn,mx]:L){
		while(e<SZ(R) && mn+bo<=R[e].fst)	actu(e++,1);
		while(s<e && R[s].snd<mx)			actu(s++,-1);
		ll sum=sums[ppc(mn)];
		// cerr<<mn<<","<<mx<<": "<<s<<","<<e<<" "<<sum<<"\n";
		cur2+=sum;
	}
	while(e<SZ(R))	actu(e++,1);
	while(s<e)		actu(s++,-1);
	
	res+=cur+cur2;
	
	// cerr<<cur<<" "<<cur2<<"\n";
	// cerr<<"\n\n";
	
	f(l,m,bo),f(m,r,bo);
}

int main(){
	JET
	cin>>n;
	fore(i,0,n)cin>>a[i];
	
	f(0,n,0);
	reverse(a,a+n);
	f(0,n,1);
	cout<<res+n<<"\n";
	return 0;
}