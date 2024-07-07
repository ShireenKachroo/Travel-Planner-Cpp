#include <iostream>
#include<cstring>
#include <fstream>      //for file handling
#include <vector>
#include <windows.h>
using namespace std;
//forward declaration of required classes
class Bus;
class Train;
class Aeroplane;
// Class for managing customer details
class Customer
{
public:
    string name;
    int age;
    int numTravelers;
    long int customerID;
    string phoneNumber;
    string address;
    Customer(){}
    // Method to get customer information from user
    void getCustomerInfo()
    {
        cout << "Enter customer's name: ";
        cin.ignore();// Ignore newline character
        getline(cin, name);
        cout << "Enter customer's age: ";
        cin >> age;
        cout << "Enter customer's address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter number of travelers: ";
        cin >> numTravelers;
        cout << "Enter customer's phone number: ";
        cin >> phoneNumber;
        cout<<"Details of customer registered successfully"<<endl;
        cout<<"\n";
        return;
    }
    // Method to display customer information
    void displayCustomerInfo()
    {
        cout << "Customer Details: " << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Number of Travelers: " << numTravelers << endl;
        return;
    }
    // Method to save customer information to file
    void saveCustomerToFile()
    {
        ofstream outFile("customer_details.txt");
        if (outFile.is_open())
        {
            outFile << "Name: " << name << endl;
            outFile << "Age: " << age << endl;
            outFile << "Address: " << address << endl;
            outFile << "Phone Number: " << phoneNumber << endl;
            outFile << "Number of Travelers: " << numTravelers << endl;
            outFile.close();
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
        return;

    }

};
// Class for managing start location details
class StartLocation
{
    string name;
    int pinCode;
public:
    StartLocation(){}
    // MEthod to get origin details from user
    void getOrigin()
    {
        cout << "Enter the place of departure(IN DELHI): ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter its pincode: ";
        cin >> pinCode;
        return;
    }
    // Method to display start location details
    void printDeparture()
    {
        cout << "Place of departure: " << name << endl;
        cout << "Pin Code: " << pinCode << endl;
        return;
    }
};
// Class for managing destination details
class Destination
{
protected:
    string name;
    string dateOfTravel;
    string dateOfReturn;

public:
    Destination(){}
    // Method to get destination details from user
    void getDestinationInfo()
    {
        cin.ignore();
        cout << "Enter date of travel: ";
        cin >> dateOfTravel;
        cin.ignore();
        cout << "Enter date of return: ";
        cin >> dateOfReturn;
        cout<<"\n";
        cin.ignore();
        return;
    }
    // Method to display destination details
    void displayDestinationInfo()
    {
        cout << "Date of Travel: " << dateOfTravel << endl;
        cout << "Date of Return: " << dateOfReturn << endl;
        return;
    }
};

// Class for managing domestic destination details
class Domestic : public Destination
{
    string weather;
    string placesOfInterest;
    double additionalCost;

public:
    Domestic(){}
    // Method to set domestic destination information
    void setDomesticInfo()
    {
        cout << "Enter weather conditions: ";
        cin >> weather;
        cout << "Enter famous places of interest: ";
        cin.ignore(); // Ignore newline character
        getline(cin, placesOfInterest);
        return;
    }
    // Method to display domestic destination information
    void displayDomesticInfo()
    {
        cout << "Weather: " << weather << endl;
        cout << "Places of Interest: " << placesOfInterest << endl;
        return;
    }
};

// Class for managing international destination details
class International : public Destination
{
    string weather;
    string placesOfInterest;
    double additionalCost;

public:
    International(){}
    // Method to set international destination information
    void setInternationalInfo()
    {
        cout << "Enter weather conditions: ";
        cin >> weather;
        cout << "Enter famous places of interest: ";
        cin.ignore(); // Ignore newline character
        getline(cin, placesOfInterest);
        return;
    }
    // Method to display international destination information
    void displayInternationalInfo()
    {
        cout << "Weather: " << weather << endl;
        cout << "Places of Interest: " << placesOfInterest << endl;
        return;
    }
};

class Transport;        //forward declaration

// Class for managing hotel details
class Hotel
{
public:
    int hotelID;
    string address;
    double rating;
    string name;

