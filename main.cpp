#include <gl\glut.h>
#include <iostream>

using namespace std;

#define HEAD_HEIGHT 3.0
#define HEAD_RADIUS 1.0

#define TORSO_HEIGHT 5.0
#define TORSO_RADIUS 1.0

#define UPPER_ARM_HEIGHT 3.0
#define LOWER_ARM_HEIGHT 2.0
#define UPPER_ARM_RADIUS 0.5
#define LOWER_ARM_RADIUS 0.5

#define UPPER_LEG_HEIGHT 3.0
#define LOWER_LEG_HEIGHT 2.0
#define UPPER_LEG_RADIUS 0.5
#define LOWER_LEG_RADIUS 0.5

GLUquadricObj *p = gluNewQuadric();

float anguloTronco = 0.0;
float anguloBrazo1 = 0.0;
float anguloAntebrazo1 = 0.0;
float anguloPierna =30.0;
float anguloPierna2=-30.0;
float anguloPie = 0.0;
float anguloPie2 = 0.0;
float translationZ =0.0;
float translationY=0.0;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };// que colores se utilizaran por haci decirlo
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };// la que reflejara por asi decirlo
const GLfloat light_position[] = { 5.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };



void inicializar()
{
    glClearColor(0.8,0.8,0.8,0);
    glEnable(GL_DEPTH_TEST);
    gluQuadricDrawStyle(p,GLU_FILL);
}

