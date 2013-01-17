
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
	
	
	mat4 perspective = mat4.perspective(60, 800/600, 0.1f, 100.0f);
	// создаём перспективную матрицу с помощью math3d.h
	
	vec2 speed = vec2(sx, sy);
	// переводим скорость в вектор из math3d
	
	vec2 pos = vec2(0, 0); // позиция шарика 0, 0
	
	// теперь создаём модель шарика
	// заливаем модель сразу на видеокарту, как в современных играх
	unsigned vao; // vertex array object
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao); // vao - идинтефикатор модели шарика в памяти видеокарты
	unsigned vbo[3]; // vertex buffer object
	// vbo - три идинтефикатора массива координат: позиция, нормаль (для освещения) каждой точки и индексы
	glGenBuffers(3, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[0]);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER,  * sizeof(unsigned) * 3, index, GL_STATIC_DRAW);


	
	while(true) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// чистим буфер цвета и глубины	
		
		
	}
	
}
