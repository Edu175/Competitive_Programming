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
typedef int ll;

int main(){FIN;
	long long t; cin>>t;
	fore(k,0,t){
	ll l[3],p=0;
	fore(i,0,3){
		cin>>l[i];
		p=max(p,l[i]);
	}//cout<<p<<"\n";
	ll s=l[0]+l[1]+l[2];
	if(p==s-p){
		cout<<"YES\n";
		continue;
	}
	ll v=0;
	fore(i,0,3){
		fore(j,0,3){
			if(i!=j){
			if(l[i]==l[j]){
				if(l[3-i-j]%2==0){
					cout<<"YES\n";
					v=1;
					break;
				}
			}
			}
		}if(v){break;}
	}if(v){
		continue;
	}else{
		cout<<"NO\n";
	}
	
	}
	 return 0;
}
