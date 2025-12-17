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

    // Simulate exit after 2 hours (120 minutes)
    // Entry was 1000, so Exit is 1000 + (120 * 60) if time is seconds? 
    // The problem doesn't specify units, but getDurationInMinutes implies we need to be consistent.
    // Let's assume timestamps are in minutes for simplicity or seconds.
    // If getDurationInMinutes does (exit - entry), then units matter.
    // Let's assume the inputs are in minutes for this demo.
    long exitTime = entryTime + 125; // 2 hours 5 minutes later
    if (manager.exitVehicle(vehicle.getLicensePlate(), exitTime)) {
        cout << "Successfully processed exit for vehicle " << vehicle.getLicensePlate() << endl;
    }

    return 0;
}