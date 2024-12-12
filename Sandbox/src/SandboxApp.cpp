#include <Rend.h>

class Sandbox : public Rend::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}


};

Rend::Application* Rend::CreateApplication()
{
	return new Sandbox();
}