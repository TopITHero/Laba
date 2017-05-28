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
	set_default_size(300,250);
	VScale_t.set_value_pos(Gtk::POS_TOP);
	VScale_t.set_value(6);
	VScale_t.set_draw_value();

	VScale_d.set_value_pos(Gtk::POS_TOP);
	VScale_d.set_value(-7);
	VScale_d.set_draw_value();

	Button_On_Off.set_active();

	set_title("Super program");
	Box_Main.set_border_width(10);
	add(Box_Main);
	Box_Main.pack_start(Box_Top);

	Box_Top.pack_start(Box_Scale_t);
	Box_Scale_t.pack_start(*Gtk::manage(new Gtk::Label("Main Camera",0)),Gtk::PACK_SHRINK);

	Box_Top.pack_start(Box_Scale_d);
	Box_Scale_d.pack_start(*Gtk::manage(new Gtk::Label("Freezer        ",0)),Gtk::PACK_SHRINK);

	VScale_t.set_digits(0);
	adjustment_t->signal_value_changed().connect(sigc::mem_fun(*this, &MainWindow::adjustment_t_value_changed));
	Box_Scale_t.pack_start(VScale_t);

	VScale_d.set_digits(0);
	adjustment_d->signal_value_changed().connect(sigc::mem_fun(*this, &MainWindow::adjustment_d_value_changed));
	Box_Scale_d.pack_start(VScale_d);

	Box_Main.pack_start(separator_one,Gtk::PACK_SHRINK);
	Box_Switch.set_border_width(10);
	Box_Main.pack_start(Box_Switch);

	Button_On_Off.property_active().signal_changed().connect(sigc::mem_fun(*this, &MainWindow::button_swiched));
	Button_Open.property_active().signal_changed().connect(sigc::mem_fun(*this, &MainWindow::warning_massage));
	Box_Switch.pack_start(*Gtk::manage(new Gtk::Label("ON/OFF",0)),Gtk::PACK_SHRINK);
	Box_Switch.pack_start(Button_On_Off);
	Box_Switch.pack_start(Button_Open);

	Box_Main.pack_start(separator_two,Gtk::PACK_SHRINK);

	Button_Quit.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::on_button_quit));
	Button_Quit.set_border_width(10);
	Box_Main.pack_start(Button_Quit);

	show_all_children();
}
MainWindow::~MainWindow(){}
void MainWindow::on_button_quit(){
	cout << "Quit" << endl;
	hide();
}	
void MainWindow::button_swiched(){
	char on[10] = "S@ON@";
	char off[10] = "S@OFF@";
	if (Button_On_Off.get_active()){
		adjustment_t->set_value(this->m_temp);
		adjustment_d->set_value(this->f_temp);
		s.talking(on);
	}else {
		this->m_temp = adjustment_t->get_value();
		this->f_temp = adjustment_d->get_value();
		adjustment_t->set_value(0);
		adjustment_d->set_value(0);
		s.talking(off);
	}
}
void MainWindow::adjustment_t_value_changed(){
	char m_msg_arr[] = "M@";
	char temp_arr[10];
	char endmsg[] = "@";
	char* send_arr = new char[strlen(m_msg_arr)+strlen(temp_arr)+1];
	double number;
	number = adjustment_t->get_value();
	strcpy(send_arr,m_msg_arr);
	sprintf(temp_arr, "%2.2f", number);
	strcat(send_arr,temp_arr);
	strcat(send_arr,endmsg);
	s.talking(send_arr);
	delete[] send_arr;
}
void MainWindow::adjustment_d_value_changed(){
	char f_msg_arr[] = "F@";
	char temp_arr[10];
	char endmsg[] = "@";
	char* send_arr = new char[strlen(f_msg_arr)+strlen(temp_arr)+1];
	double number;
	number = adjustment_d->get_value();
	strcpy(send_arr,f_msg_arr);
	sprintf(temp_arr, "%2.2f", number);	
	strcat(send_arr,temp_arr);
	strcat(send_arr,endmsg);
	s.talking(send_arr);
	delete[] send_arr;
}
void MainWindow::warning_massage(){
	double secs;
    clock_t begin = clock();
    clock_t end;
	if(Button_Open.get_active()){
		while(secs < 5){
	  		end = clock();
	  		secs = double(end - begin) / CLOCKS_PER_SEC;
	  		if(!Button_Open.get_active()){
					break;
			} 
	  	}
	  	if(Button_Open.get_active()){
	  		msg.show_open_warn();
	  	}
		
	}
}
