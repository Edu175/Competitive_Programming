#include "insects.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto djfhg:v)cout<<djfhg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

void in(ll i){
	move_inside(i);
}
void out(ll i){
	move_outside(i);
}
ll ask(){
	return press_button();
}

//9

int min_cardinality(int N){
	ll n; mt19937 rng(time(0)); n=N;
	vector<ll>a;
	fore(i,0,n)a.pb(i);
	ll res=0;
	ll k=-1;
	while(1){
		vector<ll>ai;
		vector<ll>dif;
		//random_shuffle(ALL(a),rnd());
		shuffle(ALL(a),rng);
		for(auto i:a){
			//cout<<i<<": "; imp(dif);
			if(k==-1||SZ(dif)<k){
				in(i); dif.pb(i);
				if(ask()==2)out(i),ai.pb(i),dif.pop_back();
			}
			else {
				ai.pb(i);
			}
		}
		//imp(a);
		//imp(dif);
		//cout<<"\n";
		if(k!=-1&&SZ(dif)!=k)break;
		res++;
		if(k==-1&&SZ(dif)==1){
			res=n;
			break;
		}
		k=SZ(dif);
		a=ai;
		for(auto i:dif)out(i);
	}
	return res;
}
