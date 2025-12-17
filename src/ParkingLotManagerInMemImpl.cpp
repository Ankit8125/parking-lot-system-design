#include "ParkingLotManagerInMemImpl.hpp"
#include <random>
#include <sstream>
#include <algorithm>
#include <unordered_map>

ParkingLotManagerInMemImpl::ParkingLotManagerInMemImpl() {
    // Initialize empty maps

}

string ParkingLotManagerInMemImpl::generateTicketId() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(100000, 999999);

    stringstream ss;
    ss << "TICKET_" << dis(gen);
    return ss.str();
}
/**
 * ParkingLot
 * VehicleType: MOTORCYCLE, CAR, TRUCK
 * SpotType: COMPACT, REGULAR, LARGE
 * SpotStatus: AVAILABLE, OCCUPIED
 */

/**
 * ParkingSpot
 * getSpotId, getSpotType, getFloor, getStatus, getParkedVehicleLicense
 * setSpotId, setSpotType, setFloor, setStatus, setParkedVehicleLicense
 * isAvailable, parkVehicle, removeVehicle 
 */

/**
 * ParkingTicket
 * getTicketId, getLicensePlate, getSpotId, getEntryTime, getExitTime
 * setTicketId, setLicensePlate, setSpotId, setEntryTime, setExitTime
 * getDurationInMinutes
 */

/**
 * Vehicle
 * getLicensePlate, getVehicleType, getOwnerName
 * setLicensePlate, setVehicleType, setOwnerName
 */
bool ParkingLotManagerInMemImpl::isCompatible(const ParkingLot::VehicleType &vehicleType, const ParkingLot::SpotType &spotType) {
    if(vehicleType == ParkingLot::VehicleType::MOTORCYCLE){
        if(spotType == ParkingLot::SpotType::COMPACT || spotType == ParkingLot::SpotType::REGULAR || spotType == ParkingLot::SpotType::LARGE) return true;
    }
    else if(vehicleType == ParkingLot::VehicleType::CAR){
        if(spotType == ParkingLot::SpotType::REGULAR || spotType == ParkingLot::SpotType::LARGE) return true;
    }
    else if(vehicleType == ParkingLot::VehicleType::TRUCK){
        if(spotType == ParkingLot::SpotType::LARGE) return true;
    }
    return false;
}

int ParkingLotManagerInMemImpl::getSpotPriority(const ParkingLot::VehicleType &vehicleType, const ParkingLot::SpotType &spotType) {
    if(vehicleType == ParkingLot::VehicleType::MOTORCYCLE){
        if(spotType == ParkingLot::SpotType::COMPACT) return 1;
        if(spotType == ParkingLot::SpotType::REGULAR) return 2;
        if(spotType == ParkingLot::SpotType::LARGE) return 3;
    }
    else if(vehicleType == ParkingLot::VehicleType::CAR){
        if(spotType == ParkingLot::SpotType::REGULAR) return 1;
        if(spotType == ParkingLot::SpotType::LARGE) return 2;
    }
    else if(vehicleType == ParkingLot::VehicleType::TRUCK){
        if(spotType == ParkingLot::SpotType::LARGE) return 1;
    }
    return 999;
}

bool ParkingLotManagerInMemImpl::addParkingSpot(const ParkingSpot &spot) {
    if(spot.getSpotId().empty()) return false;
    if(parkingSpot.find(spot.getSpotId()) != parkingSpot.end()) return false;
    parkingSpot[spot.getSpotId()] = spot;
    return true;
}

bool ParkingLotManagerInMemImpl::removeParkingSpot(const string &spotId) {
    auto it = parkingSpot.find(spotId);
    if(it == parkingSpot.end()) return false;
    if(!it->second.isAvailable()) return false;
    parkingSpot.erase(it);
    return true;
}

ParkingTicket* ParkingLotManagerInMemImpl::parkVehicle(const Vehicle &vehicle, const long entryTime) {
    string ticketId = generateTicketId();
    
    // check if vehicle already parked
    if(vehicleParked.find(vehicle.getLicensePlate()) != vehicleParked.end()) return nullptr;

    // Iterate over all spots to find the "Best Fit". This loops through the map. In a real DB, this would be a query.
    ParkingSpot* bestspot = nullptr; // why pointer ?
    int bestpriority = INT_MAX;
    for(auto& entry: parkingSpot){
        ParkingSpot &currSpot = entry.second;
        if(!currSpot.isAvailable()) continue;
        if(!isCompatible(vehicle.getVehicleType(), currSpot.getSpotType())) continue;
        int currpriority = getSpotPriority(vehicle.getVehicleType(), currSpot.getSpotType());
        if(bestspot == nullptr){ // lower priority
            bestpriority = currpriority;
            bestspot = &currSpot;
        }
        else{ // if priority same, prefer smaller compatible spots
            if(currpriority < bestpriority){
                bestpriority = currpriority;
                bestspot = &currSpot;
            }
            else if(currpriority == bestpriority){ // prefer lower floors
                if(currSpot.getFloor() < bestspot->getFloor()) bestspot = &currSpot;
            }

        }
    }
    if(bestspot==nullptr) return nullptr;

    // park the vehicle
    bestspot->parkVehicle(vehicle.getLicensePlate());
    vehicleParked[vehicle.getLicensePlate()] = bestspot->getSpotId();

    // add in spot (that it is now booked)
    return new ParkingTicket(ticketId, vehicle.getLicensePlate(), bestspot->getSpotId(), entryTime);
}

bool ParkingLotManagerInMemImpl::exitVehicle(const string &licensePlate, const long exitTime) {
    auto it = vehicleParked.find(licensePlate);
    if(it == vehicleParked.end()) return false;
    string spot = vehicleParked[licensePlate];
    // free the spot
    if(parkingSpot.find(spot) != parkingSpot.end()){
        parkingSpot[spot].removeVehicle();
    }
    vehicleParked.erase(it);
    return true; 
}

ParkingSpot* ParkingLotManagerInMemImpl::findVehicleByLicense(const string &licensePlate) {
    auto it = vehicleParked.find(licensePlate);
    if(it != vehicleParked.end()) return &parkingSpot[it->second];
    return nullptr;
}

vector<ParkingSpot> ParkingLotManagerInMemImpl::getAvailableSpotsByType(const ParkingLot::SpotType &spotType) {
    vector<ParkingSpot> spots;
    for(auto it: parkingSpot){
        if(it.second.getSpotType() == spotType && it.second.isAvailable()) spots.push_back(it.second);
    }
    return spots;
}

ParkingSpot* ParkingLotManagerInMemImpl::getParkingSpot(const string &spotId) {
    auto it = parkingSpot.find(spotId);
    if(it != parkingSpot.end()) return &(it->second);
    return nullptr; 
}

void ParkingLotManagerInMemImpl::reset() {
    parkingSpot.clear(); // spotId -> SpotObject
    vehicleParked.clear(); // licensePlate -> spotId
}