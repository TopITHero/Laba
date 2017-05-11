#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
	MainWindow();
	virtual ~MainWindow();
public:
	void on_button_quit();
	void button_swiched();
	void adjustment1_value_changed();
	void adjustment2_value_changed();
	Gtk::Box Box_Main, Box_Top,Box_Scales, Box_Scale_t, Box_Scale_d;
	Glib::RefPtr<Gtk::Adjustment> adjustment_t, adjustment_d;
	Gtk::Scale VScale_t, VScale_d;
	Gtk::Button Button_Quit;
	Gtk::Switch Button_On_Off;
};