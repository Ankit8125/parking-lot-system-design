#ifndef __PARKINGTICKET__
#define __PARKINGTICKET__
#include <string>

using namespace std;

class ParkingTicket {
private:
    string ticketId;
    string licensePlate;
    string spotId;
    long entryTime;
    long exitTime;

public:
    ParkingTicket();
    ParkingTicket(const string& ticketId, const string& licensePlate, const string& spotId, const long& entryTime);

    string getTicketId() const;
    string getLicensePlate() const;
    string getSpotId() const;
    long getEntryTime() const;
    long getExitTime() const;
    long getDurationInMinutes() const;

    void setTicketId(const string& ticketId);
    void setLicensePlate(const string& licensePlate);
    void setSpotId(const string& spotId);
    void setEntryTime(const long& entryTime);
    void setExitTime(const long& exitTime);
};

#endif