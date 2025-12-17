#include "Vehicle.hpp"

// Default Constructor
Vehicle::Vehicle() {
    this->licensePlate = "";
    this->vehicleType = ParkingLot::VehicleType::CAR; // Placeholder default
    this->ownerName = "";
}

// Parameterized Constructor
Vehicle::Vehicle(const string& licensePlate, const ParkingLot::VehicleType& vehicleType, const string& ownerName) {
    this->licensePlate = licensePlate;
    this->vehicleType = vehicleType;
    this->ownerName = ownerName;
}

// Getters
string Vehicle::getLicensePlate() const {
    return this->licensePlate;
}

ParkingLot::VehicleType Vehicle::getVehicleType() const {
    return this->vehicleType;
}

string Vehicle::getOwnerName() const {
    return this->ownerName;
}

// Setters
void Vehicle::setLicensePlate(const string& licensePlate) {
    this->licensePlate = licensePlate;
}

void Vehicle::setVehicleType(const ParkingLot::VehicleType& vehicleType) {
    this->vehicleType = vehicleType;
}

void Vehicle::setOwnerName(const string& ownerName) {
    this->ownerName = ownerName;
}