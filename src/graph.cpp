#include "graph.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shadermgr.h"
#include "shader.h"


std::string shaderPath = "../shader/";
std::string vertexShaderSourceStr;
std::string fragmentShaderSourceStr;
unsigned int vertexShader = 0;
unsigned int fragmentShader = 0;
unsigned int VBO = 0;
unsigned int VAO = 0;
char infoLog[512];


bool InitShader()
{
    ShaderMgr::Instance().SetPath("../shader/");
	return ShaderMgr::Instance().CreateShader("3.3.shader");
}

void DeleteShader()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
    ShaderMgr::Instance().DeleteShader();
}

void UpdateGraph()
{
	float vertices[] = {
		// 位置              // 颜色
		 0.5f, -0.5f, 0.0f,  
		 1.0f, 0.0f, 0.0f,   // 右下

		-0.5f, -0.5f, 0.0f,  
		0.0f, 1.0f, 0.0f,   // 左下

		 0.0f,  0.5f, 0.0f,  
		 0.0f, 0.0f, 1.0f    // 顶部
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// 位置属性
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// 颜色属性
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}

void RenderGraph()
{
	// draw our first triangle
	const std::vector<Shader*>& shader_vec = ShaderMgr::Instance().GetShaderVec();
	for (const Shader* shader : shader_vec)
	{
		if (nullptr == shader)
		{
			continue;
		}
		shader->use();
	}
	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

