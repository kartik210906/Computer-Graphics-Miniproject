#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>

const float G = 9.81f;
float angle = 45.0f;        // launch angle (degrees)
float speed = 40.0f;        // initial speed (m/s)
float t = 0.0f;             // time
float x = 0.0f, y = 0.0f;   // projectile position
bool flying = false;

// ---- calculations ----
float rad()     { return angle * 3.14159f / 180.0f; }
float maxHeight() { return speed * speed * sin(rad()) * sin(rad()) / (2 * G); }
float flightTime(){ return 2 * speed * sin(rad()) / G; }
float range()     { return speed * speed * sin(2 * rad()) / G; }

// velocity components at time t
float vx()  { return speed * cos(rad()); }
float vy()  { return speed * sin(rad()) - G * t; }
float velAngle() { return atan2(vy(), vx()) * 180.0f / 3.14159f; }  // direction of motion

void drawText(float tx, float ty, const char* s) {
    glRasterPos2f(tx, ty);
    for (; *s; s++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *s);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 200, -10, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ground
    glColor3f(0.0f, 0.6f, 0.0f);
    glRectf(-10, -10, 200, 0);

    // launcher
    glPushMatrix();
    glRotatef(angle, 0, 0, 1);
    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(10, 0);
    glEnd();
    glPopMatrix();

    // angle of projection: horizontal reference line + arc
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(20, 0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (float a = 0; a <= angle; a += 2)
        glVertex2f(15 * cos(a * 3.14159f / 180.0f), 15 * sin(a * 3.14159f / 180.0f));
    glEnd();
    char ang[20];
    sprintf(ang, "%.0f deg", angle);
    drawText(17, 3, ang);

    // trajectory: drawn from the formula x = v cos(a) t, y = v sin(a) t - 0.5 g t^2
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    for (float tt = 0; tt <= t; tt += 0.05f)
        glVertex2f(speed * cos(rad()) * tt,
                   speed * sin(rad()) * tt - 0.5f * G * tt * tt);
    glVertex2f(x, y);
    glEnd();

    // velocity direction line (tangent to the path)
    if (flying) {
        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x + vx() * 0.4f, y + vy() * 0.4f);
        glEnd();
    }

    // projectile
    glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

    // results
    char buf[120];
    glColor3f(0, 0, 0);
    sprintf(buf, "Speed = %.0f m/s   Angle = %.0f deg", speed, angle);
    drawText(-8, 92, buf);
    sprintf(buf, "Max Height H = %.2f m", maxHeight());
    drawText(-8, 86, buf);
    sprintf(buf, "Time of Flight T = %.2f s", flightTime());
    drawText(-8, 80, buf);
    sprintf(buf, "Range R = %.2f m", range());
    drawText(-8, 74, buf);
    sprintf(buf, "Angle of projection = %.0f deg", angle);
    drawText(-8, 68, buf);
    sprintf(buf, "Initial components: Vx = v cos(a) = %.2f m/s,  Vy = v sin(a) = %.2f m/s", speed * cos(rad()), speed * sin(rad()));
    drawText(-8, 62, buf);
    if (flying || y > 0) {
        sprintf(buf, "Now: Vx = %.2f  Vy = %.2f  direction = %.1f deg", vx(), vy(), velAngle());
        drawText(-8, 56, buf);
    }
    if (!flying && x > 0) {
        sprintf(buf, "At landing: direction = %.1f deg (below horizontal), speed = %.1f m/s", -angle, speed);
        drawText(-8, 56, buf);
    }
    drawText(-8, 48, "UP/DOWN: angle  LEFT/RIGHT: speed  SPACE: launch");

    glutSwapBuffers();
}

void update(int value) {
    if (flying) {
        t += 0.05f;
        x = speed * cos(rad()) * t;
        y = speed * sin(rad()) * t - 0.5f * G * t * t;
        if (y < 0) { y = 0; x = range(); flying = false; }
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void keyboard(unsigned char key, int, int) {
    if (key == ' ' && !flying) { t = 0; x = 0; y = 0; flying = true; }
    if (key == 27) exit(0);
}

void special(int key, int, int) {
    if (flying) return;
    if (key == GLUT_KEY_UP)    angle += 1;
    if (key == GLUT_KEY_DOWN)  angle -= 1;
    if (key == GLUT_KEY_RIGHT) speed += 1;
    if (key == GLUT_KEY_LEFT)  speed -= 1;
    t = 0; x = 0; y = 0;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Projectile Motion Simulator");
    glClearColor(0.6f, 0.8f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
