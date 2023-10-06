#pragma once
class Base {
public:
	static int people_on_base;
	static int vehicles_on_base;
	static double petrol_on_base;
	static double goods_on_base;
};

int Base::people_on_base = 1;
int Base::vehicles_on_base = 0;
double Base::petrol_on_base = 100;
double Base::goods_on_base = 10;