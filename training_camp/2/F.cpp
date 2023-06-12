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
	ll n,k; cin>>n>>k;
	ll ka[4];
	ka[0]=1;
	ka[1]=(n*(n-1))/2;
	ka[2]=(n*(n-1)*(n-2))/3;
	ka[3]=((n*(n-1)*(n-2)*(n-3))/(4*3*2))*9;
	ll res=0;
	fore(i,0,k)res+=ka[i];
	pres;
	return 0;
}
