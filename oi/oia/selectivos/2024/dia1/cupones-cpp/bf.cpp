#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto mjgltr:v)cout<<mjgltr<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

set<ll>st;
ll sum=0;
ll query(){ //difference
	ll c=0,res=0;
//	cout<<"query "; imp(st);
	for(auto i:st){
		if((c&1)!=(SZ(st)&1))res+=i;
		else res-=i;
		c^=1;
	}
//	cout<<res<<"\n";
	return res;
}

ll update(ll x){
	if(st.count(x))st.erase(x);
	else st.insert(x);
	ll dif=query();
	return (dif+sum)/2;
}
long long agregar(long long x) {
	sum+=x;
	return update(x);
}

long long sacar(long long x) {
	sum-=x;
	return update(x);
}
