#include<bits/stdc++.h>

using namespace std;

/*int perfect_sq(int n) {
    if(n<0)
        return 0;
    int sq_root=round(sqrt(n));
    if(sq_root*sq_root==n){
    	return 1;
    }else{
    	return 0;
    }
}*/

int perfect_cb(int n) {
    if(n<0)
        return 0;
    int cube_root=round(cbrt(n));
    if(cube_root*cube_root*cube_root==n){
    	return 1;
    }else{
    	return 0;
    }
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		int x=a[i];
		int v=0;
		for(int i=0;i+1<=1000000000;i++){
			if((i+1)*(i+1)<=x){
				v++;
			}else{
				break;
			}
			if(perfect_cb((i+1)*(i+1))==1&&(i+1)*(i+1)<=x){
				v--;
			}
		}
		for(int i=0;i+1<=1000000000;i++){
			if((i+1)*(i+1)*(i+1)<=x){
				v++;
			}else{
				break;
			}
		}
		cout<<v<<"\n";
	}
	return 0;
}
