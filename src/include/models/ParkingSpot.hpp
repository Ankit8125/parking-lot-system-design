#ifndef PARKINGSPOT_HPP
#define PARKINGSPOT_HPP

#include <string>
#include "./constants/ParkingLot.hpp"

using namespace std;

class ParkingSpot {
private:
    string spotId;
    ParkingLot::SpotType spotType;
    int floor;
    ParkingLot::SpotStatus status;
    string parkedVehicleLicense;

public:
    ParkingSpot();
    ParkingSpot(const string& spotId, const ParkingLot::SpotType& spotType, const int floor, const ParkingLot::SpotStatus status = ParkingLot::SpotStatus::AVAILABLE);

    string getSpotId() const;
    ParkingLot::SpotType getSpotType() const;
    int getFloor() const;
    ParkingLot::SpotStatus getStatus() const;
    string getParkedVehicleLicense() const;

    void setSpotId(const string& spotId);
    void setSpotType(const ParkingLot::SpotType& spotType);
    void setFloor(const int floor);
    void setStatus(const ParkingLot::SpotStatus& status);
    void setParkedVehicleLicense(const string& licensePlate);
    bool isAvailable() const;
    void parkVehicle(const string& licensePlate);
    void removeVehicle();
};

#endif