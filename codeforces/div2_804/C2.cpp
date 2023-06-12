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
ll MOD=1000000007;

ll factorial(ll x){
	ll res=1;
	fore(i,1,x+1)res=(res*i)%MOD;
	return res;
}

ll var(ll x,ll y){
	ll res=1;
	fore(i,0,y)res*=x-i;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		ll pos[2];
		fore(i,0,n){
			cin>>a[i];
			if(a[i]==0)pos[0]=i;
			if(a[i]==1)pos[1]=i;
		}
		//imp(a);
		ll res=1;
		if(n>1){
			priority_queue<ll, vector<ll>, greater<ll>>pq = {0,1};
			ll l=min(pos[0],pos[1]);
			ll r=max(pos[0],pos[1]);
			ll e[2]={l,r};
			ll prox=2;
			ll elem=0;
			fore(i,l+1,r)pq.push(a[i]);
			//cout<<pq.top()<<"->"<<prox<<"\n";
			while(SZ(pq)&&pq.top()==prox)elem++,prox++,pq.pop();
			res*=factorial(abs(pos[0]-pos[1])-1);
			res%=MOD;
			//cout<<"adentro: "<<res<<"\n";
			elem=0;
			while(l||r<n-1){
				ll i;
				bool ch=0;
				if(l&&(r>=n-1||a[l-1]<a[r+1]))i=l-1,l--;
				else i=r+1,r++,ch=1;
				if(a[i]!=prox)pq.push(a[i]);
				else {
					prox++;
					//cout<<a[i]<<": "<<pq.top()<<"->"<<prox<<" | ";
					while(SZ(pq)&&pq.top()==prox){
						elem++;
						prox++;
						pq.pop();
						//cout<<pq.top()<<"->"<<prox<<" ";
					}
					res*=factorial(i-(e[ch])-1)*((elem)?elem:1);
					res%=MOD;
					elem=0;
					e[ch]=i;
					//cout<<res<<"\n";
				}
			}
		}
		pres;
	}
	return 0;
}
