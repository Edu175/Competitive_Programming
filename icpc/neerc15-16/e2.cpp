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

bool is(char c){
	return '0'<=c&&c<='9';
}

int main(){FIN
	#ifdef ONLINE_JUDGE
	freopen("easy.in","r",stdin);     freopen("easy.out","w",stdout);
	#endif
	
	string s; cin>>s;
	if(is(s[0])){
		reverse(ALL(s));
		s.pb('+');
		reverse(ALL(s));
	}
	char sig=s[0];
	string r,t;
	r.pb(sig);
	// cout<<s<<"\n";
	fore(i,1,SZ(s)){
		if(is(s[i]))t.pb(s[i]);
		else {
			// cout<<i<<": "<<t<<" "<<sig<<"\n";
			for(auto c:t){
				r.pb(c);
				if(sig=='-')r.pb('+');
			}
			if(sig=='-')r.pop_back();
			t.clear();
			sig=s[i];
			r.pb(sig);
			
		}
	}
	for(auto c:t){
		r.pb(c);
		if(sig=='-')r.pb('+');
	}
	if(sig=='-')r.pop_back();
	cout<<r<<"\n";
	return 0;
}