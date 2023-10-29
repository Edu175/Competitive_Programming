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
	srand(time(0));
	cout<<10<<"\n";
	fore(i,0,10){
		fore(i,0,200000-100){
			ll rnd=rand()%10;
			if(i==0)if(rnd==0)rnd++;
			cout<<rnd;
		}
		cout<<"\n";
	}
	 return 0;
}
