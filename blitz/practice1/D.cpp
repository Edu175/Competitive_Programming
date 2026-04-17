// #include <bits/stdc++.h>
#include <cassert>
#include <cfloat>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <map>
#include <new>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define inp(v) {for(auto &i:v)cin>>i;}
#define menos1(v) {for(auto &i:v)i--;}
#define pres cout<<res<<"\n";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool dig(ll x){return x>='0'&&x<='9';}

ll cv(string s){
	ll pot=1,sum=0;
	fore(_,0,SZ(s)){
		sum+=pot;
		pot*=26;
	}
	ll x=0;
	for(auto i:s)x=26*x+i-'A';
	x+=sum;
	return x;
}

string cv(ll x){
	ll sz=0;ll pot=1;
	while(x>=0){
		x-=pot;
		if(x<0){
			x+=pot;
			break;
		}
		sz++;
		pot*=26;
	}
	string l;
	while(x)l.pb('A'+x%26),x/=26;
	while(SZ(l)<sz)l.pb('A');
	reverse(ALL(l));
	return l;
}

const ll MAXV=1e6+5;
int main(){FIN;
	// string mem[MAXV];
	// fore(i,0,MAXV)
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		// ll d1=0;
		// fore(i,0,SZ(s)-1){
		// 	d1|=dig(s[i])&&!dig(s[i]);
		// }
		ll n=SZ(s);
		vector<string> bl;
		string t;
		fore(i,0,n){
			t.pb(s[i]);
			if(i==n-1||dig(s[i])!=dig(s[i+1])){
				bl.pb(t);
				t.clear();
			}
		}
		// imp(bl)
		if(SZ(bl)==2){
			ll x=cv(bl[0]);
			ll y=stoll(bl[1]);
			cout<<"R"<<y<<"C"<<x<<"\n";
		}
		else {
			ll y=stoll(bl[1]);
			ll x=stoll(bl[3]);
			string l=cv(x);
			cout<<l<<y<<"\n";
		}
	}
	return 0;
}
