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

int main(){FIN;
	vector<string> out0,out1;
	vector<ll>v;
	string a; cin>>a;
	while(a!="flag")out0.pb(a),cin>>a;
	cin>>a;
	while(a!="flag")out1.pb(a),cin>>a;
	ll n=min(SZ(out0),SZ(out1));
	fore(i,0,n){
		if(out1[i]!=out0[i])v.pb(i);
	}
	//cout<<SZ(out0)<<" "<<SZ(out1)<<"\n";
	cout<<SZ(v)<<"\n";
	for(auto i:v)cout<<i+1<<" ";
	return 0;
}
