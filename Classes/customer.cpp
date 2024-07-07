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
