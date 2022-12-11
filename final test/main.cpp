#include<windows.h>
#include<stdlib.h>
#include<iostream>
#ifdef __APPLE__
#include<OpenGL/OpenGl.h>
#include<GLUT/glut.h>
#else
#include<Gl/glut.h>
#endif // __APPLE__
#define PI          3.141516
#include<math.h>

using namespace std;

GLint x=2;

GLint r=1;

float sun_move = 0.0f;
float cloud_move = 0.0f;
float cloud_move1 = 0.0f;
float cloud_move2 = 0.0f;
float car_move1 = 0.0f;
float car_move2 = 0.0f;
float car_move3 = 0.0f;
float xrain = 10.0f;
float yrain = 10.0f;

bool start1 = false;
bool start2 = false;
bool start3 = false;
bool rain1 = false;
bool rain2 = false;

void MyInit()
{
    glEnable(GL_DEPTH_TEST);
    gluOrtho2D(0,1600,0,800);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

}

void handleResize(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'n': start1 = true; break;
        case 'd': start2 = true; break;

        case 'r': r = 2; break;
        case 's': r = 1; break;


        glutPostRedisplay();
    }
}

void Circle(GLfloat x, GLfloat y,GLfloat radius,int c1, int c2, int c3)
{
    int i;

    int triangleAmount = 100;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(c1,c2,c3);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++){
        glVertex2f(
                   x+(radius * cos(i * twicePi / triangleAmount)),
                   y+(radius * sin(i * twicePi / triangleAmount))
                   );
    }
    glEnd();
}

void rain(){
    glPushMatrix();

    glTranslatef( xrain,yrain,0.0f);

    glBegin(GL_LINES);

    glVertex2f(-.85,1.9);glVertex2f(-.8,1.8);
    glVertex2f(-.55,1.9);glVertex2f(-.5,1.8);
    glVertex2f(-.25,1.9);glVertex2f(-.2,1.8);
            glVertex2f(.05,1.9);glVertex2f(.1,1.8);
            glVertex2f(.35,1.9);glVertex2f(.4,1.8);
            glVertex2f(.65,1.9);glVertex2f(.7,1.8);
            glVertex2f(.95,1.9);glVertex2f(1.0,1.8);

     glVertex2f(-1.0,1.6);glVertex2f(-.95,1.5);
    glVertex2f(-.7,1.6);glVertex2f(-.65,1.5);
    glVertex2f(-.4,1.6);glVertex2f(-.35,1.5);
    glVertex2f(-.1,1.6);glVertex2f(-.05,1.5);
            glVertex2f(.2,1.6);glVertex2f(.25,1.5);
            glVertex2f(.5,1.6);glVertex2f(.55,1.5);
            glVertex2f(.8,1.6);glVertex2f(.85,1.5);


    glVertex2f(-.85,1.3);glVertex2f(-.8,1.2);
    glVertex2f(-.55,1.3);glVertex2f(-.5,1.2);
    glVertex2f(-.25,1.3);glVertex2f(-.2,1.2);
             glVertex2f(.05,1.3);glVertex2f(.1,1.2);
            glVertex2f(.35,1.3);glVertex2f(.4,1.2);
            glVertex2f(.65,1.3);glVertex2f(.7,1.2);
            glVertex2f(.95,1.3);glVertex2f(1.0,1.2);

    glVertex2f(-1.0,1.0);glVertex2f(-.95,.9);
    glVertex2f(-.7,1.0);glVertex2f(-.65,0.9);
    glVertex2f(-.4,1.0);glVertex2f(-.35,0.9);
    glVertex2f(-.1,1.0);glVertex2f(-.05,0.9);
                 glVertex2f(.2,1.0);glVertex2f(.25,.9);
                 glVertex2f(.5,1.0);glVertex2f(.55,0.9);
                 glVertex2f(.8,1.0);glVertex2f(.85,0.9);



    glVertex2f(-.85,.7);glVertex2f(-.8,.6);
    glVertex2f(-.55,.7);glVertex2f(-.5,0.6);
    glVertex2f(-.25,.7);glVertex2f(-.2,0.6);
              glVertex2f(.05,.7);glVertex2f(.1,.6);
            glVertex2f(.35,.7);glVertex2f(.4,.6);
            glVertex2f(.65,.7);glVertex2f(.7,.6);
            glVertex2f(.95,.7);glVertex2f(1.0,.6);

    glVertex2f(-1.0,.4);glVertex2f(-.95,.3);
    glVertex2f(-.7,.4);glVertex2f(-.65,0.3);
    glVertex2f(-.4,.4);glVertex2f(-.35,0.3);
    glVertex2f(-.1,.4);glVertex2f(-.05,0.3);
                 glVertex2f(.2,.4);glVertex2f(.25,.3);
                 glVertex2f(.5,.4);glVertex2f(.55,0.3);
                 glVertex2f(.8,.40);glVertex2f(.85,0.3);

    glVertex2f(-.85,.1);glVertex2f(-.8,0.0);
    glVertex2f(-.55,.1);glVertex2f(-.5,0.0);
    glVertex2f(-.25,.1);glVertex2f(-.2,0.0);
              glVertex2f(.05,.1);glVertex2f(.1,.0);
            glVertex2f(.35,.1);glVertex2f(.4,.0);
            glVertex2f(.65,.1);glVertex2f(.7,.0);
            glVertex2f(.95,.1);glVertex2f(1.0,.0);


    glVertex2f(-1.0,-.2);glVertex2f(-.95,-.3);
    glVertex2f(-.7,-.2);glVertex2f(-.65,-0.3);
    glVertex2f(-.4,-.2);glVertex2f(-.35,-0.3);
    glVertex2f(-.1,-.2);glVertex2f(-.05,-0.3);
                 glVertex2f(.2,-.2);glVertex2f(.25,-.3);
                 glVertex2f(.5,-.2);glVertex2f(.55,-.3);
                 glVertex2f(.8,-.2);glVertex2f(.85,-.3);

    glVertex2f(-.85,-.5);glVertex2f(-.8,-.6);
    glVertex2f(-.55,-.5);glVertex2f(-.5,-.6);
    glVertex2f(-.25,-.5);glVertex2f(-.2,-.6);
              glVertex2f(.05,-.5);glVertex2f(.1,-.6);
            glVertex2f(.35,-.5);glVertex2f(.4,-.6);
            glVertex2f(.65,-.5);glVertex2f(.7,-.6);
            glVertex2f(.95,-.5);glVertex2f(1.0,-.6);

    glVertex2f(-1.0,-.8);glVertex2f(-.95,-.9);
    glVertex2f(-.7,-.8);glVertex2f(-.65,-0.9);
    glVertex2f(-.4,-.8);glVertex2f(-.35,-0.9);
    glVertex2f(-.1,-.8);glVertex2f(-.05,-0.9);
                 glVertex2f(.2,-.8);glVertex2f(.25,-.9);
                 glVertex2f(.5,-.8);glVertex2f(.55,-.9);
                 glVertex2f(.8,-.8);glVertex2f(.85,-.9);

    glVertex2f(-.85,-1.1);glVertex2f(-.8,-1.2);
    glVertex2f(-.55,-1.1);glVertex2f(-.5,-1.2);
    glVertex2f(-.25,-1.1);glVertex2f(-.2,-1.2);
              glVertex2f(.05,-1.1);glVertex2f(.1,-1.2);
            glVertex2f(.35,-1.1);glVertex2f(.4,-1.2);
            glVertex2f(.65,-1.1);glVertex2f(.7,-1.2);
            glVertex2f(.95,-1.1);glVertex2f(1.0,-1.2);

    glVertex2f(-1.0,-1.4);glVertex2f(-.95,-1.5);
    glVertex2f(-.7,-1.4);glVertex2f(-.65,-1.5);
    glVertex2f(-.4,-1.4);glVertex2f(-.35,-1.5);
    glVertex2f(-.1,-1.4);glVertex2f(-.05,-1.5);
                 glVertex2f(.2,-1.4);glVertex2f(.25,-1.5);
                 glVertex2f(.5,-1.4);glVertex2f(.55,-1.5);
                 glVertex2f(.8,-1.4);glVertex2f(.85,-1.5);


        glEnd();
        glPopMatrix();
}

