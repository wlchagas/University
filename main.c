#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415

int sW=600,sH=600,start=0,angx=-40,angy=45,angz=0,left_arm=0,left_darm=0,right_arm=0,right_darm=0;
int left_leg=0,left_dleg=0;right_leg=0,right_dleg=0,swapleg=0,spl=0,spr=0,walkComp=0,flagcamera=0,dw=0;
float sceneX=0.0,sceneY=0.0,sceneZ=0.0,wob,hob;

void drawCharacter(){
    glColor3f(1.0,0.0,0.0);
    glTranslatef(0.0,0.3,0.0);
    glScalef(0.4,0.4,0.4);
    glPushMatrix(); // HEAD
        glTranslatef(0.0,0.15,0.0);
        glutSolidSphere(0.1,25,25);
    glPopMatrix();

    glPushMatrix(); // NECK
        glColor3f(0.0,1.0,0.0);
        glTranslatef(0.0,0.09,0.0);
        glRotatef(90,1.0,0.0,0.0);
        gluCylinder(gluNewQuadric(),0.05,0.05,0.07,10,10);
    glPopMatrix();

    glPushMatrix(); // LEFT SHOULDER
        glTranslatef(0.18,-0.01,0.0);
        glutSolidSphere(0.04,25,25);
    glPopMatrix();

    glPushMatrix(); // RIGHT SHOULDER
        glTranslatef(-0.18,-0.01,0.0);
        glutSolidSphere(0.04,25,25);
    glPopMatrix();

    glPushMatrix(); // TORSO
        glScalef(1.0,1.0,0.5);
        glRotatef(90,1.0,0.0,0.0);
        glColor3f(0.6,0.6,0.6);
        gluCylinder(gluNewQuadric(), 0.2, 0.15 , 0.4, 30, 30 );

        glPushMatrix(); // TORSO UP CLOSE
            glScalef(1.0,1.0,0.2);
            glutSolidSphere(0.2,25,25);
        glPopMatrix();

        glPushMatrix(); //TORSO DOWN CLOSE
            glTranslatef(0.0,0.0,0.4);
            glScalef(0.75,0.8,1.0);
            gluDisk(gluNewQuadric(),0,0.2,30,30);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); // FULL RIGHT ARM
        glRotatef(right_arm,1.0,0.0,0.0);
        glPushMatrix(); // RIGHT UPPER ARM
            glTranslatef(0.18,0.0,0.0);
            glRotatef(15,0.0,0.0,1.0);
            glRotatef(90,1.0,0.0,0.0);
            gluCylinder(gluNewQuadric(), 0.041, 0.025 , 0.25, 30, 30 );

            glPushMatrix(); // RIGHT ELBOW
                glColor3f(0.0,0.0,1.0);
                glTranslatef(0.0,0.0,0.25);
                glutSolidSphere(0.025,25,25);
            glPopMatrix();

            glPushMatrix(); // RIGHT DOWN ARM
                glColor3f(1.0,0.0,0.0);
                glTranslatef(0.0,0.0,0.25);
                glRotatef(right_darm,1.0,0.0,0.0);
                glRotatef(-15,0.0,1.0,0.0);
                gluCylinder(gluNewQuadric(), 0.025, 0.02 , 0.2, 30, 30 );

                glPushMatrix(); // RIGHT HAND
                    glColor3f(1.0,0.0,1.0);
                    glTranslatef(0.0,0.0,0.2);
                    glScalef(0.9,0.9,0.9);
                    glRotatef(-90,1.0,0.0,0.0);
                    glRotatef(-90,0.0,1.0,0.0);
                    glPushMatrix(); // PALM
                        glScalef(0.95,1.0,0.5);
                        glutSolidSphere(0.04,25,25);
                    glPopMatrix();

                    glPushMatrix(); // THUMB
                        glTranslatef(-0.03,0.0,0.0);
                        glRotatef(-15,0.0,0.0,1.0);
                        glRotatef(90,1.0,0.0,0.0);
                        gluCylinder(gluNewQuadric(), 0.01, 0.01 , 0.05, 30, 30 );
                        glPushMatrix();
                            glTranslatef(-0.0005,0.0,0.05);
                            glutSolidSphere(0.01,25,25);
                        glPopMatrix();
                    glPopMatrix();

                    glPushMatrix(); // INDEX
                        glTranslatef(-0.02,-0.03,0.0);
                        glRotatef(90,1.0,0.0,0.0);
                        gluCylinder(gluNewQuadric(), 0.008, 0.008 , 0.05, 30, 30 );
                        glPushMatrix();
                            glTranslatef(0.0,0.0,0.05);
                            glutSolidSphere(0.008,25,25);
                        glPopMatrix();
                    glPopMatrix();

                    glPushMatrix(); // MIDDLE
                        glTranslatef(0.0,-0.03,0.0);
                        glRotatef(90,1.0,0.0,0.0);
                        gluCylinder(gluNewQuadric(), 0.0083, 0.0083 , 0.06, 30, 30 );
                        glPushMatrix();
                            glTranslatef(0.0,0.0,0.06);
                            glutSolidSphere(0.0083,25,25);
                        glPopMatrix();
                    glPopMatrix();

                    glPushMatrix(); // RING
                        glTranslatef(0.02,-0.02,0.0);
                        glRotatef(90,1.0,0.0,0.0);
                        gluCylinder(gluNewQuadric(), 0.008, 0.008 , 0.06, 30, 30 );
                        glPushMatrix();
                            glTranslatef(0.0,0.0,0.06);
                            glutSolidSphere(0.008,25,25);
                        glPopMatrix();
                    glPopMatrix();

                    glPushMatrix(); // PINKY
                        glTranslatef(0.03,-0.01,0.0);
                        glRotatef(10,0.0,0.0,1.0);
                        glRotatef(90,1.0,0.0,0.0);
                        gluCylinder(gluNewQuadric(), 0.007, 0.007 , 0.05, 30, 30 );
                        glPushMatrix();
                            glTranslatef(0.0,0.0,0.05);
                            glutSolidSphere(0.007,25,25);
                        glPopMatrix();
                    glPopMatrix();

                glPopMatrix(); // END RIGHT HAND
            glPopMatrix(); // END RIGHT DOWN ARM
        glPopMatrix();
    glPopMatrix(); // END RIGHT ARM


    glPushMatrix(); // FULL LEFT ARM
        glRotatef(left_arm,1.0,0.0,0.0);
        glPushMatrix(); // LEFT UPPER ARM
            glColor3f(0.0,0.0,1.0);
            glTranslatef(-0.18,0.0,0.0);
            glRotatef(-15,0.0,0.0,1.0);
            glRotatef(90,1.0,0.0,0.0);
            gluCylinder(gluNewQuadric(), 0.041, 0.025 , 0.25, 30, 30 );
            glPushMatrix(); // LEFT ELBOW
                glColor3f(1.0,0.0,0.0);
                glTranslatef(0.0,0.0,0.25);
                glutSolidSphere(0.025,25,25);
            glPopMatrix();

            glPushMatrix(); // LEFT DOWN ARM
                glColor3f(0.0,1.0,0.0);
                glTranslatef(0.0,0.0,0.25);
                glRotatef(left_darm,1.0,0.0,0.0);
                glRotatef(15,0.0,1.0,0.0);
                gluCylinder(gluNewQuadric(), 0.025, 0.02 , 0.2, 30, 30 );

                glPushMatrix(); // LEFT HAND
                    glColor3f(1.0,0.0,1.0);
                    glTranslatef(0.0,0.0,0.2);
                    glRotatef(-90,1.0,0.0,0.0);
                    glRotatef(270,0.0,1.0,0.0);
                    glScalef(0.9,0.9,0.9);
                    glPushMatrix(); // PALM
                        glScalef(0.95,1.0,0.5);
                        glutSolidSphere(0.04,25,25);
                    glPopMatrix();

                    glPushMatrix(); // THUMB
                    glTranslatef(-0.03,0.0,0.0);
                    glRotatef(-15,0.0,0.0,1.0);
                    glRotatef(90,1.0,0.0,0.0);
                    gluCylinder(gluNewQuadric(), 0.01, 0.01 , 0.05, 30, 30 );
                    glPushMatrix();
                        glTranslatef(-0.0005,0.0,0.05);
                        glutSolidSphere(0.01,25,25);
                    glPopMatrix();
                glPopMatrix();

                glPushMatrix(); // INDEX
                    glTranslatef(-0.02,-0.03,0.0);
                    glRotatef(90,1.0,0.0,0.0);
                    gluCylinder(gluNewQuadric(), 0.008, 0.008 , 0.05, 30, 30 );
                    glPushMatrix();
                        glTranslatef(0.0,0.0,0.05);
                        glutSolidSphere(0.008,25,25);
                    glPopMatrix();
                glPopMatrix();

                glPushMatrix(); // MIDDLE
                    glTranslatef(0.0,-0.03,0.0);
                    glRotatef(90,1.0,0.0,0.0);
                    gluCylinder(gluNewQuadric(), 0.0083, 0.0083 , 0.06, 30, 30 );
                    glPushMatrix();
                        glTranslatef(0.0,0.0,0.06);
                        glutSolidSphere(0.0083,25,25);
                    glPopMatrix();
                glPopMatrix();

                glPushMatrix(); // RING
                    glTranslatef(0.02,-0.02,0.0);
                    glRotatef(90,1.0,0.0,0.0);
                    gluCylinder(gluNewQuadric(), 0.008, 0.008 , 0.06, 30, 30 );
                    glPushMatrix();
                        glTranslatef(0.0,0.0,0.06);
                        glutSolidSphere(0.008,25,25);
                    glPopMatrix();
                glPopMatrix();

                glPushMatrix(); // PINKY
                    glTranslatef(0.03,-0.01,0.0);
                    glRotatef(10,0.0,0.0,1.0);
                    glRotatef(90,1.0,0.0,0.0);
                    gluCylinder(gluNewQuadric(), 0.007, 0.007 , 0.05, 30, 30 );
                    glPushMatrix();
                        glTranslatef(0.0,0.0,0.05);
                        glutSolidSphere(0.007,25,25);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix(); // END LEFT HAND
        glPopMatrix(); // END LEFT DOWN ARM
        glPopMatrix();
    glPopMatrix(); // END FULL LEFT ARM

    glPushMatrix(); // FULL RIGHT LEG
        glPushMatrix(); // RIGHT UPPER LEG
            glTranslatef(0.08,-0.38,0.0);
            glRotatef(right_leg,1.0,0.0,0.0);
            glRotatef(90,1.0,0.0,0.0);
            gluCylinder(gluNewQuadric(), 0.05, 0.05 , 0.25, 30, 30 );

            glPushMatrix(); // RIGHT KNEE
                glColor3f(0.0,0.0,0.0);
                glTranslatef(0.0,0.0,0.25);
                glutSolidSphere(0.05,25,25);
            glPopMatrix();

            glPushMatrix(); // RIGHT DOWN LEG
                glColor3f(1.0,0.0,0.0);
                glTranslatef(0.0,0.0,0.25);
                glRotatef(-5,0.0,0.0,1.0);
                glRotatef(right_dleg,1.0,0.0,0.0);
                //glRotatef(90,1.0,0.0,0.0);
                gluCylinder(gluNewQuadric(), 0.05, 0.035 , 0.25, 30, 30 );
                glPushMatrix(); // RIGHT FEET
                    glColor3f(0.0,0.0,1.0);
                    glTranslatef(0.0,-0.03,0.25);
                    glRotatef(90,1.0,0.0,0.0);
                    glScalef(1.0,0.5,1.5);
                    glutSolidSphere(0.05,25,25);
                glPopMatrix();
            glPopMatrix(); // END DOWN LEG
        glPopMatrix();
    glPopMatrix(); // END FULL RIGHT LEG

    glPushMatrix(); // FULL LEFT LEG
        glPushMatrix(); // LEFT UPPER LEG
            glTranslatef(-0.08,-0.38,0.0);
            glRotatef(left_leg,1.0,0.0,0.0);
            glRotatef(90,1.0,0.0,0.0);
            gluCylinder(gluNewQuadric(), 0.05, 0.05 , 0.25, 30, 30 );

            glPushMatrix(); // LEFT KNEE
                glColor3f(1.0,1.0,0.0);
                glTranslatef(0.0,0.0,0.25);
                glutSolidSphere(0.05,25,25);
            glPopMatrix();

            glPushMatrix(); // LEFT DOWN LEG
                glColor3f(1.0,0.0,0.0);
                glTranslatef(0.0,0.0,0.25);
                glRotatef(left_dleg,1.0,0.0,0.0);
                gluCylinder(gluNewQuadric(), 0.05, 0.035 , 0.25, 30, 30 );
                glPushMatrix(); // LEFT FEET
                    glColor3f(0.0,0.0,1.0);
                    glTranslatef(0.0,-0.03,0.25);
                    glRotatef(90,1.0,0.0,0.0);
                    glScalef(1.0,0.5,1.5);
                    glutSolidSphere(0.05,25,25);
                glPopMatrix();
            glPopMatrix(); // END LEFT DOWN LEG
        glPopMatrix();


    glPopMatrix(); // END FULL LEFT LEG
}

