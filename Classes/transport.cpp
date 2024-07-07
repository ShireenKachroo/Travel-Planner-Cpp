// Class for managing transport details
class Transport
{
protected:

    string mode;
    double cost;
public:
    Transport(){}
    // Method to set transport details
    void setTransport(string m, double c)
    {
        mode = m;
        cost = c;
        return;
    }
    // Method to display transport details
    void displayTransport()
    {
        cout << "Mode of Transport: " << mode << endl;
        cout << "Cost: " << cost << endl;
        return;
    }
};

// Class for managing bus details
class Bus : public Transport
{
    int capacity;

public:
    // Method to set bus details
    friend void  expenses (HotelBill ,Bus);
    void setBusDetails(int cap, double c)
    {
        capacity = cap;
        setTransport("Bus", c);
        return;
    }
    // Method to display bus details
    void displayBusDetails()
    {
        cout << "Bus Capacity: " << capacity << endl;
        displayTransport();
        return;
    }
};

//class for managing train details
class Train: public Transport
{
    int compartments; // Number of compartments
public:
    Train(){}
    void setTrainDetails(int comp, double c)
    {
        compartments = comp;
        setTransport("Train", c);
        return;
    }
    void displayTrainDetails()
    {
        cout << "Number of Compartments: " << compartments << endl;
        displayTransport();
        return;
    }
     friend void  expenses (HotelBill ,Train);
};

//class for managing aeroplane details
class Aeroplane: public Transport
{
    string airline; // Airline name
public:
    Aeroplane() {}
    void setAeroplaneDetails(string al, double c)
    {
        airline = al;
        setTransport("Spice Jet", c);
        return;
    }
    void displayAeroplaneDetails()
    {
        cout << "Airline: " << airline << endl;
        displayTransport();
        return;
    }
     friend void  expenses (HotelBill ,Aeroplane);
};

