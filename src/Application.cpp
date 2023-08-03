#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <assert.h>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture.h"

struct ShaderStruct {
    std::string vectorSource;
    std::string fragmentSource;
};

static std::string ParseFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    std::string data;

    while (std::getline(file, line)) {
        data.append(line + "\n");
    }

    return data;
}

static uint32_t CompileShader(uint32_t type, const std::string& source) {
    if (source.empty()) {
        std::cout << "String object null";
    }

    uint32_t id = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    // Error handling
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = (char*) malloc(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile shader" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
    }

    return id;
}

static int CreateShader(const std::string &vertexShader, const std::string &fragmantShader) {
    uint32_t program = glCreateProgram();
    uint32_t vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    uint32_t fs = CompileShader(GL_FRAGMENT_SHADER, fragmantShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);
    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Black Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glewInit();

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    if (glewInit() != GLEW_OK) {
        std::cout << "Error";
    }
    float positions[6] = {
       -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };

    VertexBuffer vb(positions, 6 * sizeof(float));
    Renderer renderer;
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    std::string vertexShader = ParseFile("res/shaders/Vertex.shader");
    std::string fragmentShader = ParseFile("res/shaders/Fragment.shader");

    uint32_t shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);

    Texture texure("res/textures/logo.png");
    texture.Bind()

    int location = glGetUniformLocation(shader, "u_Color");
    float r = 0.0f;
    float increment = 0.05f;

    

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        renderer.draw(location);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}