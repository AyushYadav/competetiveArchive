#include <bits/stdc++.h>

using namespace std;


int main(){
	int T;
	cin >> T;
	int days = 1;
	while(days<=T){ 
		int bags;
		cin >> bags;
		int bagwt[bags];
		for(int bags_counter=0;bags_counter<bags;bags_counter++){
			int temp;
			cin >> temp;
			bagwt[bags_counter]=temp;
		}
		for(int i=0;i<bags-1;i++){
			for(int j=i+1;j<bags;j++){
				if(bagwt[i]>bagwt[j]){
					int temp=bagwt[j];
					bagwt[j]=bagwt[i];
					bagwt[i]=temp;
				}
			}
		}
		int trips=0;
		int lb=0,ub=bags-1;
		int ht=0;
		while(lb<ub){
			ht=(50%bagwt[ub]==0)?(50/bagwt[ub]):(50/bagwt[ub])+1;
			int sum=0;
			sum+=bagwt[ub];
			int t=ht-1;
			int x=0;
			for(int i=1;i<=t;i++){   
				if(lb<ub){
					sum+=bagwt[lb];
					lb++;
			    }
			    else { 
			    	x+=1;
			    	break;
			    }
			}
			if(x==1 && sum>=50) trips++;
			trips++;
			ub=ub-1;
		}
		cout << "Case #" << days << ": " << trips << endl;
		days++;
	}
	return 0;
}
