#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXV=1e4+5;
ll cr[MAXV];

void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXV)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
int main(){
	JET
	init_sieve();
	ll M; cin>>M;
	fore(m,2,M)if(cr[m]==-1){
		set<ll> st;
		fore(x,0,m)fore(a,0,m)fore(b,0,m){
			unordered_set<ll> vis;
			ll p=x;
			while(!vis.count(p)){
				vis.insert(p);
				p=(p*a+b)%m;
			}
			st.insert(SZ(vis));
		}
		vector<ll> fd;
		for(auto i:st){
			ll good=1;
			for(auto j:st)if(i<j&&j%i==0){good=0;break;}
			if(good)fd.pb(i);
		}
		cerr<<"m "<<m<<": ";
		// cerr<<"tamanio "<<SZ(fd)<<"\n";
		show(fd)
	}
	return 0;
}
