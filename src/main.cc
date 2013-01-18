
#include <GL/glew.h>
#ifdef PHYS_LINUX
#include <GL/glxew.h>
#else
#include <GL/wglew.h>
#include <GL/glfw.h>

#include <iostream>
#include <math3d.h>


#include <vector>





void loadModel (unsigned& vertsNum, unsigned& indNum, unsigned*& indicies, float*& pos, float*& normals) {
	
	// делаем куб для начала
	
	// создаём точки куба (81 точка на каждую грань)
	vertsNum = 81 * 6; // 6 граней
	
	for (int i = 0; i < 6; ++i) {// для шести граней куба		
		for (int x = 0; x < 9; ++k) {// для девяти точек куба
			for (int y = 0; y < 9; ++y) {
				int id = (i * 81 + x * 9 + y) * 3; // индекс текущей точки в массиве позиций
				int indid = (i * 64 + x * 8 + y) * 3 * 2; // индекс в массиве индексов
				switch(i) {
					case 0:
						pos[id] = 1;
						pos[id + 1] = (float)x - 4.5f;
						pos[id + 2] = (float)y - 4.5f;
						break;
					case 1:
						pos[id] = -1;
						pos[id + 1] = (float)x - 4.5f;
						pos[id + 2] = (float)y - 4.5f;
						break;
					case 2:
						pos[id] = (float)x - 4.5f;
						pos[id + 1] = 1;
						pos[id + 2] = (float)y - 4.5f;
						break;
					case 3:
						pos[id] = (float)x - 4.5f;
						pos[id + 1] = -1;
						pos[id + 2] = (float)y - 4.5f;
						break;
					case 4:
						pos[id] = (float)x - 4.5f;
						pos[id + 1] = (float)y - 4.5f;
						pos[id + 2] = 1;
						break;
					case 5:
						pos[id] = (float)x - 4.5f;
						pos[id + 1] = (float)y - 4.5f;
						pos[id + 2] = 1;
						break;
				}
				// делаем треугольники из точек
				if (x < 9 && y < 9) {// последний ряд не заполняем
					indicies[indid] = id;
					indicies[intid + 1] = id + 1;
					indicies[indid + 2] = id + 1 + 9;
					indicies[indid + 3] = id;
					indicies[indid + 4] = id + 1 + 9;
					indicies[indid + 5] = id + 9;
				}
			}
		}
	}
}

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
