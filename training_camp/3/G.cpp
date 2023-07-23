#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<ll> ask(vector<ll>a){
	cout<<"next ";
	for(auto i:a)cout<<i<<" ";
	cout<<endl;
	ll k; cin>>k;
	vector<ll>ret(10);
	fore(i,0,k){
		string s; cin>>s;
		for(auto j:s)ret[j-'0']=i;
	}
	return ret;
}

int main(){FIN;
	while(1){
		vector<ll>id=ask({0,1});
		id=ask({0});
		if(id[0]==id[1])break;
	}
	vector<ll>all;
	fore(i,0,10)all.pb(i);
	while(1){
		vector<ll>id=ask(all);
		if(id[0]==id[2])break;
	}
	cout<<"done"<<endl;
	return 0;
}
