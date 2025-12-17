#ifndef __PARKINGLOTMANAGERINMEMIMPL__
#define __PARKINGLOTMANAGERINMEMIMPL__
#include "ParkingLotManager.hpp"
#include "include/strategies/PricingStrategy.hpp"
#include <vector>
#include <unordered_map>

using namespace std;

class ParkingLotManagerInMemImpl : public ParkingLotManager {
private:
    unordered_map<string, ParkingSpot> parkingSpot; // Storing parking spots. (SpotId -> SpotObject)
    unordered_map<string, string> vehicleParked; // Find where the vehicle is parked (LicensePlate -> SpotId)
    unordered_map<string, ParkingTicket*> activeTickets; // Storing active tickets (LicensePlate -> TicketObject)
    PricingStrategy* pricingStrategy;

    /**
     * Generate a unique ticket ID for parking tickets.
     * @return A unique ticket identifier
     */
    string generateTicketId();

    /**
     * Check if a vehicle type is compatible with a spot type.
     * @param vehicleType The type of vehicle.
     * @param spotType The type of parking spot.
     * @return true if the vehicle can park in the spot type, false otherwise
     */
    bool isCompatible(const ParkingLot::VehicleType &vehicleType, const ParkingLot::SpotType &spotType);

    /**
     * Get the priority of a spot type for a given vehicle type.
     * Lower numbers indicate higher priority.
     * @param vehicleType The type of vehicle.
     * @param spotType The type of parking spot.
     * @return priority value (lower = higher priority)
     */
    int getSpotPriority(const ParkingLot::VehicleType &vehicleType, const ParkingLot::SpotType &spotType);

public:
    ParkingLotManagerInMemImpl();
    virtual ~ParkingLotManagerInMemImpl() = default;

    bool addParkingSpot(const ParkingSpot &spot) override;
    bool removeParkingSpot(const string &spotId) override;

    ParkingTicket* parkVehicle(const Vehicle &vehicle, const long entryTime) override;
    bool exitVehicle(const string &licensePlate, const long exitTime) override;

    ParkingSpot* findVehicleByLicense(const string &licensePlate) override;

    vector<ParkingSpot> getAvailableSpotsByType(const ParkingLot::SpotType &spotType) override;

    ParkingSpot* getParkingSpot(const string &spotId) override;

    /**
     * Reset all internal state - useful for testing
     */
    void reset();
};

#endif