#pragma once

#include "RendererAPI.h"

namespace Crimson {

	class RenderCommand
	{
	public:

		inline static void Clear()
		{
			s_RendererAPI->Clear();
		}
		inline static void SetClearColor(const crm::vec4& color)
		{
			s_RendererAPI->SetClearColor(color);
		}


		inline static void DrawIndexed(const Ref<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}

	private:
		static Scope<RendererAPI> s_RendererAPI;
	};

}