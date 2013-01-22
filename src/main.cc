
#include <GL/glew.h>
#ifdef PHYS_LINUX
#include <GL/glxew.h>
#else
#include <GL/wglew.h>
#include <GL/glfw.h>

#include <iostream>
#include <math3d.h>


#include <vector>





void loadModel (unsigned& vertsNum, unsigned& indNum, unsigned*& indicies, float*& pos, float*& nor) {
	
	// делаем наш куб
	vertsNum = 8;
	indNum = 6 * 2;
	pos = new float[vertsNum * 3];//3 координаты на точку
	nor = new float[vertsNum * 3];
	indicies = new unsigned[indNum * 3]; // 3 точки на треугольник
	
	pos[0] = 1;
	pos[1] = 1;
	pos[2] = -1;
	
	pos[3] = 1;
	pos[4] = 1;
	pos[5] = 1;
	
	pos[6] = -1;
	pos[7] = 1;
	pos[8] = 1;
	
	pos[9] = -1;
	pos[10] = 1;
	pos[11] = -1;
	
	pos[12] = 1;
	pos[13] = -1;
	pos[14] = -1;
	
	pos[15] = 1;
	pos[16] = -1;
	pos[17] = 1;
	
	pos[18] = -1;
	pos[19] = -1;
	pos[20] = 1;
	
	pos[21] = -1;
	pos[22] = -1;
	pos[23] = -1;
	
	for (int i = 0; i < 8 * 3; ++i) {
		nor[i] = pos[i]; // в кубе позиция и нормали совпадают
	}	

	indicies[0] = 0;
	indicies[1] = 1;
	indicies[2] = 4;
	indicies[3] = 1;
	indicies[4] = 5;
	indicies[5] = 4;
	
	indicies[6] = 0;
	indicies[7] = 3;
	indicies[8] = 4;
	indicies[9] = 3;
	indicies[10] = 7;
	indicies[11] = 4;
	
	indicies[12] = 3;
	indicies[13] = 6;
	indicies[14] = 7;
	indicies[15] = 3;
	indicies[16] = 2;
	indicies[17] = 6;
	
	indicies[18] = 2;
	indicies[19] = 1;
	indicies[20] = 6;
	indicies[21] = 1;
	indicies[22] = 5;
	indicies[23] = 6;
	
	indicies[24] = 3;
	indicies[25] = 2;
	indicies[26] = 1;
	indicies[27] = 3;
	indicies[28] = 0;
	indicies[29] = 1;
	
	indicies[30] = 7;
	indicies[31] = 6;
	indicies[32] = 5;
	indicies[33] = 7;
	indicies[34] = 4;
	indicies[35] = 5;
	
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
	glViewport(0,0,800, 600); // передаём в opengl размеры окна
	glShadeModel( GL_FLAT ); // нормали не сглаживаются
    glEnable( GL_DEPTH_TEST ); // включаем тест глубины (для него и нужен буфер глубины)
    glDepthFunc( GL_LEQUAL ); // решим теста глубины
    glEnable(GL_CULL_FACE); // отсечение (я не помню что это)
    glCullFace(GL_BACK);  // рисование только одной стороны
	
	
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
	
	// загружаем модель
	unsigned vertsNum, facesNum;
	unsigned* faces;
	float* pos;
	float* nor;
	loadModel(vertsNum, facesNum, faces, pos, nor);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, vertsNum * sizeof(float) * 3, pos, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, vertsNum * sizeof(float) * 3, nor, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, facesNum * sizeof(unsigned) * 3, faces, GL_STATIC_DRAW);
	
	
	
	// создаём шейдр
	unsigned shader = glCreateProgram();
	unsigned vshader = glCreateShader(GL_VERTEX_SHADER);
	unsigned fshader = glCreateShader(GL_FRAGMENT_SHADER);

	// этот код будет выполняться на видеокарте
	auto vshaderSource = "";

	len = strlen(vshaderSource);
	glShaderSource(vshader, 1, (const GLchar**)&vshaderSource, (const GLint*)&len);//загружаем код на видеокарту
	glCompileShader(vshader);// компилируем

	//проверяем скомпилировался ли
	GLint status;
	glGetShaderiv(vshader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
    {
        char buffer[1024];
        glGetShaderInfoLog(vshader, 1024, &_len, buffer);
        std::cerr << "Vertex shader compilation failed: " << buffer;
    }

	//дубль 2
	
	auto fshaderSource = "";
	
	len = strlen(fshaderSource);
	glShaderSource(fshader, 1, (const GLchar**)&fshaderSource, (const GLint*)&len);
	glCompileShader(fshader);


	glGetShaderiv(fshader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
    {
        char buffer[1024];
        glGetShaderInfoLog(fshader, 1024, &_len, buffer);
        std::cerr << "Fragment shader compilation failed: " << buffer;
    }
    
// собираем весь код в шейдер
	glAttachShader(shader, vshader);
	glAttachShader(shader, fshader);

	glLinkProgram(shader);

	glGetProgramiv(shader, GL_LINK_STATUS, &status);
	if (status != GL_TRUE)
    {
        char buffer[1024];
        glGetProgramInfoLog(shader, 1024, &_len, buffer);
        std::cerr << "Program linking failed: " << buffer;
    }
    
    glUseProgram(shader);
    glValidateProgram(shader);
    
    glGetProgramiv(shader, GL_VALIDATE_STATUS, &status);
	if (status != GL_TRUE)
    {
        char buffer[1024];
        glGetProgramInfoLog(shader, 1024, &_len, buffer);
        std::cerr << "Program validate failed " << buffer;
    }
    // шейдер готов
    
    
	

	
	while(true) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// чистим буфер цвета и глубины	
		
		
	}
	
}
