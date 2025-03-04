#include <cstdio>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#define GLEW_DLL
#define GLFW_DLL


int main()
{
    glfwInit();
    // printf("Hello World!\n");

    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW. \n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;
    window = glfwCreateWindow(512, 512, "window", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (GLEW_OK != ret) {
        fprintf(stderr, "ERROR: %s\n", glewGetErrorString(ret));
        return 1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.5, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9, 0.0, 0.0);
        glVertex2f(0.0, 1.0);
        glColor3f(1.0, 0.5, 0.0);
        glVertex2f(1, -0.5);
        glColor3f(1.0, 0.5, 1.0);
        glVertex2f(1, 0);
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();


}
