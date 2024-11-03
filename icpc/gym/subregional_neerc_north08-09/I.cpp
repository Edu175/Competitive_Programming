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
	#ifdef ONLINE_JUDGE
    freopen("important.in","r",stdin);     freopen("important.out","w",stdout);
    #endif
	vector<char>a;
	char c;
	while(cin>>c){
		if(c>='A'&&c<='Z')a.pb(c);
	}
	cout<<"Yes\n~"<<a[0];
	fore(i,0,SZ(a)){
		cout<<" | "<<a[i];
	}
	cout<<"\n";
	return 0;
}