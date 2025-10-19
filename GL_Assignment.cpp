#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f); 
    glPointSize(15.0f);  
    glBegin(GL_POINTS);
        glVertex2f(-0.8f, 0.8f);
    glEnd();

    
    glColor3f(0.0f, 1.0f, 0.0f); 
    glLineWidth(4.0f);  
    glBegin(GL_LINES);
        glVertex2f(-0.9f, 0.7f);  
        glVertex2f(-0.4f, 0.2f);  
    glEnd();

    
    glColor3f(0.0f, 0.0f, 1.0f); 
    glBegin(GL_LINE_LOOP); 
        glVertex2f(-0.3f, 0.3f);  
        glVertex2f(0.3f, 0.3f);
        glVertex2f(0.3f, -0.3f);
        glVertex2f(-0.3f, -0.3f);
    glEnd();

    
    glColor3f(1.0f, 1.0f, 0.0f); 
    float radius = 0.3f;  
    float x_center = 0.6f, y_center = 0.5f;
    int num_segments = 100;
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < num_segments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
            float x = radius * cosf(theta);
            float y = radius * sinf(theta);
            glVertex2f(x + x_center, y + y_center);
        }
    glEnd();

    
    glColor3f(1.0f, 0.0f, 1.0f); 
    glBegin(GL_POLYGON);
        glVertex2f(0.4f, -0.7f);  
        glVertex2f(0.9f, -0.7f);  
        glVertex2f(0.65f, -0.1f);
    glEnd();

    glFlush();
}


void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glColor3f(0.0, 0.0, 0.0);         
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("dr_dina_assignment");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
