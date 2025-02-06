#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const int MAXN=3e5+5;

#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

ll ft[MAXN+1];
void upd(int i0, int v){
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
// query ]
ll query(int i0){ i0++;
	ll r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}

int m;
void upd(int l, int r, int v){
	// cout<<"upd "<<l<<" "<<r<<" "<<v<<endl;
	if(l>r){upd(l,m-1,v),upd(0,r,v);return;}
	r++;
	upd(l,v);
	if(r<m)upd(r,-v);
}


int main(){
	JET
	int n; cin>>n>>m;
	vector<vv> g(n);
	fore(i,0,m){
		int x; cin>>x; x--;
		g[x].pb(i);
	}
	vector<ii>w(n);
	fore(i,0,n)cin>>w[i].fst,w[i].snd=i;
	sort(ALL(w));
	vv nl(n);
	fore(i,0,n)nl[w[i].snd]=i;
	vector<vv> g2(n);
	fore(i,0,n)g2[nl[i]]=g[i];
	swap(g,g2);
	// vv per(n); iota(ALL(per),0);
	// sort(ALL(per),[&](int i, int j){return w[i]<w[j];});
	int k; cin>>k;
	vector<pair<pair<int,int>,int>>rans;
	fore(i,0,k){
		int l,r,v; cin>>l>>r>>v; l--,r--;
		rans.pb({{l,r},v});
	}
	vector<int> ls(n),rs(n); // ans in l
	vector<vector<int>> h(k);
	fore(i,0,n){
		auto &l=ls[i];
		auto &r=rs[i];
		l=0,r=k-1;
		int m=(l+r)/2;
		h[m].pb(i);
	}
	bool did=1;
	while(did){
		did=0;
		mset(ft,0);
		vector<vector<int>>hi(k);
		fore(t,0,k){
			upd(rans[t].fst.fst,rans[t].fst.snd,rans[t].snd);
			for(auto i:h[t]){
				auto &l=ls[i];
				auto &r=rs[i];
				ll has=0;
				for(auto p:g[i]){
					has+=query(p);
					if(has>=w[i].fst)break;
				}
				// cout<<i<<": "<<l<<" "<<r<<": "<<has<<"\n";
				if(has>=w[i].fst)r=t-1;
				else l=t+1;
				if(l<=r){
					int m=(l+r)/2;
					hi[m].pb(i);
					did=1;
				}
			}
		}
		swap(h,hi);
	}
	vv ans(n);
	fore(i,0,n)ans[w[i].snd]=ls[i];
	fore(i,0,n){
		int res=ans[i];
		if(res>=k)cout<<"NIE\n";
		else cout<<res+1<<"\n";
	}
	return 0;
}