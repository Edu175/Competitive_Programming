#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define TUCUTUCUTUCUTUCU ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXV=2e5+5,MAXN=1e5+5;

vv nod[MAXV];
ll col[MAXV];
vector<ii>ed;
vv g[MAXN];
bool check(){
	for(auto [x,y]:ed)if(abs(col[x]-col[y])!=1)return 0;
	return 1;
}

int main(){
	TUCUTUCUTUCUTUCU
	ll n; cin>>n;
	fore(i,0,n){
		ll p; cin>>p; p--;
		if(p!=-1)g[p].pb(i),g[i].pb(p),ed.pb({i,p});
	}
	ll mn=MAXV;
	fore(i,0,n){
		cin>>col[i];
		if(col[i]!=-1)nod[col[i]].pb(i),mn=min(mn,col[i]);
	}
	if(mn==MAXV)mn=0,nod[mn].pb(0),col[0]=0; // no nodes colored
	fore(c,mn,MAXV){
		for(auto x:nod[c]){
			for(auto y:g[x])if(col[y]==-1){
				col[y]=c+1;
				nod[c+1].pb(y);
			}
		}
	}
	if(!check()){
		cout<<"NEM\n";
		// fore(i,0,n)cout<<col[i]<<" ";;cout<<" dbg\n";
	}
	else {
		cout<<"IGEN\n";
		fore(i,0,n)cout<<col[i]<<" ";;cout<<"\n";
	}
	return 0;
}
/*
NEM
-1 -1 -1 -1 -1 -1  dbg
*/