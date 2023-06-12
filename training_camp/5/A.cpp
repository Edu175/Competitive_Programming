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
	ll n;
	ll h=n;
	to_string(h);
	ll m=SZ(h);
	ll flag=0,res;
	fore(i,0,m){
		if(flag)break;
		fore(j,i+1,m){
			if(flag)break;
			fore(k,j+1,m){
				if(flag)break;
				ll num=ll(h[i]+h[j]+h[k];
				if(num%8==0)res=num,flag=1;
			}
		}
	}
	if (flag)cout<<"YES\n",pres;
	else cout<<"NO\n";
	return 0;
}
