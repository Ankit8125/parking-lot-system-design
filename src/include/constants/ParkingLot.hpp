#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP

namespace ParkingLot {
    enum VehicleType {
        MOTORCYCLE,
        CAR,
        TRUCK
    };

    enum SpotType {
        COMPACT,
        REGULAR,
        LARGE
    };

    enum SpotStatus {
        AVAILABLE,
        OCCUPIED
    };
}

#endif