void graficarEjes()
{

    glColor3f (0.0f, 1.0f, 0.0f);
    glBegin (GL_QUADS);
    glVertex3f (-100.0f, -5.0f, -100.0f);
    glVertex3f (-100.0f, -5.0f, 100.0f);
    glVertex3f (100.0f, -5.0f, 100.0f);
    glVertex3f (100.0f, -5.0f, -100.0f);
    glEnd ();
}
float rotarCuerpo=0.0;
void graficar()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(20,20,30, 0,0,0, 0,1,0);


    graficarEjes();
    glRotatef(rotarCuerpo,0,1,0);
    glTranslatef(0.0,5,0.0);
    glColor3f(0.6,0.5,0.9);
    glTranslatef(0.0,translationY,translationZ);
    //torso();
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluCylinder(p, TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, HEAD_HEIGHT / 2.2, 0);

    //head();
    glPushMatrix();
    glScalef(HEAD_RADIUS, HEAD_HEIGHT / 2, HEAD_RADIUS);
    gluSphere(p, 1.0, 10, 10);
    glPopMatrix();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(TORSO_RADIUS, 0, 0);
    glRotatef(anguloBrazo1, 1, 0, 0);//lua---> brazo derecho  /////////////////////////////mover brazo 60

    //left_upper_arm();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(p, UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT, 10,
                10);
    glPopMatrix();

    glTranslatef(0, -3, 0);
    glRotatef(45, 1, 0, 0);//lla -- antebrazo derecho
    // left_lower_arm();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(p, LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT, 10,
                10);




    //codo
    glPushMatrix();
    glTranslatef(0,0,0);
    glutSolidSphere(0.7,5,5);
    glPopMatrix();


    //mano
    glPushMatrix();
    glTranslatef(0,0,2);
    glutSolidSphere(0.7,5,5);


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // primer dedo
    glPushMatrix();

    //falange proximal
    glTranslatef(-0.3,0,0.6);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();
    //falange media
    glTranslatef(0,0,0.3);
    glRotatef(90,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);


    glPopMatrix();// fin de falange media
    glPopMatrix();// fin de falange distal
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////


    //segundo dedo

    glPushMatrix();
    //falange proximal
    glTranslatef(0,0,0.6);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();
    //falange media
    glTranslatef(0,0,0.3);
    glRotatef(90,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();

    //falange distal
    glTranslatef(0,0,0.3);
    glRotatef(45,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPopMatrix();// fin de falange proximal
    glPopMatrix();// fin de falange media
    glPopMatrix();// fin de falange distal
    ////////////////////////////////////////////////////////////////////////
    // tercero dedo
    glPushMatrix();

    //falange proximal
    glTranslatef(0.2,0,0.6);
    gluCylinder(p,0.1,0.1,0.38,10,10);

    glPushMatrix();
    //falange media
    glTranslatef(0,0,0.38);
    glRotatef(90,1,0,0);
    gluCylinder(p,0.1,0.1,0.38,10,10);

    glPushMatrix();

    //falange distal
    glTranslatef(0,0,0.38);
    glRotatef(45,1,0,0);
    gluCylinder(p,0.1,0.1,0.38,10,10);

    glPopMatrix();// fin de falange proximal
    glPopMatrix();// fin de falange media
    glPopMatrix();// fin de falange distal

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    // cuarto dedo
    glPushMatrix();

    //falange proximal
    glTranslatef(0.4,0,0.6);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();
    //falange media
    glTranslatef(0,0,0.3);
    glRotatef(90,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();

    //falange distal
    glTranslatef(0,0,0.3);
    glRotatef(45,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPopMatrix();// fin de falange proximal
    glPopMatrix();// fin de falange media
    glPopMatrix();// fin de falange distal
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // quinto dedo
    glPushMatrix();

    //falange proximal
    glTranslatef(0.6,0,0.2);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();
    //falange media
    glTranslatef(0,0,0.3);
    glRotatef(90,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);


    glPopMatrix();// fin de falange media
    glPopMatrix();// fin de falange distal
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    glPopMatrix();


    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-TORSO_RADIUS, 0, 0);
    //glRotatef(anguloBrazo1*-1, 0, 0, 1);//rua brazo2
    glRotatef(anguloBrazo1*-1, 1, 0, 0);

    //right_upper_arm();
    glPushMatrix();
    // glRotatef(-90, 0, 1, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(p, UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT, 10,
                10);

    glPopMatrix();

    //glTranslatef(-UPPER_ARM_HEIGHT, 0, 0);
    glTranslatef(0, -3, 0);
    //glRotatef(anguloBrazo1*-1, 0, 0, 1);//rla antebrazo2
    glRotatef(90, -1, 0, 0);

    //right_lower_arm();
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    //  glRotatef(90, 1, 0, 0);
    gluCylinder(p, LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT, 10,
                10);
    glPushMatrix();
    glTranslatef(0,0,0);
    glutSolidSphere(0.7,5,5);
    glPopMatrix();


    //mano

    glPopMatrix();
    glTranslatef(0,2.4,0);
    glutSolidSphere(0.7,5,5);


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    glRotatef(-90,1,0,0);
    // ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // primer dedo
    glPushMatrix();

    //falange proximal
    glTranslatef(-0.3,0,0.6);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();
    //falange media
    glTranslatef(0,0,0.3);
    glRotatef(90,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);


    glPopMatrix();// fin de falange media
    glPopMatrix();// fin de falange distal
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////


    //segundo dedo

    glPushMatrix();
    //falange proximal
    glTranslatef(0,0,0.6);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();
    //falange media
    glTranslatef(0,0,0.3);
    glRotatef(90,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();

    //falange distal
    glTranslatef(0,0,0.3);
    glRotatef(45,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPopMatrix();// fin de falange proximal
    glPopMatrix();// fin de falange media
    glPopMatrix();// fin de falange distal
    ////////////////////////////////////////////////////////////////////////
    // tercero dedo
    glPushMatrix();

    //falange proximal
    glTranslatef(0.2,0,0.6);
    gluCylinder(p,0.1,0.1,0.38,10,10);

    glPushMatrix();
    //falange media
    glTranslatef(0,0,0.38);
    glRotatef(90,1,0,0);
    gluCylinder(p,0.1,0.1,0.38,10,10);

    glPushMatrix();

    //falange distal
    glTranslatef(0,0,0.38);
    glRotatef(45,1,0,0);
    gluCylinder(p,0.1,0.1,0.38,10,10);

    glPopMatrix();// fin de falange proximal
    glPopMatrix();// fin de falange media
    glPopMatrix();// fin de falange distal

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    // cuarto dedo
    glPushMatrix();

    //falange proximal
    glTranslatef(0.4,0,0.6);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();
    //falange media
    glTranslatef(0,0,0.3);
    glRotatef(90,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();

    //falange distal
    glTranslatef(0,0,0.3);
    glRotatef(45,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPopMatrix();// fin de falange proximal
    glPopMatrix();// fin de falange media
    glPopMatrix();// fin de falange distal
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // quinto dedo
    glPushMatrix();

    //falange proximal
    glTranslatef(0.6,0,0.2);
    gluCylinder(p,0.1,0.1,0.3,10,10);

    glPushMatrix();
    //falange media
    glTranslatef(0,0,0.3);
    glRotatef(90,1,0,0);
    gluCylinder(p,0.1,0.1,0.3,10,10);


    glPopMatrix();// fin de falange media
    glPopMatrix();// fin de falange distal
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////



    glPopMatrix();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(TORSO_RADIUS, -TORSO_HEIGHT, 0);
    glRotatef(anguloPierna*-1, 1, 0, 0);//lul

    //left_upper_leg();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(p, UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT, 10,
                10);
    glPopMatrix();

    glTranslatef(0, -UPPER_LEG_HEIGHT, 0);
    glRotatef(anguloPierna, 1, 0, 0);//lll

    //left_lower_leg();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(p, LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT, 10,
                10);
    //rodilla
    glPushMatrix();
    glTranslatef(0,0,0);
    glutSolidSphere(0.7,5,5);
    glPopMatrix();
     //pie
   glPushMatrix();
   glRotatef(anguloPie2,1,0,0);/////////////////rotar al caminar
    glScalef(1,1.5,1);
   glTranslatef(0,-0.2,2);
    glutSolidSphere(0.8,5,5);
   glPopMatrix();

    glPopMatrix();


    glPopMatrix();
    glPushMatrix();
    glTranslatef(-TORSO_RADIUS, -TORSO_HEIGHT, 0);
    glRotatef(anguloPierna2*-1.5, 1, 0, 0);//rul-----> pierna izquieda

    //right_upper_leg();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(p, UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT, 10,
                10);
    glPopMatrix();

    glTranslatef(0, -UPPER_LEG_HEIGHT, 0);

    glRotatef(anguloPierna2+5, 1, 0, 0);//rll --pie ezquierdo

    //    right_lower_leg();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(p, LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT, 10,
                10);
    //rodilla
    glPushMatrix();
    glTranslatef(0,0,0);
    glutSolidSphere(0.7,5,5);

   //pie
   glPushMatrix();
   glRotatef(anguloPie,1,0,0);/////////////////rotar al caminar
    glScalef(1,1.5,1);
   glTranslatef(0,-0.2,2);
    glutSolidSphere(0.8,5,5);
   glPopMatrix();

    glPopMatrix();

    glPopMatrix();
    glPopMatrix();


    /*//tronco
    glPushMatrix();
    glutSolidCube(6);

    //cuello
        glPushMatrix();

        glTranslatef(0,4,0);
        glRotatef(90,1,0,0);
        gluCylinder(p,1,3,4,16,16);

                //cabeza
                glPushMatrix();

                glTranslatef(0,0,-1);
                glutSolidSphere(1.5,10,10);
                glPopMatrix(); //fin cabeza

        glPopMatrix();//fin cuello

        //brazo derecho
        glPushMatrix();
        //glRotatef(45,1,0,1);
      //  glTranslatef(3.8,2.8,0);
        glTranslatef(3.8,2.8,0);
        glutSolidSphere(0.7,10,10);
        glTranslatef(0.1,-0.2,-0.2);
        glRotated(80,1,0,0);
        gluCylinder(p,0.8,0.8,2.5,14,14);

        glPopMatrix();//fin brazo derecho;


    glPopMatrix(); //fin tronco

    */
    /*

    glPushMatrix();
        ///Tronco
        glRotatef(anguloTronco,0,1,0);
        glutSolidCube(6);
                glPushMatrix();
                    ///Cabeza
                    glTranslatef(0,5,0);
                    glutSolidSphere(2,16,16);
                glPopMatrix();
        glPushMatrix();
            ///Brazo1
            glColor3f(1,0,0);
            glTranslatef(0,0,3);
            glRotatef(anguloBrazo1,0,0,1);
            gluCylinder(p,2,2,5,16,16);
            glPushMatrix();
                ///Antebrazo1
                glColor3f(0,0,0);
                glTranslatef(0,0,5);
                glRotatef(anguloAntebrazo1,1,0,0);
                gluCylinder(p,2,1,4,16,16);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    */


    glutSwapBuffers();
}

void redimensionar(int w,int h)
{

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80,(float)w/(float)h,1,100);

}