void Sky()
{
    glBegin(GL_POLYGON);
    glColor3ub(0,181,226);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glEnd();
}

void sun()
{
    Circle(-0.35,0.75,0.08,247,247,73);
}

void Moon()
{
    glPushMatrix();
    Circle(0.55,0.75,0.08,217,217,214);
    glPopMatrix();
}

void Cloud1()
{
    Circle(-0.85,0.77,0.07,255,255,237);
    Circle(-0.79,0.70,0.07,255,255,237);
    Circle(-0.70,0.70,0.07,255,255,237);
    Circle(-0.75,0.77,0.07,255,255,237);
}

void Cloud2()
{
    Circle(0.35,0.77,0.07,255,255,237);
    Circle(0.45,0.70,0.07,255,255,237);
    Circle(0.55,0.75,0.07,255,255,237);
    Circle(0.45,0.80,0.07,255,255,237);
}

void Cloud3()
{
    Circle(-0.05,0.85,0.07,255,255,237);
    Circle(-0.01,0.80,0.07,255,255,237);
    Circle(0.06,0.80,0.07,255,255,237);
    Circle(0.02,0.85,0.07,255,255,237);
}


void GreenFild()
{
   glTranslatef(0.57, 0.05, 0.0);
   glBegin(GL_POLYGON);
   glColor3ub(0,154,23);
   glVertex2f(-1.0, 0.0);
   glVertex2f(1.0, 0.0);
   glVertex2f(1.0, 0.3);
   glVertex2f(-1.0, 0.3);
   glEnd();


   glBegin(GL_POLYGON);
   glColor3ub(185,163,122);
   glVertex2f(-1.0, -0.15);
   glVertex2f(1.0, -0.15);
   glVertex2f(1.0, 0.0);
   glVertex2f(-1.0, 0.0);
   glEnd();
}

