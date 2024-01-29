#pragma once
#include "Core.h"

namespace Rorschach
{
	class RORSCHACH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Defined in client
	Application* CreateApplication();
}


