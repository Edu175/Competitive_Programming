#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
double distancia(pair<double,double>p,pair<double,double>q){
	return sqrt((p.fst-q.fst)*(p.fst-q.fst)+(p.snd-q.snd)*(p.snd-q.snd));
}
double avg(vector<double>v){
	double n=0,s=0;
	for(auto i:v)n++,s+=i;
	return s/n;
}
int main(){FIN;
	ll n;cin>>n;
	vector<pair<ll,ll>>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	vector<double>d;
	sort(ALL(a));
	do{
		double D=0;
		fore(i,0,n-1)D+=(distancia(a[i],a[i+1]));
		d.pb(D);
		/*for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";
		cout<<"\n";
		for(auto i:d)cout<<i<<" ";
		cout<<"\n";*/
	}
	while(next_permutation(ALL(a)));
	cout<<fixed<<setprecision(13)<<avg(d)<<"\n";
	 return 0;
}
