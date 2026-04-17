#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
    ll n,x;
    cin>>n>>x;
    vv a(n);
    ll obj=-1;
    if(x%2==0) obj=x/2;
    ll cnt=0;
    fore(i,0,n){
        int y; cin>>y; 
        if(y==obj) cnt++;
        a[i]=y;
    }
    if(cnt>(n+1)/2){
        cout<<"*\n";
        return 0;
    }
    vv b;
    fore(i,0,n){
        if(a[i]!=obj) b.pb(a[i]);
    }
    sort(ALL(b));
    int j=0;
    if(cnt>1){
        fore(i,0,n-1){
            if(i%2==0 && cnt>1){
                a[i]=obj;
                cnt--;
                continue;
            }
            a[i]=b[j];
            j++;
        }
        // cout<<"a ";
        // fore(i,0,n-1) cout<<a[i]<<" ";
        // cout<<"\n";
        bool bo=true;
        int aux;
        fore(i,1,n-1){
            if(a[i]+a[i-1]==x){
                bo=false;
                aux=a[i];
                a[i]=obj;
            }
        }
        // cout<<"a ";
        // fore(i,0,n-1) cout<<a[i]<<" ";
        // cout<<"\n";
        if(!bo){
            cout<<aux<<" ";
            fore(i,0,n-1){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
        else{
            fore(i,0,n-1){
                cout<<a[i]<<" ";
            }
            cout<<obj<<"\n";
        }
    }
    else{
        sort(ALL(a));
        fore(i,1,n){
            if(a[i]+a[i-1]==x){
                if(a[n-1]!=a[i]){
                    swap(a[n-1],a[i]);
                }
                else if(a[0]!=a[i-1]){
                    swap(a[i-1],a[0]);
                }
                else{
                    cout<<"*\n";
                    return 0;
                }
            }
        }
        fore(i,0,n){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}