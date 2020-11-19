#include <stdio.h>

int main(){
	char x[100][10];
	int d[6][6]={}, z=1, startx, starty, endx, endy, y=0;
	for(int i=0;i<36;i++){
		gets(x[i]);
		if(i==0){
			startx=x[i][0]-65;
			starty=x[i][1]-49;
		}
		if(i==35){
			endx=x[i][0]-65;
			endy=x[i][1]-49;
		}
		if(d[x[i][1]-49][x[i][0]-65]) z=0;
		d[x[i][1]-49][x[i][0]-65]=1;
	}
	for(int i=0;i<35;i++){
		int x1=x[i][1]-49, x2=x[i+1][1]-49, y1=x[i][0]-65, y2=x[i+1][0]-65;
		if((x1==x2+1 && y1==y2+2) || (x1==x2-1 && y1==y2+2) || (x1==x2+1 && y1==y2-2) || (x1==x2-1 && y1==y2-2) || (x1==x2+2 && y1==y2+1) || (x1==x2+2 && y1==y2-1) || (x1==x2-2 && y1==y2+1) || (x1==x2-2 && y1==y2-1)){
			y++; 
		}
		else{
			z=0;
		}
	}
	if((startx==endx+1 && starty==endy+2) || (startx==endx-1 && starty==endy+2) || (startx==endx+1 && starty==endy-2) || (startx==endx-1 && starty==endy-2) || (startx==endx+2 && starty==endy+1) || (startx==endx-2 && starty==endy+1) || (startx==endx+2 && starty==endy-1) || (startx==endx-2 && starty==endy-1)){
		y++;
	}
	else{
		z=0;
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(!d[i][j]) z=0;
		}
	}
	if(z) printf("Valid");
	else printf("Invalid");
	return 0;
}