void moverTronco(int i)
{
    anguloTronco = anguloTronco + 4;
    glutPostRedisplay();
    glutTimerFunc(500,moverTronco,1);
}

//brazo derecho;
bool brazo=true;

void moverBrazo1(int i)
{
    cout<< anguloBrazo1<<endl;
    if(anguloBrazo1<=45&& brazo ==true )
        anguloBrazo1 += - 1;

    if(anguloBrazo1 ==-44)
    {
        cout<<"llego a bool"<<endl;
        brazo =false;
    }
    if(anguloBrazo1==44)
    {
        brazo =true;
    }
    if(anguloBrazo1 <=45 && brazo==false)
        anguloBrazo1 = anguloBrazo1 +1;

    /*
        if(brazo)
            {
                anguloBrazo1=60;
                brazo=false;
            }

            else
            {
               anguloBrazo1=-20;
                brazo= true;
            }*/

    glutPostRedisplay();

    glutTimerFunc(100,moverBrazo1,2);
}

bool pierna;/*
void moverPiernas(int i)
{

    cout<< anguloPierna<<endl;
    if(anguloPierna<=45&& pierna==true )
        anguloPierna += - 1;
    translationZ+=-0.1;

    if(anguloPierna==-44)
    {
        cout<<"llego a bool"<<endl;
        brazo =false;
    }
    if(anguloBrazo1==44)
    {
        brazo =true;
    }
    if(anguloPierna <=45 && pierna==false)
        anguloPierna= anguloBrazo1 +1;

    glutPostRedisplay();
    glutTimerFunc(100,moverPiernas,2);
}
*/
void moverAntebrazo1(int i)
{
    /*

            if(extraPiernas)
            {
                anguloBrazo1=30;
                extraPiernas=false;
            }

            else
            {
                anguloPierna=0;
                extraPiernas= true;
            }
        anguloAntebrazo1 = anguloAntebrazo1 + 3;*/
    glutPostRedisplay();
    glutTimerFunc(100,moverAntebrazo1,2);
}
bool extrasSalto=true;
bool repeticion=true;
void saltarPersonaje(int i)
{
    /*
    if(translationY>=20&&extrasSalto==true){
      translationY -=0.1;
      extrasSalto=false;
    }
    if(translationY<=0 &&extrasSalto == false){
        translationY +=0.1;
        extrasSalto =true;
    }*/

    if(repeticion)
    {
        if(translationY<7&& extrasSalto ==true )
        {
            translationY +=  1;
            cout<<"llego a saltar!"<<translationY<<"---"<<endl;
        }

        if(translationY ==0)
        {
            cout<<"llego a bool"<<endl;
            extrasSalto =true;

        }
        if(translationY >=6)
        {
            extrasSalto =false;
        }
        if(extrasSalto ==false)
        {
            translationY -= 1;
            cout<<"llego a caer!"<<translationY<<"---"<<endl;
            if(translationY==1)
            {
                repeticion=false;
                translationY=0;
            }
        }


        glutPostRedisplay();
        glutTimerFunc(100,saltarPersonaje,2);
    }
}



