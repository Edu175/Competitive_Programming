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

bool ask(ll i, ll j){
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	string ret; cin>>ret;
	if(ret=="-1")exit(0);
	if(ret=="YES")return 1;
	return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n==-1)exit(0);
		vector<vector<ll>>h(2);
		vector<ll>c(n);
		fore(i,0,n){
//			cout<<i<<":\n";
//			imp(h[0]);
//			imp(h[1]);
//			cout<<"\n";
			vector<ll>qs(2);
			if(SZ(h[0]))qs[0]=ask(h[0].back(),i);
			if(SZ(h[1]))qs[1]=ask(h[1].back(),i);
			c[i]=qs[0]+qs[1];
			if(!SZ(h[0])||qs[0])h[0].pb(i);
			else if(!SZ(h[1])||qs[1])h[1].pb(i);
			else {
				assert(h[0].back()>h[1].back()&&c[h[0].back()]==2);
				vector<ll>p;
				while(SZ(h[0])&&c[h[0].back()]==2&&h[0].back()>h[1].back())
					p.pb(h[0].back()),h[0].pop_back();
				while(SZ(p))h[1].pb(p.back()),p.pop_back();
				h[0].pb(i);
				swap(h[0],h[1]);
			}
		}
//		cout<<n<<":\n";
//			imp(h[0]);
//			imp(h[1]);
//			cout<<"\n";
		vector<ll>res(n);
		for(auto i:h[1])res[i]=1;
		cout<<"! ";
		for(auto i:res)cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
