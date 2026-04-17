#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

bool p = 0;
ii punt[2];

void add(bool b){
	punt[b].snd++;
	if(punt[b].snd == 10 || (punt[b].snd >=5 && punt[b].snd - punt[b^1].snd >=2)){
		punt[b].fst++;
		punt[0].snd = 0;
		punt[1].snd = 0;
	}
	p = b;
}

void query(){
	if(punt[0].fst == 2){
		cout<<punt[0].fst<<" (winner)  - "<<punt[1].fst<<"\n";
		return;
	}
	if(punt[1].fst == 2){
		cout<<punt[0].fst<<" - "<<punt[1].fst<<" (winner)\n";
		return;
	}
	cout<<punt[0].fst<<" ("<<punt[0].snd;
	if(!p)cout<<"*";
	cout<<") - "<<punt[1].fst<<" ("<<punt[1].snd;
	if(p) cout<<"*";
	cout<<")\n";	
}

int main(){
	JET
	string s; cin>>s;
	for(auto x:s){
		if(x=='Q') query();
		if(x=='S') add(p);
		if(x=='R') add(p^1);
	}
	return 0;
}