# include "iGraphics.h"
# include <GLAux.h>
# include <time.h>
# include <stdlib.h>
int x1=100,y=200,x2=300,x3=600,strike=0,page=0,length=20,down=0,move=0,length1,check=0,xc=600,save=-1,score=0,hs=0,xs,ys,score1,hs1=0;
FILE *fp;
void time()
{
}
void mydelay(int mseconds)
{
	clock_t start, end;
	double elapsed;
	start = clock();
	while(1)
	{
		end = clock();
		elapsed = ((double) (end - start)) / ((double)CLOCKS_PER_SEC/1000.0);
		if(elapsed>mseconds)break;
	}
}
void iDraw()
{
	int i,j,k,l,m;
	if(page==0){
		iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\stick hero\\open.bmp");
		if((fp = fopen("save","r"))!=NULL){
			move = getw(fp);

			fclose(fp);
		}
		if(move==1){
			iShowBMP(700,500,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\stick hero\\cont.bmp");
			if((fp = fopen("x2","r"))!=NULL){
				x2 = getw(fp);

				fclose(fp);
			}
			if((fp = fopen("x3","r"))!=NULL){
				x3 = getw(fp);

				fclose(fp);
			}
			if((fp = fopen("score","r"))!=NULL){
				score = getw(fp);

				fclose(fp);
			}

		}
		else{
			x2 = 300;
			x3 = 600;
			score=0;
		}
		//save=-1;
		if((fp = fopen("hs","r"))!=NULL){
			hs = getw(fp);

			fclose(fp);
			}
	}
	if(page==1){
		iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\stick hero\\bg.bmp");
		iShowBMP(xc,350,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\stick hero\\cloud.bmp");

		//iShowBMP(100,200,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\stick hero\\perry.bmp");
		iSetcolor(0,0,90);
		if(strike==0){
			iFilledRectangle(x1,0,50,y);
			iFilledRectangle(x2,0,50,y);
			iFilledRectangle(x3,0,50,y);
			//strike++;
		}

		else{
			iFilledRectangle(x1,0,50,y);
			iFilledRectangle(x2,0,50,y);
			iFilledRectangle(x3,0,50,y);
			iShowBMP(xc,350,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\stick hero\\cloud.bmp");

			if(check==1)point();
		}
		score1 = score;
		xs = 675;
		ys = 675;
		if(down==0)iFilledRectangle(x1+50,y,5,length);
		if(down==1)iFilledRectangle(x1+50,y,length,5);
		if(save==0)iShowBMP(300,300,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\stick hero\\save.bmp");
		//length = getLength();
	}
	if(page==2){
		mydelay(200);
		iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\stick hero\\go.bmp");
		xs = 450;
		ys = 290;
		score1=score;
		if(hs1==1){
			if((fp=fopen("hs","w"))!=NULL){
				putw(hs,fp);
				fclose(fp);
			}
			iText(300,150,"CONGRATULATIONS!! NEW HIGH SCORE!!", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if((fp=fopen("save","w"))!=NULL){
			putw(0,fp);
			fclose(fp);
		}
	}
	if(page==3)iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\stick hero\\ins.bmp");
	if(page==4){
		iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\stick hero\\hs.bmp");
		xs=340;
		ys=520;
		score1 = hs;
	}
	if(page==1 || page==2 || page==4){
		i = score1/10000;
		if(i==0)iText(xs,ys,"0", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(i==1)iText(xs,ys,"1", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(i==2)iText(xs,ys,"2", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(i==3)iText(xs,ys,"3", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(i==4)iText(xs,ys,"4", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(i==5)iText(xs,ys,"5", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(i==6)iText(xs,ys,"6", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(i==7)iText(xs,ys,"7", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(i==8)iText(xs,ys,"8", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(i==9)iText(xs,ys,"9", GLUT_BITMAP_TIMES_ROMAN_24);
		score1 = score1%10000;
		j = score1/1000;
		if(j==0)iText(xs+10,ys,"0", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(j==1)iText(xs+10,ys,"1", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(j==2)iText(xs+10,ys,"2", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(j==3)iText(xs+10,ys,"3", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(j==4)iText(xs+10,ys,"4", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(j==5)iText(xs+10,ys,"5", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(j==6)iText(xs+10,ys,"6", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(j==7)iText(xs+10,ys,"7", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(j==8)iText(xs+10,ys,"8", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(j==9)iText(xs+10,ys,"9", GLUT_BITMAP_TIMES_ROMAN_24);
		score1%=1000;
		k= score1/100;
		if(k==0)iText(xs+20,ys,"0", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(k==1)iText(xs+20,ys,"1", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(k==2)iText(xs+20,ys,"2", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(k==3)iText(xs+20,ys,"3", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(k==4)iText(xs+20,ys,"4", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(k==5)iText(xs+20,ys,"5", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(k==6)iText(xs+20,ys,"6", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(k==7)iText(xs+20,ys,"7", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(k==8)iText(xs+20,ys,"8", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(k==9)iText(xs+20,ys,"9", GLUT_BITMAP_TIMES_ROMAN_24);
		score1%=100;
		l = score1/10;
		if(l==0)iText(xs+30,ys,"0", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(l==1)iText(xs+30,ys,"1", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(l==2)iText(xs+30,ys,"2", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(l==3)iText(xs+30,ys,"3", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(l==4)iText(xs+30,ys,"4", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(l==5)iText(xs+30,ys,"5", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(l==6)iText(xs+30,ys,"6", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(l==7)iText(xs+30,ys,"7", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(l==8)iText(xs+30,ys,"8", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(l==9)iText(xs+30,ys,"9", GLUT_BITMAP_TIMES_ROMAN_24);

		m = score1%10;
		if(m==0)iText(xs+40,ys,"0", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(m==1)iText(xs+40,ys,"1", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(m==2)iText(xs+40,ys,"2", GLUT_BITMAP_TIMES_ROMAN_24);

		else if(m==3)iText(xs+40,ys,"3", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(m==4)iText(xs+40,ys,"4", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(m==5)iText(xs+40,ys,"5", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(m==6)iText(xs+40,ys,"6", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(m==7)iText(xs+40,ys,"7", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(m==8)iText(xs+40,ys,"8", GLUT_BITMAP_TIMES_ROMAN_24);
		else if(m==9)iText(xs+40,ys,"9", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

int getLength(void)
{
 if(length<=length1 && length>=length1-50)return 1;
 else return 2;
}
void point(void)
{

	if(x1>0){
		x1-=10;
		x2-=10;
		x3-=10;
	}
	if(x1==0){
		x1=100;
		x2 = x3-50;
		x3 = ((rand()%4))*100+x2;
		length=20;
		strike=0;
		check=0;
		down=0;
	}
	if(xc==0)xc=600;
	else xc-=10;
	mydelay(300);
}
void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
	if(page==0 && mx>700 && mx<900 && my>200 && my<275)exit(0);
	if(page==0 && mx>700 && mx<900 && my<350 && my>275)page=3;
	if(page==0 && mx>700 && mx<900 && my>350 && my<425)page = 4;
	if(page==0 && mx>700 && mx<900 && my>425 && my<500)page=1;
	if(page==0 && mx>700 && mx<900 && my>500 && my<575)page=1;

	if(page==1 && mx>800 && mx<900 && my>600 && my<700)save=0;
	if(save==0 && mx>300 && mx<450 && my>300 && my<400)save=1;
	if(save==0 && mx>450 && mx<600 && my>300 && my<400)save=2;
	if(save==1 && page==1){
		if((fp=fopen("save","w"))!=NULL){
			putw(1,fp);
			fclose(fp);
		}
		if((fp=fopen("x2","w"))!=NULL){
			putw(x2,fp);
			fclose(fp);
		}
		if((fp=fopen("x3","w"))!=NULL){
			putw(x3,fp);
			fclose(fp);
		}
		if((fp=fopen("score","w"))!=NULL){
			putw(score,fp);
			fclose(fp);
		}
		if(hs1==1){
		if((fp=fopen("hs","w"))!=NULL){
			putw(hs,fp);
			fclose(fp);
		}
		}
		exit(0);
	}
	else if(save==2 && page==1){
		if((fp=fopen("save","w"))!=NULL){
			putw(2,fp);
			fclose(fp);
		}
		if((fp=fopen("score","w"))!=NULL){
			putw(0,fp);
			fclose(fp);
		}
		if((fp=fopen("hs","w"))!=NULL){
			putw(hs,fp);
			fclose(fp);
		}
		exit(0);
	}

	if((page==2 || page==4 || page==3) && (mx>800 && mx<900 && my>0 && my<100)){
		page=0;
		length=20;
		down=0;
		move=0;
		strike=0;
		score=0;
		check=0;
	}
	}
}

void iPassiveMouseMove(int mx,int my)
{


}

void iKeyboard(unsigned char key)
{


}

void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_UP && down==0)
		length+=20;
	if(key == GLUT_KEY_RIGHT){
		down=1;
		length1 = x2-x1;
		if(score<10000)score+=length1/10;
		if(score>hs){hs = score;hs1=1;}
		strike=1;
		check = getLength();
		if(check==2)page=2;

	}
}

int main()
{
	iSettimer(1000, time);
	iInitialize(900, 700, "Final");
	return 0;
}
