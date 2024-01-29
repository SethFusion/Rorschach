#pragma once

#ifdef RSC_PLATFORM_WINDOWS

extern Rorschach::Application* Rorschach::CreateApplication();

int main(int argc, char** argv)
{
	Rorschach::Log::Init();
	RSC_CORE_WARN("Initialized Log!");
	int a = 5;
	RSC_CORE_INFO("Information! var={0}", a);
	auto app = Rorschach::CreateApplication();
	app->Run();
	delete app;
}

#endif