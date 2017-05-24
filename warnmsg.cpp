#include "warnmsg.h"
Warnmsg::Warnmsg():Warning("Fridge", "Hey, bro, fridge is open!!! You must close it!!!", "dialog-information"){
	Notify::init("Hello world!");
}
Warnmsg::~Warnmsg(){}

void Warnmsg::show_open_warn(){
	Warning.show();
}