void drawScene(){
    glPushMatrix(); // SCENE
        glTranslatef(sceneX,sceneY,sceneZ);

        glPushMatrix(); // TERRAIN
            glColor3f(0.0,1.0,0.5);
            glTranslatef(0,-0.07,0);
            glRotatef(90,1.0,0.0,0.0);
            gluDisk(gluNewQuadric(),0,10.0,30,30);
        glPopMatrix();

        glPushMatrix(); // TOWER
            glColor3f(0.5,0.5,0.5);
            glTranslatef(-0.325,34.9,-2);
            glScalef(1.0,70,1.0);
            glRotatef(90,1.0,0.0,0.0);
            gluCylinder(gluNewQuadric(),1.0,1.0,0.5,30,30);
        glPopMatrix();

    glPopMatrix();
}

void correctScene(){
    if(angy < 180)
        angy++;

    if(angx < -5)
        if(angy%4 == 0)
            angx++;

    glutPostRedisplay();
}

void animate(){
    if(start == 1){
        if( sceneX < 0.16 ){
            if(dw == 1){
                sceneX += 0.001;
                sceneZ += 0.004;
            }
        } else swapleg = 2;


        if(left_leg == 0 && right_leg == 0 ){
            if(swapleg == 0){
                left_leg++;
                swapleg = 1;
            } else if (swapleg == 1){
                right_leg++;
                swapleg = 0;
            }
            spl = 0;
            spr = 0;
            dw = 0;
        } else if ( right_leg <= 0 && left_leg < 90 && spl == 0){
            left_leg++;
            left_dleg--;
            if(left_leg >= 0){
                right_arm = (3*left_leg)/8;
                right_darm = (3*right_arm)/8;
            }
        } else if ( left_leg <= 0 && right_leg < 90 && spr == 0){
            right_leg++;
            right_dleg--;
            if(right_leg >= 0){
                left_arm = (3*right_leg)/8;
                left_darm = (3*left_arm)/8;
            }
        } else if ( (right_leg <= 0 && left_leg >= 90) || spl == 1){
            left_leg--;
            if(-left_leg == left_dleg){
                left_dleg++;
            }else left_dleg += 2;
            if(left_leg%5 == 0){
                right_leg--;
                right_dleg--;
            }
            if(left_leg >= 0){
                right_arm = (3*left_leg)/8;
                right_darm = (3*right_arm)/8;
            }
            spl = 1;
            dw = 1;
        } else if ( (left_leg <= 0 && right_leg >= 90) || spr == 1){
            right_leg--;
            if(-right_leg == right_dleg){
                right_dleg++;
            }else right_dleg += 2;
            if(right_leg%5 == 0){
                left_leg--;
                left_dleg--;
            }
            if(right_leg >= 0){
                left_arm = (3*right_leg)/8;
                left_darm = (3*left_arm)/8;
            }
            spr = 1;
            dw = 1;
        }
        //printf("%d %d, %d %d\n",right_leg,left_leg,right_dleg,left_dleg);
        if(dw == 0 && right_leg == 0 && left_leg == 0)
            start = 0;
        glutPostRedisplay();
    }
}

