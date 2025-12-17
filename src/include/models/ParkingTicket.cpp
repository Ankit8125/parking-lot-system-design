#include "ParkingTicket.hpp"

ParkingTicket::ParkingTicket() {
    this->ticketId = "";
    this->licensePlate = "";
    this->spotId = "";
    this->entryTime = 0;
    this->exitTime = 0;
}

ParkingTicket::ParkingTicket(const string& ticketId, const string& licensePlate, const string& spotId, const long& entryTime) {
    this->ticketId = ticketId;
    this->licensePlate = licensePlate;
    this->spotId = spotId;
    this->entryTime = entryTime;
    this->exitTime = 0;
}

string ParkingTicket::getTicketId() const {
    return this->ticketId;
}

string ParkingTicket::getLicensePlate() const {
    return this->licensePlate;
}

string ParkingTicket::getSpotId() const {
    return this->spotId;
}

long ParkingTicket::getEntryTime() const {
    return this->entryTime;
}

long ParkingTicket::getExitTime() const {
    return this->exitTime;
}

void ParkingTicket::setTicketId(const string& ticketId) {
    this->ticketId = ticketId;
}

void ParkingTicket::setLicensePlate(const string& licensePlate) {
    this->licensePlate = licensePlate;
}

void ParkingTicket::setSpotId(const string& spotId) {
    this->spotId = spotId;
}

void ParkingTicket::setEntryTime(const long& entryTime) {
    this->entryTime = entryTime;
}

void ParkingTicket::setExitTime(const long& exitTime) {
    this->exitTime = exitTime;
}

long ParkingTicket::getDurationInMinutes() const {
    if (this->exitTime == 0) {
        return 0;
    }

    // Assuming time is in minutes since epoch
    return this->exitTime - this->entryTime;
}