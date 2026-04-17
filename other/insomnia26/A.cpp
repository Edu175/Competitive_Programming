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
const ll MAXN=1e5+5;
int ft[MAXN+1]; // for more dimensions, make ft multi-dimensional
void upd(int i0, int v){ // add v to i0th element (0-based)
	// add extra fors for more dimensions
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
int get(int i0){ // get sum of range [0,i0)
	int r=0;
	// add extra fors for more dimensions
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}

const ll R=1e10;

vector<ii> a;
ll n,k;
bool can(ll t){
	mset(ft,0);
	auto b=a;
	fore(i,0,n){
		// cout<<i<<": "<<b[i].fst<<","<<b[i].snd<<": ";
		b[i].snd=min(b[i].fst+t,b[i].snd);
		// cout<<b[i].fst<<","<<b[i].snd<<"\n";
	}
	vv posr(n);
	vector<ii> sdr;
	fore(i,0,n)sdr.pb({b[i].snd,i});
	sort(ALL(sdr));
	ll cnt=0;
	fore(i,0,SZ(sdr)){
		posr[sdr[i].snd]=cnt;
		cnt+=i==SZ(sdr)-1||sdr[i].fst!=sdr[i+1].fst;
	}
	
	ll prev=-1;
	vv bu;
	ll res=0,tot=0;
	fore(i,0,n){
		auto [l,r]=b[i];
		if(prev<l){
			for(auto rj:bu)upd(rj,1),tot++;
			bu.clear();
		}
		bu.pb(posr[i]); prev=l;
		res+=tot-get(posr[i]);
	}
	// cout<<"can "<<t<<": ";
	// for(auto i:b)cout<<i.fst<<","<<i.snd<<" ";;cout<<": "<<res<<"\n";
	return res>=k;
}

int main(){FIN;
	cin>>n>>k;
	a.resize(n);
	fore(i,0,n)cin>>a[i].fst;
	fore(i,0,n)cin>>a[i].snd;
	sort(ALL(a),[&](ii a, ii b){
		return a.fst<b.fst;
	});
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	
	ll l=0,r=R;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can(m))r=m;
		else l=m;
	}
	ll res=r;
	if(res>=R)res=-1;
	cout<<res<<"\n";
	return 0;
}