    Hotel(){}
    Hotel(string n, int h,double r):name(n),hotelID(h),rating(r){}
    // Method to add hotel details
    void addHotel()
    {
        cout << "Enter hotel name: ";
        cin.ignore(); // Ignore newline character
        getline(cin, name);
        cout << "Enter hotel ID: ";
        cin >> hotelID;
        cin.ignore(); // Ignore newline character
        return;
    }
    // Method to display hotel details
    void displayHotel()
    {
        cout << "Hotel Name: " << name << endl;
        cout << "Hotel ID: " << hotelID << endl;
        cout << "Address: " << address << endl;
        return;
    }
    //hotel infor---> file handling
    void saveHotelToFile()
    {
        ofstream outFile("hotel_details.txt");
        if (outFile.is_open())
        {
            outFile << "Name: " << name << endl;
            outFile << "Hotel ID: "<< hotelID << endl;
            outFile.close();
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
        return;
    }
};

//class for displaying hotels to visit information
class HotelsToVisit:public Hotel
{
private:
    vector<Hotel> internationalHotel;
    vector<Hotel> indianHotel;

public:
    HotelsToVisit(){}
    //to add hotel
    void addIndianHotel(string name,int hotelID, double rating)
    {
        indianHotel.push_back(Hotel(name,hotelID,rating));
        saveHotelsToFile("indian_hotels.txt", indianHotel);
        return;
    }
    // Method to add an international hotel
    void addInternationalnHotel(string name,int hotelID, double rating)
    {
        internationalHotel.push_back(Hotel(name, hotelID,rating));
        saveHotelsToFile("international_hotels.txt", internationalHotel);
        return;
    }
    // Method to save places to a file
    void saveHotelsToFile(string fileName, const vector<Hotel>& hotel)
    {
        ofstream outFile(fileName);
        if (outFile.is_open())
        {
            for (const auto& hotel : hotel)
            {
                outFile << "Name: " << hotel.name << endl;
                outFile << "ID: " << hotel.hotelID << endl;
                outFile << "Rating: " << hotel.rating << endl;
                outFile << endl; // Separate entries with a blank line
            }
            outFile.close();
        }
        else
        {
            cout << "Unable to open file: " << fileName << endl;
        }
        return;
    }
    // Method to load places from a file
    void loadHotelsFromFile(string fileName)
    {
        ifstream inFile(fileName);
        if (inFile.is_open())
        {
            string line;
            while (getline(inFile, line))
            {
                if (line.empty())
                {
                    continue;
                }
                string name = line.substr(line.find(": ") + 2); // Extract name
                getline(inFile, line); // Read description
                double rating = stod(line.substr(line.find(": ") + 2)); // Extract rating
                if (fileName == "indian_hotels.txt")
                {
                    indianHotel.push_back(Hotel(name, hotelID, rating));
                }
                else if (fileName == "international_hotels.txt")
                {
                    internationalHotel.push_back(Hotel(name, hotelID,rating));
                }
            }
            inFile.close();
        }
        else
        {
            cout << "Unable to open file: " << fileName << endl;
        }
        return;
    }
    // Method to display all Indian places to visit

    void displayIndianHotels()
    {
        cout << "\n==Indian Hotels to Visit==\n";
        for (const auto& hotel : indianHotel)
        {
            cout << "Name: " << hotel.name << endl;
            cout << "Rating: " << hotel.rating << endl;
            cout << endl;
        }
        return;
    }
    // Method to display all international places to visit
    void displayInternationalHotel()
    {
        cout << "\n==International Hotels to Visit==\n";
        for (const auto& hotel : internationalHotel)
        {
            cout << "Name: " << hotel.name << endl;
            cout << "Rating: " << hotel.rating << endl;
            cout << endl;
        }
        return;
    }
};

// Class for managing hotel bill calculation
class HotelBill : public Hotel
{
public:
    double rentPerDay;
    HotelBill(){}
    // Method to calculate hotel bill
    double totalBill;
    void calculateBill(int days)
    {
        totalBill = days * rentPerDay;
        cout << "Total Bill: " << totalBill << endl;
        return;
    }
     friend void  expenses (HotelBill ,Bus);
     friend void  expenses (HotelBill ,Train);
     friend void  expenses (HotelBill ,Aeroplane);
};

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

// Class for managing reviews
class Review
{
public:
    string reviewText;
    int rating;

