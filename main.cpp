#include <gtkmm/application.h>
#include "controler.h"

int main(int argc , char* argv[]){
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	MainWindow window;
	return app->run(window);

}