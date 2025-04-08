#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll flag=s[0]=='>';
		ll p=-1;
		ll n=SZ(s);
		fore(i,0,n)if(s[i]=='-')p=i;
		if(p==-1||n-p-1<3)flag=0;
		if(!flag){
			cout<<"No\n";
			continue;
		}
		vector<ii>res;
		for(ll i=n-3;i>p;i--)res.pb({0,i+2});
		fore(i,0,p)if(s[i]=='>')res.pb({i,p+3});
		
		// string ans(n,'*');
		// for(auto [l,r]:res){
		// 	assert(l>=0&&l<n&&r<n&&r-l+1>=5);
		// 	fore(i,l+1,r-2)ans[i]='-';
		// 	ans[l]=ans[r]=ans[r-1]=ans[r-2]='>';
		// }
		// assert(s==ans);
		
		
		cout<<"Yes "<<SZ(res)<<"\n";
		for(auto [l,r]:res){
			cout<<l+1<<" "<<r-l+1<<"\n";
		}
	}
	
	return 0;
}
