#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

static int p = 0;

class a {
    string driver, arrival, depart, from, to, seat[8][4];
    int busn;
public:
    void add();
    void update();
    void allotment();
    void remove();
    void empty();
    void search();
    void position(int i);
    void avail();
} bus[10];

void vline(char ch) {
    for (int i=80;i>0;i--)
    cout<<ch;
}

void a::add() {
    addBusAgain:
    cout<<"Enter bus no: ";
    cin>>bus[p].busn;
    for (int x = 0; x < p; x++) {
        if (bus[p].busn == bus[x].busn) {
            cout<<"Bus number already exists.\nTry again.\n";
            cin.clear();
            goto addBusAgain;
        }
    }
    cout<<"\nEnter Driver's name: ";
    cin.ignore();
    getline(cin, bus[p].driver);
    cout<<"\nArrival time: ";
    getline(cin, bus[p].arrival);
    cout<<"\nDeparture time: ";
    getline(cin, bus[p].depart);
    cout<<"\nFrom: ";
    getline(cin, bus[p].from);
    cout<<"\nTo: ";
    getline(cin, bus[p].to);
    bus[p].empty();
    p++;
}

void a::empty() {
    for(int i=0; i<8; i++) {
        for(int j=0;j<4;j++) {
            bus[p].seat[i][j] = "Empty";
        }
    }
}

void a::update() {
    int bus_number;
    int k;
    cout<<"Enter bus no: ";
    cin>>bus_number;
    for (k=0;k<10;k++) {
        if (bus[k].busn == bus_number) {
            cout<<"\nEnter Updated Driver's name: ";
            cin.ignore();
            getline(cin, bus[k].driver);
            cout<<"\nEnter Updated Arrival time: ";
            getline(cin, bus[k].arrival);
            cout<<"\nEnter Updated Departure time: ";
            getline(cin, bus[k].depart);
            cout<<"\nEnter Updated From: ";
            getline(cin, bus[k].from);
            cout<<"\nEnter Updated To: ";
            getline(cin, bus[k].to);
            break;
        }
    }
    if (bus[k].busn != bus_number){
        cout<<"No entry.\n";
    }
}

void a::allotment() {
    int seat, number;
    cout<<"Bus no: ";
    cin>>number;
    int d;
    for(d=0;d<=p;d++) {
        if(bus[d].busn == number)
        break;
    }
    while(d<=p) {
        cout<<"\nSeat Number (1-32): ";
        cin>>seat;
        if(seat>32) {
            cout<<"\nThere are only 32 seats available in this bus.";
        }
        else {
            if (bus[d].seat[seat/4][(seat%4)-1] == "Empty") {
                cout<<"Enter passenger's name: ";
                cin.ignore();
                getline(cin, bus[d].seat[seat/4][(seat%4)-1]);
                break;
            } else {
                cout<<"The seat no. is already reserved.\n";
            }
        }
    }
    if(d>p) {
        cout<<"No entry.\n";
    }
}

void a::remove() {
    int seatdel, busbusnum;
    cout<<"Bus no: ";
    cin>>busbusnum;
    int c;
    for(c=0;c<=p;c++) {
        if(bus[c].busn == busbusnum)
        break;
    }
    while(c<=p) {
        cout<<"\nSeat Number (1-32): ";
        cin>>seatdel;
        if(seatdel>32) {
            cout<<"\nThere are only 32 seats available in this bus.";
        } else {
             if(bus[c].seat[seatdel/4][(seatdel%4)-1] != "Empty") {
                cout<<"Enter new passenger name or Enter 'Empty' to delete passenger: ";
                cin.ignore();
                getline(cin, bus[c].seat[seatdel/4][(seatdel%4)-1]);
            } else {
                cout<<"The seat no. is not reserved.\n";
            }
        }
            break;
    }
}


void a::search() {
    int n, srchnum;
    cout<<"Enter bus no: ";
    cin>>srchnum;
    for(n=0;n<=p;n++) {
        if(bus[n].busn == srchnum)
        break;
    }
    while(n<=p) {
        vline('*');
        cout<<"\nBus no: \t"<<bus[n].busn
        <<"\t\tDriver: \t\t"<<bus[n].driver<<"\nArrival time: \t"
        <<bus[n].arrival<<"\t\tDeparture time:\t\t"<<bus[n].depart
        <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"<<bus[n].to<<"\n";
        vline('*');
        bus[0].position(n);
        int a=1;
        for (int i=0; i<8; i++) {
            for(int j=0;j<4;j++) {
                a++;
                if(bus[n].seat[i][j] != "Empty")
                cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
            }
        }
        break;
    }
    if(n>p) {
        cout<<"Not found...";
    }
}

