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

