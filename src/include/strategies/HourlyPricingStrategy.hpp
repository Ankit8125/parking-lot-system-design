#ifndef HOURLYPRICINGSTRATEGY_HPP
#define HOURLYPRICINGSTRATEGY_HPP

#include "PricingStrategy.hpp"
#include <cmath>
#include <algorithm>

class HourlyPricingStrategy : public PricingStrategy {
private:
    double hourlyRate;

public:
    HourlyPricingStrategy(double rate) : hourlyRate(rate) {}

    double calculatePrice(const ParkingTicket& ticket) override {
        long durationMinutes = ticket.getDurationInMinutes();
        if (durationMinutes <= 0) return 0.0;

        // Calculate hours, rounding up to the nearest hour
        double hours = std::ceil(static_cast<double>(durationMinutes) / 60.0);
        return hours * hourlyRate;
    }
};

#endif
