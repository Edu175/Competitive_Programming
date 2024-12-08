#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define impm(a) fore(i,0,n){fore(j,0,n)cout<<a[i][j]+1<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef long long LL;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

void paste(vector<vv>&a, vector<vv>b, ll r, ll c){
	fore(i,0,SZ(b))fore(j,0,SZ(b[0]))a[r+i][c+j]=b[i][j];
}
vector<vv> subo(vector<vv>a, ll v){
	fore(i,0,SZ(a))fore(j,0,SZ(a[0]))a[i][j]+=v;
	return a;
}
vector<vv> get(ll n){
	vector<vv>a(n,vv(n));
	fore(i,0,n)fore(j,0,n)a[i][j]=(i-j+n)%n;
	return a;
}
int main(){JET
	ll n,k; cin>>n>>k;
	vector<pair<char,ii>>ts(k);
	vv pr(n),pc(n);
	iota(ALL(pr),0);
	iota(ALL(pc),0);
	fore(_,0,k){
		char c; cin>>c;
		ll i,j; cin>>i>>j; i--,j--;
		if(c=='R')swap(pr[i],pr[j]);
		else swap(pc[i],pc[j]);
	}
	vv volr(n),volc(n);
	ll q=-1,flag=1;
	auto doit=[&](vv &p, vv &vol){
		vv vis(n);
		ll cnt=0;
		fore(x,0,n)if(!vis[x]){
			ll z=0;
			for(auto y=x;!vis[y];y=p[y]){
				vol[y]=cnt++;
				vis[y]=1;
				z++;
			}
			if(q==-1)q=z;
			else flag&=q==z;
		}
	};
	doit(pr,volr);
	doit(pc,volc);
	if(!flag){cout<<"*\n";return 0;}
	vector<vv> a(n,vv(n,-1));
	ll m=n/q;
	fore(i,0,m)fore(j,0,m){
		ll v=(i+j)%m*q;
		auto b=subo(get(q),v);
		paste(a,b,i*q,j*q);
	}
	vector<vv>res(n,vv(n));
	fore(i,0,n)fore(j,0,n){
		res[i][j]=a[volr[i]][volc[j]];
	}
	// impm(a); cout<<"\n";
	// imp(volc)
	// imp(volr)
	auto check=[&](vector<vv>a){
		auto b=a;
		fore(i,0,n)fore(j,0,n)b[i][j]=a[pr[i]][pc[j]];
		// cout<<"check?\n";
		// impm(a);
		// cout<<endl;
		// impm(b);
		// cout<<endl;
		return a==b;
	};
	assert(check(res));
	fore(i,0,n){
		fore(j,0,n)cout<<res[i][j]+1<<" ";
		cout<<"\n";
	}
	return 0;
}