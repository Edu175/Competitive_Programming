#include <bits/stdc++.h>
#include<cmath>
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
	while(t--){
		ll l,r;
		cin>>l>>r;
		ll a[r-l];
		ll pot2[20];
		pot2[0]=1;
		fore(i,1,20){
			pot2[i]=2*pot2[i-1];
		}
		ll v=0;
		fore(i,ceil(log2(l)),1000000){
			ll e=pot2[i-1];
			if(i==ceil(log2(l))){
				e=pot2[i-1]-l;
			}
			if(pot2[i+1]>r){
				e=r-pot2[i];
				v=max(v,e);
				break;
			}v=max(v,e);
		}cout<<v<<"\n";
		fore(i,l,r){
			if(i&(i+1)){
				v++;
			}else{
				v=0;
				cout<<v<<"\n";
				break;
			}cout<<v<<"\n";
		}*/
	}
	 return 0;
}
