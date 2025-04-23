#ifndef CONTROL_H
#define CONTROL_H
#include "Restaurant.h"
#include "View.h"
class Control
{
	public:
		Control();
		~Control();
		void launch();
		void initTables(Restaurant* r);
		void initReservations(Restaurant* r);
	private:
		Restaurant* restaurant;
		View* view;
};

#endif
