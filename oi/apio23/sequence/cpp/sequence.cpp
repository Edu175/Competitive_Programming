#include "sequence.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,apio=b;i<apio;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto slkdh:v)cout<<slkdh<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
};

int sequence(int N, std::vector<int> A) {
	ll n=N;
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i]-1;
	vector<ll>pos[n];
	fore(i,0,n)pos[a[i]].pb(i);
	STree bal(n);
	fore(i,0,n)bal.upd(i,1);
	ll res=0;
	fore(i,0,n){
		cout<<"\nin "<<i<<":\n";
		for(auto j:pos[i])bal.upd(j,0);
		vector<ll>b;
		ll q=1;
		if(pos[i][0]!=0)
		fore(j,0,SZ(pos[i])){
			ll l=pos[i][j],r=pos[i][j+1];
			if(l+1!=r){
				b.pb(q);
				q=1;
				b.pb(bal.query(l+1,r));
			}
			else q++;
		}
		
		imp(b);
		fore(l,0,SZ(b)){
			ll c=0,dif=0;
			fore(r,l,SZ(b)){
				if(r&1)dif+=b[r];
				else c+=b[r];
				if(abs(dif+c)&1){
					if(c-1>=abs(dif))res=max(res,c);
				}
				else {
					if(c>=abs(dif))res=max(res,c);
				}
			}
		}
		for(auto j:pos[i])bal.upd(j,-1);
	}
	return res;
}
