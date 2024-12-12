#pragma once

#ifdef RD_PLATFORM_WINDOWS

// Creates an extern to SandboxApp.cpp when the Platform is Windows 
extern Rend::Application* Rend::CreateApplication();

int main(int argc, char** argv) 
{
	printf("Penis");
	auto app = Rend::CreateApplication();
	app->Run();
	delete app;
}

#endif