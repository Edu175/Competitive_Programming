#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll maxn=3e5+5,INF=1e18;
ll sig[maxn],h[maxn],cnt[maxn];
int n;
void mksig(){
	vector<ii> v(1,{n,INF});
	for(int i=n; i--;){
		while(v.back().snd<=h[i]) v.pop_back();
		sig[i]=v.back().fst;
		v.pb({i,h[i]});
	}
}
int find(int l){return cnt[l]?l:sig[l]=find(sig[l]);}
void act(int l, ll x){
	int del=min(cnt[l],x);
	cnt[l]-=del;
	x-=del;
	if(!cnt[l] && x) act(find(l),x);
}
int main(){
	JET
	int q; cin>>n>>q;
	
	fore(i,0,n) cin>>h[i];
	mksig();
	fore(i,0,n) cnt[i]=h[i];
	cnt[n]=INF;
	while(q--){
		char t; int l;
		cin>>t>>l; l--;
		// cout<<t<<" "<<l<<"quer\n";
		// cout<<h[l]<<"\n";
		// cout<<cnt[l]<<" : :\n";
		if(t=='+'){
			int x; cin>>x;
			act(find(l),x);
		}
		else cout<<h[l]-cnt[l]<<"\n";
	}
	return 0;
}