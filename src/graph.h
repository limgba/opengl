#pragma once
#include <string>

extern std::string shaderPath;
extern std::string vertexShaderSourceStr;
extern std::string fragmentShaderSourceStr;

extern unsigned int vertexShader;
extern unsigned int fragmentShader;
extern unsigned int shaderProgram;
extern unsigned int VBO;
extern unsigned int VAO;
extern unsigned int EBO;
extern char infoLog[512];

bool InitShader();
void DeleteShader();
void UpdateGraph();
void RenderGraph();

