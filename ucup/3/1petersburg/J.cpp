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

typedef __int128 xl;
typedef  pair<ll,xl> elem;
ll L=2e7,S=1e9;

vector<elem> merge(vector<elem> &a, vector<elem> &b){
	vector<elem> c;
	ll l=0,r=0;
	while(l<SZ(a)||r<SZ(b)){
		ll w=0;
		if(l==SZ(a) || (r<SZ(b)&&b[r].fst<b[l].fst))w=1;
		elem x=w?b[r++]:a[l++];
		if(abs(x.fst)<=L&&(!SZ(c)||c.back().fst!=x.fst))c.pb(x);
	}
	return c;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ii> a(n);
	fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
	sort(ALL(a));
	L=S/(n/2)*2;
	cerr<<"L "<<L<<"\n";
	vector<elem> all={{0,0}};
	fore(i,0,n){
		cerr<<SZ(all)<<"\n";
		vector<elem> nue=all;
		for(auto &v:all)v.fst-=a[i].fst;
		for(auto &v:nue)v.fst+=a[i].fst,v.snd|=(xl(1)<<a[i].snd);
		all=merge(all,nue);
	}
	for(auto [val,mk]:all)if(!val){
		vv ans;
		fore(i,0,n)if(mk>>i&1)ans.pb(i);
		cout<<SZ(ans)<<" ";
		for(auto i:ans)cout<<i<<" ";;cout<<"\n";
		exit(0);
	}
	ll mn=0; ll SEE=20;
	fore(i,0,SZ(all))if(abs(all[i].fst)<abs(all[mn].fst))mn=i;
	cout<<"ventana\n";
	fore(i,max(mn-SEE,0ll),min(mn+SEE,(ll)SZ(all)))cout<<all[i].fst<<" ";;cout<<endl;
	assert(0);
	return 0;
}
