#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;


void caso(ll c){
	c-=4;
	string s = "R";
	while(c>12){
		s+="LRRL";
		c-=8;
	}
	assert(c==12);
	string s1 = s; reverse(ALL(s));
	s+=s1;
	s+="LRRLRLRRLRRLRL";
	cout<<s<<"\n";
}

int main(){
	JET
	ll r,c; cin>>r>>c;
	if(r&1) r--;
	if(c&1) c--;
	if(!r){
		if(c<=10) c = 4;
		else c = (c/4)*4;
	}
	if(!r && c%8 == 0){
		caso(c);
		return 0;
	}
	c-=4;
	string s = "R";
	while(c>=8){
		s+="LRRL";
		c-=8;
	}
	while(r>2){
		s+="S";
		r-=2;
	}
	string s1 = s; reverse(ALL(s));
	s+=s1;
	// cout<<"asa "<<s<<"\n"; 
	if(!r) s+="RR";
	else if(!c) s+="SRRS";
	else if(c==2) s+="SRSRRL";
	else if(c==4) s+="LRRLRRSS";
	else if(c==6) s+="SRLRSRRLRL";
	cout<<s<<"\n";
	return 0;
}