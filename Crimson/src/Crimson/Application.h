#pragma once

#include "cnpch.h"

#include "Crimson/LayerStack.h"
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace Crimson {

	/*
	    @brief will be a singleton, since we will only have one application for the programs lifetime
	    being one Crimson Engine application
	*/
	class CRIMSON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:

		bool OnWindowClosed(WindowCloseEvent& e);

		bool m_Running = true;
		std::unique_ptr<Window> m_Window;

		LayerStack m_LayerStack;
	};


	// to be defined in client
	Application* CreateApplication();


}
