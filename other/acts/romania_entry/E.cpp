#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	map<char,ll>trabuco;
	trabuco['R']=0;
	trabuco['G']=1;
	trabuco['B']=2;
	ll n; cin>>n;
	vector<pair<ll,char>>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	sort(ALL(a));
	vector<ll>res(3);
	fore(i,0,n){
		ll c=trabuco[a[i].snd];
		res[c]+=5*a[i].fst*a[i].fst+-(i?a[i-1].fst*a[i-1].fst:0);
	}
	cout<<"R - "<<res[0]<<"\n";
	cout<<"G - "<<res[1]<<"\n";
	cout<<"B - "<<res[2]<<"\n";
	return 0;
}
