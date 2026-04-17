#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		vv ar[n];
		ll gr[n];
		mset(gr,0);
		fore(i,0,m){
			int x,y; cin>>x>>y;
			x--,y--;
			gr[x]++;
			gr[y]++;
			ar[x].pb(y);
			ar[y].pb(x);	
		}
		ll rta=0;
		queue<ll> matar;
		set<ll> muertos;
		fore(i,0,n){
			if(gr[i]==1) matar.push(i); 
		}
		while(SZ(matar)){
			int x = matar.front();
			// cout<<"ddd "<<x<<"\n";
			matar.pop();
			if(muertos.count(x)) continue;
			muertos.insert(x);
			rta++;
			for(auto y: ar[x]){
				if(!muertos.count(y)){
					muertos.insert(y);
					for(auto k:ar[y]){
						gr[k]--;
						if(gr[k]==1){
							matar.push(k);
						}
					}
				}
			}
		}
		ll aux = n-SZ(muertos);
		cout<<rta+aux/2<<"\n";
	}
	return 0;
}