void Tree()
{
    glTranslatef(-0.05,0.06,0.0);
    glScalef(0.75,0.75,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(116,102,59);
   glVertex2f(0.1162468930092, 0.2896753474995);
   glVertex2f(0.13, 0.2896753474995);
   glVertex2f(0.13, 0.3672880331443);
   glVertex2f(0.1162468930092, 0.3672880331443);
   glEnd();

   Circle(0.1052922971095, 0.3929293898675, 0.03,48,183,0);
   Circle(0.1403392113147, 0.3887571381764, 0.03,48,183,0);
   Circle(0.1219813038739, 0.4288107544108, 0.03,48,183,0);

   glTranslatef(-0.6,0.03,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(116,102,59);
   glVertex2f(0.1162468930092, 0.2896753474995);
   glVertex2f(0.13, 0.2896753474995);
   glVertex2f(0.13, 0.3672880331443);
   glVertex2f(0.1162468930092, 0.3672880331443);
   glEnd();

   Circle(0.1052922971095, 0.3929293898675, 0.03,48,183,0);
   Circle(0.1403392113147, 0.3887571381764, 0.03,48,183,0);
   Circle(0.1219813038739, 0.4288107544108, 0.03,48,183,0);

}

void Brence()
{
    glTranslatef(0.05,-0.28,0.0);
    glScalef(1.45,1.45,0.0);

   ///wood 1 =>
   glBegin(GL_POLYGON);
   glColor3ub(226,187,123);
   glVertex2f(-0.2542312385713, 0.2998139127905);
   glVertex2f(0.2574061863554, 0.2998139127905);
   glColor3ub(210,176,76);
   glVertex2f(0.2574061863554, 0.3541585119043);
   glVertex2f(-0.2542312385713, 0.3541585119043);
   glEnd();

   ///wood 2 =>
   glTranslatef(0.0,-0.07,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(226,187,123);
   glVertex2f(-0.2542312385713, 0.2998139127905);
   glVertex2f(0.2574061863554, 0.2998139127905);
   glColor3ub(210,176,76);
   glVertex2f(0.2574061863554, 0.3541585119043);
   glVertex2f(-0.2542312385713, 0.3541585119043);
   glEnd();


   ///wood 3 =>
   glTranslatef(0.0,-0.07,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(226,187,123);
   glVertex2f(-0.2542312385713, 0.2998139127905);
   glVertex2f(0.2574061863554, 0.2998139127905);
   glColor3ub(210,176,76);
   glVertex2f(0.2574061863554, 0.3541585119043);
   glVertex2f(-0.2542312385713, 0.3541585119043);
   glEnd();


   ///wood 4 =>
   glTranslatef(0.0,0.12,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(226,187,123);
   glVertex2f(-0.2527872474695, 0.1564183250678);
   glVertex2f(0.2568524532016, 0.1564183250678);
   glVertex2f(0.2568524532016, 0.16554435867);
   glVertex2f(-0.2527872474695, 0.16554435867);
   glEnd();

   ///wood 5 =>
   glTranslatef(0.0,-0.007,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(183,119,41);
   glVertex2f(-0.2527872474695, 0.1564183250678);
   glVertex2f(0.2568524532016, 0.1564183250678);
   glVertex2f(0.2568524532016, 0.16554435867);
   glVertex2f(-0.2527872474695, 0.16554435867);
   glEnd();

   ///wood 6 =>
   glTranslatef(0.0,-0.007,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(226,187,123);
   glVertex2f(-0.2527872474695, 0.1564183250678);
   glVertex2f(0.2568524532016, 0.1564183250678);
   glVertex2f(0.2568524532016, 0.16554435867);
   glVertex2f(-0.2527872474695, 0.16554435867);
   glEnd();

   ///wood 7 =>
   glTranslatef(0.0,-0.007,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(183,119,41);
   glVertex2f(-0.2527872474695, 0.1564183250678);
   glVertex2f(0.2568524532016, 0.1564183250678);
   glVertex2f(0.2568524532016, 0.16554435867);
   glVertex2f(-0.2527872474695, 0.16554435867);
   glEnd();

   ///Still 1 =>
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(-0.2148648127542, 0.0398486454081);
   glVertex2f(-0.1968119335137, 0.0398486454081);
   glVertex2f(-0.1968119335137, 0.2979597328761);
   glVertex2f(-0.2148648127542, 0.2979597328761);
   glEnd();

   ///Still 2 =>
   glTranslatef(0.41,0.0,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(-0.2148648127542, 0.0398486454081);
   glVertex2f(-0.1968119335137, 0.0398486454081);
   glVertex2f(-0.1968119335137, 0.2979597328761);
   glVertex2f(-0.2148648127542, 0.2979597328761);
   glEnd();

   ///Still 3 =>
   glTranslatef(-0.41,0.0,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(-0.1974108276694, 0.0989896732208);
   glVertex2f(0.2023150828568, 0.0989896732208);
   glVertex2f(0.2023150828568, 0.1103731141929);
   glVertex2f(-0.1974108276694, 0.1103731141929);
   glEnd();
}


void Lamp()
{
    ///lamp 1 ------------------------------------------------------
    ///---------------------------------------------------------------

    glTranslatef(0.0,0.0,0.0);
    ///7
   glBegin(GL_POLYGON);
   glColor3ub(255,255,237);
   glVertex2f(-0.6569192005552, 0.139341350996);
   glVertex2f(-0.6372311889273, 0.139341350996);
   glVertex2f(-0.6372311889273, 0.2619265937207);
   glVertex2f(-0.6569192005552, 0.2619265937207);
   glEnd();

   Circle(-0.6478324259577, 0.1390889405905, 0.01,255,255,237);

    ///1
    glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(-0.6843236620708, 0.07718807113);
   glVertex2f(-0.5876164607654, 0.07718807113);
   glVertex2f(-0.5876164607654, 0.0975781436943);
   glVertex2f(-0.6843236620708, 0.0975781436943);
   glEnd();

   ///2
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(-0.603637232066, 0.0974325003189);
   glVertex2f(-0.6036341095858, 0.2628436164055);
   glVertex2f(-0.6697967594371, 0.2624068217273);
   glVertex2f(-0.6699650878069, 0.097446749117);
   glEnd();

   ///3
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(-0.641563902274, 0.2630794626454);
   glVertex2f(-0.6308135428019, 0.2630794626454);
   glVertex2f(-0.6308135428019, 0.659428690115);
   glVertex2f(-0.641563902274, 0.659428690115);
   glEnd();

   ///4
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(-0.6408085102302, 0.6545147115207);
   glVertex2f(-0.5400694892518, 0.6545147115207);
   glVertex2f(-0.5400694892518, 0.6502165132922);
   glVertex2f(-0.6408085102302, 0.6502165132922);
   glEnd();

   ///5
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(-0.5502777100443, 0.634366907325);
   glVertex2f(-0.5395322144732, 0.634366907325);
   glVertex2f(-0.5395322144732, 0.6569324480241);
   glVertex2f(-0.5502777100443, 0.6569324480241);
   glEnd();

   ///6
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(-0.5723671466751, 0.6183163677373);
   glVertex2f(-0.5168708555807, 0.6183163677373);
   glVertex2f(-0.5168708555807, 0.6336759472927);
   glVertex2f(-0.5723671466751, 0.6336759472927);
   glEnd();

   Circle(-0.5454422370373, 0.5967576728263, 0.03,255,252,201);
   Circle(-0.5454422370373, 0.5790276051341, 0.045,255,233,0);

   ///lamp 2 ------------------------------------------------------
    ///---------------------------------------------------------------

    glTranslatef(-0.08,0.0,0.0);

    ///7
   glBegin(GL_POLYGON);
   glColor3ub(255,255,237);
   glVertex2f(0.6549328639253, 0.1407484264765);
   glVertex2f(0.6761473835915, 0.1407484264765);
   glVertex2f(0.6761473835915, 0.2617752054273);
   glVertex2f(0.6549328639253, 0.2617752054273);
   glEnd();

    Circle(0.6655371837027, 0.1425135840442, 0.01,255,255,237);

    ///1
    glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(0.6066899890751, 0.0767546643068);
   glVertex2f(0.7026117774843, 0.0767546643068);
   glVertex2f(0.7026117774843, 0.0966408887331);
   glVertex2f(0.6066899890751, 0.0966408887331);
   glEnd();

   ///2
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(0.6865754432486, 0.0964362489289);
   glVertex2f(0.6865754432486, 0.2619843936668);
   glVertex2f(0.6215742179164, 0.2619843936668);
   glVertex2f(0.6215742179164, 0.0964362489289);
   glEnd();

   ///3
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(0.6485012474634, 0.2620090268782);
   glVertex2f(0.6599878079326, 0.2620090268782);
   glVertex2f(0.6599878079326, 0.6592604263789);
   glVertex2f(0.6485012474634, 0.6592604263789);
   glEnd();

   ///4
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(0.5567515292757, 0.6498834893202);
   glVertex2f(0.6581408701755, 0.6498834893202);
   glVertex2f(0.6581408701755, 0.6592604263789);
   glVertex2f(0.5567515292757, 0.6592604263789);
   glEnd();

   ///5
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(0.5573568387736, 0.6344480971235);
   glVertex2f(0.5688577192339, 0.6344480971235);
   glVertex2f(0.5688577192339, 0.6592657865378);
   glVertex2f(0.5573568387736, 0.6592657865378);
   glEnd();

   ///6
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
   glVertex2f(0.5371377747231, 0.620033834887);
   glVertex2f(0.5899783778121, 0.620033834887);
   glVertex2f(0.5899783778121, 0.6335693588309);
   glVertex2f(0.5371377747231, 0.6335693588309);
   glEnd();

   Circle(0.5646114367828, 0.5954701693858, 0.03,255,252,201);
   Circle(0.5630045092954, 0.5810078219992, 0.045,255,233,0);

   glTranslatef(0.08,0.0,0.0);

}

///------------------------------------------------------------
///building 1--------------------------------------------------
///------------------------------------------------------------

void Building1()
{
   glTranslatef(0.05,-0.4,0.0);
   glScalef(1.4,1.4,0.0);

   /// windows 1 of building 1
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.3675138307325, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5980199224049);
   glVertex2f(-0.3675138307325, 0.5980199224049);
   glEnd();

   glTranslatef(-0.0, -0.05,0.0);
   /// windows 2 of building 1
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.3675138307325, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5980199224049);
   glVertex2f(-0.3675138307325, 0.5980199224049);
   glEnd();

   glTranslatef(0.05,0.0,0.0);
   /// windows 3 of building 1
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.3675138307325, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5980199224049);
   glVertex2f(-0.3675138307325, 0.5980199224049);
   glEnd();

   glTranslatef(-0.05, -0.05,0.0);
   /// windows 4 of building 1
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.3675138307325, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5980199224049);
   glVertex2f(-0.3675138307325, 0.5980199224049);
   glEnd();

   glTranslatef(0.05,0.0,0.0);
   /// windows 5 of building 1
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.3675138307325, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5980199224049);
   glVertex2f(-0.3675138307325, 0.5980199224049);
   glEnd();

   glTranslatef(-0.0, -0.05,0.0);
   /// windows 6 of building 1
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.3675138307325, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5980199224049);
   glVertex2f(-0.3675138307325, 0.5980199224049);
   glEnd();

   glTranslatef(-0.05,0.0,0.0);
   /// windows 7 of building 1
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.3675138307325, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5980199224049);
   glVertex2f(-0.3675138307325, 0.5980199224049);
   glEnd();

   glTranslatef(0.05, -0.05,0.0);
   /// windows 8 of building 1
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.3675138307325, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5980199224049);
   glVertex2f(-0.3675138307325, 0.5980199224049);
   glEnd();

   glTranslatef(-0.05,0.0,0.0);
   /// windows 9 of building 1
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.3675138307325, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5681795164583);
   glVertex2f(-0.3276803586085, 0.5980199224049);
   glVertex2f(-0.3675138307325, 0.5980199224049);
   glEnd();

   ///Building 1
   glTranslatef(0.0,0.2,0.0);

   glBegin(GL_POLYGON);
   glColor3ub(255,112,115);
   glVertex2f(-0.3770122806442, 0.6279379382142);
   glVertex2f(-0.2549312026879, 0.6279379382142);
   glVertex2f(-0.2549312026879, 0.6577323545464);
   glVertex2f(-0.3770122806442, 0.6577323545464);
   glEnd();

   glBegin(GL_POLYGON);
   glColor3ub(255,182,115);
   glVertex2f(-0.3770122806442, 0.2991020602492);
   glVertex2f(-0.2549312026879, 0.2991020602492);
   glVertex2f(-0.2549312026879, 0.6577323545464);
   glVertex2f(-0.3770122806442, 0.6577323545464);
   glEnd();

}

///------------------------------------------------------------
///building 2--------------------------------------------------
///------------------------------------------------------------

void Building2()
{
   glTranslatef(0.0,-0.03,0.0);

   /// windows 1 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

   glTranslatef(0.052,0.0,0.0);
   /// windows 2 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

   glTranslatef(-0.052,-0.05,0.0);
   /// windows 3 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

   glTranslatef(0.052,0.0,0.0);
   /// windows 4 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

   glTranslatef(-0.052,-0.05,0.0);
   /// windows 5 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

   glTranslatef(0.052,0.0,0.0);
   /// windows 6 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

    glTranslatef(-0.052,-0.05,0.0);
   /// windows 7 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

   glTranslatef(0.052,0.0,0.0);
   /// windows 8 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

   glTranslatef(-0.052,-0.05,0.0);
   /// windows 9 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

   glTranslatef(0.052,0.0,0.0);
   /// windows 10 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

   glTranslatef(-0.052,-0.05,0.0);
   /// windows 11 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

   glTranslatef(0.052,0.0,0.0);
   /// windows 12 of building 2
   glBegin(GL_POLYGON);
   glColor3ub(255,252,201);
   glVertex2f(-0.2401309554659, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6364447731626);
   glVertex2f(-0.2009514574351, 0.6662432646226);
   glVertex2f(-0.2401309554659, 0.6662432646226);
   glEnd();

   ///building 2

   glTranslatef(-0.055,0.25,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.240502605875, 0.3562786451883);
   glVertex2f(-0.1386379787192, 0.3562786451883);
   glVertex2f(-0.1386379787192, 0.6953429887287);
   glVertex2f(-0.240502605875, 0.6953429887287);
   glEnd();

   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1600597683314, 0.6953429887287);
   glVertex2f(-0.1600597683314, 0.7662400770463);
   glVertex2f(-0.2205977262944, 0.7662400770463);
   glVertex2f(-0.2205977262944, 0.6953429887287);
   glEnd();

   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1868118872825, 0.7662400770463);
   glVertex2f(-0.1868118872825, 0.8287690925309);
   glVertex2f(-0.1956365467259, 0.8287690925309);
   glVertex2f(-0.1956365467259, 0.7662400770463);
   glEnd();
}

