#include "ParkingSpot.hpp"

ParkingSpot::ParkingSpot() {
    this->spotId = "";
    this->spotType = ParkingLot::SpotType::REGULAR;
    this->floor = 1;
    this->status = ParkingLot::SpotStatus::AVAILABLE;
    this->parkedVehicleLicense = "";
}

ParkingSpot::ParkingSpot(const string& spotId, const ParkingLot::SpotType& spotType, const int floor, const ParkingLot::SpotStatus status) {
    this->spotId = spotId;
    this->spotType = spotType;
    this->floor = floor;
    this->status = status;
    this->parkedVehicleLicense = "";
}

string ParkingSpot::getSpotId() const {
    return this->spotId;
}

ParkingLot::SpotType ParkingSpot::getSpotType() const {
    return this->spotType;
}

int ParkingSpot::getFloor() const {
    return this->floor;
}

ParkingLot::SpotStatus ParkingSpot::getStatus() const {
    return this->status;
}

string ParkingSpot::getParkedVehicleLicense() const {
    return this->parkedVehicleLicense;
}

void ParkingSpot::setSpotId(const string& spotId) {
    this->spotId = spotId;
}

void ParkingSpot::setSpotType(const ParkingLot::SpotType& spotType) {
    this->spotType = spotType;
}

void ParkingSpot::setFloor(const int floor) {
    this->floor = floor;
}

void ParkingSpot::setStatus(const ParkingLot::SpotStatus& status) {
    this->status = status;
}

void ParkingSpot::setParkedVehicleLicense(const string& parkedVehicleLicense) {
    this->parkedVehicleLicense = parkedVehicleLicense;
}

bool ParkingSpot::isAvailable() const {
    return this->status == ParkingLot::SpotStatus::AVAILABLE;
}

void ParkingSpot::parkVehicle(const string& licensePlate) {
    this->parkedVehicleLicense = licensePlate;
    this->status = ParkingLot::SpotStatus::OCCUPIED;
}

void ParkingSpot::removeVehicle() {
    this->parkedVehicleLicense = "";
    this->status = ParkingLot::SpotStatus::AVAILABLE;
}