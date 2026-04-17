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
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": \n";
		ll r,c; cin>>r>>c;
		fore(i,0,r*2+1){
			fore(j,0,c*2+1){
				if((i==0||i==1)&&(j==0||j==1)){
					cout<<'.';
					continue;
				}
				if(i%2==0){
					if(j%2==0)cout<<'+';
					else cout<<'-';
				}
				if(i%2==1){
					if(j%2==0)cout<<'|';
					else cout<<'.';
				}
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