///------------------------------------------------------------
///Building--------------------------------------------------
///------------------------------------------------------------

void Building3()
{
   /// windows 1 of Building
   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1138146695506, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6739585159215);
   glVertex2f(-0.1138146695506, 0.6739585159215);
   glEnd();

   glTranslatef(0.0,-0.03,0.0);
   /// windows 2 of Building
   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1138146695506, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6739585159215);
   glVertex2f(-0.1138146695506, 0.6739585159215);
   glEnd();

   glTranslatef(0.0,-0.03,0.0);
   /// windows 3 of Building
   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1138146695506, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6739585159215);
   glVertex2f(-0.1138146695506, 0.6739585159215);
   glEnd();

   glTranslatef(0.0,-0.03,0.0);
   /// windows 4 of Building
   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1138146695506, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6739585159215);
   glVertex2f(-0.1138146695506, 0.6739585159215);
   glEnd();

   glTranslatef(0.0,-0.03,0.0);
   /// windows 5 of Building
   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1138146695506, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6739585159215);
   glVertex2f(-0.1138146695506, 0.6739585159215);
   glEnd();

   glTranslatef(0.0,-0.03,0.0);
   /// windows 6 of Building
   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1138146695506, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6739585159215);
   glVertex2f(-0.1138146695506, 0.6739585159215);
   glEnd();

   glTranslatef(0.0,-0.03,0.0);
   /// windows 7 of Building
   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1138146695506, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6739585159215);
   glVertex2f(-0.1138146695506, 0.6739585159215);
   glEnd();

   glTranslatef(0.0,-0.03,0.0);
   /// windows 8 of Building
   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1138146695506, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6739585159215);
   glVertex2f(-0.1138146695506, 0.6739585159215);
   glEnd();

   glTranslatef(0.0,-0.03,0.0);
   /// windows 9 of Building
   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1138146695506, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6739585159215);
   glVertex2f(-0.1138146695506, 0.6739585159215);
   glEnd();

   glTranslatef(0.0,-0.03,0.0);
   /// windows 10 of Building
   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(-0.1138146695506, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6578581229505);
   glVertex2f(-0.0125228768787, 0.6739585159215);
   glVertex2f(-0.1138146695506, 0.6739585159215);
   glEnd();

   ///building

   glTranslatef(0.0,0.27,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(191,153,114);
   glVertex2f(-0.1259892686182, 0.3562840394922);
   glVertex2f(-0.0007462019349, 0.7046632385195);
   glVertex2f(-0.1259892686182, 0.7046632385195);
   glEnd();

   glBegin(GL_POLYGON);
   glColor3ub(255,222,0);
   glVertex2f(-0.1259892686182, 0.3562840394922);
   glVertex2f(-0.0007462019349, 0.3562840394922);
   glVertex2f(-0.0007462019349, 0.7046632385195);
   glVertex2f(-0.1259892686182, 0.7046632385195);
   glEnd();
}

///------------------------------------------------------------
///building 4--------------------------------------------------
///------------------------------------------------------------

