// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;

typedef struct CPoint{
	int x;
	int y;
}CPoint;

double CalculateAngle(CPoint p1, CPoint p2, CPoint p3, CPoint p4);

bool isInsideSector(CPoint origin, CPoint tip , CPoint checkP, bool flag , double perAng){
	double angle = CalculateAngle(origin , tip , origin , checkP);
	if(flag) angle = 360.0 - angle;
	if(perAng > angle) return true;
	return false;
}

int main(){
	int p,x,y;
	// cin >> t;
	CPoint origin,tip,checkP;
	origin.x = 50;
	origin.y = 50;
	tip.x = 50;
	tip.y = 100;
	p=45;
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			bool flag = false;
			x=i,y=j;
			checkP.x = x ;
			checkP.y = y ;
			if(x<50) flag=true;
			if(p==0) cout << "." ;
			else if (p>0 && x==50 && y==50) cout << "o" ;
			else {
				double inCircle = (2500 - (((x-50)*(x-50)) + ((y-50)*(y-50)) ));
				
				if(inCircle < 0) cout << "." ;
				
				else{
					double angle = (p*360)/100;
					if(isInsideSector(origin, tip, checkP, flag , angle)) cout << "o" ;
					else cout << "." ;
				} 
			}	
		}
		cout << endl;
	}
	return 0;

}


double CalculateAngle(CPoint p1, CPoint p2, CPoint p3, CPoint p4){
	double x1 = (float)p1.x - p2.x;
	double y1 = (float)p1.y - p2.y;
	double x2 = (float)p3.x - p4.x;
	double y2 = (float)p3.y - p4.y;
	double angle1 , angle2 , angle;
	if (x1 != 0.0f)	angle1 = atan(y1/x1);
	else angle1 = 3.14159 / 2.0;	
	if (x2 != 0.0f) angle2 = atan(y2/x2);
	else angle2 = 3.14159 / 2.0;	
	angle = fabs(angle2-angle1);
	angle = angle * 180.0 / 3.14159;	
	return angle;
}



