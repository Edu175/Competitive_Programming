#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,renison=b;i<renison;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii; 
typedef vector<ll> vv;

ll INF=1e9;

int main(){
	FIN;
	ll n; cin>>n;
	vector<ll> box={INF,INF,INF};
	fore(i,0,n){
		ll a,b,c; cin>>a>>b>>c;
		vector<ll> v={a,b,c};
		sort(ALL(v));
		fore(i,0,3)box[i]=min(box[i],v[i]);
	}
	ll res=1;
	for(auto i:box)res*=i;
	cout<<res<<"\n";
	return 0;
}