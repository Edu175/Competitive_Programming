#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,renison=b;i<renison;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii; 
typedef vector<ll> vv;

vector<ll> pot,mini,med,maxi;

pair<ll,ll> solve1(ll x, ll k){
	pair<ll,ll> res;
	if(x>=mini[k+1])res={min(med[k+1],x),pot[k+1]};
	else if(x>=maxi[k])res={maxi[k],pot[k]};
	else res=solve1(x,k-1);
	// cout<<"solve1 "<<x<<" "<<k<<" -> "<<res.fst<<" "<<res.snd<<"\n";
	return res;
}

vector<ll> solve(ll x, ll k){
	if(x%4!=0)return {};
	if(k==1&&x>0)return {};
	if(k==1)return {2};
	auto s=solve1(x,k);
	ll va=s.snd;
	x-=s.fst;
	auto s2=solve(x,k-1);
	if(SZ(s2)==0)return {};
	auto res=s2;
	res.pb(va);
	return res;
}

int main(){
	FIN;
	ll n,k; cin>>n>>k;
	pot.resize(k+4);
	mini.resize(k+4);
	med.resize(k+4);
	maxi.resize(k+4);
	fore(i,0,SZ(pot))pot[i]=(1ll<<i);
	mini[2]=0;
	med[2]=0;
	maxi[2]=4;
	fore(i,3,k+4){
		mini[i]=2*mini[i-1]+pot[i];
		med[i]=maxi[i-1]+med[i-1]+pot[i];
		maxi[i]=2*maxi[i-1]+pot[i];
	}
	// fore(i,0,k+4)cout<<pot[i]<<" "<<mini[i]<<" "<<med[i]<<" "<<maxi[i]<<"\n";
	while(n--){
		ll x; cin>>x;
		auto res=solve(x,k);
		if(SZ(res)==0)cout<<"-1\n";
		else{
			cout<<SZ(res)<<" ";
			for(auto i:res)cout<<i<<" ";
			cout<<"\n";
		}
	}
	return 0;
}