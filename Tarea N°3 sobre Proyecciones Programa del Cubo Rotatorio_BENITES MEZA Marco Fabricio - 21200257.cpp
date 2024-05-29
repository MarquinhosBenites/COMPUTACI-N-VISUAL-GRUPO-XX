//PROGRAMA QUE MUESTRA UN CUBO QUE PUEDE ROTAR, DESPLAZARSE Y CAMBIAR ENTRE PROYECCIÓN ORTOGONAL Y PERSPECTIVA
//Autor: Marco Fabricio Benites Meza
//Fecha de edición: miércoles 29 de mayo del 2024
//Curso: Computación Visual
//Universidad Nacional Mayor de San Marcos. Universidad del Perú, Décana de América
#include <GL/glut.h>
GLfloat anguloCuboX = 0.0f;
GLfloat anguloCuboY = 0.0f;
GLfloat anguloEsfera = 0.0f; 
GLint ancho, alto;
int hazPerspectiva = 1;
// Parámetros para la proyección ortogonal
GLfloat orthoLeft = -4.0f;
GLfloat orthoRight = 4.0f;
GLfloat orthoBottom = -4.0f;
GLfloat orthoTop = 4.0f;
// Parámetros para la proyección perspectiva
GLfloat perspectiveAngle = 45.0f;
GLfloat perspectiveZnear = 1.0f;
GLfloat perspectiveZfar = 4.8f;

/*
Significado de variables:
GLfloat orthoLeft: Límite izquierdo de la proyección ortogonal.
GLfloat orthoRight: Límite derecho de la proyección ortogonal.
GLfloat orthoBottom: Límite superior de la proyección ortogonal.
GLfloat orthoTop: Límite inferior de la proyección ortogonal.
GLfloat perspectiveAngle: Ángulo de visión de la proyección perspectiva.
GLfloat GLfloat perspectiveZnear: Distancia mínima desde la cámara donde comienza la proyección perspectiva.
GLfloat perspectiveZfar: Distancia máxima desde la cámara donde termina la proyección perspectiva.
*/

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(hazPerspectiva){
    	(perspectiveAngle, (GLfloat)width/(GLfloat)height, perspectiveZnear, perspectiveZfar);
	}
   		
    else{
    	glOrtho(orthoLeft, orthoRight, orthoBottom, orthoTop, 1.0f, 8.0f);
	}
	glMatrixMode(GL_MODELVIEW);
    ancho = width;
    alto = height;
}//fin del void reshape

void drawCube(void) {
    	glColor3f(1.0f, 0.0f, 0.0f);
    	glBegin(GL_QUADS);  //cara frontal
    	glVertex3f(-1.0f, -1.0f,  1.0f);
    	glVertex3f( 1.0f, -1.0f,  1.0f);
    	glVertex3f( 1.0f,  1.0f,  1.0f);
    	glVertex3f(-1.0f,  1.0f,  1.0f);
    	glEnd();

    	glColor3f(0.0f, 1.0f, 0.0f);
    	glBegin(GL_QUADS);  //cara trasera
    	glVertex3f( 1.0f, -1.0f, -1.0f);
    	glVertex3f(-1.0f, -1.0f, -1.0f);
    	glVertex3f(-1.0f,  1.0f, -1.0f);
    	glVertex3f( 1.0f,  1.0f, -1.0f);
    	glEnd();

    	glColor3f(0.0f, 0.0f, 1.0f);
    	glBegin(GL_QUADS);  //cara lateral izquierda
    	glVertex3f(-1.0f, -1.0f, -1.0f);
    	glVertex3f(-1.0f, -1.0f,  1.0f);
    	glVertex3f(-1.0f,  1.0f,  1.0f);
    	glVertex3f(-1.0f,  1.0f, -1.0f);
    	glEnd();

    	glColor3f(1.0f, 1.0f, 0.0f);
    	glBegin(GL_QUADS);  //cara lateral derecha
    	glVertex3f( 1.0f, -1.0f,  1.0f);
    	glVertex3f( 1.0f, -1.0f, -1.0f);
    	glVertex3f( 1.0f,  1.0f, -1.0f);
    	glVertex3f( 1.0f,  1.0f,  1.0f);
    	glEnd();

    	glColor3f(0.0f, 1.0f, 1.0f);
    	glBegin(GL_QUADS);  //cara arriba
    	glVertex3f(-1.0f,  1.0f,  1.0f);
    	glVertex3f( 1.0f,  1.0f,  1.0f);
    	glVertex3f( 1.0f,  1.0f, -1.0f);
    	glVertex3f(-1.0f,  1.0f, -1.0f);
    	glEnd();

    	glColor3f(1.0f, 0.0f, 1.0f);
    	glBegin(GL_QUADS);  //cara abajo
    	glVertex3f( 1.0f, -1.0f, -1.0f);
    	glVertex3f( 1.0f, -1.0f,  1.0f);
    	glVertex3f(-1.0f, -1.0f,  1.0f);
    	glVertex3f(-1.0f, -1.0f, -1.0f);
    	glEnd();
}//fin del void drawcube

void display() { 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(anguloCuboX, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloCuboY, 0.0f, 1.0f, 0.0f);
    glutWireTeapot(1.5f);
    drawCube();

    glLoadIdeztity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(anguloEsfera, 0.0f, 1.0f, 0.0f);
    glTranslatef(3.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    //drawCube();
    glFlush();
    glutSwapBuffers();
}

void init(){ 
	glClearColor(0,0,0,0); 
	glEnable(GL_DEPTH_TEST); 
	ancho = 400; 
	alto = 400; 
} 

void idle() { 
	display(); 
} 

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'p':
        case 'P':
            hazPerspectiva = 1;
            reshape(ancho,alto);
            break;

        case 'o':
        case 'O':
            hazPerspectiva = 0;
            reshape(ancho,alto);
            break;

        case 'i':
            orthoLeft -= 0.1f; //límite izquierdo
            reshape(ancho,alto);
            break;

        case 'd':
            orthoRight += 0.1f; //límite derecho
            reshape(ancho,alto);
            break;

        case 'r':
            orthoBottom -= 0.1f; //límite inferior
            reshape(ancho,alto);
            break;

        case 'u':
            orthoTop += 0.1f; //límite superior
            reshape(ancho,alto);
            break;

        case 'f':
            perspectiveZfar -= 0.1f; //disminuye distancia máxima
            reshape(ancho,alto);
            break;

        case 'F':
            perspectiveZfar += 0.1f; //aumenta distancia máxima
            reshape(ancho,alto);
            break;

        case 'b':
            perspectiveAngle -= 0.1f; //disminuye ángulo de visión
            reshape(ancho,alto);
            break;

        case 'B':
            perspectiveAngle += 0.1f; //aumenta ángulo de visión
            reshape(ancho,alto);
            break;

        case 'n':
            perspectiveZnear -= 0.1f; //disminuye distancia mínima
            reshape(ancho,alto);
            break;

        case 'N':
            perspectiveZnear += 0.1f; //aumenta distancia mínima
            reshape(ancho,alto);
            break;

        case 27:   // escape
            exit(0);
            break;
    }//fin del switch
} //fin del void keyboard


int main(int argc, char **argv){ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
	glutInitWindowPosition(100, 100); 
	glutInitWindowSize(ancho, alto); 
	glutCreateWindow("Cubo 1"); 
	init(); 
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape); 
	glutIdleFunc(idle); 
	glutKeyboardFunc(keyboard); 
	glutMainLoop(); 
	return 0;
}
