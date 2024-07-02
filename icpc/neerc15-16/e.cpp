#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int main(){FIN
	#ifdef ONLINE_JUDGE
	freopen("easy.in","r",stdin);     freopen("easy.out","w",stdout);
	#endif
	
	string s;
	cin>>s;
	string rta;
	fore(i,0,SZ(s)){
		if(s[i]=='-'){
			rta.pb(s[i]);
			rta.pb(s[i+1]);
			i+=2;
			while(i<SZ(s) && s[i]=='0'){
				i++;
				rta.pb('+');
				rta.pb('0');
			}
			if(i==SZ(s)){
			}
			else if((s[i]=='+' || s[i]=='-')){
				i--;
			}
			else{
				rta.pb('+');
				rta.pb(s[i]);
			}
		}
		else rta.pb(s[i]);
	}
	cout<<rta<<"\n";
	return 0;
}