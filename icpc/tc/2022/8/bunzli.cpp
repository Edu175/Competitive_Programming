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

bool comp1(pair<ll,ll>p1, pair<ll,ll>p2){
	if(p1.fst==p2.fst) return p1.snd>p2.snd;
	else return p1.fst<p2.fst;
}
bool comp2(pair<ll,ll>p1, pair<ll,ll>p2){
	return p1.snd<p2.snd;
}

int main(){FIN;
    ll t; cin>>t;
    while(t--){
		ll p,n,multi;
        cin>>p>>n;
        multi=p/n;
        ll total=0,mayor=0;
        pair<ll,ll> a[n+1];
        ll can[n+1];
        for (ll w=0;w<n;w++){
            cin>>a[w].fst;
            a[w].snd=w;
            total=total+a[w].fst;
            
        }
        cout<<"\n";
        if (total<p){
            cout<<"IMPOSSIBLE";
        }
        ll atotal=0;
        if (total>p){
            for(ll g=0;g<n;g++){
                if (a[g].fst>=multi){
                    can[g]=multi;
                }else{
                    can[g]=a[g].fst;
                }
                atotal+=can[g];
            }
            ll resto=p-atotal;
            sort(a,a+n,comp1);
        	reverse(a,a+n);
            while(resto!=0){
                for (ll z=0;z<n;z++){
                    if (a[z].fst>can[a[z].snd]){
                        can[a[z].snd]++;
                        resto--;
                    }
                    if (resto==0){
                        break;
                    }
                    if (z==n){
                        z=0;
                    }
                }
            }
            for (ll u=0;u<n;u++){
                cout<<can[u]<<" ";
            }
        }
    }
    



    return 0;
}
