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

ll dist(pair<ll,ll>p1,pair<ll,ll>p2){
	ll cx=abs(p1.fst-p2.fst);
	ll cy=abs(p1.snd-p2.snd);
	return cx*cx+cy*cy;
}

bool colineales(pair<ll,ll>p1,pair<ll,ll>p2,pair<ll,ll>p3){
	ll cx1=p1.fst-p2.fst;
	ll cy1=p1.snd-p2.snd;
	ll cx2=p2.fst-p3.fst;
	ll cy2=p2.snd-p3.snd;
	//cout<<cx1<<","<<cy1<<" "<<cx2<<","<<cy2<<"\n";
	if(cx1==cx2&&cy1==cy2)return 1;
	else return 0;
}

int main(){FIN;
	pair<ll,ll>a,b,c; cin>>a.fst>>a.snd>>b.fst>>b.snd>>c.fst>>c.snd;
	ll flag=1;
	if(dist(a,b)!=dist(b,c))flag=0;//,cout<<"no iguales\n";
	if(colineales(a,b,c))flag=0;//,cout<<"colineales\n";
	if(flag)cout<<"YES";
	else cout<<"NO";
	return 0;
}
//Sən məğlub oldun
