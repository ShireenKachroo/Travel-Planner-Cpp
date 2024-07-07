// Class for managing booking details
class Booking
{
public:
    string bookingRef;
    double amount;
    bool isCancelled;
    Booking (){}
    Booking(string br, double a) : bookingRef(br), amount(a), isCancelled(false) {}
    // Method to cancel booking
    void cancelBooking()
    {
        if (!isCancelled)
        {
            isCancelled = true;
            cout << "Booking cancelled.\n";
        }
        else
        {
            cout << "Booking already cancelled.\n";
        }
        return;
    }
};

// Class for managing booking cancellations
class BookingCancellation
{
public:
    // Method to cancel a booking
    void cancelBooking(Booking &booking)
    {
        booking.cancelBooking();
        return;
    }
};

