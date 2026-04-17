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

int main(){FIN;
	string s; cin>>s;
	ll n=SZ(s);
	string a[3];
	ll pot[3];
	pot[0]=1;
	fore(i,1,3)pot[i]=pot[i-1]*26;
	fore(h,0,3){
		a[h].resize(n,'.');
		fore(i,0,n)a[h][i]='a'+((i/pot[h])%26);
	}
	vector<ll>k(n,0);
	for(ll h=2;h>=0;h--){
		cout<<"? "<<a[h]<<endl;
		string t; cin>>t;
		fore(i,0,n)k[i]+=pot[h]*(t[i]-'a');
	}
	string res(n,'.');
	fore(i,0,n)res[k[i]]=s[i];
	cout<<"! "<<res<<"\n";
	return 0;
}
