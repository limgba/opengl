#pragma once
#include <string>
#include <vector>

class Shader;

class ShaderMgr
{
public:
	ShaderMgr();
	~ShaderMgr();
	void DeleteShader();
	static ShaderMgr& Instance();
	void SetPath(const std::string& path);
	bool CreateShader(const std::string& shader_file_name);
	const std::vector<Shader*>& GetShaderVec();

private:
	std::string m_path;
	std::vector<Shader*> m_shader_vec;
};