void a::position(int l) {
    int s=0;p=0;
    for (int i =0; i<8;i++) {
        cout<<"\n";
        for (int j = 0;j<4; j++) {
            s++;
            if (bus[l].seat[i][j] == "Empty") {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].seat[i][j];
                p++;
            } else {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].seat[i][j];
            }
        }
    }
    cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
}

void a::avail() {
    for(int f=0;f<p;f++) {
        if (bus[f].busn != '\0') {
            cout<<'\n';
            vline('*');
            cout<<"\nBus no: \t"<<bus[f].busn<<"\t\tDriver: \t\t"<<bus[f].driver
            <<"\nArrival time: \t"<<bus[f].arrival<<"\t\tDeparture Time: \t"
            <<bus[f].depart<<"\nFrom: \t\t"<<bus[f].from<<"\t\tTo: \t\t\t"
            <<bus[f].to<<"\n";
            vline('*');
            cout<<'\n';
            vline('_');
            cout<<'\n';
        }
    }
    if (bus[0].busn == '\0') {
        cout<<"\nNo bus added yet.\n";
    }
}

int main() {
    int w,choice,e;
    while (1) {
        start:
        system("cls");
        cout<<"\t\t\tBUS RESERVATION SYSTEM\n\n\t\t\t"
        <<"1.Admin.\n\t\t\t"
        <<"2.User.\n\t\t\t"
        <<"3.Exit.\n";
        cout<<"\n\t\t\tEnter your choice:-> ";
        cin>>w;
        switch(w) {
            case 1:{
                string pass;
                cout<<"Enter password: ";
                cin>>pass;
                if (pass == "admin") {
                    admin:
                    system("cls");
                    cout<<"\n\n\n\n\n";
                    cout<<"\t\t\tADMIN MENU\n\n\t\t\t"
                    <<"1.Add Bus.\n\t\t\t"
                    <<"2.Update Bus info.\n\t\t\t"
                    <<"3.Update/Delete passenger info.\n\t\t\t"
                    <<"4.Add Seat Reservation.\n\t\t\t"
                    <<"5.Search Bus.\n\t\t\t"
                    <<"6.List Bus.\n\t\t\t"
                    <<"7.Back to main menu.\n\n\t\t\t";
                    cout<<"Enter your choice:-> ";
                    cin>>choice;
                    switch(choice) {
                        case 1: {
                            bus[p].add();
                            cout << "\n\nPress any key to continue...";
                            _getch();
                            goto admin;
                            break;
                        }
                        
                        case 2: {
                            bus[p].update();
                            cout << "\n\nPress any key to continue...";
                            _getch();
                            goto admin;
                            break;
                        }

                        case 3: {
                            bus[p].remove();
                            cout << "\n\nPress any key to continue...";
                            _getch();
                            goto admin;
                            break;
                        }

                        case 4: {
                            bus[p].allotment();
                            cout << "\n\nPress any key to continue...";
                            _getch();
                            goto admin;
                            break;
                        }

                        case 5:{
                            bus[0].search();
                            cout << "\n\nPress any key to continue...";
                            _getch();
                            goto admin;
                            break;
                        }

                        case 6: {
                            bus[0].avail();
                            cout << "\n\nPress any key to continue...";
                            _getch();
                            goto admin;
                            break;
                        }

                        case 7:
                            goto start;

                        default:
                            goto admin;
                    }
                } else {
                    goto start;
                }
            }  

            case 2:{
                custMenu:
                system("cls");
                cout<<"\n\n\n\n\n";
                cout<<"\t\t\tCUSTOMER MENU\n\n\t\t\t"
                <<"1.Add Reservation.\n\t\t\t"
                <<"2.Search Available Seat.\n\t\t\t"
                <<"3.List Available Bus.\n\t\t\t"
                <<"4.Back to main menu.\n";
                cout<<"\n\t\t\tEnter your choice:-> ";
                cin>>e;
                switch(e) {
                    case 1:{
                        bus[p].allotment();
                        cout << "\n\nPress any key to continue...";
                        _getch();
                        goto custMenu;
                        break;
                    }

                    case 2:{
                        bus[0].search();
                        cout << "\n\nPress any key to continue...";
                        _getch();
                        goto custMenu;
                        break;
                    }

                    case 3:{
                        bus[0].avail();
                        cout << "\n\nPress any key to continue...";
                        _getch();
                        goto custMenu;
                        break;
                    }

                    case 4:
                        goto start;

                    default:
                        goto custMenu;
                }
            }

            case 3:
                exit(0);

            default:
                goto start;
        }
    }
    return 0;
}
