
#include "Rorschach.h"

class Sandbox : public Rorschach::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Rorschach::Application* Rorschach::CreateApplication()
{
	return new Sandbox();
}