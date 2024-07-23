#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define foru(i,a,b) for(ll i=b-1; i>=a;i--)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
using namespace std;
int main(){JET
 ll n,a,b,c,t;
 cin>>n>>t>>a>>b>>c;
 ll s[4]={t,t,t,t}; 
 ll sx[4]={a-1,a-1,a+c-2,a+c-2};
 ll sy[4]={b-1,b+c-2,b-1,b+c-2};
 ll y[n]; 
 fore(i,0,n){
  y[i]=(i!=n-1)?0:n-1;
 }

 fore(i,0,4){
  fore(j,1,n){
   fore(k,y[j-1],y[j]+1){
    s[i]-=abs(sx[i]-j)+abs(sy[i]-k);
   }
  }
 }
 
 fore(i,0,4){
  if(sy[i]>y[sx[i]] && s[i]<0){
   foru(k,sx[i],n-1){
    if(y[k]<y[k+1] && y[k]<sy[i]){
     ll dy = (1-s[i])/2;
     if(dy>sy[i]-y[k]) dy=sy[i]-y[k];
     fore(x,0,4){
      if((sx[x]<=k && sy[x]<=y[k]) || (sx[x]>k && sy[x]>=y[k]+dy)) continue;
      if(sx[x]<=k && sy[x]>=y[k]+dy){
       s[x]+=2*dy;
      }
                        else if(sx[x]>k && sx[x]<=y[k]){
       s[x]-=2*dy;
      }else{
       s[x]+=((sx[x]<=k)?dy:-dy)-dy+2*(sy[x]-y[k]);
      }
     }
     y[k]+=dy;
    }
   }
  }
 }
 fore(i,0,4){
  if(s[i]<0){
   cout << "Impossible";
   return 0;
  }
 }
 fore(i,0,y[0]){
  cout << 'U';
 }
 fore(i,1,n){
  cout << 'R';
  fore(j,y[i-1],y[i]){
   cout << 'U';
  }
 }
 return 0;
}