bool extraPiernas=true;
bool extrarRotarCuerpo= true;


void eventoTeclado(unsigned char key,int x, int y)
{
    float auxPiernas=0.0;
    switch(key)
    {
    case ' ':
        repeticion =true;
        glutTimerFunc(100,saltarPersonaje,2);


        break;
    case 'w':

        translationZ +=-0.5;
        if(extraPiernas)
        {
            auxPiernas=anguloPierna;
            //   anguloPierna=30;
            anguloPierna = anguloPierna2;
            anguloPierna2= auxPiernas;
            anguloPie=-25;
            anguloPie2=0;
            extraPiernas=false;
        }

        else
        {
            /* anguloPierna=0;
             anguloPierna2= anguloPierna;*/

            auxPiernas=anguloPierna;
            //   anguloPierna=30;
            anguloPierna = anguloPierna2;
            anguloPierna2= auxPiernas;
            anguloPie=0;
            anguloPie2=-25;
            extraPiernas= true;

        }
        break;
    case 's':

        translationZ +=0.5;
        if(extraPiernas)
        {
            /*anguloPierna=-30;
            anguloPierna2= anguloPierna;*/
            auxPiernas=anguloPierna;

        anguloPierna = anguloPierna2;
        anguloPierna2= auxPiernas;
         anguloPie=-45;
            anguloPie2=0;
            extraPiernas=false;
        }

        else
        {
            /*anguloPierna=0;
            anguloPierna2= anguloPierna;*/
            auxPiernas=anguloPierna;
        anguloPierna = anguloPierna2;
        anguloPierna2= auxPiernas;
         anguloPie=0;
         anguloPie2=-45;

            extraPiernas= true;

        }

        /*auxPiernas=anguloPierna;
        //   anguloPierna=30;
        anguloPierna = anguloPierna2;
        anguloPierna2= auxPiernas;*/
        break;

    case 'd':
        rotarCuerpo+=5;

        break;
    case 'a':
        rotarCuerpo-=5;

        break;
    case 27:
        exit(0);
        break;


    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,400);
    glutInitWindowPosition(100,200);
    glutCreateWindow("Hola Mundo");

    inicializar();

    glutDisplayFunc(graficar);
    glutReshapeFunc(redimensionar);


    glutKeyboardFunc(eventoTeclado);

    //glutTimerFunc(500,moverTronco,1);
    glutTimerFunc(100,moverBrazo1,2);
    //glutTimerFunc(100,moverAntebrazo1,2);
    // glutTimerFunc(100,moverPiernas,2);





    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,   light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION,  light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return 0;
}
