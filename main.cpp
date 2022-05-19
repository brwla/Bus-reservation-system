#include <iostream>
#include <string.h>
#include "conio.h"
using namespace std;

static int p = 0;

class a {
    char busn[5], driver[15], arrival[5], depart[5], from[15], to[15], seat[8][4][15];

public:
    void add();
    void update();
    void allotment();
    void remove();
    void empty();
    void search();
    void avail();
    void position(int i);
}

bus[10];

void vline(char ch) {
    for (int i=80;i>0;i--)
    cout<<ch;
}

void a::add() {
    cout<<"Enter bus no: ";
    cin>>bus[p].busn;
    cout<<"\nEnter Driver's name: ";
    cin>>bus[p].driver;
    cout<<"\nArrival time: ";
    cin>>bus[p].arrival;
    cout<<"\nDeparture time: ";
    cin>>bus[p].depart;
    cout<<"\nFrom: ";
    cin>>bus[p].from;
    cout<<"\nTo: ";
    cin>>bus[p].to;
    bus[p].empty();
    p++;
}

void a::empty() {
    for(int i=0; i<8; i++) {
        for(int j=0;j<4;j++) {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}

void a::update() {
    char number[5];
    int k;
    cout<<"Enter bus no: ";
    cin>>number;
    for (k=0;k<10;k++) {
        if (strcmp(bus[k].busn, number)==0) {
            cout<<"\nEnter Updated Driver's name: ";
            cin>>bus[k].driver;
            cout<<"\nUpdated Arrival time: ";
            cin>>bus[k].arrival;
            cout<<"\nUpdated Departure time: ";
            cin>>bus[k].depart;
            cout<<"\nUpdated From: ";
            cin>>bus[k].from;
            cout<<"\nUpdated To: ";
            cin>>bus[k].to;
            break;
        }
    }
    if (strcmp(bus[k].busn, number)!=0){
        cout<<"No entry.\n";
    }
}

void a::allotment() {
    int seat;
    char number[5];
    cout<<"Bus no: ";
    cin>>number;
    int n;
    for(n=0;n<=p;n++) {
        if(strcmp(bus[n].busn, number)==0)
        break;
    }
    while(n<=p) {
        cout<<"\nSeat Number: ";
        cin>>seat;
        if(seat>32) {
            cout<<"\nThere are only 32 seats available in this bus.";
        }
        else {
            if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0) {
                cout<<"Enter passenger's name: ";
                cin>>bus[n].seat[seat/4][(seat%4)-1];
                break;
            } else {
                cout<<"The seat no. is already reserved.\n";
            }
        }
    }
    if(n>p) {
        cout<<"No entry.\n";
    }
}

void a::remove() {
    int seatdel;
    char number[5];
    cout<<"Bus no: ";
    cin>>number;
    int n;
    for(n=0;n<=p;n++) {
        if(strcmp(bus[n].busn, number)==0)
        break;
    }
    while(n<=p) {
        cout<<"\nSeat Number: ";
        cin>>seatdel;
        if(seatdel>32) {
            cout<<"\nThere are only 32 seats available in this bus.";
        } else {
             if(strcmp(bus[n].seat[seatdel/4][(seatdel%4)-1],"Empty")!=0) {
                cout<<"Enter new passenger name or Enter 'Empty' to delete passenger: ";
                cin>>bus[n].seat[seatdel/4][(seatdel%4)-1];
            } else {
                cout<<"The seat no. is not reserved.\n";
            }
        }
            break;
    }
}


void a::search() {
    int n;
    char number[5];
    cout<<"Enter bus no: ";
    cin>>number;
    for(n=0;n<=p;n++) {
        if(strcmp(bus[n].busn, number)==0)
        break;
    }
    while(n<=p) {
        vline('*');
        cout<<"\nBus no: \t"<<bus[n].busn
        <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
        <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
        <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
        bus[n].to<<"\n";
        vline('*');
        bus[0].position(n);
        int a=1;
        for (int i=0; i<8; i++) {
            for(int j=0;j<4;j++) {
                a++;
                if(strcmp(bus[n].seat[i][j],"Empty")!=0)
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
            if(strcmp(bus[l].seat[i][j], "Empty")==0) {
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
    for(int n=0;n<p;n++) {
        if (bus[n].busn != " ") {
            vline('*');
            cout<<"\nBus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver
            <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
            <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"
            <<bus[n].to<<"\n";
            vline('*');
            cout<<'\n';
            vline('_');
            cout<<'\n';
        }
    }
}

int main() {
    start:
    int w,choice;
    while(1) {
        system("cls");
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\tBUS RESERVATION SYSTEM\n\n\t\t\t"
        <<"1.Admin.\n\t\t\t"
        <<"2.Reservation.\n\t\t\t"
        <<"3.Search Available Seat.\n\t\t\t"
        <<"4.View Available Bus. \n\t\t\t"
        <<"5.Exit.";
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
                    <<"4.Back to main menu.\n\t\t\t";
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
                            goto start;
                        }

                        default:{
                            goto admin;
                        }
                    }
                } else {
                    goto start;
                }
            }  

            case 2:{
                bus[p].allotment();
                cout << "\n\nPress any key to continue...";
                _getch();
                break;
            }
            case 3:{
                bus[0].search();
                cout << "\n\nPress any key to continue...";
                _getch();
                break;
            }
            case 4:{
                bus[0].avail();
                cout << "\n\nPress any key to continue...";
                _getch();
                break;
            }
            case 5:
                exit(0);

            default:
                goto start;
        }
    }
    return 0;
}