#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfhg:v)cout<<dfhg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=1024*1024+5;

ll n,m;
ii cv(ll x){return {x/m,x%m};}
ll cv(ii x){return x.fst*m+x.snd;}
char a[MAXN];
vector<ii> dir={{1,0},{0,1},{-1,0},{0,-1}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
bool allowed(ii x){
	return x.fst>=0&&x.fst<n&&x.snd>=0&&x.snd<m;
}
ll num(ll x){
	auto i=cv(x);
	ll res=0;
	for(auto d:dir){
		auto j=d+i;
		if(!allowed(j))continue;
		auto y=cv(j);
		res+=a[y]=='.';
	}
	return res;
}
ll count(){
	ll res=0;
	fore(x,0,n*m){
		if(a[x]=='.')res+=num(x)==1;
	}
	return res;
}
int main(){FIN;
	cin>>n>>m;
	ll k; cin>>k;
	ll sd; srand((long long)&sd);
	fore(i,0,n*m)cin>>a[i];
	fore(i,0,n)if(i%4==0)a[cv({i,m-1})]='X';
	fore(i,1,n){
		for(ll j=0,p=i&1;j+2<m;j+=3,p^=1){
			if(i<=1||p)a[cv({i,j})]=a[cv({i,j+2})]='X';
		}
	}
	cerr<<"found "<<count()<<" out of "<<k<<"\n";
	fore(i,0,n){
		fore(j,0,m)cout<<a[cv({i,j})];
		cout<<"\n";
	}
	
}