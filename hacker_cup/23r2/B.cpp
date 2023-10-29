#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

void rot(vector<ll>&a, ll x){rotate(a.begin(),a.begin()+x,a.end());}
bool check(vector<ll>h,ll pos){
	rot(h,pos);
	ll n=SZ(h)/2;
	//imp(h);
	fore(i,0,n){
		if(h[i]!=h[2*n-1-i])return 0;
		if(i<n/2){
			if(!(h[i]<h[i+n]))return 0;
		}
		else if(i>=(n+1)/2){
			if(!(h[i]>h[i+n]))return 0;
		}
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	fore(_,1,t+1){
		cout<<"Case #"<<_<<": ";
		ll n; cin>>n;
		vector<ll>a(n),b(n),h(2*n);
		fore(i,0,2*n){
			cin>>h[i];
			if(i<n)a[i]=h[i];
			else b[i-n]=h[i];
		}
		vector<ll>c(2*n);
		fore(i,0,2*n){
			ll o=h[(i+n)%(2*n)];
			if(h[i]==o)c[i]=2;
			else if(h[i]<o)c[i]=0;
			else if(h[i]>o)c[i]=1;
		}
		//cout<<"\n";
		ll q=0,pos=-1;
		fore(i,0,5*n){
			ll p=i%(2*n);
			if(c[p]==0)q++;
			else q=0;
			//cout<<i<<" "<<q<<"\n";
			if(q==n/2*2){
				pos=(p-n/2+1+2*n)%(2*n);
				break;
			}
		}
		
		//imp(h);
		//imp(c);
		//cout<<pos<<"\n";
		if(pos==-1||!check(h,pos))cout<<"-1\n";
		else cout<<pos<<"\n";
	}
	return 0;
}