void rotateScene(){
    glRotatef(angx,1.0,0.0,0.0);
    glRotatef(angy,0.0,1.0,0.0);
    glRotatef(angz,0.0,0.0,1.0);
}

void jobs(){

}

void jobsCorrect(){

}

void Display(void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glClear (GL_DEPTH_BUFFER_BIT);
    //printf("angx = %d, angy = %d, angz = %d\n",angx,angy,angz);
    glPushMatrix();
        rotateScene();
        drawScene();
        drawCharacter();
        animate();
        jobs();
    glPopMatrix();

    if (swapleg == 2){
        correctScene();
        jobsCorrect();
    }

    glEnable(GL_DEPTH_TEST);
    glutSwapBuffers();
}

void jumpObstacle(int x, int y){
    wob = (float)x/(sW/2)-1;
    hob = (sH-y)/(float)(sH/2)-1;
    printf("wob = %f, hob = %f\n",wob,hob);
    glPushMatrix();
        glTranslatef(wob,hob,0.0);
        glutSolidSphere(0.1,25,25);
    glPopMatrix();
}

void Keyboard (unsigned char key, int x, int y){
    switch (key) {
        case 'x':
            angx = (angx + 5) % 360;
        break;
        case 'X':
            angx = (angx - 5) % 360;
        break;
        case 'y':
            angy = (angy + 5) % 360;
        break;
        case 'Y':
            angy = (angy - 5) % 360;
        break;
        case 'z':
            angz = (angz + 5) % 360;
        break;
        case 'Z':
            angz = (angz - 5) % 360;
        break;
        case 's':
            start = 1;
        break;

    }
    glutPostRedisplay();
}

void MouseInt (int botao, int estado, int x, int y) {
    switch(botao) {
        case GLUT_LEFT_BUTTON:
            if(estado == GLUT_DOWN)
                jumpObstacle(x,y);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (sW, sH);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ezio Auditore Climbing a tower");
    glutDisplayFunc(Display);
    glutKeyboardFunc(Keyboard);
    glutMouseFunc(MouseInt);
    glutMainLoop();
    return 0;
}
