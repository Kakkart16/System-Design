/*<-------------------------------------------------------------------------------------------------------- ->

Parking lot system design requirements:

1. There should be multiple floors in the parking lot.
2. There should be multiple gates in the parking lot.
3. There should be a parking attendant at each gate.
4. The entry gate should process parking ticket.
5. The exit gate should process payment on hourly basis.
6. The parking lot should have facility for different type of vehicles.
7. There should be a display board at each floor showing the details of vacant spots on the floor. 


<----------------------------------------------------------------------------------------------------------->*/


#include <bits/stdc++.h>
using namespace std;


// Forward declarations
class ParkingLot;
class ParkingFloor;
class ParkingSpace;
class ParkingDisplayBoard;
class Gate;
class Entrance;
class Exit;
class Account;
class Admin;
class ParkingAttendant;
class Vehicle;
class ParkingTicket;
class PaymentInfo;
class Payment;


// Enums
enum class VehicleType {
    BIKE,
    CAR,
    TRUCK
};

enum class ParkingSpaceType {
    BIKE_PARKING,
    CAR_PARKING,
    TRUCK_PARKING
};

enum class PaymentType {
    CASH,
    CREDIT_CARD,
    DEBIT_CARD,
    UPI
};

enum class ParkingTicketStatus {
    PAID,
    ACTIVE
};

enum class PaymentStatus {
    UNPAID,
    PENDING,
    COMPLETED,
    DECLINED,
    CANCELLED,
    REFUNDED
};

// classes

// Address class
class Address {
public:
    string country;
    string state;
    string city;
    string street;
    string pinCode; 
};

// ParkingTicket class
class ParkingTicket {
public:
    int ticketId;
    int levelId;
    int spaceId;
    time_t vehicleEntryDateTime;
    time_t vehicleExitDateTime;
    ParkingSpaceType parkingSpaceType;
    double totalCost;
    ParkingTicketStatus parkingTicketStatus;

    void updateTotalCost() {
        // Implementation
    }

    void updateVehicleExitTime(time_t exitTime) {
        vehicleExitDateTime = exitTime;
    }
};

// PaymentInfo class
class PaymentInfo {
public:
    double amount;
    time_t paymentDate;
    int transactionId;
    ParkingTicket parkingTicket;
    PaymentStatus paymentStatus;
};

// Vehicle class
class Vehicle {
public:
    string licenseNumber;
    VehicleType vehicleType;
    ParkingTicket parkingTicket;
    PaymentInfo paymentInfo;
};

// ParkingSpace class
class ParkingSpace {
public:
    int spaceId;
    bool isFree;
    double costPerHour;
    Vehicle vehicle;
    ParkingSpaceType parkingSpaceType;
};

// ParkingDisplayBoard class
class ParkingDisplayBoard {
public:
    map<ParkingSpaceType, int> freeSpotsAvailableMap;

    void updateFreeSpotsAvailable(ParkingSpaceType type, int spaces) {
        freeSpotsAvailableMap[type] = spaces;
    }
};

// ParkingFloor class
class ParkingFloor {
public:
    int levelId;
    vector<ParkingSpace> parkingSpaces;
    ParkingDisplayBoard parkingDisplayBoard;
};

// Account class
class Account {
public:
    string name;
    string email;
    string password;
    string empId;
    Address address;
};

// Admin class
class Admin : public Account {
public:
    bool addParkingFloor(ParkingLot &parkingLot, ParkingFloor &floor);
    bool addParkingSpace(ParkingFloor &floor, ParkingSpace &parkingSpace);
    bool addParkingDisplayBoard(ParkingFloor &floor, ParkingDisplayBoard &displayBoard);
    // Additional methods
};

// Payment class
class Payment {
public:
    PaymentInfo makePayment(ParkingTicket &ticket, PaymentType paymentType) {
        // Implementation
        return PaymentInfo(); 
    }
};

// ParkingAttendant class
class ParkingAttendant : public Account {
public:
    Payment paymentService;

    bool processVehicleEntry(Vehicle &vehicle) {
        // Implementation
        return true;
    }

    PaymentInfo processPayment(ParkingTicket &ticket, PaymentType paymentType) {
        return paymentService.makePayment(ticket, paymentType);
    }
};

// Gate class
class Gate {
public:
    int gateId;
    ParkingAttendant parkingAttendant;
};

// Entrance class
class Entrance : public Gate {
public:
    ParkingTicket getParkingTicket(Vehicle &vehicle) {
        // Implementation
        return ParkingTicket(); 
    }
};

// Exit class
class Exit : public Gate {
public:
    ParkingTicket payForParking(ParkingTicket &ticket, PaymentType paymentType) {
        // Implementation
        return ticket; 
    }
};

// ParkingLot class
class ParkingLot {
public:
    vector<ParkingFloor> parkingFloors;
    vector<Entrance> entrances;
    vector<Exit> exits;
    Address address;
    string parkingLotName;

    bool isParkingSpaceAvailableForVehicle(Vehicle &vehicle) {
        // Implementation
        return true;
    }

    bool updateParkingAttendant(ParkingAttendant &attendant, int gateId) {
        // Implementation
        return true;
    }
};


int main(){
	return 0;
}