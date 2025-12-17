#include <iostream>
#include "ParkingLotManagerInMemImpl.hpp"

using namespace std;

int main() {
    cout << "Parking Lot Management System C++" << endl;
    cout << "This is a demonstration runner for the parking lot system." << endl;
    cout << "Run the call tests to validate the implementation." << endl;

    // Instantiate the manager
    ParkingLotManagerInMemImpl manager;

    // Create a sample parking spot
    ParkingSpot spot("A1", ParkingLot::SpotType::COMPACT, 1);
    if (manager.addParkingSpot(spot)) {
        cout << "Successfully added parking spot A1" << endl;
    }

    // Create a sample vehicle
    Vehicle vehicle("ABC123", ParkingLot::VehicleType::MOTORCYCLE, "John Doe");

    // Park the vehicle
    long entryTime = 1000;
    auto ticket = manager.parkVehicle(vehicle, entryTime);

    if (ticket) {
        cout << "Successfully parked vehicle " << ticket->getLicensePlate()
                  << " in spot " << ticket->getSpotId() << endl;
    }

    return 0;
}