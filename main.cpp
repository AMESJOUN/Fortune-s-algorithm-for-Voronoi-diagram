#include "GL\glut.h"
#include <time.h>
#include "Voronoi.h"

double w = 1000;
Voronoi * v;
Vertices *ver;
Vertices *dir;
Edges *edg;

void drawVoronoi()
{
	for (Vertices::iterator i = ver->begin(); i != ver->end(); ++i)
	{
		glBegin(GL_QUADS);
		glVertex2f(-1 + 2 * (*i)->x / w - 0.01, -1 + 2 * (*i)->y / w - 0.01);
		glVertex2f(-1 + 2 * (*i)->x / w + 0.01, -1 + 2 * (*i)->y / w - 0.01);
		glVertex2f(-1 + 2 * (*i)->x / w + 0.01, -1 + 2 * (*i)->y / w + 0.01);
		glVertex2f(-1 + 2 * (*i)->x / w - 0.01, -1 + 2 * (*i)->y / w + 0.01);
		glEnd();
	}

	for (Edges::iterator i = edg->begin(); i != edg->end(); ++i)
	{
		glBegin(GL_LINES);
		glVertex2f(-1 + 2 * (*i)->begin->x / w, -1 + 2 * (*i)->begin->y / w);
		glVertex2f(-1 + 2 * (*i)->end->x / w, -1 + 2 * (*i)->end->y / w);
		glEnd();
	}
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	v = new Voronoi();
	ver = new Vertices();
	dir = new Vertices();

	srand(time(NULL));

	for (int i = 0; i < 30; i++)
	{

		ver->push_back(new Point(w * (double)rand() / (double)RAND_MAX, w * (double)rand() / (double)RAND_MAX));
		dir->push_back(new Point((double)rand() / (double)RAND_MAX - 0.5, (double)rand() / (double)RAND_MAX - 0.5));
	}

	edg = v->CreateEdges(ver, w, w);

	glutInit(&argc, argv); //glut's Initialization
	glutInitDisplayMode(GLUT_SINGLE); // display mode
	glutInitWindowSize(600, 600); 
	glutInitWindowPosition(200, 20);
	glutCreateWindow("Voronoi's diagramm"); //title for the window

	glutDisplayFunc(drawVoronoi); // Tell GLUT to use the method "display" for rendering
	glutMainLoop(); // Enter GLUT's main loop

	system("pause");
	return 0;
}