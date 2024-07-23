#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
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
typedef unsigned long long ull;
static ull fun(ull x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}

int main(){JET
	ll n,m,k; cin>>n>>m>>k;
	vector<string>a(n);
	fore(i,0,n)cin>>a[i];
	vector<vector<ull>> has(m,vector<ull>(4));
	ull iden=0;
	fore(i,0,n)iden+=fun(i);
	fore(i,0,n)fore(j,0,m){
		has[j][a[i][j]-'A']+=fun(i);
	}
	ll res=-1;
	fore(i,0,n){
		ull h=0;
		fore(j,0,m)fore(l,0,4)if(l!=a[i][j]-'A')h+=has[j][l];
		if(h==(iden-fun(i))*k)res=i;
	}
	cout<<res+1<<"\n";
	return 0;
}