void building4()
{

   /// windows 1 of building 4
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.024716547193, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.5627260227889);
   glVertex2f(0.024716547193, 0.5627260227889);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 2 of building 4
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.024716547193, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.5627260227889);
   glVertex2f(0.024716547193, 0.5627260227889);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 3 of building 4
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.024716547193, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.5627260227889);
   glVertex2f(0.024716547193, 0.5627260227889);
   glEnd();

   glTranslatef(-0.06,-0.1,0.0);
   /// windows 4 of building 4
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.024716547193, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.5627260227889);
   glVertex2f(0.024716547193, 0.5627260227889);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 5 of building 4
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.024716547193, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.5627260227889);
   glVertex2f(0.024716547193, 0.5627260227889);
   glEnd();


   glTranslatef(0.03,0.0,0.0);
   /// windows 6 of building 4
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.024716547193, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.4674281771371);
   glVertex2f(0.0473676411274, 0.5627260227889);
   glVertex2f(0.024716547193, 0.5627260227889);
   glEnd();

   ///building 4

   glTranslatef(-0.06,0.1,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(108,147,92);
   glVertex2f(0.0138313322841, 0.3551415551011);        //1
   glVertex2f(0.1197981952474, 0.3551415551011);        //2
   glVertex2f(0.1197981952474, 0.5936709701907);        //3
   glVertex2f(0.1080038111179, 0.5936709701907);        //4
   glVertex2f(0.1080038111179, 0.6193278374599);        //5
   glVertex2f(0.0986223084984, 0.6193278374599);        //6
   glVertex2f(0.0986223084984, 0.6447584242285);        //7
   glVertex2f(0.0336417103538, 0.6447584242285);        //8
   glVertex2f(0.0336417103538, 0.619530520669);         //9
   glVertex2f(0.024573899048, 0.619530520669);         //10
   glVertex2f(0.024573899048, 0.5934122763982);         //11
   glVertex2f(0.0138313322841, 0.5934122763982);        //12
   glEnd();
}

///------------------------------------------------------------
///building 5--------------------------------------------------
///------------------------------------------------------------

void building5()
{
   glTranslatef(0.0,0.0,0.0);

   Circle(0.2086858573072, 0.6890528488606, 0.02f,155,211,221);
   Circle(0.1678247066683, 0.6349273331597, 0.02f,155,211,221);
   Circle(0.2122377334482, 0.6345272158013, 0.02f,155,211,221);
   Circle(0.1682248240267, 0.5853127807209, 0.02f,155,211,221);
   Circle(0.2126378508065, 0.5861130154377, 0.02f,155,211,221);
   Circle(0.1674245893099, 0.5352981109238, 0.02f,155,211,221);
   Circle(0.2112078988105, 0.5358033852765, 0.02f,155,211,221);
   Circle(0.1662603126719, 0.4859115646627, 0.02f,155,211,221);
   Circle(0.2112078988105, 0.4872599922469, 0.02f,155,211,221);
   Circle(0.1671592643947, 0.4342218406034, 0.02f,155,211,221);
   Circle(0.2125563263946, 0.4351207923262, 0.02f,155,211,221);
   Circle(0.1657938708577, 0.3847625298982, 0.02f,155,211,221);
   Circle(0.21192298836, 0.3855718126614, 0.02f,155,211,221);

   glBegin(GL_POLYGON);
   glColor3ub(129,97,62);
   glVertex2f(0.1358989704392, 0.3583748724437);
   glVertex2f(0.2392024688221, 0.3583748724437);
   glVertex2f(0.2392024688221, 0.8328158287431);
   glVertex2f(0.1358989704392, 0.6969425403896);
   glEnd();
}

///------------------------------------------------------------
///building 6--------------------------------------------------
///------------------------------------------------------------

void building6()
{
   glTranslatef(-0.015,0.03,0.0);

   /// windows 1 of building 6
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.2808892728611, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.478038898087);
   glVertex2f(0.2808892728611, 0.478038898087);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 2 of building 6
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.2808892728611, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.478038898087);
   glVertex2f(0.2808892728611, 0.478038898087);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 3 of building 6
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.2808892728611, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.478038898087);
   glVertex2f(0.2808892728611, 0.478038898087);
   glEnd();

   glTranslatef(-0.06,-0.05,0.0);
   /// windows 4 of building 6
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.2808892728611, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.478038898087);
   glVertex2f(0.2808892728611, 0.478038898087);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 5 of building 6
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.2808892728611, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.478038898087);
   glVertex2f(0.2808892728611, 0.478038898087);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 6 of building 6
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.2808892728611, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.478038898087);
   glVertex2f(0.2808892728611, 0.478038898087);
   glEnd();

   glTranslatef(-0.06,-0.05,0.0);
   /// windows 7 of building 6
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.2808892728611, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.478038898087);
   glVertex2f(0.2808892728611, 0.478038898087);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 8 of building 6
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.2808892728611, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.478038898087);
   glVertex2f(0.2808892728611, 0.478038898087);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 9 of building 6
   glBegin(GL_POLYGON);
   glColor3ub(173,223,179);
   glVertex2f(0.2808892728611, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.4439081623828);
   glVertex2f(0.2946697576994, 0.478038898087);
   glVertex2f(0.2808892728611, 0.478038898087);
   glEnd();

   ///building 6
   glTranslatef(-0.06,0.1,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(172,159,60);
   glVertex2f(0.2642930133724, 0.2985610246143);
   glVertex2f(0.3635535977543, 0.2985610246143);
   glVertex2f(0.2862079791507, 0.5386340718463);
   glVertex2f(0.2651794735966, 0.4984216664884);
   glEnd();

   glBegin(GL_POLYGON);
   glColor3ub(255,164,0);
   glVertex2f(0.2642930133724, 0.2985610246143);
   glVertex2f(0.3635535977543, 0.2985610246143);
   glVertex2f(0.3647881841163, 0.4978682847632);
   glVertex2f(0.3444975208623, 0.5386340718463);
   glVertex2f(0.2862079791507, 0.5386340718463);
   glVertex2f(0.2651794735966, 0.4984216664884);
   glEnd();
}

///------------------------------------------------------------
///building 7--------------------------------------------------
///------------------------------------------------------------

void building7()
{
    glTranslatef(-0.01,0.0,0.0);

   /// windows 1 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(0.05,0.0,0.0);
   /// windows 2 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(-0.05,-0.05,0.0);
   /// windows 3 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(0.05,0.0,0.0);
   /// windows 4 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(-0.05,-0.05,0.0);
   /// windows 5 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(0.05,0.0,0.0);
   /// windows 6 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(-0.05,-0.05,0.0);
   /// windows 7 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(0.05,0.0,0.0);
   /// windows 8 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(-0.05,-0.05,0.0);
   /// windows 9 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(0.05,0.0,0.0);
   /// windows 10 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(-0.05,-0.05,0.0);
   /// windows 11 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(0.05,0.0,0.0);
   /// windows 12 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(-0.05,-0.05,0.0);
   /// windows 13 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(0.05,0.0,0.0);
   /// windows 14 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(-0.05,-0.05,0.0);
   /// windows 15 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   glTranslatef(0.05,0.0,0.0);
   /// windows 16 of building 7
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.4046452008349, 0.6807980591592);
   glColor3ub(255,255,255);
   glVertex2f(0.4333574389198, 0.6807980591592);
   glColor3ub(155,211,221);
   glVertex2f(0.4333574389198, 0.7132553717769);
   glVertex2f(0.4046452008349, 0.7132553717769);
   glEnd();

   ///building 7

   glTranslatef(-0.05,0.35,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(103,71,54);
   glVertex2f(0.3950885097609, 0.7283075608735);
   glVertex2f(0.4926480928341, 0.7283075608735);
   glVertex2f(0.4926480928341, 0.7559608215291);
   glVertex2f(0.3950885097609, 0.7559608215291);
   glEnd();

   glBegin(GL_POLYGON);
   glColor3ub(252,76,2);
   glVertex2f(0.3950885097609, 0.298919397702);
   glVertex2f(0.4926755226327, 0.298919397702);
   glVertex2f(0.4926755226327, 0.7559608215291);
   glVertex2f(0.3950885097609, 0.7559608215291);
   glEnd();

}

