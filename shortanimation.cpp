#include <GL\glew.h>
#include <GL\freeglut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void display();
void init();
void move();
void key(unsigned char,int,int);
void bresenham_circle(int);
void plot_point(int,int);
void myRotate(float,float,float);
void fall();
void afterFall();
void mainmenu(int id);
void idle();

float orx=1,ory=0,Orx=1,Ory=0,x=1,y=0;
int flag = 0;							//Flag for moving
int flag1 = 0;							//Flag for the fall
int flagr = 0;							//Flag for the rock
int flagh = 0;							//flag for the helmet
int xc,yc;
int q = 1;
double h=100,k=500;								//Origin for clouds
float b = 4;								//Variable for Blood
float impact;
float theta = 270;						//Angle for Rotating the leg
float theta1 = 0;						//Angle for Rotation of the body
float fx,fy;							//Translation variables while falling
float r[2];								//Result Array in the myRotate function
float keypt[1][3] = {135,95,10};		//Key Point for rotating leg
bool done = false;						//To check if the play is done
bool falling = false;					//To check if he is falling
bool first_page = true;					//Value to check for the intro page

int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1000,600);
	glutCreateWindow("The Helm");
	glutInitWindowPosition(0,0);
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	init();
	glutMainLoop();
	return 0;
}


