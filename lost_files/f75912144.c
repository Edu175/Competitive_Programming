#include "meetings.h"

#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(ll i=a,ioi=b; i<ioi; i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto sdklhg:v)cout<<sdklhg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;

const ll K=18;
//#define oper min
vector<ll>h;
ll oper(ll a, ll b){ // arg max
	if(h[a]>h[b])return a;
	return b;
}

struct ST{
	ll st[K][1<<K]; ll n;
	void init(vector<ll>a){
		n=SZ(a);
		fore(i,0,n)st[0][i]=i;
		fore(k,1,K)fore(i,0,n-(1<<k)+1){
			//if(i+(1<<k)>n)continue;
			st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
		}
	}
	ll query(ll s, ll e){
		ll k=63-__builtin_clzll(e-s);
		ll res=oper(st[k][s],st[k][e-(1<<k)]);
		//cout<<"query "<<s<<","<<e<<": "<<res<<endl;
		//cout<<st[k][s]<<" "<<st[k][e-(1<<k)]<<"\n";
		return res;
	}
};

ST st;
ll dnc(ll l, ll r){
	//cout<<l<<","<<r<<endl;
	if(r-l<=0)return 0;
	if(r-l==1)return h[l];
	ll m=st.query(l,r);
	//cout<<m<<endl;
	return min(dnc(l,m)+(r-m)*h[m],dnc(m+1,r)+(m-l+1)*h[m]);
}

std::vector<long long> minimum_costs(std::vector<int> H, std::vector<int> l,
                                     std::vector<int> r) {
  int q = l.size();
  fore(i,0,SZ(H))h.pb(H[i]);
  std::vector<long long> C(q);
  /*for (int j = 0; j < Q; ++j) {
    C[j] = H[L[j]];
  }*/
  st.init(h);
  fore(i,0,q){
  	r[i]++;
  	/*vector<ii>a;
  	fore(l[i],0,r[i])a.pb({h[i],i});
  	sort(ALL(a));*/
  	C[i]=dnc(l[i],r[i]);
  }
  /*cout<<q<<"\n";
  cout<<"C "; imp(C);*/
  return C;
}
