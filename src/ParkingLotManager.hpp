#ifndef __PARKINGLOTMANAGER__
#define __PARKINGLOTMANAGER__
#include <string>
#include <vector>
#include "models/Vehicle.hpp"
#include "models/ParkingSpot.hpp"
#include "models/ParkingTicket.hpp"
#include "constants/ParkingLot.hpp"

using namespace std;

class ParkingLotManager {
public:
    virtual ~ParkingLotManager() = default;

    /**
     * @param spot The parking spot to add
     * @return true if the spot was successfully added, false otherwise
     */
    virtual bool addParkingSpot(const ParkingSpot &spot) = 0;

    /**
     * @param spotId The unique identifier of the spot to remove
     * @return true if the spot was successfully removed, false otherwise
     */
    virtual bool removeParkingSpot(const string &spotId) = 0;

    /**
     * @param Vehicle The vehicle to park
     * @param entryTime The timestamp when the vehicle enters
     * @return A parking ticket if successful, nullptr otherwise
     */
    virtual ParkingTicket* parkVehicle(const Vehicle &vehicle, const long entryTime) = 0;

    /**
     * @param licensePlate The license plate of the vehicle to exit
     * @param exitTime The timestamp when the vehicle exits
     * @return true if the vehicle successfully exited, false otherwise
     */
    virtual bool exitVehicle(const string &licensePlate, const long exitTime) = 0;

    /**
     * @param licensePlate The license plate of the vehicle to find
     * @return The parking spot where the vehicle is parked, or nullptr if not found
     */
    virtual ParkingSpot* findVehicleByLicense(const string &licensePlate) = 0;

    /**
     * @param spotType The type of parking spots to retrieve
     * @return A vector of available parking spots of the specified type
     */
    virtual vector<ParkingSpot> getAvailableSpotsByType(const ParkingLot::SpotType &spotType) = 0;

    /**
     * @param spotId The unique identifier of the spot to retrieve
     * @return The parking spot with the given ID, or nullptr if not found
     */
    virtual ParkingSpot* getParkingSpot(const string &spotId) = 0;
};

#endif