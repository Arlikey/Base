#include "Base.h"

class Vehicle {
	double petrolAmount;
	double tankVolume;
public:
	Vehicle(double petrol_amount, double tank_volume) : petrolAmount(petrol_amount), tankVolume(tank_volume) {}
	double getTankVolume() {
		return tankVolume;
	}
	double getPetrolAmount() {
		return petrolAmount;
	}
	void arrive() {
		Base::people_on_base++;
		Base::vehicles_on_base++;
	}
	bool leave() {
		if (Base::people_on_base <= 0 || Base::petrol_on_base - (tankVolume - petrolAmount) < 0) {
			return false;
		}
		Base::people_on_base--;
		Base::vehicles_on_base--;
		Base::petrol_on_base -= tankVolume - petrolAmount;
		petrolAmount += tankVolume - petrolAmount;
		return true;
	}
};

class Bus : public Vehicle {
	int currentPeople;
	int maxPeople;
public:
	Bus(int people, int max_people, double petrol, double max_petrol) : Vehicle(petrol, max_petrol), currentPeople(people), maxPeople(max_people) {}
	int getPeopleCount() {
		return currentPeople;
	}
	int getMaxPeople() {
		return maxPeople;
	}
	void arrive() {
		Vehicle::arrive();
		Base::people_on_base += currentPeople;
		currentPeople = 0;
	}
	bool leave() {
		if ( !Vehicle::leave() ) return false;
		if (maxPeople - Base::people_on_base <= 0) {
			currentPeople += maxPeople;
		} else {
			currentPeople += Base::people_on_base;
		}
		Base::people_on_base -= currentPeople;
		return true;
	}
};

class Truck : public Vehicle {
	double currentLoad;
	double maxLoad;
public:
	Truck(double load, double max_load, double petrol, double max_petrol) : Vehicle(petrol, max_petrol), currentLoad(load), maxLoad(max_load) {}
	double getCurrentLoad() {
		return currentLoad;
	}
	double getMaxLoad() {
		return maxLoad;
	}
	void arrive() {
		Vehicle::arrive();
		Base::goods_on_base += currentLoad;
		currentLoad = 0;
	}
	bool leave() {
		if ( !Vehicle::leave() ) return false;;
		if (maxLoad - Base::goods_on_base <= 0) {
			currentLoad += maxLoad;
		}
		else {
			currentLoad += Base::goods_on_base;
		}
		Base::goods_on_base -= currentLoad;
		return true;
	}
};