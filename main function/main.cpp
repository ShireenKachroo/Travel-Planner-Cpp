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
