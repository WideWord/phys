


#include <GL/glew.h>
#ifdef PHYS_LINUX
#include <GL/glxew.h>
#else
#include <GL/wglew.h>
#endif
#include <GL/glfw.h>

#include <iostream>
#include "math3d.h"


#include <vector>





void loadModel (unsigned& vertsNum, unsigned& indNum, unsigned*& indicies, float*& pos, float*& nor, float*& tex) {
	
	// делаем наш куб
	vertsNum = 6 * 4;
	indNum = 6 * 2;
	pos = new float[vertsNum * 3];//3 координаты на точку
	nor = new float[vertsNum * 3];
	indicies = new unsigned[indNum * 3]; // 3 точки на треугольник
	tex = new float[vertsNum * 2];
	
	int pid = 0;
	int nid = 0;
	int tid = 0;
	int iid = 0;
	
	pos[pid++] = 1;
	pos[pid++] = 1;
	pos[pid++] = -1;
	
	tex[tid++] = 0;
	tex[tid++] = 0;
	
	nor[nid++] = 1;
	nor[nid++] = 0;
	nor[nid++] = 0;
	
	
	pos[pid++] = 1;
	pos[pid++] = 1;
	pos[pid++] = 1;
	
	tex[tid++] = 1;
	tex[tid++] = 0;
	
	nor[nid++] = 1;
	nor[nid++] = 0;
	nor[nid++] = 0;
	
	pos[pid++] = 1;
	pos[pid++] = -1;
	pos[pid++] = 1;
	
	tex[tid++] = 1;
	tex[tid++] = 1;
	
	nor[nid++] = 1;
	nor[nid++] = 0;
	nor[nid++] = 0;
	
	pos[pid++] = 1;
	pos[pid++] = -1;
	pos[pid++] = -1;
	
	tex[tid++] = 0;
	tex[tid++] = 1;
	
	nor[nid++] = 1;
	nor[nid++] = 0;
	nor[nid++] = 0;
	
	indicies[iid++] = 0;
	indicies[iid++] = 1;
	indicies[iid++] = 2;
	indicies[iid++] = 0;
	indicies[iid++] = 2;
	indicies[iid++] = 3;
	
	
	
	pos[pid++] = -1;
	pos[pid++] = 1;
	pos[pid++] = -1;
	
	tex[tid++] = 0;
	tex[tid++] = 0;
	
	nor[nid++] = -1;
	nor[nid++] = 0;
	nor[nid++] = 0;
	
	
	pos[pid++] = -1;
	pos[pid++] = 1;
	pos[pid++] = 1;
	
	tex[tid++] = 1;
	tex[tid++] = 0;
	
	nor[nid++] = -1;
	nor[nid++] = 0;
	nor[nid++] = 0;
	
	pos[pid++] = -1;
	pos[pid++] = -1;
	pos[pid++] = 1;
	
	tex[tid++] = 1;
	tex[tid++] = 1;
	
	nor[nid++] = -1;
	nor[nid++] = 0;
	nor[nid++] = 0;
	
	pos[pid++] = -1;
	pos[pid++] = -1;
	pos[pid++] = -1;
	
	tex[tid++] = 0;
	tex[tid++] = 1;
	
	nor[nid++] = -1;
	nor[nid++] = 0;
	nor[nid++] = 0;
	
	indicies[iid++] = 4;
	indicies[iid++] = 5;
	indicies[iid++] = 6;
	indicies[iid++] = 4;
	indicies[iid++] = 6;
	indicies[iid++] = 7;
	
	pos[pid++] = 1;
	pos[pid++] = 1;
	pos[pid++] = -1;
	
	tex[tid++] = 0;
	tex[tid++] = 0;
	
	nor[nid++] = 0;
	nor[nid++] = 1;
	nor[nid++] = 0;
	
	
	pos[pid++] = 1;
	pos[pid++] = 1;
	pos[pid++] = 1;
	
	tex[tid++] = 1;
	tex[tid++] = 0;
	
	nor[nid++] = 0;
	nor[nid++] = 1;
	nor[nid++] = 0;
	
	pos[pid++] = -1;
	pos[pid++] = 1;
	pos[pid++] = 1;
	
	tex[tid++] = 1;
	tex[tid++] = 1;
	
	nor[nid++] = 0;
	nor[nid++] = 1;
	nor[nid++] = 0;
	
	pos[pid++] = -1;
	pos[pid++] = 1;
	pos[pid++] = -1;
	
	tex[tid++] = 0;
	tex[tid++] = 1;
	
	nor[nid++] = 0;
	nor[nid++] = 1;
	nor[nid++] = 0;
	
	indicies[iid++] = 8;
	indicies[iid++] = 9;
	indicies[iid++] = 10;
	indicies[iid++] = 8;
	indicies[iid++] = 10;
	indicies[iid++] = 11;
	
	pos[pid++] = 1;
	pos[pid++] = -1;
	pos[pid++] = -1;
	
	tex[tid++] = 0;
	tex[tid++] = 0;
	
	nor[nid++] = 0;
	nor[nid++] = -1;
	nor[nid++] = 0;
	
	
	pos[pid++] = 1;
	pos[pid++] = -1;
	pos[pid++] = 1;
	
	tex[tid++] = 1;
	tex[tid++] = 0;
	
	nor[nid++] = 0;
	nor[nid++] = -1;
	nor[nid++] = 0;
	
	pos[pid++] = -1;
	pos[pid++] = -1;
	pos[pid++] = 1;
	
	tex[tid++] = 1;
	tex[tid++] = 1;
	
	nor[nid++] = 0;
	nor[nid++] = -1;
	nor[nid++] = 0;
	
	pos[pid++] = -1;
	pos[pid++] = -1;
	pos[pid++] = -1;
	
	tex[tid++] = 0;
	tex[tid++] = 1;
	
	nor[nid++] = 0;
	nor[nid++] = -1;
	nor[nid++] = 0;
	
	indicies[iid++] = 12;
	indicies[iid++] = 13;
	indicies[iid++] = 14;
	indicies[iid++] = 12;
	indicies[iid++] = 14;
	indicies[iid++] = 15;
	
	pos[pid++] = 1;
	pos[pid++] = 1;
	pos[pid++] = 1;
	
	tex[tid++] = 0;
	tex[tid++] = 0;
	
	nor[nid++] = 0;
	nor[nid++] = 0;
	nor[nid++] = 1;
	
	
	pos[pid++] = -1;
	pos[pid++] = 1;
	pos[pid++] = 1;
	
	tex[tid++] = 1;
	tex[tid++] = 0;
	
	nor[nid++] = 0;
	nor[nid++] = 0;
	nor[nid++] = 1;
	
	pos[pid++] = -1;
	pos[pid++] = -1;
	pos[pid++] = 1;
	
	tex[tid++] = 1;
	tex[tid++] = 1;
	
	nor[nid++] = 0;
	nor[nid++] = 0;
	nor[nid++] = 1;
	
	pos[pid++] = 1;
	pos[pid++] = -1;
	pos[pid++] = 1;
	
	tex[tid++] = 0;
	tex[tid++] = 1;
	
	nor[nid++] = 0;
	nor[nid++] = 0;
	nor[nid++] = 1;
	
	indicies[iid++] = 16;
	indicies[iid++] = 17;
	indicies[iid++] = 18;
	indicies[iid++] = 16;
	indicies[iid++] = 18;
	indicies[iid++] = 19;
	
	pos[pid++] = 1;
	pos[pid++] = 1;
	pos[pid++] = -1;
	
	tex[tid++] = 0;
	tex[tid++] = 0;
	
	nor[nid++] = 0;
	nor[nid++] = 0;
	nor[nid++] = -1;
	
	
	pos[pid++] = -1;
	pos[pid++] = 1;
	pos[pid++] = -1;
	
	tex[tid++] = 1;
	tex[tid++] = 0;
	
	nor[nid++] = 0;
	nor[nid++] = 0;
	nor[nid++] = -1;
	
	pos[pid++] = -1;
	pos[pid++] = -1;
	pos[pid++] = -1;
	
	tex[tid++] = 1;
	tex[tid++] = 1;
	
	nor[nid++] = 0;
	nor[nid++] = 0;
	nor[nid++] = -1;
	
	pos[pid++] = 1;
	pos[pid++] = -1;
	pos[pid++] = -1;
	
	tex[tid++] = 0;
	tex[tid++] = 1;
	
	nor[nid++] = 0;
	nor[nid++] = 0;
	nor[nid++] = -1;
	
	indicies[iid++] = 20;
	indicies[iid++] = 21;
	indicies[iid++] = 22;
	indicies[iid++] = 20;
	indicies[iid++] = 22;
	indicies[iid++] = 23;
	
	
	
	
}


