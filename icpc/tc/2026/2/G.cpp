#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll maxn=3e5+5;
vv nxt[maxn];

int ft[maxn+1];;
void clearft(){mset(ft,0);}
void upd(int i0, int v){
	for(int i=i0+1; i<=maxn; i+=i&-i) ft[i]+=v;
}
int get(int i0){
	int r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
ll get(int i0, int j0){
	return get(j0)-get(i0);
}

ll mn[maxn],mx[maxn];
ll ant[maxn];


int main(){
	JET
	ll n,m; cin>>n>>m;
	ll a[m];
	fore(i,0,m) cin>>a[i],nxt[--a[i]].pb(i);
	fore(i,0,n) nxt[i].pb(m),sort(ALL(nxt[i]));
	
	for(int i=n-1; i>=0; i--){
		mn[i]=(nxt[i][0]==m?i+1:1);
		mx[i]=i+1+get(0,nxt[i][0]);
		upd(nxt[i][0],1);
	}
	
	clearft();
	
	fore(i,0,n){
		upd(nxt[i][0],1); 
	}
		
	fore(i,0,m){
		ll j=lower_bound(ALL(nxt[a[i]]),i)-nxt[a[i]].begin();
		upd(i,-1);
		upd(nxt[a[i]][j+1],1);
		mx[a[i]]=max(mx[a[i]],1+get(i,nxt[a[i]][j+1]));
	}
	fore(i,0,n){
		cout<<mn[i]<<" "<<mx[i]<<"\n";
	}
	return 0;
}