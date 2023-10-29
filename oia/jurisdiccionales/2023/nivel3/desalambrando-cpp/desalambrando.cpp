#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
ll uf[MAXN];
void uf_init(){mset(uf,-1);}
ll uf_find(ll x){return (uf[x]<0?x:uf_find(uf[x]));}
ll uf_join(ll x, ll y){
	x=uf_find(x); y=uf_find(y);
	if(x==y)return 0;
	if(-uf[x]<-uf[y])swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
	return 1;
}

long long desalambrando(int N, vector<int> &A, vector<int> &B, vector<int> &C) {
	ll n=N,m=SZ(A);
	vector<pair<ll,ii>>a;
	fore(i,0,m)a.pb({C[i],{A[i],B[i]}});
	sort(ALL(a)); reverse(ALL(a));
	ll res=0,sum=0;
	fore(i,0,m)sum+=C[i];
	uf_init();
	for(auto [c,i]:a){
		if(uf_join(i.fst,i.snd))res+=c;
	}
	return sum-res;
}
