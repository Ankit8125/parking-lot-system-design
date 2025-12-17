#ifndef __VEHICLE__
#define __VEHICLE__
#include <string>
#include "./constants/ParkingLot.hpp"

using namespace std;

class Vehicle {
private:
    string licensePlate;
    ParkingLot::VehicleType vehicleType;
    string ownerName;

public:
    Vehicle();
    Vehicle(const string& licensePlate, const ParkingLot::VehicleType& vehicleType, const string& ownerName);

    string getLicensePlate() const;
    ParkingLot::VehicleType getVehicleType() const;
    string getOwnerName() const;

    void setLicensePlate(const string& licensePlate);
    void setVehicleType(const ParkingLot::VehicleType& vehicleType);
    void setOwnerName(const string& ownerName);
};

#endif