void init(){
	glClearColor(0,0.8,1,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1200,20,600,-100,100);
	//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glPointSize(2);
	glutPostRedisplay();
	return;
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	if(!first_page){
	impact = x+203;
	/*
	if(!flag1 && !flagh && !flagr)
		idle();*/
	glPushMatrix();
	glScalef(1.2,1.2,1);
	//6
	glColor3f(0,1,1);
	glBegin(GL_POLYGON);
		glVertex2f(orx+134.3,ory+104.9);
		glVertex2f(orx+170.35,ory+135.35);
		glVertex2f(orx+168.57,ory+137.15);
		glVertex2f(orx+134.30,ory+107.95);
	glEnd();
	glFlush();

	//7
	xc=orx+100;
	yc=ory+100;
	glColor3f(1,0,0);
	bresenham_circle(20);
	bresenham_circle(15);

	//12
	xc=orx+183;
	yc=ory+100;
	glColor3f(1,0,0);
	bresenham_circle(20);
	bresenham_circle(15);
	bresenham_circle(5);

	//8
	xc=orx+100;
	yc=ory+100;
	bresenham_circle(5);

	//9
	xc=orx+135;
	yc=ory+100;
	bresenham_circle(5);

	//Spokes
	glColor3f(1,1,0);

	for(int x=100;x<=183;x+=83){
			glBegin(GL_LINES);
			if(flag == 1){
				glVertex2f(orx+x,ory+115);
				glVertex2f(orx+x,ory+105);

				glVertex2f(orx+x,ory+95);
				glVertex2f(orx+x,ory+85);
	
				glVertex2f(orx+x+5,ory+100);
				glVertex2f(orx+x+15,ory+100);

				glVertex2f(orx+x-5,ory+100);
				glVertex2f(orx+x-15,ory+100);
			}


			else{
				glVertex2f(orx+x-3.54,ory+103.53);
				glVertex2f(orx+x-10.6,ory+110.6);

				glVertex2f(orx+x+10.6,ory+110.6);
				glVertex2f(orx+x+3.53,ory+103.53);

				glVertex2f(orx+x-3.54,ory+96.46);
				glVertex2f(orx+x-10.61,ory+89.39);

				glVertex2f(orx+x+3.53,ory+96.46);
				glVertex2f(orx+x+10.07,ory+89.39);
			}
		glEnd();
	}
	//1
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(orx+100,ory+100);
		glVertex2f(orx+135,ory+100);
		glVertex2f(orx+135,ory+103);
		glVertex2f(orx+100,ory+103);
	glEnd();
	glFlush();

	//2
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(orx+105,ory+100);
		glVertex2f(orx+108,ory+100);
		glVertex2f(orx+128.57,ory+120.7);
		glVertex2f(orx+125.57,ory+121.2);
	glEnd();
	glFlush();


	//5
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(orx+135,ory+100);
		glVertex2f(orx+138,ory+100);
		glVertex2f(orx+121.94,ory+134.43);
		glVertex2f(orx+118.94,ory+134.43);
	glEnd();
	
	//10
	glColor3f(0,1,1);
	glBegin(GL_POLYGON);
		glVertex3f(orx+110.94,ory+134.43,-20);
		glVertex3f(orx+126.94,ory+134.43,-20);
		glVertex3f(orx+126.94,ory+140.43,-20);
		glVertex3f(orx+110.94,ory+140.43,-20);
	glEnd(); 

	//13
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(orx+183,ory+100);
		glVertex2f(orx+186,ory+100);
		glVertex2f(orx+169.94,ory+134.43);
		glVertex2f(orx+166.94,ory+134.43);
	glEnd();

	//11
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(orx+123,ory+128);
		glVertex2f(orx+160,ory+128);
		glVertex2f(orx+160,ory+130);
		glVertex2f(orx+123,ory+130);
	glEnd();

	

	glPushMatrix();
	glTranslatef(fx,fy,0);

	//Body
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
		myRotate(Orx+149,Ory+167.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+153,Ory+165.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+155,Ory+164.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+155,Ory+163.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+154,Ory+161.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+128,Ory+135.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+126,Ory+134.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+124,Ory+134.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+118,Ory+136.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+112,Ory+139.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+110,Ory+141.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+110,Ory+143.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+111,Ory+145.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+137,Ory+171.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+139,Ory+172.43,-10);
		glVertex3f(r[0],r[1],-10);
		myRotate(Orx+145,Ory+174.43,-10);
		glVertex3f(r[0],r[1],-10);
	glEnd();

	//Hands
	//glRotatef(30,0,0,1);
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);					//Left hand
		myRotate(Orx+136,Ory+172,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+143,Ory+147.2,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+149,Ory+149.2,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+143,Ory+172,0);
		glVertex3f(r[0],r[1],0);
	glEnd();
	
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		myRotate(Orx+136,Ory+172,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+143,Ory+147.2,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+149,Ory+149.2,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+143,Ory+172,0);
		glVertex3f(r[0],r[1],0);
	glEnd();

	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
		myRotate(Orx+144,Ory+147.2,0);
		glVertex3f(r[0],r[1],10);
		myRotate(Orx+149,Ory+149.2,0);
		glVertex3f(r[0],r[1],10);
		myRotate(Orx+167.57,Ory+137.15,10);
		glVertex3f(r[0],r[1],10);
		myRotate(Orx+161,Ory+135.15,10);
		glVertex3f(r[0],r[1],10);		
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		myRotate(Orx+144,Ory+147.2,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+149,Ory+149.2,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+167.57,Ory+137.15,10);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+161,Ory+135.15,10);
		glVertex3f(r[0],r[1],0);	
	glEnd();


	glBegin(GL_POLYGON);									//RIGHT HAND
		glColor3f(1,1,0);
		myRotate(Orx+154,Ory+165.43,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+159,Ory+145.43,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+153,Ory+144,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+148,Ory+163,0);
		glVertex3f(r[0],r[1],0);
	glEnd();

	glBegin(GL_LINE_LOOP);									//RIGHT HAND
		glColor3f(0,0,0);
		myRotate(Orx+154,Ory+165.43,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+159,Ory+145.43,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+153,Ory+144,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+153,Ory+144,0);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+148,Ory+163,0);
		glVertex3f(r[0],r[1],0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1,1,0);
		myRotate(Orx+159,Ory+145.43,-10);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+168.57,Ory+139.15,-10);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+168.57,Ory+135,-10);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+153,Ory+144,0);
		glVertex3f(r[0],r[1],0);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		myRotate(Orx+159,Ory+145.43,-10);
	
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+168.57,Ory+139.15,-10);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+168.57,Ory+135,-10);
		glVertex3f(r[0],r[1],0);
		myRotate(Orx+153,Ory+144,0);
		glVertex3f(r[0],r[1],0);
	glEnd();

	//face
	glColor3f(1,0.81,0.79);
	glBegin(GL_POLYGON);
	for(int i=0;i<=360;i++){
			myRotate(Orx+148+8*cos(i),Ory+176.43+11*sin(i),10);
			glVertex3f(r[0],r[1],10);	
	}
	glEnd();


	glColor3f(1,0,0);
	glPointSize(2);
	glBegin(GL_POINTS);
		myRotate(Orx+144,Ory+178,11);
		glVertex3f(r[0],r[1],11);
		myRotate(Orx+150,Ory+178,11);
		glVertex3f(r[0],r[1],11);
		myRotate(Orx+147,Ory+175,11);
		glVertex3f(r[0],r[1],11);
	glEnd();

	glColor3f(1,1,1);
	int j;
	if(flag1 && impact==250)
		j=3;
	else 
		j=2;
	glBegin(GL_POLYGON);
	for(int i=0;i<=360;i++){
		myRotate(Orx+148+3*cos(i),Ory+170+j*sin(i),11);
		glVertex3f(r[0],r[1],11);
	}
	glEnd();

	glPointSize(2);
	//Legs
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
		myRotate(Orx+124,Ory+(keypt[0][1] + 39.43),1);
		glVertex3f(r[0],r[1],1);
		myRotate(Orx+130,Ory+(keypt[0][1] + 35),10);
		glVertex3f(r[0],r[1],1);
		myRotate(Orx+136,Ory+(keypt[0][1] + 32),10);					//up knee
		glVertex3f(r[0],r[1],1);
		myRotate(Orx+(keypt[0][0]+7),Ory+(keypt[0][1]+5),9);			//bottom right		
		glVertex3f(r[0],r[1],1);
		myRotate(Orx + keypt[0][0],Ory + keypt[0][1],10);				//bottom left
		glVertex3f(r[0],r[1],1);
		myRotate(Orx+131,Ory+(keypt[0][1]+27),9);						//low knee
		glVertex3f(r[0],r[1],1);
		myRotate(Orx+112.57,Ory+128.36,10);
		glVertex3f(r[0],r[1],1);
		myRotate(Orx+111.15,Ory+128.83,10);
		glVertex3f(r[0],r[1],1);
		myRotate(Orx+110.68,Ory+129.55,10);
		glVertex3f(r[0],r[1],1);
		myRotate(Orx+110,Ory+130.43,10);
		glVertex3f(r[0],r[1],1);
		myRotate(Orx+109,Ory+135.43,10);
		glVertex3f(r[0],r[1],1);
		myRotate(Orx+108,Ory+142.43,10);
		glVertex3f(r[0],r[1],1);
	glEnd();

	//foot
	glColor3f(0.6,0,0.2);
	glBegin(GL_POLYGON);
		myRotate(Orx + keypt[0][0],Ory + keypt[0][1],10);
		glVertex3f(r[0],r[1],10);
		myRotate(Orx+(keypt[0][0]+13),Ory+keypt[0][1],10);
		glVertex3f(r[0],r[1],10);
		myRotate(Orx+(keypt[0][0]+13),Ory+(keypt[0][1]+4),10);
		glVertex3f(r[0],r[1],10);
		myRotate(Orx+(keypt[0][0]+7),Ory+(keypt[0][1]+5),10);
		glVertex3f(r[0],r[1],10);
	glEnd();
	
	//Helmet
	if(flagh){
		int h=148,k=180.43;
		glColor3f(0,0,1);
		glBegin(GL_POLYGON);
			for(int i=15;i<=195;i++){
				myRotate(Orx+h+11*cos(i*(3.14/180)),Ory+k+11*sin(i*(3.14/180)),20);
				glVertex3f(r[0],r[1],20);
			}
		glEnd();
	
		glColor3f(1,1,1);
		glPointSize(1);
		glBegin(GL_POINTS);
			for(int i=120;i<=430;i++){
				myRotate(Orx+148+8*cos(i*(3.14/180)),Ory+176.43+11*sin(i*(3.14/180)),20);
				glVertex3f(r[0],r[1],20);
				}
		glEnd();
		glPointSize(2);
	}
	glPopMatrix();


	//15
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
		glVertex3f(orx+168.57,ory+137.15,0);
		glVertex3f(orx+161,ory+135.15,10);
		glVertex3f(orx+161,ory+139,10);
		glVertex3f(orx+168.57,ory+139,0);
	glEnd();

	//Rock
	if(flagr){
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_POLYGON|GL_LINES);
			glVertex3f(252,83,-20);
			glVertex3f(250,85,-20);
			glVertex3f(252,100,-20);
			glVertex3f(254,102,-20);
			glVertex3f(256,104,-20);
			glVertex3f(258,106,-20);
			glVertex3f(260,108,-20);
			glVertex3f(265,108,-20);
			glVertex3f(268,113,-20);
			glVertex3f(270,115,-20);
			glVertex3f(272,113,-20);
			glVertex3f(274,112,-20);
			glVertex3f(276,108,-20);	
			glVertex3f(278,105,-20);
			glVertex3f(280,100,-20);
			glVertex3f(283,95,-20);
			glVertex3f(285,93,-20);
			glVertex3f(287,90,-20);
			glVertex3f(289,88,-20);
			glVertex3f(292,85,-20);
			glVertex3f(290,83,-20);
			glVertex3f(285,80,-20);
		glEnd();
	}

	glPopMatrix();
		

	//Trees
	for(int x=90;x<=1200;x+=170){
		glBegin(GL_POLYGON);
		glColor3f(0,1,0);
		glVertex2f(x,340);
		glVertex2f(x+60,340);
		glVertex2f(x-5,360);
		glVertex2f(x+40,360);
		glVertex2f(x+15,380);
		glVertex2f(x+30,380);
		glVertex2f(x,420);
		glVertex2f(x-30,380);
		glVertex2f(x-5,380);
		glVertex2f(x-40,360);
		glVertex2f(x-5,360);
		glVertex2f(x-60,340);
		glVertex2f(x,340);
		glEnd();

		glColor3f(0.35,0.16,0.14);
	glBegin(GL_POLYGON);
		glVertex2f(x-10,300);
		glVertex2f(x+10,300);
		glVertex2f(x+10,340);
		glVertex2f(x-10,340);
	glEnd();
	}
	
	//Road Dividers
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(0,300);
		glVertex2f(1200,300);
		glVertex2f(0,290);
		glVertex2f(1200,290);
	glEnd();

	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(0,30);
		glVertex2f(1200,30);
		glVertex2f(0,20);
		glVertex2f(1200,20);
	glEnd();

	for(int x=0,flag=0;x<1200;x+=60){
		flag = !flag;
		glBegin(GL_POLYGON);
			glColor3f(flag,flag,0);
			glVertex2f(x,290);
			glVertex2f(x+60,290);
			glVertex2f(x+60,300);
			glVertex2f(x,300);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(flag,flag,0);
			glVertex2f(x,20);
			glVertex2f(x+60,20);
			glVertex2f(x+60,30);
			glVertex2f(x,30);
		glEnd();
	}

	//Road
	glColor3f(0.13,0.1,0.1);
	glBegin(GL_POLYGON);
		glVertex3f(0,30,-50);
		glVertex3f(1200,30,-50);
		glVertex3f(1200,290,-50);
		glVertex3f(0,290,-50);
	glEnd();

	//Road Stripes
	glColor3f(1,1,1);
	for(int x=125;x<1200;x+=250){
		glBegin(GL_POLYGON);
			glVertex3f(x,150,-49);
			glVertex3f(x+125,150,-49);
			glVertex3f(x+125,155,-49);
			glVertex3f(x,155,-49);
		glEnd();
	}

	//Blood
	if(done && !flagh){
		if(b<15)
			b+=0.01;
		glColor3f(1,0,0);
		glBegin(GL_POLYGON);
			for(int i=0;i<360;i++)
				glVertex3f(690+(b+3)*cos(i*(3.14/180)),Ory+85+(b+3)*sin(i*(3.14/180)),0);
		glEnd();
		glBegin(GL_POLYGON);
			for(int i=0;i<360;i++)
				glVertex3f(695+b*cos(i*(3.14/180)),Ory+87+b*sin(i*(3.14/180)),0);
		glEnd();
		glBegin(GL_POLYGON);
			for(int i=0;i<360;i++)
				glVertex3f(693+(b+4)*cos(i*(3.14/180)),Ory+82+(b+8)*sin(i*(3.14/180)),0);
		glEnd();
	}
	
	//Text
	if(done){
	glPushMatrix();
		if(flagh && done){
			const unsigned char a[100] = "He is still in One Piece...Thanks to the Helm :D";
			glColor3f(0,1,0);
			glRasterPos2f(500,250);
			glutBitmapString(GLUT_BITMAP_HELVETICA_18,a);
		}
		else if(done){
			const unsigned char a[100] = "You do not want this to happen with you!!! So wear Helmet";
			glColor3f(1,0,0);
			glRasterPos2f(500,250);
			glutBitmapString(GLUT_BITMAP_HELVETICA_18,a);
		}
		else{
			const unsigned char a[100] = " ";
			glColor3f(1,1,1);
			glRasterPos2f(1500,250);
			glutBitmapString(GLUT_BITMAP_HELVETICA_18,a);
		}
		glFlush();
	}
	glPopMatrix();

	//Clouds
	glColor3f(1,1,1);
	h+=0.1;
	if(h >= 1200)
		h=0;
	double l=h;
	for(int j=0;j<3;j++,l+=400){
		double x = l;
		glBegin(GL_POLYGON);
		for(int i=0;i<=360;i++)
			glVertex3f(x+20*cos(i*(3.14/180)),k+15*sin(i*(3.14/180)),10);
		glEnd();
		if(x>1100){
			x -= 1200;
			glBegin(GL_POLYGON);
			for(int i=0;i<=360;i++)
				glVertex3f(x+20*cos(i*(3.14/180)),k+15*sin(i*(3.14/180)),10);
			glEnd();
		}
		x = l+15;
		glBegin(GL_POLYGON);
		for(int i=0;i<=360;i++)
			glVertex3f(x+20*cos(i*(3.14/180)),k+20*sin(i*(3.14/180)),10);
		glEnd();
		if(x>1100){
			x -= 1200;
			glBegin(GL_POLYGON);
			for(int i=0;i<=360;i++)
				glVertex3f(x+20*cos(i*(3.14/180)),k+20*sin(i*(3.14/180)),10);
			glEnd();
		}
		x = l+30;
		glBegin(GL_POLYGON);
		for(int i=0;i<=360;i++)
			glVertex3f(x+20*cos(i*(3.14/180)),k+15*sin(i*(3.14/180)),10);
		glEnd();
		if(x>1100){
			x -= 1200;
			glBegin(GL_POLYGON);
			for(int i=0;i<=360;i++)
				glVertex3f(x+20*cos(i*(3.14/180)),k+15*sin(i*(3.14/180)),10);
			glEnd();
		}
	}
	}
	if(first_page){
		glColor3f(1,0,0);
		const unsigned char texts[10][50] ={"DEPARTMENT OF COMPUTER SCIENCE",
							 "REVA INSTITUTE OF TECHNOLOGY AND MANAGEMENT",
							 "CG MINI PROJECT ON THE HELM",
							 "USING OPENGL",
							 "Under The Guidance of",
							 "Prof. Tirumagal E.",
							 " Dept. of CSE, REVA ITM",
							 "Prepared By :-",
							 "YASHAS U HIREMATH (1RE13CS186)",
							 "V SRINIDHI (1RE13CS180)"};
		glRasterPos2f(400,550);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18,texts[0]);
		glRasterPos2f(320,530);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18,texts[1]);
		glRasterPos2f(430,510);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18,texts[2]);
		glRasterPos2f(500,490);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18,texts[3]);
		glRasterPos2f(320,320);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18,texts[4]);
		glRasterPos2f(420,300);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18,texts[5]);
		glRasterPos2f(415,280);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18,texts[6]);
		glRasterPos2f(320,160);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18,texts[7]);
		glRasterPos2f(420,140);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18,texts[8]);
		glRasterPos2f(420,120);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18,texts[9]);
	}
	glFlush();
	glutSwapBuffers();
}
void bresenham_circle(int r){
  int x=0,y=r;
  float pk=(5.0/4.0)-r;
  /* Plot the points */
  /* Plot the first point */
  plot_point(x,y);
  int k;
  /* Find all vertices till x=y */
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point(x,y);
  }
  glFlush();
}

