#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <time.h>
#include <thread>
#include <math.h>
#include "Handler.h"
#include "GameObject.h"
#include "Player.h"
#include "BasicEnemy.h"
#include "Application.h"
#include "FollowingEnemy.h"
#include "Bullet.h"


Handler handler;

void bulletCollision() {
	for (int i = 1; i < handler.size(); i++) {
		if (handler.getObject(i)->getID() == "Bullet") {
			float tempBulX = handler.getObject(i)->getX(), tempBulY = handler.getObject(i)->getY();
			for (int j = 1; j < handler.size(); j++) {
				float tempX = handler.getObject(j)->getX(), tempY = handler.getObject(j)->getY();
				if ((abs(tempX - tempBulX) < 11) && (abs(tempY - tempBulY) < 11) && (handler.getObject(j)->getID() != "Bullet")) {
					handler.removeObject(j);
					handler.removeObject(i-1);
				}

			}
		}
	}
}

void playerCollision() {
	float tempPlayerX = handler.getObject(0)->getX(), tempPlayerY = handler.getObject(0)->getY();
	for (int i = 1; i < handler.size(); i++) {
		float tempX = handler.getObject(i)->getX(), tempY = handler.getObject(i)->getY();;
		if (abs(tempPlayerX - tempX) < 11 && abs(tempPlayerY - tempY) < 11 && handler.getObject(i)->getID() != "Bullet") {
			handler.removeObject(0);
		}
	}
}

double mouseX = 0, mouseY = 0;
float bulletX = 0, bulletY = 0, bulletVector = 0;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && handler.getObject(0)->getID() == "Player") {
		glfwGetCursorPos(window, &mouseX, &mouseY);
		mouseX *= (2000.0 / 2560.0);
		mouseY *= (2000.0 / 1440.0);
		
		bulletX = (float)mouseX - handler.getObject(0)->getX();
		bulletY = -1*((float)mouseY - handler.getObject(0)->getY());

		bulletVector = sqrt((bulletX * bulletX) + (bulletY * bulletY));
		bulletVector/=10;

		handler.addObject(new Bullet(handler.getObject(0)->getX(), handler.getObject(0)->getY(), (bulletX/bulletVector) - handler.getObject(0)->getPercievedX(), (bulletY / bulletVector) - handler.getObject(0)->getPercievedY()));
	}
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (key == GLFW_KEY_W) {
		switch (action) {
		
		case GLFW_PRESS:

			for (int i = 1; i < handler.size(); i++) {
				handler.getObject(i)->setVelY(handler.getObject(i)->getVelY() - handler.getObject(0)->getVelY());
			}
			handler.getObject(0)->setPercievedY(5);

			break;
		
		case GLFW_RELEASE:

			for (int i = 1; i < handler.size(); i++) {
				handler.getObject(i)->setVelY(handler.getObject(i)->getVelY() + handler.getObject(0)->getVelY());
			}
			handler.getObject(0)->setPercievedY(0);
			
			break;
		}
	}
	if (key == GLFW_KEY_S) {
		switch (action) {

		case GLFW_PRESS:

			for (int i = 1; i < handler.size(); i++) {
				handler.getObject(i)->setVelY(handler.getObject(i)->getVelY() + handler.getObject(0)->getVelY());
			}
			handler.getObject(0)->setPercievedY(-5);

			break;

		case GLFW_RELEASE:

			for (int i = 1; i < handler.size(); i++) {
				handler.getObject(i)->setVelY(handler.getObject(i)->getVelY() - handler.getObject(0)->getVelY());
			}
			handler.getObject(0)->setPercievedY(0);

			break;
		}
	}
	if (key == GLFW_KEY_A) {
		switch (action) {
		
		case GLFW_PRESS:

			for (int i = 1; i < handler.size(); i++) {
				handler.getObject(i)->setVelX(handler.getObject(i)->getVelX() + handler.getObject(0)->getVelX());
			}
			handler.getObject(0)->setPercievedX(-5);

			break;

		case GLFW_RELEASE:

			for (int i = 1; i < handler.size(); i++) {
				handler.getObject(i)->setVelX(handler.getObject(i)->getVelX() - handler.getObject(0)->getVelX());
			}
			handler.getObject(0)->setPercievedX(0);

			break;
		}
	}
	if (key == GLFW_KEY_D) {
		switch (action) {

		case GLFW_PRESS:

			for (int i = 1; i < handler.size(); i++) {
				handler.getObject(i)->setVelX(handler.getObject(i)->getVelX() - handler.getObject(0)->getVelX());
			}
			handler.getObject(0)->setPercievedX(5);

			break;

		case GLFW_RELEASE:

			for (int i = 1; i < handler.size(); i++) {
				handler.getObject(i)->setVelX(handler.getObject(i)->getVelX() + handler.getObject(0)->getVelX());
			}
			handler.getObject(0)->setPercievedX(0);

			break;
		}
	}
	if (key == GLFW_KEY_ESCAPE) {
		glfwSetWindowShouldClose(window, 1);
	}
	
}


float main(void) {

	srand(time(0));

	handler.addObject(new Player(1000, 1000, 5, 5));
	handler.addObject(new BasicEnemy(500, 500, 0, 0));
	handler.addObject(new BasicEnemy(1500, 1500, 0, 0));
	handler.addObject(new FollowingEnemy(1700, 1700, 0, 0, handler.getObject(0)));

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;
	
	GLFWmonitor* primary = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(primary);

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(mode->width, mode->height, "OpenGL Game", primary, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);


	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "error" << std::endl;
	}
	std::cout << glGetString(GL_VERSION) << std::endl;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {

		bulletCollision();
		playerCollision();
		handler.tick();
		//std::cout << handler->getObject(0)->getID() << std::endl;
		

			glClear(GL_COLOR_BUFFER_BIT);

			glBegin(GL_QUADS);

			for (int i = 0; i < handler.size(); i++) {
				float vertex[4];
				float* colorArray = handler.getObject(i)->getColor();

				glColor3f(colorArray[0], colorArray[1], colorArray[2]);
				
				for (int j = 0; j < 4; j++) {
					vertex[j] = handler.getObject(i)->getVertex(j);
				}

				glVertex2f(-1.0f + vertex[0] / 1000.0f, -1.0f + vertex[3] / 1000.0f);
				glVertex2f(-1.0f + vertex[1] / 1000.0f, -1.0f + vertex[3] / 1000.0f);
				glVertex2f(-1.0f + vertex[1] / 1000.0f, -1.0f + vertex[2] / 1000.0f);
				glVertex2f(-1.0f + vertex[0] / 1000.0f, -1.0f + vertex[2] / 1000.0f);


			}

			glEnd();

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();

			//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	glfwTerminate();
	return 0;
}