    Review(string rt, int r) : reviewText(rt), rating(r) {}
};

// Class for managing reviews and ratings
class ReviewAndRating
{
public:
    // Method to add a review
    void addReview(Review &review)
    {
        cout << "Review added.\n";
        return;
    }

    // Method to get average rating
    double getAverageRating() const
    {
        return 4.5; // Sample rating
    }
};

// Class for managing place details
class Place
{
public:
    string name;
    string description;
    string weather;
    double rating;

    Place(string n, string desc, string w, double r) : name(n), description(desc), weather(w), rating(r) {}
};

// Class for managing places to visit
class PlacesToVisit
{
private:
    vector<Place> indianPlaces;
    vector<Place> internationalPlaces;

public:
    // Method to add an Indian place to visit
    void addIndianPlace(string name, string description, string weather, double rating)
    {
        indianPlaces.push_back(Place(name, description, weather, rating));
        savePlacesToFile("indian_places.txt", indianPlaces);
        return;
    }
    // Method to add an international place to visit
    void addInternationalPlace(string name, string description, string weather, double rating)
    {
        internationalPlaces.push_back(Place(name, description, weather, rating));
        savePlacesToFile("international_places.txt", internationalPlaces);
        return;
    }
    // Method to save places to a file
    void savePlacesToFile(string fileName, const vector<Place>& places)
    {
        ofstream outFile(fileName);
        if (outFile.is_open())
        {
            for (const auto& place : places)
            {
                outFile << "Name: " << place.name << endl;
                outFile << "Description: " << place.description << endl;
                outFile << "Weather: " << place.weather << endl;
                outFile << "Rating: " << place.rating << endl;
                outFile << endl; // Separate entries with a blank line
            }
            outFile.close();
        }
        else
        {
            cout << "Unable to open file: " << fileName << endl;
        }
        return;
    }
    // Method to load places from a file
    void loadPlacesFromFile(string fileName)
    {
        ifstream inFile(fileName);
        if (inFile.is_open())
        {
            string line;
            while (getline(inFile, line))
            {
                if (line.empty())
                {
                    continue; // Skip blank lines
                }
                string name = line.substr(line.find(": ") + 2); // Extract name
                getline(inFile, line); // Read description
                string description = line.substr(line.find(": ") + 2); // Extract description
                getline(inFile, line); // Read weather
                string weather = line.substr(line.find(": ") + 2); // Extract weather
                getline(inFile, line); // Read rating
                double rating = stod(line.substr(line.find(": ") + 2)); // Extract rating
                if (fileName == "indian_places.txt")
                {
                    indianPlaces.push_back(Place(name, description, weather, rating));
                }
                else if (fileName == "international_places.txt")
                {
                    internationalPlaces.push_back(Place(name, description, weather, rating));
                }
            }
            inFile.close();
        }
        else
        {
            cout << "Unable to open file: " << fileName << endl;
        }
        return;
    }
    // Method to display all Indian places to visit
    void displayIndianPlaces()
    {
        cout << "Indian Places to Visit:\n";
        for (const auto& place : indianPlaces)
        {
            cout << "Name: " << place.name << endl;
            cout << "Description: " << place.description << endl;
            cout << "Weather: " << place.weather << endl;
            cout << "Rating: " << place.rating << endl;
            cout << endl;
        }
        return;
    }
    // Method to display all international places to visit
    void displayInternationalPlaces()
    {
        cout << "International Places to Visit:\n";
        for (const auto& place : internationalPlaces)
        {
            cout << "Name: " << place.name << endl;
            cout << "Description: " << place.description << endl;
            cout << "Weather: " << place.weather << endl;
            cout << "Rating: " << place.rating << endl;
            cout << endl;
        }
        return;
    }
};
void expenses(HotelBill h1,Bus t)
{
    double e;
    e=h1.totalBill+t.cost;
    cout<<"Your total expense is: "<<e<<endl;
    return;
}
void expenses(HotelBill h1,Aeroplane t)
{
    double e;
    e=h1.totalBill+t.cost;
    cout<<"Your total expense is: "<<e<<endl;
    return;
}
void expenses(HotelBill h1,Train t)
{
    double e;
    e=h1.totalBill+t.cost;
    cout<<"Your total expense is: "<<e<<endl;
    return;
}

//Driver Code
int main()
{

    PlacesToVisit planner;
    planner.addIndianPlace("01. Goa", "Beautiful beaches", "Tropical", 4.5);
    planner.addIndianPlace("02. Sikkim", "Part of easterm Himalayas", "Sub Tropical", 4.6);
    planner.addIndianPlace("03. Kerala", "Scenic boat rides", "Tropical", 4.7);
    planner.addIndianPlace("04. Jaipur", "Historical monuments", "Hot", 4.6);
    planner.addIndianPlace("05. Leh-Ladakh", "Spectacular landscapes", "Cold", 4.9);

    planner.addInternationalPlace("01. Paris", "Iconic landmark in Paris", "Mild", 4.9);
    planner.addInternationalPlace("02. England", "Where tradition meets innovation in a teacup", "Cold", 4.8);
    planner.addInternationalPlace("03. Japan", "Blend of traditional culture and modern technology", "Variable", 4.3);
    planner.addInternationalPlace("04. Iceland", "Waterfalls, volcanoes, Northern Lights.", "Cool", 4.5);
    planner.addInternationalPlace("05. South Africa", " Safari, culture, coastline", "Diverse", 4);

    HotelsToVisit h;
    h.addIndianHotel("01.Hyatt Hotels", 1022, 4.4);
    h.addIndianHotel("02. Hilton Hotels & Resorts", 1025, 4.3);
    h.addIndianHotel("03. Accor Hotels", 1025, 4.1);
    h.addIndianHotel("04. Radisson Hotel", 1025, 4.3);
    h.addInternationalnHotel("05. Fairmont Hotels", 3011, 4.4);
    h.addInternationalnHotel("06. Marriott International", 3011, 4.4);
    h.addInternationalnHotel("07. Carlson Rezidor", 3011, 4.1);
    h.addInternationalnHotel("08. Wyndham Hotels", 3011, 4.2);

    Customer customer;
    Destination d;
    Transport t;
    StartLocation s;
    Domestic d1;
    International i;
    Booking b;
    Bus b1;
    Train t1;
    Aeroplane a1;

    int choice;
    int p,z,a;

    int k;

    menu:
    cout << "\n=== Travel Planning Menu ===\n" << endl;
    cout << "1. Add Customer Details" << endl;
    cout << "2. Book a Trip" << endl;
    cout << "3. Book a Hotel"<<endl;
    cout << "4. Cancel Booking" << endl;
    cout << "5. View Details" << endl;
     cout <<"6. Exit Program\n" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout<<"\n";

    HotelBill h1;

    if (choice == 1)
    {
        cout << "\n=== Add Customer Details ===\n" << endl;
        customer.getCustomerInfo();
        goto menu;
    }
    else if (choice == 2)
    {
        s.getOrigin();
        cout << "\n=== Book a Trip ===\n" << endl;
        // Implement booking functionality
       cout<<"The place you want to visit"<<endl;
       cout<<"1. Domestic  "<<endl;
       cout<<"2. International "<<endl;
       cin>>a;
      if(a==1)
      {
          cout<<"Places to visit in India\n"<<endl;
          planner.displayIndianPlaces();
          int c;
          cout<<"Enter the code of the desired place you want to visit:";
          cin>>c;
          cout<<"\n"<<endl;
          d.getDestinationInfo();
          if(c==1)
          {
          cout<<"==Prices of different transportation=="<<endl;
          cout<<"Delhi to goa via bus= 3500"<<endl;
          cout<<"Delhi to goa via train= 4500"<<endl;
          cout<<"Delhi to goa via flight= 6000"<<endl;
          cout<<"\n01-Bus\n02-Train\n03-Flight"<<endl;
          cout<<"Enter the code of mode of transport you will be using:"<<endl;
          cin>>z;
              if(z==1)
              {
                  k = customer.numTravelers*3500;
                  b1.setBusDetails(20,k);

              }
              else if(z==2)
              {
                  k = customer.numTravelers*4500;
                  t1.setTrainDetails(7,k);
              }
              else if (z==3)
              {
                  k = customer.numTravelers*6000;
                  a1.setAeroplaneDetails("Vistara",k);
              }
          }
          else if(c==2)
          {
              cout<<"Delhi to Sikkim via bus= 3300"<<endl;
              cout<<"Delhi to sikkim via train= 5500"<<endl;
              cout<<"Delhi to sikkim via flight= 7500"<<endl;
              cout<<"\n01-Bus\n02-Train\n03-Flight"<<endl;
              cout<<"Enter the code of mode of transport you will be using:"<<endl;
              cin>>z;
              if(z==1)
              {
                  k = customer.numTravelers*3300;
                  b1.setBusDetails(20,k);
              }
              else if(z==2)
              {
                  k = customer.numTravelers*5500;
                  t1.setTrainDetails(7,k);
              }
              else if (z==3)
              {
                  k = customer.numTravelers*7500;
                  a1.setAeroplaneDetails("Vistara",k);
              }
          }
           else if(c==3)
          {
              cout<<"Delhi to kerala via bus= 6000"<<endl;
              cout<<"Delhi to kerala via train= 7000"<<endl;
              cout<<"Delhi to kerala via flight= 10000"<<endl;
              cout<<"\n01-Bus\n02-Train\n03-Flight"<<endl;
              cout<<"Enter the code of mode of transport you will be using:"<<endl;
              cin>>z;
              if(z==1)
              {
                  k = customer.numTravelers*6000;
                  b1.setBusDetails(20,k);
              }
              else if(z==2)
              {
                  k = customer.numTravelers*7000;
                  t1.setTrainDetails(7,k);
              }
              else if (z==3)
              {
                  k = customer.numTravelers*10000;
                  a1.setAeroplaneDetails("Vistara",k);
              }
          }
           else if(c==4)
          {
              cout<<"Delhi to Jaipur via bus= 800"<<endl;
              cout<<"Delhi to Jaipur via train= 1500"<<endl;
              cout<<"Delhi to Jaipur via flight= 3000"<<endl;
              cout<<"\n01-Bus\n02-Train\n03-Flight"<<endl;
              cout<<"Enter the code of mode of transport you will be using:"<<endl;
              cin>>z;
              if(z==1)
              {
                  k = customer.numTravelers*800;
                  b1.setBusDetails(20,k);
              }
              else if(z==2)
              {
                  k = customer.numTravelers*1500;
                  t1.setTrainDetails(7,k);
              }
              else if (z==3)
              {
                  k = customer.numTravelers*3000;
                  a1.setAeroplaneDetails("Vistara",k);
              }
           }
            else if(c==5)
           {
              cout<<"Delhi to Leh-Ladakh via bus= 2500"<<endl;
              cout<<"Delhi to Leh-Ladakh via train= 3500"<<endl;
              cout<<"Delhi to Leh-Ladakh via flight= 7000"<<endl;
              cout<<"\n01-Bus\n02-Train\n03-Flight"<<endl;
              cout<<"Enter the code of mode of transport you will be using:"<<endl;
              cin>>z;
              if(z==1)
              {
                  k = customer.numTravelers*2500;
                  b1.setBusDetails(20,k);
              }
              else if(z==2)
              {
                  k = customer.numTravelers*3500;
                  t1.setTrainDetails(7,k);
              }
              else if (z==3)
              {
                  k = customer.numTravelers*7000;
                  a1.setAeroplaneDetails("Vistara",k);
              }

          }
          else
          {
            cout<<"Invalid entry"<<endl;
          }
          cout<<"Transportation successfully booked!\n"<<endl;
          }
          else if(a==2)
          {
          cout<<"International Places to visit "<<endl;
          planner.displayInternationalPlaces();
          d.getDestinationInfo();
          cout<<"The mode of transport is Aeroplane only"<<endl;
          z=3;
          //a1.setAeroplaneDetails("Spicejet",15000);
          int g;
          cout<<"Enter the code of the desired place you want to visit:";
          cin>>g;
          if (g==1)
          {
              cout<<"Delhi to Paris= 70,000"<<endl;
              k = customer.numTravelers*70000;
              a1.setAeroplaneDetails("Air India",k);
          }
           else if (g==2)
          {
              cout<<"Delhi to England=70,000"<<endl;
              k = customer.numTravelers*70000;
              a1.setAeroplaneDetails("Air India",k);
          }
          else if (g==3)
          {
              cout<<"Delhi to Japan=65,000"<<endl;
              k = customer.numTravelers*65000;
              a1.setAeroplaneDetails("Malaysia airlines",k);
          }
          else if (g==4)
          {
              cout<<"Delhi to Iceland=50,000"<<endl;
              k = customer.numTravelers*50000;
              a1.setAeroplaneDetails("Qatar Airlines",k);
          }
          else if (g==5)
          {
              cout<<"Delhi to South Africa=40,000"<<endl;
              k = customer.numTravelers*40000;
              a1.setAeroplaneDetails("Qatar Airlines",k);
          }
      }

      else
        {
            cout<<"invalid entry"<<endl;
        }
        goto menu;
    }
    else if(choice == 3)
    {
        cout<<"Do you want to stay in hotel or book airbnb or NOTA?"<<endl;
        cout<<"1. Hotel"<<endl;
        cout<<"2. AirBnb"<<endl;
        cout<<"3. None of the above"<<endl;
        cin>>p;
        if (p==1)
        {

                if(a==1)
                    {
                        cout<<"Below are the Indian hotels we have affiliations with:"<<endl;
                        h.displayIndianHotels();
                        int n;
                        cout<<"Enter the code of the hotel you wanna stay in: ";
                        cin>>n;
                        if (n==1)
                        {
                            cout<<"The rate per room per day= Rs15,000"<<endl;
                            h1.rentPerDay = 15000;
                        }
                        else if (n==2)
                        {
                            cout<<"The rate per room per day= Rs8,000"<<endl;
                            h1.rentPerDay = 18000;
                        }
                        else if (n==3)
                        {
                            cout<<"The rate per room per day= Rs12,000"<<endl;
                            h1.rentPerDay = 12000;
                        }
                        else if (n==4)
                        {
                            cout<<"The rate per room per day= Rs13,000"<<endl;
                            h1.rentPerDay = 13000;
                        }
                    }
                else if(a==2)
                    {
                        cout<<"Below are the International hotels we have affiliations with:"<<endl;
                        h.displayInternationalHotel();
                        int m;
                        cout<<"Enter the code of the hotel you wanna stay in: ";
                        cin>>m;
                        if (m==5)
                        {
                            cout<<"The rate per room per day= Rs25,000"<<endl;
                            h1.rentPerDay = 25000;
                        }
                        else if (m==6)
                        {
                            cout<<"The rate per room per day= Rs30,000"<<endl;
                            h1.rentPerDay = 30000;
                        }
                        else if (m==7)
                        {
                            cout<<"The rate per room per day= Rs18,000"<<endl;
                            h1.rentPerDay = 18000;
                        }
                        else if (m==8)
                        {
                            cout<<"The rate per room per day= Rs12,000"<<endl;
                            h1.rentPerDay = 12000;
                        }

                    }
                int l;
                cout<<"\nEnter the number of days you will stay: ";
                cin>>l;
                h1.calculateBill(l);
        }
        /*if(p==1)
        {
            h1.addHotel();
            int l;
            cout<<"enter the number of days you will stay: "<<endl;
            cin>>l;
            h1.calculateBill(l);
        }*/
        else if(p==2)
        {
            cout<<"To book your room via airbnb, please go to the website given below\nhttps://www.airbnb.co.in/host/instant-book"<<endl;
            h1.calculateBill(0);
        }
        else if(p==3)
        {
            h1.calculateBill(0);
        }
        else
        {
            cout<<"invalid entry"<<endl;
        }
             goto menu;
    }

    else if(choice == 4)
    {
        cout<< "=== Are you sure you wanna cancel your booking? ===" << endl;
        cout<<"1.YES"<<endl<<"2.NO"<<endl;
        int n;
        cin>>n;
        if(n==1)
        {
            if(n==1)
                Beep(500,700);
            b.cancelBooking();
            goto menu;
        }
        else
        {
            goto menu;
        }
    }
    else if (choice == 5)
    {
        cout<<"YOUR BOOKING DETAILS ARE "<<endl<<endl;
        customer.displayCustomerInfo();
        d.displayDestinationInfo();
        if(z==1)
        {
            expenses(h1,b1);
        }
        else if(z==2)
        {
            expenses(h1,t1);
        }
        else if(z==3)
        {
            expenses(h1,a1);
        }
        cout<<endl;
        goto menu;
    }
     else if (choice == 6)
    {
        cout << "Goodbye!" << endl;
        return 0;
    }
    else
    {
        cout << "Invalid choice. Please enter a valid option." << endl;
        goto menu;
    }
}
