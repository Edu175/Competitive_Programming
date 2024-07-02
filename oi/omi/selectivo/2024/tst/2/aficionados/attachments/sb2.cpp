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
	map<ll,vector<ll>>pos;
	ll s=0;
	pos[s].pb(-1);
	fore(i,0,n){
		s+=a[i]?1:-1;
		pos[s].pb(i);
	}
	ll res=0;
	fore(x,-n,n+1)if(SZ(pos[x])){
		res=max(res,pos[x].back()-pos[x][0]);
	}
	
	// cout<<res<<"\n";
	return res;
}