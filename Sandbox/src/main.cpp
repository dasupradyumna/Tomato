#include <Tomato/Application.hpp>
#include <Tomato/EntryPoint.hpp>

class sandbox : public tmt::application { };

tmt::application *tmt::create_application() { return new sandbox {}; }
