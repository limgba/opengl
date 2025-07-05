#include "head.h"

#define IS_INSIDE_DEBUG

#ifdef IS_INSIDE_DEBUG
std::string g_path("../");
#else
std::string g_path("../../");
#endif

float g_mix_value = 0.2;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    static int keys[] = {
        GLFW_KEY_ESCAPE,
        GLFW_KEY_UP,
        GLFW_KEY_DOWN,
    };
    for (const auto& key : keys)
    {
        int key_status = glfwGetKey(window, key);
        if (GLFW_PRESS != key_status)
        {
            continue;
        }
        switch (key)
        {
        case GLFW_KEY_ESCAPE:
        {
            glfwSetWindowShouldClose(window, true);
        }
        break;
        case GLFW_KEY_UP:
        {
            g_mix_value += 0.001f;
            if (g_mix_value > 1.0f)
            {
                g_mix_value = 1.0f;
            }
        }
        break;
        case GLFW_KEY_DOWN:
        {
            g_mix_value -= 0.001f;
            if (g_mix_value < 0.0f)
            {
                g_mix_value = 0.0f;
            }
        }
        break;
        }
    }
}