///------------------------------------------------------------
///building 8--------------------------------------------------
///------------------------------------------------------------

void building8()
{

   glTranslatef(-0.02,0.,0.0);

   /// windows 1 of building 8
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.5290038715411, 0.3627343613617);
   glVertex2f(0.550120303972, 0.3627343613617);
   glVertex2f(0.550120303972, 0.4015839304195);
   glVertex2f(0.5290038715411, 0.4015839304195);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 2 of building 8
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.5290038715411, 0.3627343613617);
   glVertex2f(0.550120303972, 0.3627343613617);
   glVertex2f(0.550120303972, 0.4015839304195);
   glVertex2f(0.5290038715411, 0.4015839304195);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 3 of building 8
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(0.5290038715411, 0.3627343613617);
   glVertex2f(0.550120303972, 0.3627343613617);
   glVertex2f(0.550120303972, 0.4015839304195);
   glVertex2f(0.5290038715411, 0.4015839304195);
   glEnd();

   ///building 8

   glTranslatef(-0.06,0.0,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(189,22,44);
   glVertex2f(0.52, 0.3);
   glVertex2f(0.6254673219138, 0.3);
   glVertex2f(0.6254673219138, 0.3344608085148);
   glVertex2f(0.52, 0.3344608085148);
   glEnd();

   glBegin(GL_POLYGON);
   glColor3ub(246,235,97);
   glVertex2f(0.52, 0.3);
   glVertex2f(0.6254673219138, 0.300857323395);
   glVertex2f(0.6242389218131, 0.4138701326616);
   glVertex2f(0.5730555842829, 0.4826605383021);
   glVertex2f(0.5194154465513, 0.4105943990596);
   glEnd();
}

///------------------------------------------------------------
///building 9--------------------------------------------------
///------------------------------------------------------------

void building9()
{
   glTranslatef(0.05,0.0,0.0);

   /// windows 1 of building 9
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(-0.487207616763, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.4013086868927);
   glVertex2f(-0.487207616763, 0.4013086868927);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 2 of building 9
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(-0.487207616763, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.4013086868927);
   glVertex2f(-0.487207616763, 0.4013086868927);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 3 of building 9
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(-0.487207616763, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.4013086868927);
   glVertex2f(-0.487207616763, 0.4013086868927);
   glEnd();

   glTranslatef(-0.06,-0.05,0.0);
   /// windows 4 of building 9
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(-0.487207616763, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.4013086868927);
   glVertex2f(-0.487207616763, 0.4013086868927);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 5 of building 9
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(-0.487207616763, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.4013086868927);
   glVertex2f(-0.487207616763, 0.4013086868927);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 6 of building 9
   glBegin(GL_POLYGON);
   glColor3ub(155,211,221);
   glVertex2f(-0.487207616763, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.3630606609455);
   glVertex2f(-0.4674102230509, 0.4013086868927);
   glVertex2f(-0.487207616763, 0.4013086868927);
   glEnd();

   ///building 9
   glTranslatef(-0.06,0.06,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(250,70,22);
   glVertex2f(-0.4969960305824, 0.2970418233865);
   glVertex2f(-0.3918236181898, 0.2970418233865);
   glVertex2f(-0.3918236181898, 0.4127976231897);
   glVertex2f(-0.4432108865739, 0.4824421298581);
   glVertex2f(-0.4969960305824, 0.4127976231897);
   glEnd();
}

///------------------------------------------------------------
///building 10-------------------------------------------------
///------------------------------------------------------------

void building10()
{
   /// windows 1 of building 10
   glBegin(GL_POLYGON);
   glColor3ub(252,210,153);
   glVertex2f(-0.6031637901305, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4338255367188);
   glVertex2f(-0.6031637901305, 0.4338255367188);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 2 of building 10
   glBegin(GL_POLYGON);
   glColor3ub(252,210,153);
   glVertex2f(-0.6031637901305, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4338255367188);
   glVertex2f(-0.6031637901305, 0.4338255367188);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 3 of building 10
   glBegin(GL_POLYGON);
   glColor3ub(252,210,153);
   glVertex2f(-0.6031637901305, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4338255367188);
   glVertex2f(-0.6031637901305, 0.4338255367188);
   glEnd();

   glTranslatef(-0.06,-0.05,0.0);
   /// windows 4 of building 10
   glBegin(GL_POLYGON);
   glColor3ub(252,210,153);
   glVertex2f(-0.6031637901305, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4338255367188);
   glVertex2f(-0.6031637901305, 0.4338255367188);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 5 of building 10
   glBegin(GL_POLYGON);
   glColor3ub(252,210,153);
   glVertex2f(-0.6031637901305, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4338255367188);
   glVertex2f(-0.6031637901305, 0.4338255367188);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 6 of building 10
   glBegin(GL_POLYGON);
   glColor3ub(252,210,153);
   glVertex2f(-0.6031637901305, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4338255367188);
   glVertex2f(-0.6031637901305, 0.4338255367188);
   glEnd();


   glTranslatef(-0.06,-0.05,0.0);
   /// windows 7 of building 10
   glBegin(GL_POLYGON);
   glColor3ub(252,210,153);
   glVertex2f(-0.6031637901305, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4338255367188);
   glVertex2f(-0.6031637901305, 0.4338255367188);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 8 of building 10
   glBegin(GL_POLYGON);
   glColor3ub(252,210,153);
   glVertex2f(-0.6031637901305, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4338255367188);
   glVertex2f(-0.6031637901305, 0.4338255367188);
   glEnd();

   glTranslatef(0.03,0.0,0.0);
   /// windows 9 of building 10
   glBegin(GL_POLYGON);
   glColor3ub(252,210,153);
   glVertex2f(-0.6031637901305, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4049816336233);
   glVertex2f(-0.5910099793306, 0.4338255367188);
   glVertex2f(-0.6031637901305, 0.4338255367188);
   glEnd();

   ///building 10

   glTranslatef(-0.055,0.09,0.0);
   glBegin(GL_POLYGON);
   glColor3ub(128,126,120);
   glVertex2f(-0.62, 0.3);
   glVertex2f(-0.52, 0.3);
   glVertex2f(-0.52, 0.46);
   glVertex2f(-0.5403475703003, 0.4938945926428);
   glVertex2f(-0.5982433237331, 0.4942311958605);
   glVertex2f(-0.62, 0.46);
   glEnd();
}

///-----------------------------------------------------------------
///-------------------Road------------------------------------------
///-----------------------------------------------------------------

void Road()
{
    glTranslatef(0.0,-0.3,0.0);
    ///Road Line1
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-1.0,-0.62);
    glVertex2f(-0.8,-0.62);
    glVertex2f(-0.8,-0.63);
    glVertex2f(-1.0,-0.63);
    glEnd();

    ///Road Line 2
    glTranslatef(0.3,0.0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-1.0,-0.62);
    glVertex2f(-0.8,-0.62);
    glVertex2f(-0.8,-0.63);
    glVertex2f(-1.0,-0.63);
    glEnd();

    ///Road Line 3
    glTranslatef(0.3,0.0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-1.0,-0.62);
    glVertex2f(-0.8,-0.62);
    glVertex2f(-0.8,-0.63);
    glVertex2f(-1.0,-0.63);
    glEnd();

    ///Road Line 4
    glTranslatef(0.3,0.0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-1.0,-0.62);
    glVertex2f(-0.8,-0.62);
    glVertex2f(-0.8,-0.63);
    glVertex2f(-1.0,-0.63);
    glEnd();

    ///Road Line 5
    glTranslatef(0.3,0.0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-1.0,-0.62);
    glVertex2f(-0.8,-0.62);
    glVertex2f(-0.8,-0.63);
    glVertex2f(-1.0,-0.63);
    glEnd();

    ///Road Line 6
    glTranslatef(0.3,0.0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-1.0,-0.62);
    glVertex2f(-0.8,-0.62);
    glVertex2f(-0.8,-0.63);
    glVertex2f(-1.0,-0.63);
    glEnd();

    ///Road Line 7
    glTranslatef(0.3,0.0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-1.0,-0.62);
    glVertex2f(-0.8,-0.62);
    glVertex2f(-0.8,-0.63);
    glVertex2f(-1.0,-0.63);
    glEnd();

    glTranslatef(-1.8,-0.07,0.0);
    ///Road
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glVertex2f(1.0,-0.29);
    glVertex2f(-1.0,-0.29);
    glEnd();

}


