#include "cnpch.h"

#include "OpenGLShader.h"

#include <Glad/glad.h>



namespace Crimson {


	OpenGLShader::OpenGLShader(const std::string& filepath)
		: m_UniformCache()
	{

		// Read vertexFile and fragmentFile 
		ShaderProgramSource shaderCode = get_file_contents(filepath);


		// Convert the shader source strings into character arrays
		const char* vertexSource = shaderCode.VertexSource.c_str();
		const char* fragmentSource = shaderCode.FragmentSource.c_str();


		// Create Vertex Shader Object and get its reference
		uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
		// Attach Vertex Shader source to the Vertex Shader Object
		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		// Compile the Vertex Shader into machine code
		glCompileShader(vertexShader);
		compileErrors(vertexShader, "Vertex");

		// Create Fragment Shader Object and get its reference
		uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		// Attach Fragment Shader source to the Fragment Shader Object
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		// Compile the Vertex Shader into machine code
		glCompileShader(fragmentShader);
		compileErrors(fragmentShader, "Fragment");

		// Create Shader Program Object and get its reference
		m_RendererID = glCreateProgram();

		// Attach the Vertex and Fragment Shaders to the Shader Program
		glAttachShader(m_RendererID, vertexShader);
		glAttachShader(m_RendererID, fragmentShader);

		glLinkProgram(m_RendererID);

		// checking for link errors
		compileErrors(m_RendererID, "Program");

		glValidateProgram(m_RendererID);


		// Delete the now useless Vertex and Fragment Shader objects
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	// Reads a text file and outputs a string with everything in the text file
	ShaderProgramSource OpenGLShader::get_file_contents(const std::string& filename)
	{
		std::ifstream in(filename.c_str(), std::ios::binary);

		if (!in) {
			CN_CORE_ERROR("Failed to open filename: {0}", filename);
		}

		enum class ShaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		// 1 for vert and 1 for frag
		std::stringstream ss[2];

		ShaderType type = ShaderType::NONE;



		std::string line;


		while (getline(in, line))
		{

			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
				{

					type = ShaderType::VERTEX;
				}
				else if (line.find("fragment") != std::string::npos)
				{

					type = ShaderType::FRAGMENT;

				}
			}

			else {
				ss[(int)type] << line << "\n";
			}
		}

		return { ss[0].str() , ss[1].str() };

	}



	// Checks if the different Shaders have compiled properly
	void OpenGLShader::compileErrors(unsigned int shader, const std::string& type)
	{
		// Stores status of compilation
		int hasCompiled;

		// status of linking
		int hasLinked;

		// Character array to store error message in
		char infoLog[1024];
		if (type != "Program")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
			if (hasCompiled == GL_FALSE)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				CN_CORE_ERROR("Shader Compilation Error for {0}: {1}", type, infoLog)
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &hasLinked);
			if (hasLinked == GL_FALSE)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				CN_CORE_ERROR("Shader Linking Error for {0}: {1}", type, infoLog)
			}
		}
	}

	int OpenGLShader::GetUniform(const std::string& name)
	{
		if (m_UniformCache.find(name) != m_UniformCache.end())
			return m_UniformCache[name];

		int loc = glGetUniformLocation(m_RendererID, name.c_str());
		if (loc == -1)
			CN_CORE_ERROR("Uniform ( {0} ) does not exist!", name)
		else
			m_UniformCache[name] = loc;

		return loc;
	}

	void OpenGLShader::UploadUniformInt(const std::string& name, int value)
	{
		glUniform1i(GetUniform(name), value);
	}

	void OpenGLShader::UploadUniformMat4(const std::string& name, const crm::mat4& matrix)
	{
		glUniformMatrix4fv(GetUniform(name), 1, GL_FALSE, matrix.data);
	}

	void OpenGLShader::UploadUniformMat3(const std::string& name, const crm::mat3& matrix)
	{
		glUniformMatrix3fv(GetUniform(name), 1, GL_FALSE, matrix.data);
	}

	void OpenGLShader::UploadUniformFloat(const std::string& name, float value) 
	{
		glUniform1f(GetUniform(name), value);
	}

	void OpenGLShader::UploadUniformFloat2(const std::string& name, const crm::vec2& v) 
	{
		glUniform2f(GetUniform(name),v.x, v.y);
	}

	void OpenGLShader::UploadUniformFloat3(const std::string& name, const crm::vec3& v) 
	{
		glUniform3f(GetUniform(name), v.x, v.y, v.z);
	}

	void OpenGLShader::UploadUniformFloat4(const std::string& name, const crm::vec4& vec)
	{
		glUniform4f(GetUniform(name), vec.x, vec.y, vec.z, vec.w);
	}
}