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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		string a,b; cin>>a>>b;
		ll count[2];
		count[0]=0, count[1]=0;
		string ap;
		fore(i,0,n){
			if(i<=n-m){
				count[a[i]-'0']++;
			}
			if(i>=n-m)ap.pb(a[i]);
		}
		//cout<<ap<<"\n"<<b<<"\n";
		//imp(count);
		bool flag=1;
		fore(i,1,m)if(b[i]!=ap[i])flag=0;//,cout<<"str ";
		if(count[b[0]-'0']==0)flag=0;//,cout<<"cant ";
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
