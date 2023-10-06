#include <iostream>
#include "Base.h"
#include "Vehicles.h"

using namespace std;

int main() {

	Vehicle car(12.3, 56.2);

	car.arrive();

	cout << "Car tank volume: " << car.getTankVolume() << endl;

	cout << "Car fuel level after arrive: " << car.getPetrolAmount() << endl;

	Bus bus(10, 40, 63.1, 150);

	bus.arrive();

	cout << "\nBus tank volume: " << bus.getTankVolume() << endl;
	cout << "Bus max people: " << bus.getMaxPeople() << endl;
	cout << "Bus fuel level after arrive: " << bus.getPetrolAmount() << endl;
	cout << "Bus current people: " << bus.getPeopleCount() << endl;

	if ( !bus.leave() ) cout << "\nBus hasn't left.\n";
	else {
		cout << "\nBus fuel level after leave: " << bus.getPetrolAmount() << endl;
		cout << "Bus current people: " << bus.getPeopleCount() << endl;
	}

	Truck truck(3, 10, 125, 300);

	if ( !car.leave() ) cout << "\nCar hasn't left.\n";
	else cout << "\nCar fuel level after leave: " << car.getPetrolAmount() << endl;

	truck.arrive();

	cout << "\nTruck tank volume: " << truck.getTankVolume() << endl;
	cout << "Truck max load: " << truck.getMaxLoad() << endl;
	cout << "Truck fuel level after arrive: " << truck.getPetrolAmount() << endl;
	cout << "Truck current load: " << truck.getCurrentLoad() << endl;

	if ( !truck.leave() ) cout << "\nTruck hasn't left.\n";
	else {
		cout << "\nTruck fuel level after leave: " << truck.getPetrolAmount() << endl;
		cout << "Truck current load: " << truck.getCurrentLoad() << endl;
	}

	return 0;
}