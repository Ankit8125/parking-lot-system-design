#ifndef PRICINGSTRATEGY_HPP
#define PRICINGSTRATEGY_HPP

#include "../models/ParkingTicket.hpp"

class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    /**
     * Calculate the price based on the ticket information (duration, vehicle type, etc.)
     * @param ticket The parking ticket containing entry/exit times
     * @return The calculated price
     */
    virtual double calculatePrice(const ParkingTicket& ticket) = 0;
};

#endif
