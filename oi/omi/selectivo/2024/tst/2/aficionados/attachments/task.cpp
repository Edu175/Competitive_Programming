#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto slkgh:v)cout<<slkgh.fst<<","<<slkgh.snd<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int Doblemente_Aficionados(int n, vector<int> a) {
	// cout<<"\n";
	vector<ll>oc(n);
	fore(i,0,n){
		a[i]--;
		oc[a[i]]++;
	}
	vector<ll>hago(n+1);
	fore(i,0,n)hago[oc[i]]=1;
	ll res=0;
	fore(k,1,n+1){ // O(sqrt(n))
		set<ii>st;
		vector<ll>c(n);
		auto upd=[&](ll v, ll q){
			st.erase({c[v],v});
			c[v]+=q;
			st.insert({c[v],v});
		};
		ll p=0;
		fore(i,0,n){
			while(p<n&&c[a[p]]+1<=k)upd(a[p++],1);
			if(SZ(st)>=2&&
			prev((st.end()))->fst==
			prev(prev(st.end()))->fst)
				res=max(res,p-i);
			// cout<<k<<": "<<i<<","<<p<<": "; imp(st);
			upd(a[i],-1);
		}
	}
	// cout<<res<<"\n";
	return res;
}