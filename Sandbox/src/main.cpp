#include <Tomato/Application.h>
#include <Tomato/EntryPoint.h>

class Sandbox : public TM::Application
{ };

TM::Application* TM::CreateApplication()
{
  return new Sandbox {};
}
