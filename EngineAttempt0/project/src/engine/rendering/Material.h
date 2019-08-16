#pragma once
#include "pch.h"
#include "Shader.h"

class Material
{
	public:
	Material(ShaderProgram shader)
	{
		mShader = shader;
	}

	Material()
	{
	
	}

	inline ShaderProgram* GetShader()
	{
		return &mShader;
	}

	void ChangeShader(ShaderProgram otherShader)
	{
		mShader = otherShader;
	}

	virtual void ApplyShaderParameters()
	{
		
	}

	void SubmitMVP(mat4 model, mat4 view, mat4 projection)
	{
		mShader.SetMat4f("model", model);
		mShader.SetMat4f("view", view);
		mShader.SetMat4f("projection", projection);
	}

	void Bind()
	{
		mShader.RunProgram();
	}

	protected:
	ShaderProgram mShader;
};