#pragma once

#ifdef RD_PLATFORM_WINDOWS

// Creates an extern to SandboxApp.cpp when the Platform is Windows 
extern Rend::Application* Rend::CreateApplication();

int main(int argc, char** argv) 
{
	Rend::Log::Init();
	RD_INFO("PENIS");
	RD_CORE_WARN("Log Initialized!");
	int a = 5;
	RD_INFO("Hello! Var={0}",a);


	auto app = Rend::CreateApplication();
	app->Run();
	delete app;
}

#endif