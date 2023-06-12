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

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		m--;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll res=0;
		priority_queue<ll,vector<ll>,greater<ll>>pq;
		ll s=0;
		for(ll i=m;i>0;i--){
			/*if(a[i]>=0)*/pq.push(-2*a[i]);
			s+=a[i];
			//cout<<i<<": "<<SZ(pq)<<" "<<s<<"\n";
			while(s>0){
				//cout<<i<<" "<<s<<"\n";
				s+=pq.top();
				//cout<<pq.top()<<"\n";
				pq.pop();
				res++;
			}
			assert(s<=0);
		}
		priority_queue<ll>pq2;
		s=0;
		fore(i,m+1,n){
			/*if(a[i]<=0)*/pq2.push(-2*a[i]);
			s+=a[i];
			//cout<<i<<": "<<SZ(pq2)<<" "<<s<<"\n";
			while(s<0){
				//cout<<i<<" "<<s<<" --> ";
				s+=pq2.top();
				//cout<<pq2.top()/2<<" "<<s<<"\n";
				//cout<<pq2.top()<<"\n";
				pq2.pop();
				res++;
			}
			assert(s>=0);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
