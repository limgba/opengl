#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

extern std::string g_path;
extern float g_mix_value;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
