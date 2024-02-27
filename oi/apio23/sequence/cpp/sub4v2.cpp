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
typedef int ll;
typedef pair<ll,ll> ii;
const ll C=5e5,MAXN=2*C+5;
#define NEUT 3*C
#define oper min
struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
ll l[MAXN],r[MAXN];
bool cmp(ll i, ll j){
	return ii({l[i],i})<ii({l[j],j});
}
int sequence(int N, std::vector<int> A) {
	ll n=N;
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i]-1;
	vector<ll>pos[n];
	fore(i,0,n)pos[a[i]].pb(i);
	vector<ll>s(n);
	fore(i,0,n)s[i]=1;
	ll res=0;
	fore(i,0,n)if(SZ(pos[i])){
		//cout<<"\nin"<<i<<":\n";
		for(auto j:pos[i])s[j]=0;
		//imp(s);
		ll sum=0,rew=0;
		vector<ll>rw(n+1);
		vector<ll>ev{n};
		l[n]=r[n]=rw[n]=0;
		fore(j,0,n){
			sum+=s[j],rew+=a[j]==i;
			rw[j]=rew;
			l[j]=sum-rew,r[j]=sum+rew;
			ev.pb(j);
			//cout<<j<<": "<<sum<<" "<<rew<<"\n";
			//cout<<"add "<<p<<","<<q<<" "<<rew<<"\n";
			//cout<<res<<"\n\n";
		}
		sort(ALL(ev),cmp); reverse(ALL(ev));
		STree st(2*n+5+C);
		for(auto i:ev){
			/*if(i<0){
				cout<<"-1\n";
				st.upd(C,0);
				continue;
			}*/
			//cout<<i<<": "<<l[i]<<","<<r[i]<<": "<<rw[i]<<" - "<<st.query(0,r[i]+C+1)<<" = "<<rw[i]-st.query(0,r[i]+C+1)<<"\n";
			res=max(res,rw[i]-st.query(0,r[i]+C+1));
			st.upd(r[i]+C,rw[i]);
		}
		//cout<<res<<"\n";
		for(auto j:pos[i])s[j]=-1;
	}
	return res;
}
