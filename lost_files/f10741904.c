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

int main(){
	while(1){
		ll a[5]={1,2,3,4,5};
		ll x; cin>>x;
		ll y; cin>>y;
		if(x==-1){
			break;
		}
		cout<<lower_bound(a,a+5,x)-a<<" ";
		cout<<upper_bound(a,a+5,y)-a;
	}
	return 0;
}
