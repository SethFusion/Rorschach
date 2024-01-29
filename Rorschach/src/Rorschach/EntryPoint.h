#pragma once

#ifdef RSC_PLATFORM_WINDOWS

extern Rorschach::Application* Rorschach::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Rorschach::CreateApplication();
	app->Run();
	delete app;
}

#endif