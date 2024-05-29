//PROGRAMA QUE MUESTRA UN CUBO QUE PUEDE ROTAR, DESPLAZARSE Y CAMBIAR ENTRE PROYECCI�N ORTOGONAL Y PERSPECTIVA
//Autor: Marco Fabricio Benites Meza
//Fecha de edici�n: mi�rcoles 29 de mayo del 2024
//Curso: Computaci�n Visual
//Universidad Nacional Mayor de San Marcos. Universidad del Per�, D�cana de Am�rica
#include <GL/glut.h>
GLfloat anguloCuboX = 0.0f;
GLfloat anguloCuboY = 0.0f;
GLfloat anguloEsfera = 0.0f; 
GLint ancho, alto;
int hazPerspectiva = 1;
// Par�metros para la proyecci�n ortogonal
GLfloat orthoLeft = -4.0f;
GLfloat orthoRight = 4.0f;
GLfloat orthoBottom = -4.0f;
GLfloat orthoTop = 4.0f;
// Par�metros para la proyecci�n perspectiva
GLfloat perspectiveAngle = 45.0f;
GLfloat perspectiveZnear = 1.0f;
GLfloat perspectiveZfar = 4.8f;

/*
Significado de variables:
GLfloat orthoLeft: L�mite izquierdo de la proyecci�n ortogonal.
GLfloat orthoRight: L�mite derecho de la proyecci�n ortogonal.
GLfloat orthoBottom: L�mite superior de la proyecci�n ortogonal.
GLfloat orthoTop: L�mite inferior de la proyecci�n ortogonal.
GLfloat perspectiveAngle: �ngulo de visi�n de la proyecci�n perspectiva.
GLfloat GLfloat perspectiveZnear: Distancia m�nima desde la c�mara donde comienza la proyecci�n perspectiva.
GLfloat perspectiveZfar: Distancia m�xima desde la c�mara donde termina la proyecci�n perspectiva.
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
            orthoLeft -= 0.1f; //l�mite izquierdo
            reshape(ancho,alto);
            break;

        case 'd':
            orthoRight += 0.1f; //l�mite derecho
            reshape(ancho,alto);
            break;

        case 'r':
            orthoBottom -= 0.1f; //l�mite inferior
            reshape(ancho,alto);
            break;

        case 'u':
            orthoTop += 0.1f; //l�mite superior
            reshape(ancho,alto);
            break;

        case 'f':
            perspectiveZfar -= 0.1f; //disminuye distancia m�xima
            reshape(ancho,alto);
            break;

        case 'F':
            perspectiveZfar += 0.1f; //aumenta distancia m�xima
            reshape(ancho,alto);
            break;

        case 'b':
            perspectiveAngle -= 0.1f; //disminuye �ngulo de visi�n
            reshape(ancho,alto);
            break;

        case 'B':
            perspectiveAngle += 0.1f; //aumenta �ngulo de visi�n
            reshape(ancho,alto);
            break;

        case 'n':
            perspectiveZnear -= 0.1f; //disminuye distancia m�nima
            reshape(ancho,alto);
            break;

        case 'N':
            perspectiveZnear += 0.1f; //aumenta distancia m�nima
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