int main () {
		
	float sx, sy; // скорость x, y
	float m; // масса
	
	//std::cout << "Speed: ";
	//std::cin >> sx >> sy; // читаем скорость с консоли
	//std::cout << "M: ";
	//std::cin >> m; // читаем массу
	
	glfwInit();
	glfwOpenWindow(800, 600,  // размер окна
		8, 8, 8, 8, 8, 1, //каналы
		GLFW_WINDOW);
	glewInit();
	glClearColor(1, 0, 0, 1); // устанавливаем цвет, которым будем очищать экран (буфер цвета)
	// очистка - просто заливка этим цветом
	glClearDepth(1); // этим значением будем заливать буфер глубины
	glViewport(0,0,800, 600); // передаём в opengl размеры окна
	glShadeModel( GL_FLAT ); // нормали не сглаживаются
    glEnable( GL_DEPTH_TEST ); // включаем тест глубины (для него и нужен буфер глубины)
    glDepthFunc( GL_LEQUAL ); // решим теста глубины
    //glEnable(GL_CULL_FACE); // отсечение (см вниз)
    //glCullFace(GL_FRONT);  // рисование только одной стороны
	
	// теперь создаём модель шарика
	// заливаем модель сразу на видеокарту, как в современных играх
	unsigned vao; // vertex array object
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao); // vao - идинтефикатор модели шарика в памяти видеокарты
	unsigned vbo[4]; // vertex buffer object
	// vbo - 4 идинтефикатора массива координат: позиция, нормаль (для освещения) каждой точки и индексы
	// и текстурные координаты
	glGenBuffers(4, vbo);
	
	// загружаем модель
	unsigned vertsNum, facesNum;
	unsigned* faces;
	float* pos;
	float* nor;
	float* tex;
	loadModel(vertsNum, facesNum, faces, pos, nor, tex);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, vertsNum * sizeof(float) * 3, pos, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, vertsNum * sizeof(float) * 3, nor, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, facesNum * sizeof(unsigned) * 3, faces, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[3]);
	glBufferData(GL_ARRAY_BUFFER, vertsNum * sizeof(float) * 2, tex, GL_STATIC_DRAW);
	
	
	// создаём шейдр для куба
	unsigned shader = glCreateProgram();
	unsigned vshader = glCreateShader(GL_VERTEX_SHADER);
	unsigned fshader = glCreateShader(GL_FRAGMENT_SHADER);

	// этот код будет выполняться на видеокарте
	auto vshaderSource = "#version 330 core\n\
	uniform mat4 perspective;\n\
	uniform mat4 model;\n\
	uniform mat4 view;\n\
	in vec3 position;\n\
	in vec3 normal;\n\
	in vec2 texture;\n\
	out vec3 f_position;\n\
	out vec3 f_normal;\n\
	out vec2 f_texture;\n\
	void main (void) {\n\
		vec4 vertex = model * vec4(position, 1);\n\
		f_position = vec3(vertex);\n\
		f_normal = mat3(model) * normal;\n\
		f_texture = texture;\n\
		gl_Position = (perspective * view) * vertex;\n\
	}";

	int len = strlen(vshaderSource);
	int _len;
	glShaderSource(vshader, 1, (const GLchar**)&vshaderSource, (const GLint*)&len);//загружаем код на видеокарту
	glCompileShader(vshader);// комcolorпилируем

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
	
	auto fshaderSource = "#version 330 core\n\
	out vec4 o_color;\n\
	uniform vec3 color;\n\
	in vec3 f_position;\n\
	in vec3 f_normal;\n\
	in vec2 f_texture;\n\
	uniform sampler2D cubeTexture;\n\
	void main (void) {\n\
		o_color = vec4(vec3(texture(cubeTexture, f_texture)), 1);\n\
		o_color *= max(dot(normalize(vec3(0.1, -1, -0.2)), normalize(-f_normal)), 0);\n\
	}";
	
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
    
    //загружаем текстуру для куба
    GLuint cubeTexture;
    glGenTextures(1, &cubeTexture);
	glBindTexture(GL_TEXTURE_2D, cubeTexture);
	// установим параметры фильтрации текстуры - линейная фильтрация
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // установим параметры "оборачивания" текстуры
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//загрузим текстуру из файла
	glfwLoadTexture2D("cube.tga", GLFW_BUILD_MIPMAPS_BIT);
	
	//разрешим использовать
	glfwEnable(GL_TEXTURE_2D);
	

    
	mat4 perspective = mat4::perspective(60, 800.0f/600.0f, 0.1f, 100.0f);
	// создаём перспективную матрицу с помощью math3d.h
	
	vec2 speed = vec2(sx, sy);
	// переводим скорость в вектор из math3d
	
	vec2 position = vec2(0, 0); // позиция куба 0, 0
	float rotation = 0; // поворо куба вокруг оси z
    mat4 model, view;
	vec3 camPosition = vec3(0, 4, 10);// позиция камеры
	quat camRotation = quat::euler(vec3(0, 0, -0.3f));

	glUseProgram(shader);// используем созданный шейдер
	while(true) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// чистим буфер цвета и глубины	
		
		//переводим координаты кубика в матрицу
		mat4 model = mat4::translation(vec3(position.x, position.y, 0));
		model *= mat4::rotation(quat::euler(vec3(0, rotation, 0)));
		mat4 view = mat4::rotation(camRotation) * mat4::translation(-camPosition);
		
		
		
		//передаём матрицы в шейдер
		GLint loc;
		loc = glGetUniformLocation(shader, "perspective");
		glUniformMatrix4fv(loc, 1, GL_TRUE, *perspective);
		loc = glGetUniformLocation(shader, "view");
		glUniformMatrix4fv(loc, 1, GL_TRUE, *view);
		loc = glGetUniformLocation(shader, "model");
		glUniformMatrix4fv(loc, 1, GL_TRUE, *model);
		loc = glGetUniformLocation(shader, "color");
		glUniform3f(loc, 1, 1, 1);
		
		// передаём загруженные на видеокарту вершины куба в шейдер
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		loc = glGetAttribLocation(shader, "position");
		glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(loc);
		
		glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
		loc = glGetAttribLocation(shader, "normal");
		glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(loc);
		
		glBindBuffer(GL_ARRAY_BUFFER, vbo[3]);
		loc = glGetAttribLocation(shader, "texture");
		glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
		glEnableVertexAttribArray(loc);
		
		//передаём текстуру в шейдер
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, cubeTexture);
		loc = glGetUniformLocation(shader, "cubeTexture");
		glUniform1i(loc, 0);
		
		

		
		// рисуем куб
		glDrawElements(GL_TRIANGLES, facesNum * 3, GL_UNSIGNED_INT, NULL);
		
		
		//обновляем окно
		glfwSwapBuffers();
		
		rotation += 0.005f;
		
		
	}
	
}
