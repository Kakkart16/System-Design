#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>

using namespace std;

// Forward Declarations
class Show;
class Movie;
class Address;
class Audi;
class Seat;
class Booking;
class Payment;
class Search;
class Member;
class SystemMember;
class Admin;
class User;
class BMSService;
class CinemaHall;

// Enums
enum class SeatType {
    DELUX, VIP, ECONOMY, OTHER
};

enum class SeatStatus {
    BOOKED, AVAILABLE, RESERVED, NOT_AVAILABLE
};

enum class Genre {
    SCI_FI, DRAMA, ROM_COM, FANTASY
};

enum class BookingStatus {
    REQUESTED, PENDING, CONFIRMED, CANCELLED
};

enum class PaymentStatus {
    UNPAID, PENDING, COMPLETED, DECLINED, CANCELLED, REFUNDED
};

// Classes
class Address {
public:
    int pinCode; // ZipCode
    string street;
    string city;
    string state;
    string country;
};

class Seat {
public:
    int seatId;
    SeatType seatType;
    SeatStatus seatStatus;
    double price;
};

class Show {
public:
    int showId;
    Movie* movie;
    string startTime;
    string endTime;
    CinemaHall* cinemaPlayedAt;
    vector<Seat> seats;
};

class Movie {
public:
    string movieName;
    int movieId;
    int durationInMins;
    string language;
    Genre genre;
    string releaseDate;
    map<string, vector<Show>> cityShowMap;
};

class Audi {
public:
    int audiId;
    string audiName;
    int totalSeats;
    vector<Show> shows;
};

class CinemaHall {
public:
    int cinemaHallId;
    string cinemaHallName;
    Address address;
    vector<Audi> audiList;

    map<string, vector<Movie>> getMovies(vector<string> dateList);
    map<string, vector<Show>> getShows(vector<string> dateList);
};

class Account {
public:
    string userName;
    string password;
};

class User {
public:
    int userId;
    Search* searchObj;
};

class SystemMember : public User {
public:
    Account account;
    string name;
    string email;
    Address address;
};

class Member : public SystemMember {
public:
    Booking makeBooking(Booking booking);
    vector<Booking> getBooking();
};

class Admin : public SystemMember {
public:
    bool addMovie(Movie movie);
    bool addShow(Show show);
};

class Search {
public:
    vector<Movie> searchMoviesByNames(const string& name);
    vector<Movie> searchMoviesByGenre(Genre genre);
    vector<Movie> searchMoviesByLanguage(const string& language);
    vector<Movie> searchMoviesByDate(const string& releaseDate);
};

class Booking {
public:
    string bookingId;
    string bookingDate;
    Member* member;
    Audi* audi;
    Show* show;
    BookingStatus bookingStatus;
    double totalAmount;
    vector<Seat> seats;
    Payment* paymentObj;

    bool makePayment(Payment payment);
};

class Payment {
public:
    double amount;
    string paymentDate;
    int transactionId;
    PaymentStatus paymentStatus;
};

class BMSService {
public:
    vector<CinemaHall> cinemas;

    vector<Movie> getMovies(const string& date, const string& city);
    vector<CinemaHall> getCinemaHalls(const string& city);
};

// Methods Definitions (can be expanded as needed)
map<string, vector<Movie>> CinemaHall::getMovies(vector<string> dateList) {
    map<string, vector<Movie>> movieMap;
    // Implementation logic here
    return movieMap;
}

map<string, vector<Show>> CinemaHall::getShows(vector<string> dateList) {
    map<string, vector<Show>> showMap;
    // Implementation logic here
    return showMap;
}

vector<Movie> BMSService::getMovies(const string& date, const string& city) {
    vector<Movie> movies;
    // Implementation logic here
    return movies;
}

vector<CinemaHall> BMSService::getCinemaHalls(const string& city) {
    vector<CinemaHall> cinemaHalls;
    // Implementation logic here
    return cinemaHalls;
}

Booking Member::makeBooking(Booking booking) {
    // Implementation logic here
    return booking;
}

vector<Booking> Member::getBooking() {
    vector<Booking> bookings;
    // Implementation logic here
    return bookings;
}

bool Admin::addMovie(Movie movie) {
    // Implementation logic here
    return true;
}

bool Admin::addShow(Show show) {
    // Implementation logic here
    return true;
}

bool Booking::makePayment(Payment payment) {
    // Implementation logic here
    return true;
}

// Search methods
vector<Movie> Search::searchMoviesByNames(const string& name) {
    vector<Movie> movies;
    // Implementation logic here
    return movies;
}

vector<Movie> Search::searchMoviesByGenre(Genre genre) {
    vector<Movie> movies;
    // Implementation logic here
    return movies;
}

vector<Movie> Search::searchMoviesByLanguage(const string& language) {
    vector<Movie> movies;
    // Implementation logic here
    return movies;
}

vector<Movie> Search::searchMoviesByDate(const string& releaseDate) {
    vector<Movie> movies;
    // Implementation logic here
    return movies;
}

int main() {
    // Example usage
    BMSService bmsService;
    vector<Movie> movies = bmsService.getMovies("2024-09-02", "New York");
    vector<CinemaHall> cinemaHalls = bmsService.getCinemaHalls("New York");

    // Additional test cases or usage examples

    return 0;
}
