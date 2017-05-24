#include <libnotifymm.h>
#include <ctime>
class Warnmsg{
public:
	Warnmsg();
	virtual ~Warnmsg();

	void wait(unsigned milliseconds);
	void show_open_warn();
	
	Notify::Notification Warning;
	
};