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
		cout<<"Case #"<<te-t<<": ";
		ll c[3]; ll m[3]; ll y[3]; ll k[3];
		ll mc=1000005;
		ll mm=1000005;
		ll my=1000005;
		ll mk=1000005;
		fore(i,0,3){
			cin>>c[i]>>m[i]>>y[i]>>k[i];
			mc=min(mc,c[i]);
			mm=min(mm,m[i]);
			my=min(my,y[i]);
			mk=min(mk,k[i]);
		}
		ll color=mc+mm+my+mk;
		ll res=0;
		if(color<1000000)cout<<"IMPOSSIBLE\n",res=1;
		fore(i,0,5){
			if(res){
				break;
			}
			color=mc+mm+my+mk;
			if(color==1000000){
				break;
			}
			/*if(i==0)ll ref=std::ref(mc);
			if(i==1)ref=std::ref(mm);
			if(i==2)ref=std::ref(my);
			if(i==3)ref=std::ref(mk);
			cout<<ref<<" ";*/
			if(((i==0)?mc:((i==1)?mm:((i==2)?my:mk)))<(color-1000000)){
				((i==0)?mc:((i==1)?mm:((i==2)?my:mk)))=0;
			}else ((i==0)?mc:((i==1)?mm:((i==2)?my:mk)))-=color-1000000;
		}
		if(res){
			continue;
		}
		cout<<mc<<" "<<mm<<" "<<my<<" "<<mk<<"\n";
	}
	return 0;
}
