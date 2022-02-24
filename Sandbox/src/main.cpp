#include <Tomato/Application.h>
#include <Tomato/EntryPoint.h>

class sandbox : public tmt::application
{ };

tmt::application* tmt::create_application() { return new sandbox {}; }
