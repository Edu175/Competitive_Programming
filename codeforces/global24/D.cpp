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

ll nC2(ll n){
	return (n*(n-1))/2;
}
ll f(ll n,ll p){
	ll res=1;
	fore(i,1,n+1)res=(res*i)%p;
	return res;
}
ll fpow(ll b, ll e, ll MOD){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

int main(){FIN;
	ll n,p; cin>>n>>p;
	ll rf=(n+1)/2;
	cout<<"red flag: "<<rf<<"\n";
	cout<<"tri todos: "<<nC2(n-1)<<"\n";
	
	ll trf=0;
	fore(i,2,rf+1){
		trf=(trf+(((rf-i+1)*(rf-i)%p)*2)%p)%p;
		cout<<i<<": "<<(((rf-i+1)*(rf-i)%p)*2)<<"\n";
	}
	cout<<"tri rf: "<<trf<<"\n";
	ll tri=((nC2(n-1)-trf)+p)%p;
	cout<<"tri c/uno: "<<tri<<"\n";
	tri=(tri*n)%p;
	tri=(tri*fpow(3,p-2,p))%p;
	//cout<<"total: "<<tri<<"\n";
	ll esp=0;
	if(n%2==0)esp=(n/2)*(n-2);
	tri=(tri-esp+p)%p;
	//cout<<tri<<" "<<esp<<"\n";
	ll cn=(tri*3)%p,ce=(esp*4)%p;
	ll res=(cn*f(n-3,p))%p+(ce*f(n-3,p))%p;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
