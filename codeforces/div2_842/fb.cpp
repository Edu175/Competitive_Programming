#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,MOD; cin>>n>>MOD;
	vector<ll> c(4,0),j(n+1,0);
	vector<ll>a;
	fore(i,0,3*n)a.pb(i);
	vector<ll>A1,A3;
	fore(i,0,n)A1.pb(i);
	fore(i,2*n,3*n)A3.pb(i);
	ll cnt1=0,cnt2=0,cnt3=0;
	ll uno=1;
	vector<vector<ll>>dbg;
	do{
		ll t=2;
		vector<ll>a1,a3;
		fore(i,0,n)a1.pb(a[i]);
		fore(i,2*n,3*n)a3.pb(a[i]);
		if(a1==A1||a3==A3)t=1;
		ll f1=0,f3=0;
		fore(i,0,n)if(a[i]>=2*n)f1=1;
		fore(i,2*n,3*n)if(a[i]<n)f3=1;
		if(t!=1&&f1&&f3)t=3;
		if(!f1&&!f3){
			cnt2++;
			ll m=0;
			fore(i,n,2*n)m+=(a[i]<n);
			j[m]++;
			if(m==1)dbg.pb(a);
		}
		if(!f1)cnt1++;
		if(!f3)cnt3++;
		if(uno++==1)c[0]++;
		else c[t]++;
	}
	while(next_permutation(ALL(a)));
	ll res=0;
	cout<<"cnt1: "<<cnt1<<" "<<cnt3<<"\n";
	cout<<"cnt2:\n";
	fore(i,0,n+1)cout<<i<<": "<<j[i]<<"\n";
	cout<<cnt2<<"\n";
	fore(i,0,4)res+=c[i]*i,cout<<i<<": "<<c[i]<<"\n";
	cout<<res<<"\n";
	for(auto v:dbg){
		for(auto i:v)cout<<i+1<<" ";cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
