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
typedef pair<ll,ll> ii;

const ll A=60;
const ll B=100;

ii dp[A][B];
ll cho[A][B];
ll n;
ii f(ll i, ll s){
	if(s<0||s>=20)return {0,0}; //6
	if(i==-1)return {s==0,0};
	auto &res=dp[i][s];
	if(res.fst!=-1)return res;
	fore(j,0,4){
		auto resi=f(i-1,(s-j)*2+((n>>(i-1))&1));
		resi.snd+=(j==3)<<i;
		if(resi>res)cho[i][s]=j,res=resi;
	}
	//cout<<i<<" "<<s<<": "<<res.fst<<","<<res.snd<<" | "<<cho[i][_s]<<endl;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		ll k=63-__builtin_clzll(n);
		fore(i,0,A)fore(j,0,B)dp[i][j]={-1,-1};
		ll on=(n>>k)&1;
		auto rq=f(k,on);
		//cout<<"can? "<<rq.fst<<","<<rq.snd<<"\n";
		vector<ll>res(3);
		for(ll i=k,s=on;i>=0;i--){
			ll j=cho[i][s];
			//cout<<i<<" "<<s<<": "<<j<<endl;
			fore(h,0,j)res[h]+=1ll<<i;
			s=(s-j)*2+((n>>(i-1))&1);
		}
		imp(res);
	}
	return 0;
}
