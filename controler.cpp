#include "controler.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow():Box_Top(Gtk::ORIENTATION_VERTICAL),
	Box_Main(Gtk::ORIENTATION_VERTICAL),
	Box_Scales(Gtk::ORIENTATION_VERTICAL),
	Box_Scale_t(),
	Box_Scale_d(),
	Button_Quit("Quit"),
	Button_On_Off(),
	adjustment_t(Gtk::Adjustment::create(0,0,10,1)),
	adjustment_d(Gtk::Adjustment::create(0,-10,0,1)),
	VScale_t(adjustment_t, Gtk::ORIENTATION_HORIZONTAL),
	VScale_d(adjustment_d, Gtk::ORIENTATION_HORIZONTAL)

{
	set_default_size(300,200);
	VScale_t.set_value_pos(Gtk::POS_TOP);
	VScale_t.set_draw_value();

	VScale_d.set_value_pos(Gtk::POS_TOP);
	VScale_d.set_draw_value();

	set_title("Super program");
	
	set_border_width(10);
	add(Box_Main);
	Box_Main.pack_start(Box_Top);

	Box_Top.pack_start(Box_Scale_t);
	Box_Scale_t.pack_start(*Gtk::manage(new Gtk::Label("Main Camera",0)),Gtk::PACK_SHRINK);

	Box_Top.pack_start(Box_Scale_d);
	Box_Scale_d.pack_start(*Gtk::manage(new Gtk::Label("Cold Camera",0)),Gtk::PACK_SHRINK);

	VScale_t.set_digits(0);
	adjustment_t->signal_value_changed().connect(sigc::mem_fun(*this, &MainWindow::adjustment1_value_changed));
	Box_Scale_t.pack_start(VScale_t);

	VScale_d.set_digits(0);
	adjustment_d->signal_value_changed().connect(sigc::mem_fun(*this, &MainWindow::adjustment2_value_changed));
	Box_Scale_d.pack_start(VScale_d);

	Button_On_Off.property_active().signal_changed().connect(sigc::mem_fun(*this, &MainWindow::button_swiched));
	Box_Main.pack_start(Button_On_Off);

	Button_Quit.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::on_button_quit));
	Box_Main.pack_start(Button_Quit);

	show_all_children();
}
MainWindow::~MainWindow(){}
void MainWindow::on_button_quit(){
	cout << "Quit" << endl;
	hide();
}	
void MainWindow::button_swiched(){
	if (Button_On_Off.get_active()){
		cout << "ON" << endl;
	}else {
		cout << "Off" << endl;
	}
}
void MainWindow::adjustment1_value_changed(){
	const double number = adjustment_t->get_value();
	cout << "Temperature changed to: "<< number << endl;
}
void MainWindow::adjustment2_value_changed(){
	const double number = adjustment_d->get_value();
	cout << "Temperature changed to: "<< number << endl;
}