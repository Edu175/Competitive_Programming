#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi,popcnt,lzcnt")
const ll MAXN=3e9+5;

bitset<MAXN> vis;
ll tot=0;
set<ll>st;
ll n;
ll prv;
void cant(ll num){
	ll w=0,h=0,q=0;
	ll _num=num;
	fore(e2,0,35)if(num<=n){
		ll v=num;
		
		fore(e3,0,35)if(v<=n){
			h=max(h,e2);
			w=max(w,e3);
			q++;
			// cout<<e2<<" "<<e3<<": "<<v<<endl;
			// cout<<"*";
			assert(!vis[v]);
			vis[v]=1;
			// tmp.pb(v);
			v*=3;
		}
		// cout<<"\n";
		num*=2;
	}
	if(!st.count(q))tot+=(1ll<<w)*h*w;
	st.insert(q);
	if(clock()-prv>=5*CLOCKS_PER_SEC)cout<<_num<<": "<<tot<<" parcial"<<endl,prv=clock();
}

int main(){FIN;
	cin>>n;
	prv=clock();
	fore(i,1,n+1){
		if(i%2&&i%3)cant(i);
	}
	cout<<tot<<"\n";
	// vv tmp;
	// // solo el 1
	// ll num=1; // aca poner id, en vez de 1
	// fore(e2,0,35){
	// 	ll v=num;
		
	// 	fore(e3,0,35)if(v<=n){
	// 		// cout<<e2<<" "<<e3<<": "<<v<<endl;
	// 		cout<<"*";
	// 		assert(!vis[v]);
	// 		vis[v]=1;
	// 		tmp.pb(v);
	// 		v*=3;
	// 	}
	// 	cout<<"\n";
	// 	num*=2;
	// }
	// cout<<SZ(tmp)<<"\n";
	// imp(tmp)
	return 0;
}
