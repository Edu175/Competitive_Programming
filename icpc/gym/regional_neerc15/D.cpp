#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n;

ll dist(ll x, ll y){
	return min(abs(x-y), n - abs(x-y));
}

ll mod(ll x){
	if(x<0) x+=n;
	return x;
}

ll lad(ll x, ll root, ll m){
	if(x+root == n) return m;
	if(root<=n/2){
		if(x<=root || x>=root - n/2 + n) return 0;
		return 1;
	}
	else if(x>=root - n/2) return 0;
	return 1;
}

int main(){
	JET
	#ifdef ONLINE_JUDGE
	freopen("distance.in","r",stdin);     freopen("distance.out","w",stdout);
	#endif
	cin>>n;
	vv deg(n,0);
	fore(i,0,n-3){
		ll x,y; cin>>x>>y;
		x--,y--;
		deg[x]++,deg[y]++;		
	}	
	ll root = -1;
	fore(i,0,n) if(!deg[i]) root = i;
	assert(root>=0);
	ll mode = deg[(root+1)%n] == 3; //0 izq,  1 der
	ll q; cin>>q;
	while(q--){
		ll x,y; cin>>x>>y;
		x--,y--;
		if(dist(root,y) > dist(root,x)) swap(x,y);
		ll ladx = lad(x,root,mode), lady = lad(y,root,mode);
		if(ladx == lady || ladx == mode){
			cout<<dist(root,x) - dist(root,y)<<"\n";
			continue;
		}
		cout<<dist(root,x) - dist(root,y)+1<<"\n";
	}
	return 0;
}