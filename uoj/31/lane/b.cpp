#include "lane.h"
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
#define der clockwise
#define izq anticlockwise

ll w=0;
void go(){
	if(!w)der();
	else izq();
}
void back(){
	if(w)der();
	else izq();
}
void turn(){w^=1;}
int sub1(){ // costs exactly 2n once empty
	ll n=0;
	while(1){
		if(ask())break; // +1
		n++;
		flip();
		der(); // +1
	}
	return n;
}
ll prv=1;
bool les(ll k){
	// cerr<<"les "<<k<<"\n";
	fore(i,0,k-prv){
		if(i==0||ask())flip();
		go();
	}
	prv=k;
	if(!ask())flip();
	turn();
	fore(i,0,k)go();
	return !ask();
}
bool is1(){
	ll x=ask();
	der();
	flip();
	izq();
	return ask()!=x;
}
int solve(int c) {
	if(c==1)return sub1();
	if(is1())return 1;
	if(!ask())flip();
	go();
	
	ll k=1,prim=0;
	while(!les(k))k+=k-prim,prim=1;
	turn();
	ll z=1;
	go();
	while(!ask()){
		z++;
		go();
	}
	// cerr<<k<<" "<<z<<": "<<k-z<<"\n";
	return k-z;
}
