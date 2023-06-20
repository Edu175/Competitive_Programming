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
	ll n; cin>>n; ll a[n];
	fore(i,0,n){
		cin>>a[i];
	}
	ll v,p=0;
	fore(i,0,(1ll<<n)){
		v=0;
		fore(j,0,n){
			if(i&(1ll<<j)){
				v+=a[j];
			}else{
				v-=a[j];
			}
		}if(v%360==0){
			p++;
			break;
		}
	}
	if(p){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	
	 return 0;
}
