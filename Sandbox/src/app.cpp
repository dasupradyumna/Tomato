#include <Engine.h>

class Sandbox : public TM::Application
{
public:
  Sandbox() {}
  ~Sandbox() {}
};

TM::Application *TM::CreateApplication()
{
  return new Sandbox{};
}
