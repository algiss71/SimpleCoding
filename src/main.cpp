#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
int main(void)
{
    //GLFWwindow* pwindow;

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "glfwInit feiled!" << std::endl;
        return -1;
    }

    /*Îïöèè OpenGL*/

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pWindow = glfwCreateWindow(640, 480, "Battle City", nullptr, nullptr);
        if (!pWindow)
    {
        std::cout << "glfwCreateWindow feiled!" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);
    if (!gladLoadGL())
    {
        std::cout << "" << std::endl;
        return -1;
    }

    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    //std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;

    glClearColor(0, 1, 0, 1);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}