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
using namespace std;
typedef unsigned long long ll;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll N,V; cin>>N>>V;
	ll n=100;//rng()%N+1;
	cout<<n<<"\n";
	fore(i,0,n){
		if(i)cout<<" ";
		cout<<rng()%10+91;
	}
	cout<<"\n";
	return 0;
}
