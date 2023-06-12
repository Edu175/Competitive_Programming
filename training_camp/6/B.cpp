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
	string s; cin>>s;
	pair<ll,ll> r[SZ(s)];
	fore(i,0,SZ(s)){
		r[i].fst=0,r[i].snd=0;
	}
	//vector<ll>l;
	ll n; cin>>n;
	string a[n];
	fore(i,0,n){
		cin>>a[i];
		string t=a[i];
		fore(j,0,SZ(s)-SZ(t)+1){
			bool flag=1;
			fore(h,0,SZ(t)){
				if(t[h]!=s[j+h]){
					flag=0;
					break;
				}
			}
			if(flag)r[j+SZ(t)-1].fst=1,r[j+SZ(t)-1].snd=max(ll(j),r[j+SZ(t)-1].snd);
		}
	}
	//sort(ALL(l));
	ll res=0, pos=0, start=0;
	//ll j=0;
	ll count=0;
	fore(i,0,SZ(s)){
		if(r[i].fst&&r[i].snd>=start){
			if(count>res)res=count,pos=start;
			//i=l[j]-1;
			i=r[i].snd;
			//j++;
			start=i+1;
			count=0;
		}
		else count++;
	}
	if(count>res)res=count,pos=start;
	/*fore(i,0,SZ(s)){
		cout<<"{"<<r[i].fst<<","<<r[i].snd<<"} ";
	}
	cout<<"\n";*/
	//imp(l);
	cout<<res<<" "<<pos<<"\n";
	return 0;
}