// Function to draw two concentric circles
void concentric_circles(void)
{
  /* Clears buffers to preset values */
  glClear(GL_COLOR_BUFFER_BIT);
  int radius1 = 100, radius2 = 200;
  bresenham_circle(radius1);
  bresenham_circle(radius2);
}

void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}

void move(){
	if(impact == 270)
		flag1 = 1;
	if(flag1 && impact == 250){
		if(y + 80 <=115 && y + 80 >=80){
			falling = true;
			fall();
		}
		else{
			flag1 = 0;
		}

	}
	
	else{
		//for(int i=0;i<1000000;i++);
		for(int i=0;i<500000;i++);
		if(orx<800){
			orx++;
			Orx++;
			x++;
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			flag = !flag;
			display();
		}
		else{
			if(flag1)
				flagr = 1;
			orx = 0;
			Orx = 0;
			x = 0;
		}
		theta = theta - 0.02;
		if(theta > -90){
			keypt[0][0] = 135 + (5)*cos(theta);
			keypt[0][1] = 100 + (5)*sin(theta);
		}
		else
			theta = 270;
	}
		glutPostRedisplay();
}

void key(unsigned char k,int x,int y){
	
	if(k == 's' ||k == 'S')
		glutIdleFunc(NULL);
	if(k == 'p' || k == 'P'){
		if(!done)
			glutIdleFunc(move);
	}
	if(k == 'h' || k == 'H'){
		flagh = !flagh;
		display();
	}
	if(k == 'r' || k == 'R'){
		flag1 = 0;
		flagh = 0;
		flagr = 0;
		orx = 0;
		Orx = 0;
		ory = 0;
		Ory = 0;
		x = 0;
		fx = 0;
		fy = 0;
		theta = 270;
		theta1 = 0;
		done = false;
		falling = false;
		glutIdleFunc(idle);
		init();
		display();
	}
	if(k == 'a' && !falling){
		if(ory+80 <280){
		ory+=0.8;
		Ory+=0.8;
		y+=0.8;
		}
	}
	if(k == 'z' && !falling){
		if(ory+80 > 40){
		ory-=0.8;
		Ory-=0.8;
		y-=0.8;
		}
	}
	if(k == 'i')
		first_page = false;
}

