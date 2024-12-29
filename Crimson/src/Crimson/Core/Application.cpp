#include "cnpch.h"
#include "Application.h"
#include "Input.h"

#include "Crimson/Events/ApplicationEvent.h"
#include "Crimson/Events/KeyEvent.h"
#include "Crimson/Events/MouseEvent.h"
#include "Subsystems.h"

#include "Crimson/Renderer/Renderer.h"

#include "Crimson/Core/TimeStep.h"

#include "Crimson/Renderer/OrthographicCamera.h"

#include <GLFW/glfw3.h>

namespace Crimson {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;



	Application::Application()
	{
		CN_CORE_ASSERT(s_Instance == nullptr, "Already Created Application!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		Renderer::Init();


		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

	}

	Application::~Application()
	{
		m_Window.reset();
		Renderer::Shutdown();
		Subsystems::ShutDownGL();
	} 

	void Application::Run()
	{
		while (m_Running) {

			float time = (float)glfwGetTime(); // platform::gettime()
			m_TimeStep = time - m_PreviousFrameTime;
			m_PreviousFrameTime = time;

			if (!m_Minimized)
			{

				// we can use range based for loop because we implimented begin and end
				for (const auto& layer : m_LayerStack)
				{
					layer->OnUpdate(m_TimeStep);
				}

			}

			m_ImGuiLayer->Begin();
			for (const auto& layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		// even though we dispatch starting from top layer, on windows closed we dont check other layers
		// we simply terminate
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));
		
		//CN_CORE_TRACE(e.ToString());

		// going backwards since if an overlay with some button handles event
		// we are done, we dont propogate
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			// we need to decrement first since it points one past pos
			(*(--it))->OnEvent(e);
			if (e.GetHandled())
				break;
		}


	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0){
			m_Minimized = true;
			return false;
		}

		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
		m_Minimized = false;
		return false;
	}

}