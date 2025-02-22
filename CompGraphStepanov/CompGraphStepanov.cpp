#define GLWF
#define GLEW

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

void drawHexagon() {
    float radius = 0.5;

    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.4, 1.0, 0.4);
    glVertex2f(0.0, 0.0);

    for (int i = 0; i <= 6; i++) {
        float angle = i * PI / 3.0;
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
        glClearColor(1.0, 0.2, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        drawHexagon(); 

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
