#include <windows.h>
#include <GL/glut.h>


//A function to draw X and Y axis as well as graph
void Initialize()
{
    glClearColor(0.196078,0.6,0.8,0);//Background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-700.0, 700.0, -500.0, 1000.0, -10.0, 10.0);//graph size
}
void Road()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f( 0.329412,0.329412,0.329412);
    glVertex2i(-700,-500);//left
    glVertex2i(700,-500);//right
    glVertex2i(700,-250);//right top
    glVertex2i(-700,-250);//left top
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f( 1,1,1);
    glVertex2i(-700,-300);
    glVertex2i(700,-300);
    glVertex2i(-700,-400);
    glVertex2i(700,-400);
    glVertex2i(-700,-500);
    glVertex2i(700,-500);
    glEnd();

    glBegin(GL_POLYGON);//green place
    glColor3f( 0.184314 ,0.309804 ,0.184314);
    glVertex2i(-100,-480);
    glVertex2i(100,-480);
    glVertex2i(130,-290);
    glVertex2i(-70,-290);
    glEnd();

    glBegin(GL_POLYGON);//hill
    glColor3f( 0.92 ,0.78 ,0.62);
    glVertex2i(-700,-250);
    glVertex2i(-560,100);
    glVertex2i(-420,-250);
    glVertex2i(-280,100);
    glVertex2i(-140,-250);
    glVertex2i(70,100);
    glVertex2i(140,-250);
    glVertex2i(280,100);
    glVertex2i(420,-250);
    glVertex2i(560,100);
    glVertex2i(700,-250);
    glEnd();
}
float y=-700;
void Draw( )
{
    Road();
    glBegin(GL_POLYGON);
    glColor3f( 0.85 ,0.85 ,0.95);
    glVertex2i(-20,y+400);//left
    glVertex2i(20,y+400);//right
    glVertex2i(20,y+650);//right top
    glVertex2i(-20,y+650);//left top
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex2i(-20,y+650);//left
    glVertex2i(20,y+650);//right
    glVertex2i(0,850+y);//right top
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(  0 ,0 ,0.61);
    glVertex2i(-50,y+320);//left
    glVertex2i(-20,y+400);//right
    glVertex2i(-20,y+520);//right top
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(  0 ,0 ,0.61);
    glVertex2i(50,y+320);//left
    glVertex2i(20,y+400);//right
    glVertex2i(20,y+520);//right top
    glEnd();

    glBegin(GL_QUADS);
    glColor3f( 0.89  ,0.47 ,0.20);
    glVertex2i(-15,y+350);//left
    glVertex2i(-5,y+350);//right
    glVertex2i(-5,y+400);//right top
    glVertex2i(-15,y+400);//left top
    glEnd();

    glBegin(GL_QUADS);
    glColor3f( 0.89  ,0.47 ,0.20);
    glVertex2i(5,y+350);//left
    glVertex2i(15,y+350);//right
    glVertex2i(15,y+400);//right top
    glVertex2i(5,y+400);//left top
    glEnd();
    if(y<1000){
        y=y+.5;
    }
    else{
        y=-700;
    }


    glutSwapBuffers( );
}

int main(int Argc, char** Argv)
{
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200,800);
    glutInitWindowPosition(150,150);
    glutCreateWindow("Launching Rocket");
    Initialize();
    glutDisplayFunc(Draw);
    glutIdleFunc(Draw);
    glutMainLoop();
}
