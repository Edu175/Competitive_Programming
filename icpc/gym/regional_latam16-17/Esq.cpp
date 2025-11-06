#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

int main(){
    JET
	ll n,q; cin>>n>>q;
	vv a(n);
	vector<ii>sd;
	fore(i,0,n)cin>>a[i],sd.pb({a[i],i});
	sort(ALL(sd));
	vv pos(n);
	fore(i,0,n)pos[sd[i].snd]=i;
	while(q--){
		char ty; cin>>ty;
		if(ty=='Q'){
			ll l,r,k; cin>>l>>r>>k; k--; l-=2;
			ll u[2];
			for(int idx=0;idx<n;idx++){
				auto &[v,i]=sd[idx];
				u[!k]=v;
				k-=l<i&&i<r;
			}
			cout<<u[1]<<"\n";
		}
		else {
			ll i; cin>>i; i--;
			ll p=pos[i],q=pos[i+1];
			swap(sd[p].snd,sd[q].snd);
			swap(pos[i],pos[i+1]);
		}
	}
    return 0;
}