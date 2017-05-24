#include <gtkmm.h>
#include "warnmsg.h"
#include "superclient.h"
class MainWindow : public Gtk::Window {
private:
	double m_temp=6, f_temp= -7;
public:
	MainWindow();
	virtual ~MainWindow();
protected:
	void on_button_quit();
	void button_swiched();
	void adjustment_t_value_changed();
	void adjustment_d_value_changed();
	void warning_massage();
	Gtk::Box Box_Main, Box_Top;
	Gtk::Box Box_Scales, Box_Scale_t, Box_Scale_d;
	Gtk::Box Box_Switch;
	Glib::RefPtr<Gtk::Adjustment> adjustment_t, adjustment_d;
	Gtk::Scale VScale_t, VScale_d;
	Gtk::Button Button_Quit;
	Gtk::Switch Button_On_Off;
	Gtk::Switch Button_Open;
	Gtk::Separator separator_one;
	Gtk::Separator separator_two;
	Warnmsg msg;
	SuperClient s;
};