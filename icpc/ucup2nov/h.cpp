#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
ll cv(string s){
	reverse(ALL(s));
	while(SZ(s)&&s.back()=='0')s.pop_back();
	reverse(ALL(s));
	if(SZ(s))return stoll(s);
	return 0;
}

ii f(ll n){
	if(n<10)return {0,0};
	auto s=to_string(n);
	ll mn=n,p=-1;
	fore(e,1,SZ(s)){
		auto l=cv(s.substr(0,e)),r=cv(s.substr(e));
		if(abs(r-l)<mn)mn=abs(r-l),p=e;
	}
	return {mn,p};
}
ll bar(ll n){
	if(n<10)return -1;
	auto s=to_string(n);
	ll mn=n,p=-1;
	fore(e,1,SZ(s)){
		auto l=cv(s.substr(0,e)),r=cv(s.substr(e));
		if(abs(r-l)<mn)mn=abs(r-l),p=e;
	}
	return p;
}
ll sum(ll l, ll r){
	return r*(r-1)/2-l*(l-1)/2;
}
ll getall(ll a, ll l, ll r){
	if(a>=l&&a<r){
		return 
		a*(a-l)-sum(l,a)+
		sum(a,r)-a*(r-a);
	}
	return abs(sum(l,r)-a*(r-l));
}
ll pot[19];
void solve(ll k, ll R){ // k-length, [10,R)
	ll pe=(k-1)/2,z=1,a=1,n=;
	
}

int main(){FIN;
	pot[0]=1;
	fore(i,1,19)pot[i]=pot[i-1]+
	ll cnt=0,bef=-1;
	fore(i,10,ll(1e9)){
		ll now=bar(i);
		if(bef!=now){
			cnt++;
			cout<<i<<": "<<now<<"\n";
		}
		bef=now;
	}
	cout<<cnt<<" CNT\n";
	// fore(i,10,10000000)cout<<bar(i)<<"\n";
	// fore(n,10,1000000){
	// 	info(n);
	// }
	
	return 0;
}
