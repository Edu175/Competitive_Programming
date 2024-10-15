#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll tras(char c){
	if(c=='I') return 1;
	if(c=='V') return 5;
	if(c=='X') return 10;
	else return 50;
}
ii num(string k){
	ll r=tras(k[SZ(k)-1]);
	ll n=SZ(k);
	ll cnt=0;
	fore(i,1,SZ(k))	{
		if(tras(k[n-i-1])<tras(k[n-i])) cnt++;
		if(cnt>1) return {0,0};
		else r+=tras(k[n-i-1]);
	}
	return {r,1};
}
bool check(string s){
	ll l=0,r=0,_=0,u=0;
	string k="";
	fore(i,0,SZ(s)){
		if(s[i]!='+'&&s[i]!='-'&&s[i]!='='){
			k+=s[i];
		}
		else{
			if(!num(k).snd) return 0;
			l+=num(k).fst;
			if(s[i]=='+'||s[i]=='-'||s[i]=='='){
				
			}
		}
	}
	
}
int main(){
	JET
	string s;
	ll n=SZ(s);
	fore(i,0,n){
		
	}
	return 0;
}
