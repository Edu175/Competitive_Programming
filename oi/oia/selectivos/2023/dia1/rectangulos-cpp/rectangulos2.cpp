#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;

int consulta(int i,int W,int H);

int rectangulos(vector<int> xe, vector<int> ye) {
    ll n=SZ(xe);
    ll minx=0,miny=0;
    vector<ll>x(n),y(n);
    fore(i,0,n)x[i]=xe[i],y[i]=ye[i];
    fore(i,0,n){
    	if(xe[i]<xe[minx])minx=i;
    	if(ye[i]<ye[miny])miny=i;
    }
    sort(ALL(x));
    sort(ALL(y));
    ll l=0,r=n-1;
    while(l<=r){
    	ll m=(l+r)/2;
    	if(consulta(minx+1,max((ll)1,2*abs(x[m]-xe[minx])),2e9))r=m-1;
    	else l=m+1;
    }
    ll X=x[l];
    l=0,r=n-1;
    while(l<=r){
    	ll m=(l+r)/2;
    	if(consulta(miny+1,2e9,max((ll)1,2*abs(y[m]-ye[miny]))))r=m-1;
    	else l=m+1;
    }
    ll Y=y[l];
    ll res=-1;
    fore(i,0,n)if(xe[i]==X&&ye[i]==Y)res=i;
    //cout<<X<<" "<<Y<<"\n";
    return res+1;
}
