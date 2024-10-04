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
// const ll MAXV=2e6+5;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		map<ll,ll>mas,menos;
		set<ll> todo;
		fore(i,0,n){
			ll d,a; cin>>d>>a;
			mas[d]+=a;
			menos[d+k]+=a;
			todo.insert(d);
			todo.insert(d+k);
		}
		ll s=0,res=0,got=0;
		for(auto i:todo){
			s+=mas[i];
			ll q=min(got,menos[i]);
			menos[i]-=q,got-=q;
			s-=menos[i];
			if(s<m)got+=s,s=0;
			else res++,s-=m,got+=m;
		}
		
	}
	return 0;
}
