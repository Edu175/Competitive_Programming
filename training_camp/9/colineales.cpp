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
typedef long long ll;

bool colineales(vector<pair<ll,ll>>abc){
	sort(ALL(abc));
	reverse(ALL(abc));
	pair<ll,ll> a=abc[0],b=abc[1],c=abc[2];
	ll cx1=a.fst-b.fst;
	ll cy1=a.snd-b.snd;
	ll cx2=b.fst-c.fst;
	ll cy2=b.snd-c.snd;
	ll g1=gcd(cx1,cy1);
	ll g2=gcd(cx2,cy2);
	cx1/=g1, cy1/=g1;
	cx2/=g2, cy2/=g2;
	//cout<<cx1<<","<<cy1<<" "<<cx2<<","<<cy2<<"\n";
	if(cx1==cx2&&cy1==cy2)return 1;
	else return 0;
}

int main(){
	ll t; cin>>t;
	while(t--){
		vector<pair<ll,ll>>abc(3);
		fore(i,0,3)cin>>abc[i].fst>>abc[i].snd;
		cout<<colineales(abc)<<"\n";
	}
	return 0;
}
