#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef float ll;

ll pot10(ll x){
	ll res=1;
	fore(i,0,x)res*=10;
	return res;
}
ll res1;
ll res2;
ll cant1;
ll cant2;

vector<ll> op2(ll a,ll b){
	vector<ll> res;
	res.pb(a+b);
	res.pb(a-b);
	res.pb(b-a);
	res.pb(a*b);
	res.pb(a/b);
	res.pb(b/a);
	return res;
}

void inop3(ll v1, ll v2, ll v3){
	for(auto i:op2(v1,v2)){
		for(auto j:op2(i,v3)){
			if(j==res1)cant1++;
			else if(j==res2)cant2++;
		}
	}
}

void op3(ll a,ll b,ll c){
	inop3(a,b,c);
	inop3(a,c,b);
	inop3(b,c,a);
}

void inop4(ll v1, ll v2, ll v3, ll v4){
	for(auto i:op2(v1,v2)){
		op3(i,v3,v4);
	}
}

void op4(ll a,ll b,ll c,ll d){
	inop4(a,b,c,d);
	inop4(a,c,b,d);
	inop4(a,d,c,b);
	inop4(b,c,d,a);
	inop4(b,d,c,a);
	inop4(c,d,a,b);
}

void inop5(ll v1, ll v2, ll v3, ll v4, ll v5){
	for(auto i:op2(v1,v2)){
		op4(i,v3,v4,v5);
	}
}

void op5(ll a,ll b,ll c,ll d,ll e){
	inop5(a,b,c,d,e);
	inop5(a,c,b,d,e);
	inop5(a,d,c,b,e);
	inop5(a,e,c,b,d);
	inop5(b,c,d,a,e);
	inop5(b,d,c,a,e);
	inop5(b,e,c,a,d);
	inop5(c,d,a,b,e);
	inop5(c,e,a,b,d);
	inop5(d,e,a,b,c);
}

void inop6(ll v1, ll v2, ll v3, ll v4, ll v5, ll v6){
	for(auto i:op2(v1,v2)){
		op5(i,v3,v4,v5,v6);
	}
}

void op6(ll a,ll b,ll c,ll d,ll e,ll f){
	inop6(a,b,c,d,e,f);
	inop6(a,c,b,d,e,f);
	inop6(a,d,c,b,e,f);
	inop6(a,e,c,b,d,f);
	inop6(a,f,c,b,d,e);
	inop6(b,c,d,a,e,f);
	inop6(b,d,c,a,e,f);
	inop6(b,e,c,a,d,f);
	inop6(b,f,c,a,d,e);
	inop6(c,d,a,b,e,f);
	inop6(c,e,a,b,d,f);
	inop6(c,f,a,b,d,e);
	inop6(d,e,a,b,c,f);
	inop6(d,f,a,b,c,e);
	inop6(e,f,a,b,c,f);
}

int main(){
	ll a,b,c,d,e,f,r,s; 
	cout<<"Introducir 6 cartas: "; cin>>a>>b>>c>>d>>e>>f;
	cout<<"Introducir las 2 cartas de resultado: "; cin>>r>>s;
	FIN;
	res1=r*pot10(((s)?(int(log10(s))+1):1))+s;
	res2=s*pot10(((r)?(int(log10(r))+1):1))+r;
	//cout<<res1<<" "<<res2<<"\n";
	cant1=0; cant2=0;
	op6(a,b,c,d,e,f);
	if(res1==res2){
		cout<<"Existen "<<cant1<<" posibles soluciones con "<<res1<<"\n";
	}
	else{
		cout<<"Existen "<<cant1+cant2<<" posibles soluciones:\n";
		cout<<"Con "<<res1<<": "<<cant1<<"\n";
		cout<<"Con "<<res2<<": "<<cant2<<"\n";
	}
	return 0;
}