void Ambulance()
{
    glTranslatef(-1.8,0.3,0.0);

    ///font yellow

    glBegin(GL_POLYGON);
    glColor3ub(255,233,0);
    glVertex2f(-0.5087974535273, -0.7067749616515); ///g
    glVertex2f(-0.5492803425609, -0.705909017501); ///h
    glVertex2f(-0.5497133146361, -0.6966001178837); ///i
    glVertex2f(-0.511178799941, -0.696383631846); ///j
    glEnd();

    /// red sign

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-0.799074062856, -0.6685283161903);
    glVertex2f(-0.7924014927737, -0.6685283161903);
    glVertex2f(-0.7924014927737, -0.6211179498165);
    glVertex2f(-0.799074062856,-0.6211179498165);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-0.7713302188298, -0.647983824095);
    glVertex2f(-0.7713302188298, -0.6414868479623);
    glVertex2f(-0.8190917731027, -0.6414868479623);
    glVertex2f(-0.8190917731027, -0.647983824095);
    glEnd();

    ///red box

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-0.7186683745985, -0.5956537244683);
    glVertex2f(-0.7016322471349, -0.5956537244683);
    glVertex2f(-0.7016322471349, -0.584861607523);
    glVertex2f(-0.7186683745985, -0.584861607523);
    glEnd();

    ///red line
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-0.8982991941929, -0.694647378969);
    glVertex2f(-0.5115324142564, -0.694647378969);
    glVertex2f(-0.5115324142564, -0.6905736228047);
    glVertex2f(-0.891574199069, -0.6905736228047);
    glVertex2f(-0.891574199069, -0.6709732453117);
    glVertex2f(-0.8981456197273, -0.6709732453117);
    glEnd();

    ///Ash bump
    glBegin(GL_POLYGON);
    glColor3ub(54,69,79);
    glVertex2f(-0.9078271807606, -0.7449033692606);
    glVertex2f(-0.8814495301069, -0.7449033692606);
    glVertex2f(-0.8814495301069, -0.7279384902094);
    glVertex2f(-0.9078271807606, -0.7279384902094);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(54,69,79);
    glVertex2f(-0.5177040560444, -0.7449983646941);
    glVertex2f(-0.4915433710796, -0.7449983646941);
    glVertex2f(-0.4915433710796, -0.7282023591047);
    glVertex2f(-0.5177040560444, -0.7282023591047);
    glEnd();

    ///Windows

    glBegin(GL_POLYGON);
    glColor3ub(89,203,232);
    glVertex2f(-0.7491112018505, -0.6685599300258);
    glVertex2f(-0.6807298510119, -0.6685599300258);
    glVertex2f(-0.6807298510119, -0.6108116042505);
    glVertex2f(-0.7491112018505, -0.6108116042505);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(89,203,232);
    glVertex2f(-0.6586810132538, -0.6687601987084);
    glVertex2f(-0.5626105384039, -0.6687601987084);
    glVertex2f(-0.6021132007599, -0.6109283010192);
    glVertex2f(-0.6586810132538, -0.6109283010192);
    glEnd();

    ///wheel 1
    Circle(-0.7902028990535, -0.7452530998401,0.02,178,190,181);
    Circle(-0.7902028990535, -0.7452530998401,0.04,60,82,145);

    ///wheel 2
    Circle(-0.6096181989375, -0.7459644920126,0.02,178,190,181);
    Circle(-0.6096181989375, -0.7459644920126,0.04,60,82,145);

    ///car body
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.8795516626156, -0.7445441327614); ///c
    glVertex2f(-0.5224360738969, -0.7448765042713); ///d
    glVertex2f(-0.5224360738969, -0.7271246491871); ///e
    glVertex2f(-0.5053336769255, -0.7262587050366); ///f
    glVertex2f(-0.5087974535273, -0.7067749616515); ///g
    glVertex2f(-0.5492803425609, -0.705909017501); ///h
    glVertex2f(-0.5497133146361, -0.6966001178837); ///i
    glVertex2f(-0.511178799941, -0.696383631846); ///j
    glVertex2f(-0.5501462867113, -0.6712712514829); ///k
    glVertex2f(-0.6009782093379, -0.595574589938); ///l
    glVertex2f(-0.8490950825927, -0.5952898154598); ///m
    glVertex2f(-0.8981642750178, -0.6696095737406); ///n
    glVertex2f(-0.8979927205972, -0.7260509781013); ///o
    glVertex2f(-0.8806657241217, -0.7258794236808); ///p
    glEnd();
}


