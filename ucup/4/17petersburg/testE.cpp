#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	// JET
	vv pot3(20); pot3[0]=1;
	fore(i,1,SZ(pot3))pot3[i]=pot3[i-1]*3;
	fore(_mk,0,pot3[16]){
		// cerr<<"trying "<<_mk<<"\n";
		vector<array<ll,5>> eq(4);
		ll mk=_mk;
		ll valid=1;
		fore(i,0,4){
			ll opu=i^2;
			fore(j,0,5)if(j!=opu){
				eq[i][j]=mk%3;
				mk/=3;
				if(i==j)valid&=eq[i][j]==2;
			}
		}
		if(!valid)continue;
		// cerr<<"paso\n";
		fore(_est,0,pot3[4]){
			array<ll,4>cols;
			ll est=_est;
			fore(i,0,4)cols[i]=est%3,est/=3;
			ll good=0;
			fore(i,0,4){
				ll s=0;
				fore(j,0,4)s+=eq[i][j]*cols[j];
				good|=(s%3==eq[i][4]);
			}
			if(!good){valid=0;break;}
		}
		if(valid){
			cout<<"FOUND ONE!!\n";
			fore(i,0,4){
				fore(j,0,4)cout<<eq[i][j]<<" ";
				cout<<"= "<<eq[i][4]<<"\n";
			}
			exit(0);
		}
	}
	cout<<"that's all\n";
	return 0;
}