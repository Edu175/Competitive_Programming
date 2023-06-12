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
	ll n; cin>>n;
	string s; cin>>s;
	ll j=0;
	ll res=0;
	ll disc=0;
	ll stop=-1;
	ll flag=0;
	fore(i,1,n){
		if(j!=stop&&s[i]==s[j]){
			flag=1;
			if(j)disc++;
			else stop=i;
			j++;
		}
		else {
			if(j==stop)res=max(disc,res);
			j=0;
			//cout<<stop<<","<<disc<<" ";
			disc=0;
			if(flag)i=stop;
			flag=0;
			stop=-1;
		}
	}
	//cout<<stop<<"\n";
	if((n%2==0&&stop==n/2)&&(s[n-1]==s[stop-1])){
		res=max(disc,res);
		//cout<<stop<<","<<disc<<" ";
	}
	res=n-res;
	pres;
	return 0;
}
