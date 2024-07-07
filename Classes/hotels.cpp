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