void policeCar()
{
    glTranslatef(0.0,0.3,0.0);
    //Front Red Light
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-0.3201314701232, -0.8934694399697);//C
    glVertex2f(-0.3007521952951, -0.8929157464031);//D
    glVertex2f(-0.2996448081621, -0.9084191662656);//E
    glVertex2f(-0.3300979543205, -0.9084191662656);//F
    glEnd();

    //Middle Blue Line
    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
    glVertex2f(-0.2789012936316, -0.890523260507);//C
    glVertex2f(0.0786287887837, -0.890523260507);//D
    glVertex2f(0.0790323216081, -0.9050504421853);//E
    glVertex2f(-0.279304826456, -0.9054539750097);//F
    glEnd();

    //Back Red Light
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(0.1097008162622, -0.8933479902778);//C
    glVertex2f(0.1351233841992, -0.8933479902778);//D
    glVertex2f(0.1395622452675, -0.9094893032537);//E
    glVertex2f(0.1097008162622, -0.9090857704293);//F
    glEnd();

    //Upper First Red Light
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-0.1290151572795, -0.8126778836034);//C
    glVertex2f(-0.1097161230061, -0.8123451416332);//D
    glVertex2f(-0.1097161230061, -0.8213291748294);//E
    glVertex2f(-0.1290151572795, -0.8213291748294);//F
    glEnd();

    //Upper Middle Blue Light
    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
    glVertex2f(-0.1097161230061, -0.8126778836034);//C
    glVertex2f(-0.0904170887328, -0.8126778836034);//D
    glVertex2f(-0.0904170887328, -0.820663690889);//E
    glVertex2f(-0.1093833810359, -0.8213291748294);//F
    glEnd();

    //upper Third Red Light
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-0.090481827402, -0.8128083875862);//C
    glVertex2f(-0.0709058090473, -0.8127109944601);//D
    glVertex2f(-0.0707110227951, -0.8219633414436);//E
    glVertex2f(-0.0905792205282, -0.8218659483175);//F
    glEnd();

    //Front Window
    glBegin(GL_POLYGON);
    glColor3ub(89,203,232);
    glVertex2f(-0.1999184225531, -0.8676394567482);//C
    glVertex2f(-0.1499640703112, -0.8330342071505);//D
    glVertex2f(-0.0709859603422, -0.8330342071505);//E
    glVertex2f(-0.0707068857487, -0.8676394567482);//F
    glEnd();

    //Back Window
    glBegin(GL_POLYGON);
    glColor3ub(89,203,232);
    glVertex2f(-0.059155273315, -0.8333661019481);//C
    glVertex2f(0.0192760403068, -0.8331853846356);//D
    glVertex2f(0.0396970966185, -0.8682445432592);//E
    glVertex2f(-0.0589745560025, -0.8677023913217);//F
    glEnd();

    //Front Bumper
    glBegin(GL_POLYGON);
    glColor3ub(54,69,79);
    glVertex2f(-0.3590619301494, -0.9351920295936);//C
    glVertex2f(-0.3211878633978, -0.9350632062374);//D
    glVertex2f(-0.3213166867541, -0.9492337754301);//E
    glVertex2f(-0.359319576862, -0.9487184820049);//F
    glEnd();

    //Back Bumper
    glBegin(GL_POLYGON);
    glColor3ub(54,69,79);
    glVertex2f(0.121461923388, -0.9351619839148);//C
    glVertex2f(0.169355555797, -0.9349176286474);//D
    glVertex2f(0.17, -0.95);//E
    glVertex2f(0.121461923388, -0.9493345894236);//F
    glEnd();

    ///wheel 1
    Circle(-0.2, -0.95,0.015,178,190,181);
    Circle(-0.2, -0.95,0.03,60,82,145);

     ///wheel 2
    Circle(0, -0.95,0.015,178,190,181);
    Circle(0, -0.95,0.03,60,82,145);

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.3434181713891, -0.9332891767494);//C
    glVertex2f(-0.3210780402756, -0.9347785188236);//D
    glVertex2f(-0.3210780402756, -0.9491754922079);//E
    glVertex2f(0.1202636610569, -0.9491754922079);//F
    glVertex2f(0.1197672136988, -0.9347785188236);//G
    glVertex2f(0.1445895816028, -0.9352749661817);//H
    glVertex2f(0.1391286606639, -0.9094597035616);//I
    glVertex2f(0.1103347138953, -0.9094597035616);//J
    glVertex2f(0.108348924463, -0.8935733881031);//K
    glVertex2f(0.1351570817993, -0.893076940745);//L
    glVertex2f(0.1301926082185, -0.874211941138);//M
    glVertex2f(0.0601935307293, -0.8732190464218);//N
    glVertex2f(0.0289173471703, -0.8220849685396);//O
    glVertex2f(-0.1493072543801, -0.8215885211816);//P
    glVertex2f(-0.2302281737471, -0.8722261517057);//Q
    glVertex2f(-0.3185958034852, -0.887119572448);//R
    glEnd();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    rain();

    glTranslatef(2.0,0.04,0.0);
    glScalef(1.1,1.1,0.0);

    glPushMatrix();
    glTranslatef(car_move1,0.0,0.0);
    Ambulance();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(car_move2,0.0,0.0);
    policeCar();
    glPopMatrix();

    glTranslatef(-1.8,0.3,0.0);
    Road();

    glScalef(0.9,0.9,0.0);
    Brence();
    Lamp();
    Tree();
    GreenFild();
    glTranslatef(0.05,0.27,0.0);
    Building1();
    Building2();
    Building3();
    building4();
    building5();
    building6();
    building7();
    building8();
    building9();
    building10();

    car_move1 += 0.003;
    {
    if(car_move1 > 1.9)
    {
        car_move1 = -1.0;
    }
    }


    car_move2 -= 0.003;{
       if(car_move2 >1.0)
       {
           car_move2 = -1.7;
       }
    }

    glTranslatef(-0.1,0.0,0.0);

    glPushMatrix();
    glTranslatef(cloud_move,0.0,0.0);
    Cloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud_move1,0.0,0.0);
    Cloud2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud_move2,0.0,0.0);
    Cloud3();
    glPopMatrix();

    cloud_move += 0.003;
    {
    if(cloud_move > 1.9)
    {
        cloud_move = -1.0;
    }
    }

    cloud_move1 += 0.003;{
       if(cloud_move1 > 1.0)
       {
           cloud_move1 = -1.7;
       }
    }

    cloud_move2 += 0.003;
    {
        if(cloud_move2 > 1.5)
        {
            cloud_move2 = -1.2;
        }
    }

    glPushMatrix();
    glTranslatef(0.0, sun_move, 0.0);
    sun();
    glPopMatrix();

    if(start3==true)
    {
        Moon();

    }

    if(start1 == true)
    {
        sun_move -= 0.005;
        if(sun_move < -0.62)
        {
            glDisable(GL_LIGHT0);
            start1 = false;
            start3= true;

        }
    }

    if(start2 == true)
    {
        start3=false;
        glEnable(GL_LIGHT0);
        sun_move += 0.005;
        if(sun_move > 0.3)
        {
            glEnable(GL_LIGHT0);
        }
        if(sun_move > 0)
        {
            start2 = false;
        }
    }

    Sky();

    glutSwapBuffers();
}

void update(int value)
{

    if(r == 2){
        if(xrain > 0.1f){
            xrain = -0.2f;
            yrain = -0.5f;
        }
        xrain = xrain + 0.03f;
        yrain = yrain - 0.03f;
    }

    else{

        xrain = 10.0f;
        yrain = 10.0f;

    }
    glutPostRedisplay();

    glutTimerFunc(25, update,0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(100, 0);
    glutCreateWindow("City");
    MyInit();
    glutDisplayFunc(display);
    glutReshapeFunc(handleResize);

    glutKeyboardFunc(keyboard);

    glutTimerFunc(25, update, 0);
    glutMainLoop();
   return 0;
}

///---------------------------------------------------------------------------------------
///
///Taking points from https://www.geogebra.org
///Taking color code from https://colorcodes.io/