void myRotate(float x,float y,float z){
	float cor[3]={x,y,1};
	float h=Orx+132.5,k=Ory+154;
	float thetar = (theta1)*(3.14/180);
	float m = -h*(cos(thetar)-1) + k*(sin(thetar)),n = -k*(cos(thetar)-1) - h*(sin(thetar)); 
	float rot_mat[3][3] = {{cos(thetar),-sin(thetar),m},{sin(thetar),cos(thetar),n},{0,0,1}};
	r[0]=r[1]=0;
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++)
				r[i]+=cor[j]*(rot_mat[i][j]);
	}	
}

void fall(){
	fx+=0.85;
	if(fx>=400 && flagh)
			flag = -1;
	if(fx<400){
		theta1-=0.31;
		if(fx<100)
			fy+=0.35;
		if(fx<150)
			fy+=0.25;
		if(fx<175)
			fy+=0;
		if(fx<200)
			fy-=0.25;
		if(fx>=225)
			fy-=0.35;
	}
	else if (flag<0 && fx<700){
		fx+=0.35;
		if(fx<700 && theta1!=-360){
			theta1-=0.90;
			orx+=3;
			if(fx<500){
				fy+=0.75;
				ory+=0.5;
				orx--;
			}
			if(fx<550){
				fy+=0.65;
				ory+=0.5;
				orx--;
			}
			if(fx<575){
				fy+=0;
				ory+=0.5;
				orx++;
			}
			if(fx<600){
				fy-=0.35;
				ory-=1;
			}
			if(fx>=625)
				fy-=0.45;
		}
	}
	else {
		orx+=8;
		flag1=0;
		done = true;
		glutIdleFunc(idle);
	}
}

void idle(){
	display();
}