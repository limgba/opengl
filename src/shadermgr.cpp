#include "shader.h"
#include "shadermgr.h"

ShaderMgr::ShaderMgr()
{
}

ShaderMgr::~ShaderMgr()
{
}

void ShaderMgr::DeleteShader()
{
	for (auto& shader : m_shader_vec)
	{
		if (nullptr == shader)
		{
			continue;
		}
		delete shader;
		shader = nullptr;
	}
}

ShaderMgr& ShaderMgr::Instance()
{
	static ShaderMgr instance;
	return instance;
}

void ShaderMgr::SetPath(const std::string& path)
{
	m_path = path;
}

bool ShaderMgr::CreateShader(const std::string& shader_file_name)
{
	std::string vs = m_path + shader_file_name + ".vs";
	std::string fs = m_path + shader_file_name + ".fs";
	Shader* shader = new Shader(vs.c_str(), fs.c_str());
	m_shader_vec.push_back(shader);
	return true;
}

const std::vector<Shader*>& ShaderMgr::GetShaderVec()
{
	return m_shader_vec;
}

