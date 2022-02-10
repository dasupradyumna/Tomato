#include <Engine.h>

class Sandbox : public TM::Application
{
};

TM::Application *TM::CreateApplication()
{
  return new Sandbox{};
}
