
#include <GL/glew.h>
#ifdef PHYS_LINUX
#include <GL/glxew.h>
#else
#include <GL/wglew.h>
#include <GL/glfw.h>

#include <iostream>
#include <math3d.h>


int main () {
		
	float sx, sy; // скорость x, y
	float m; // масса
	
	std::cout << "Speed: ";
	std::cin >> sx >> sy; // читаем скорость с консоли
	std::cout << "M: ";
	std::cin >> m; // читаем массу
	
	glfwInit();
	glfwOpenWindow(800, 600,  // размер окна
		8, 8, 8, 8, 8, 1 //каналы
		GLFW_WINDOW);
	glewInit();
	glClearColor(0, 0, 0, 1); // устанавливаем цвет, которым будем очищать экран (буфер цвета)
	// очистка - просто заливка этим цветом
	glClearDepth(1); // этим значением будем заливать буфер глубины
	
	
	while(true) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// чистим буфер цвета и глубины	
		
		
	}
	
}
