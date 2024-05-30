#include <GL/glut.h> 
GLfloat anguloCuboX = 0.0f;  
GLfloat anguloCuboY = 0.0f; 
GLfloat anguloEsfera = 0.0f; 
GLint ancho, alto; 
int hazPerspectiva = 1; 

// Parámetros de proyección
GLfloat left = -4.0f, right = 4.0f, bottom = -4.0f, top = 4.0f, nearVal = 1.0f, farVal = 4.8f;
GLfloat fovy = 45.0f; // Ángulo de visión para la perspectiva

void reshape(int width, int height) 
{ 
	glViewport(0, 0, width, height); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	
	if(hazPerspectiva) 
		gluPerspective(fovy, (GLfloat)width/(GLfloat)height, nearVal, farVal); 
	else 
		glOrtho(left, right, bottom, top, nearVal, farVal); 
	
	glMatrixMode(GL_MODELVIEW); 
	
	ancho = width; 
	alto = height;
} 

void drawCube(void) 
{ 
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
	glBegin(GL_QUADS);  //cara lateral izq 
	glVertex3f(-1.0f, -1.0f, -1.0f); 
	glVertex3f(-1.0f, -1.0f,  1.0f); 
	glVertex3f(-1.0f,  1.0f,  1.0f); 
	glVertex3f(-1.0f,  1.0f, -1.0f); 
	glEnd();
	glColor3f(1.0f, 1.0f, 0.0f); 
	glBegin(GL_QUADS);  //cara lateral dcha 
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
	
} 

void display() 
{ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	glLoadIdentity(); 
	
	glTranslatef(0.0f, 0.0f, -5.0f); 
	
	glRotatef(anguloCuboX, 1.0f, 0.0f, 0.0f); 
	glRotatef(anguloCuboY, 0.0f, 1.0f, 0.0f);
	glutWireTeapot(1.5f);
	
	glLoadIdentity(); 
	
	glTranslatef(0.0f, 0.0f, -5.0f); 
	glRotatef(anguloEsfera, 0.0f, 1.0f, 0.0f); 
	glTranslatef(3.0f, 0.0f, 0.0f); 
	
	glColor3f(1.0f, 1.0f, 1.0f); 
	//drawCube(); 
	
	glFlush(); 
	glutSwapBuffers(); 
	
	//	anguloCuboX+=0.1f; 
	//	anguloCuboY+=0.1f; 
	//	anguloEsfera+=0.2f; 
} 

void init() 
{ 
	glClearColor(0,0,0,0); 
	glEnable(GL_DEPTH_TEST); 
	ancho = 400; 
	alto = 400; 
} 

void idle() 
{ 
	display(); 
} 

void keyboard(unsigned char key, int x, int y) 
{ 
	switch(key) 
	{
	case 'p': 
	case 'P': 
		hazPerspectiva=1; 
		reshape(ancho,alto); 
		break; 
		
	case 'o': 
	case 'O': 
		hazPerspectiva=0; 
		reshape(ancho,alto); 
		break; 
		
		// Modificación de parámetros de proyección para Ortogonal
	case 'i': // Decrementar el límite izquierdo
		left -= 0.1f;
		reshape(ancho, alto);
		break;
	case 'I': // Incrementar el límite izquierdo
		left += 0.1f;
		reshape(ancho, alto);
		break;
	case 'd': // Incrementar el límite derecho
		right += 0.1f;
		reshape(ancho, alto);
		break;
	case 'D': // Decrementar el límite derecho
		right -= 0.1f;
		reshape(ancho, alto);
		break;
	case 'a': // Decrementar el límite inferior
		bottom -= 0.1f;
		reshape(ancho, alto);
		break;
	case 'A': // Incrementar el límite inferior
		bottom += 0.1f;
		reshape(ancho, alto);
		break;
	case 'u': // Incrementar el límite superior
		top += 0.1f;
		reshape(ancho, alto);
		break;
	case 'U': // Decrementar el límite superior
		top -= 0.1f;
		reshape(ancho, alto);
		break;
	case 'n': // Decrementar Znear
		nearVal -= 0.1f;
		reshape(ancho, alto);
		break;
	case 'N': // Incrementar Znear
		nearVal += 0.1f;
		reshape(ancho, alto);
		break;
	case 'f': // Decrementar Zfar
		farVal -= 0.1f;
		reshape(ancho, alto);
		break;
	case 'F': // Incrementar Zfar
		farVal += 0.1f;
		reshape(ancho, alto);
		break;
		
		// Modificación de parámetros de proyección para Perspectiva
	case 'b': // Decrementar el ángulo de visión
		fovy -= 0.1f;
		reshape(ancho, alto);
		break;
	case 'B': // Incrementar el ángulo de visión
		fovy += 0.1f;
		reshape(ancho, alto);
		break;
	case 'm': // Decrementar Znear
		nearVal -= 0.1f;
		reshape(ancho, alto);
		break;
	case 'M': // Incrementar Znear
		nearVal += 0.1f;
		reshape(ancho, alto);
		break;
	case 'g': // Decrementar Zfar
		farVal -= 0.1f;
		reshape(ancho, alto);
		break;
	case 'G': // Incrementar Zfar
		farVal += 0.1f;
		reshape(ancho, alto);
		break;
		
	case 27:   // escape 
		exit(0); 
		break; 
	} 
} 

int main(int argc, char **argv) 
{ 
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
