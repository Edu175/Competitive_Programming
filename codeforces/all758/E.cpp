#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
#define showt(v) {for(auto i:v)cout<<i[0]<<","<<i[1]<<","<<i[2]<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;

bool can_tri(vector<array<ll,3>> &a, ll k){
	vv ys; // of color 2
	for(auto &i:a)if(i[2]==2)ys.pb(i[1]);
	// cerr<<"can_tri "<<k<<"\n";
	// showt(a)
	// show(ys)
	sort(ALL(ys));
	// nth_element(ys.begin(),ys.begin()+k-1,ys.end());
	ll C=ys[k-1];
	ll ty=0,cant=0;
	ll u=-INF;
	for(auto &v:a)if(v[1]>C){
		if(v[2]==ty&&v[0]>u){
			cant++;
			if(cant>=k)cant=0,ty++,u=v[0];
		}
		if(ty>=2)return 1;
	}
	return 0;
}
bool can_lin(vector<array<ll,3>> &a, ll k){ // sorted by first
	ll ty=0,cant=0;
	ll u=-INF;
	for(auto &v:a){
		if(v[2]==ty&&v[0]>u){
			cant++;
			if(cant>=k)cant=0,ty++,u=v[0];
		}
		if(ty>=3)return 1;
	}
	return 0;
}

ll solve(vector<array<ll,3>> &a){
	// cerr<<"solve "; showt(a)
	ll n=SZ(a);
	sort(ALL(a)); // by first coord
	ll l=0,r=n/3+1;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can_tri(a,m)||can_lin(a,m))l=m;
		else r=m;
	}
	return l;
}
ii rot(ii a){return {-a.snd,a.fst};}

int main(){FIN;
	ll n; cin>>n;
	vector<array<ll,3>> a(n);
	fore(i,0,n){
		fore(j,0,3)cin>>a[i][j];
		a[i][2]--;
	}
	// cerr<<"orig "; showt(a)
	ll res=0;
	fore(_,0,4){
		vv per(3); iota(ALL(per),0);
		do{
			vector<array<ll,3>> b(n);
			fore(i,0,n){
				b[i][0]=a[i][0];
				b[i][1]=a[i][1];
				b[i][2]=per[a[i][2]];
			}
			res=max(res,solve(b));
		}while(next_permutation(ALL(per)));
		
		// roto a
		for(auto &i:a){
			ii par={i[0],i[1]};
			par=rot(par);
			i[0]=par.fst;
			i[1]=par.snd;
		}
	}
	cout<<res*3<<"\n";
	return 0;
}
