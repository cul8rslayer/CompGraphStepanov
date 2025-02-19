#define GLWF
#define GLEW

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359f // Определяем число Пи

void drawHexagon() {
    float radius = 0.5f; // Радиус шестиугольника

    glBegin(GL_TRIANGLE_FAN);

    // Центр (зелёный)
    glColor3f(0.4f, 1.0f, 0.4f);
    glVertex2f(0.0f, 0.0f);

    // Вершины (красный)
    glColor3f(1.0f, 0.2f, 0.3f);
    for (int i = 0; i <= 6; i++) { // 6 вершин + первая точка замыкает фигуру
        float angle = i * PI / 3.0f;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }

    glEnd();
}

int main() {
    if (!glfwInit()) {
        printf("Ошибка инициализации GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(500, 500, "Шестиугольник", NULL, NULL);
    if (!window) {
        printf("Ошибка создания окна\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        printf("Ошибка инициализации GLEW\n");
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        drawHexagon(); // Рисуем шестиугольник

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
