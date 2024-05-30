#include <GL/glut.h>
#include <stdio.h>

// Variables globales para la rotación y la traslación
float rotationX = 0.0, rotationY = 0.0, rotationZ = 0.0;
float posX = 0.0, posY = 0.0, posZ = -50.0;  // El cubo empieza 50 unidades atrás para mejor visualización

// Función de redimensionamiento
void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)width / height, 1, 500);
	glMatrixMode(GL_MODELVIEW);
}

// Función para dibujar el cubo
void drawCube() {
	glBegin(GL_QUADS);
	// Frente
	glColor3f(1, 0, 0); // Rojo
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(-1, 1, 1);
	// Atrás
	glColor3f(0, 1, 0); // Verde
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, 1, -1);
	glVertex3f(1, 1, -1);
	glVertex3f(1, -1, -1);
	// Izquierda
	glColor3f(0, 0, 1); // Azul
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, 1, -1);
	// Derecha
	glColor3f(1, 1, 0); // Amarillo
	glVertex3f(1, -1, -1);
	glVertex3f(1, 1, -1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, -1, 1);
	// Arriba
	glColor3f(1, 0, 1); // Magenta
	glVertex3f(-1, 1, -1);
	glVertex3f(-1, 1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, -1);
	// Abajo
	glColor3f(0, 1, 1); // Cian
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);
	glVertex3f(-1, -1, 1);
	glEnd();
}

// Visualización
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	// Aplicar transformaciones
	glTranslatef(posX, posY, posZ);
	glRotatef(rotationX, 1, 0, 0);
	glRotatef(rotationY, 0, 1, 0);
	glRotatef(rotationZ, 0, 0, 1);
	
	// Dibujar el cubo
	drawCube();
	
	glutSwapBuffers();
}

// Inicialización
void init() {
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
}

// Función de teclado
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'f': // Avanzar hacia adelante 5 unidades
		posZ += 5.0;
		break;
	case 'b': // Retroceder 5 unidades
		posZ -= 5.0;
		break;
	case 'r': // Girar a la derecha 10 grados
		rotationY += 10.0;
		break;
	case 'l': // Girar a la izquierda 10 grados
		rotationY -= 10.0;
		break;
	case 'u': // Girar hacia arriba 10 grados
		rotationX -= 10.0;
		break;
	case 'd': // Girar hacia abajo 10 grados
		rotationX += 10.0;
		break;
	default:
		break;
	}
	glutPostRedisplay(); // Actualizar la pantalla
}

int main(int argc, char **argv) {
	// Inicializar GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Cubo con Transformaciones");
	
	// Llamar funciones
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	
	return 0;
}
