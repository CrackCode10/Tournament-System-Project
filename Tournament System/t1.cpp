#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <math.h>
using namespace std;

// --------------------- VARIABLE --------------------//
string opteamname;
string teamname;
string opentname;
string name;
string footteamname;
string footopteamname;
int howmanyplayer;
char yesno;
int value;

int yes = false;
int count = 0;
const int arraysize = 11;
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int flag4 = 0;
// --------------------FUNCTION PROTYPE ------------//
void menu();
void checkpassdigit(string passwort);
void checkmail(string emails);
int selectgame();
int admincheck();
void playertype();
void display(string criteamname, string playername[9], string playerfield[9]);
void displayplname();
void displayfootballtype();
void vsdisplay();
int change(string n);
string slice(string line, int field);

// _________________  File handling prototype  ______________

void storedata();
void storedatafootball();
void load_datacricket();
void load_datafootball();

// ---------------------ARRAY------------------------//

string playername[arraysize];
string playerfield[arraysize];

string opentplayername[arraysize];
string opentplayerfield[arraysize];

string footplayername[arraysize];
string footplayerfield[arraysize];

string opfootplayername[arraysize];
string opfootplayerfield[arraysize];

string s_name[arraysize];
string s_field[arraysize];

string s_optname[arraysize];
string s_optfield[arraysize];

string s_footname[arraysize];
string s_footfield[arraysize];

string s_footoptname[arraysize];
string s_footoptfield[arraysize];

main()
{
    // load_datacricket();

    string password = " ";
    string logpassword = " ";
    string email = " ", logemail = " ";

    menu();
    cout << "************     TEAM REGISTRATION    ***************" << endl;
    cout << "Enter the email: ";
    cin >> email;

    cout << "Set up a password: ";
    cin >> password;
    // checkmail(email);
    checkpassdigit(password);
    if (count > 7)
    {
        menu();
        cout << "************        ADD TEAM         ***************" << endl;
        int option = selectgame();
        cout << "Press any key to Login....";
        getch();
        system("cls");

        menu();
        int opti;
        cout << "1.Login as a  cricket team " << endl;
        cout << "2.Login as a football team " << endl;
        cout << "3.Login as an admin " << endl;
        cout << "Select one of the option: " << endl;
        cin >> opti;

        if (opti == 3)
        {
            menu();
            cout << "**********     ONLY ADMIN CAN LOGIN    *******************" << endl;
            // this is the login password and id
            while (logemail != "qaim@" || logpassword != "12345")
            {
                cout << "Enter your email id(qaim@):";
                cin >> logemail;
                cout << "Enter your password(12345) :";
                cin >> logpassword;
            }
            if (logemail == "qaim@" && logpassword == "12345")
            {

                menu();
                cout << "***********************   ADMIN    **********************" << endl;
                int options = admincheck();
                if (options == 1)
                {
                    cout << "-----------------  YOUR TEAM    ----------------" << endl;
                    cout << "TEAM NAME ----------------" << teamname << "---------" << endl;
                    cout << "CAPTAIN NAME  ------------" << name << "--------------" << endl;

                    displayplname();

                    // sorting batsman
                    for (int c = 0; c < howmanyplayer; c++)
                    {
                        if (playerfield[c] == "b")
                        {
                            cout << playername[c] << "\t \t" << playerfield[c] << endl;
                        }
                    }
                    // soring for allrounder
                    for (int d = 0; d < howmanyplayer; d++)
                    {
                        if (playerfield[d] == "a")
                        {
                            cout << playername[d] << "\t \t" << playerfield[d] << endl;
                        }
                    }
                    // sorting for bowler
                    for (int e = 0; e < howmanyplayer; e++)
                    {
                        if (playerfield[e] == "bo")
                        {
                            cout << playername[e] << "\t \t" << playerfield[e] << endl;
                        }
                    }

                    vsdisplay();

                    cout << "-----------------   OPPONENT TEAM    ----------------" << endl;
                    cout << "TEAM NAME ----------------" << opteamname << "---------" << endl;
                    cout << "CAPTAIN NAME  ------------" << opentname << "--------------" << endl;
                    displayplname();
                    for (int t = 0; t < howmanyplayer; t++)
                    {
                        if (opentplayerfield[t] == "b")
                        {
                            cout << opentplayername[t] << "\t \t" << opentplayerfield[t] << endl;
                        }
                    }
                    // soring for allrounder
                    for (int n = 0; n < howmanyplayer; n++)
                    {
                        if (opentplayerfield[n] == "a")
                        {
                            cout << opentplayername[n] << "\t \t" << opentplayerfield[n] << endl;
                        }
                    }
                    // sorting for bowler
                    for (int p = 0; p < howmanyplayer; p++)
                    {
                        if (opentplayerfield[p] == "bo")
                        {
                            cout << opentplayername[p] << "\t \t" << opentplayerfield[p] << endl;
                        }
                    }
                }
            }
        }

        if (opti == 1)
        {
            menu();
            cout << "**************    Login as a team    ***********" << endl;

            while (email != logemail || password != logpassword)
            {
                cout << "Enter your email id: ";
                cin >> logemail;
                cout << "Enter your password: ";
                cin >> logpassword;
            }
            if (email == logemail && password == logpassword)
            {

                if (option == 1)
                {

                    cout << endl;
                    cout << "---------------Game Cricket-----------------" << endl;
                    cout << "----------------Information of your team----------" << endl;
                    cout << "Enter your team name ";
                    cin >> teamname;
                    cout << "Enter the captain  name: ";
                    cin >> name;
                    cout << "How many player you want to Enter";
                    cin >> howmanyplayer;

                    playertype();
                    cout << endl;
                    for (int x = 0; x < howmanyplayer; x++)
                    {

                        cout << "Enter the name of player:";
                        cin >> playername[x];
                        cout << "Enter the player type: ";
                        cin >> playerfield[x];
                        cout << endl;
                        storedata();
                    }
                    cout << endl;
                    cout << "Press any key to add oponent team.... ";
                    getch();
                    system("cls");

                    cout << "-----Information of oponent team------" << endl;
                    cout << "--------------Game Cricket-----------------" << endl;
                    cout << "Enter the team name ";
                    cin >> opteamname;
                    cout << "Enter the captain name: ";
                    cin >> opentname;
                    playertype();
                    cout << endl;
                    for (int opent = 0; opent < howmanyplayer; opent++)
                    {

                        cout << "Enter the name of player:";
                        cin >> opentplayername[opent];
                        cout << "Enter the player type: ";
                        cin >> opentplayerfield[opent];
                        cout << endl;
                        storedata();
                    }
                }

                cout << "Enter if you want to remove player(Y or N): ";
                cin >> yesno;

                if (yesno == 'y')
                {
                    cout << "How many player you want to remove ";
                    cin >> value;

                    string nameofplayer;
                    for (int r1 = 1; r1 <= value; r1++)
                    {

                        cout << "--" << r1 << "--"
                             << "Enter name of player to Remove: " << endl;
                        cin >> nameofplayer;
                        for (int i = 0; i < howmanyplayer; i++)
                        {
                            if (playername[i] == nameofplayer)
                            {
                                playername[i] = ' ';
                                playerfield[i] = ' ';
                            }
                            else if (opentplayername[i] == nameofplayer)
                            {
                                opentplayername[i] = ' ';
                                opentplayerfield[i] = ' ';
                            }
                        }
                    }
                }
                if (yesno = 'n')
                {
                    menu();
                    cout << "**********     ONLY ADMIN CAN LOGIN    *******************" << endl;

                    while (logemail != "qaim@" || logpassword != "12345")
                    {
                        cout << "Enter your email id(qaim@):";
                        cin >> logemail;
                        cout << "Enter your password(12345) :";
                        cin >> logpassword;
                    }
                    if (logemail == "qaim@" && logpassword == "12345")
                    {
                        menu();
                        cout << "***********************   ADMIN    **********************" << endl;
                        int options = admincheck();
                        if (options == 1)
                        {
                            cout << "-----------------  YOUR TEAM    ----------------" << endl;
                            cout << "TEAM NAME ----------------" << teamname << "---------" << endl;
                            cout << "CAPTAIN NAME  ------------" << name << "--------------" << endl;

                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (playerfield[i] == "b")
                                {
                                    s_field[flag1] = playerfield[i];
                                    s_name[flag1] = playername[i];

                                    flag1++;
                                }
                            }
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (playerfield[i] == "a")
                                {
                                    s_field[flag1] = playerfield[i];
                                    s_name[flag1] = playername[i];

                                    flag1++;
                                }
                            }
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (playerfield[i] == "bo")
                                {
                                    s_field[flag1] = playerfield[i];
                                    s_name[flag1] = playername[i];

                                    flag1++;
                                }
                            }
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                cout << s_name[i] << "\t" << s_field[i] << endl;
                            }

                            vsdisplay();

                            cout << "-----------------   OPPONENT TEAM    ----------------" << endl;
                            cout << "TEAM NAME ----------------" << opteamname << "---------" << endl;
                            cout << "CAPTAIN NAME  ------------" << opentname << "--------------" << endl;

                            displayplname();
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (opentplayerfield[i] == "b")
                                {
                                    s_optfield[flag2] = opentplayerfield[i];
                                    s_optname[flag2] = opentplayername[i];

                                    flag2++;
                                }
                            }
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (opentplayerfield[i] == "a")
                                {
                                    s_optfield[flag2] = opentplayerfield[i];
                                    s_optname[flag2] = opentplayername[i];

                                    flag2++;
                                }
                            }
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (opentplayerfield[i] == "bo")
                                {
                                    s_optname[flag2] = opentplayername[i];
                                    s_optfield[flag2] = opentplayerfield[i];

                                    flag2++;
                                }
                            }

                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                cout << s_optname[i] << "\t " << s_optfield[i] << endl;
                            }
                        }
                    }
                }
            }
        }
        if (opti == 2)
        {

            if (option == 2)
            {

                cout << endl;
                cout << "-----------------  Game Football -------------" << endl;
                cout << "-----------------  Enter your team -------------" << endl;
                cout << "Enter how many football player: ";
                cin >> howmanyplayer;
                cout << "Enter the name of your team: ";
                cin >> footteamname;
                cout << endl;
                displayfootballtype();
                cout << endl;
                for (int f = 0; f < howmanyplayer; f++)
                {

                    cout << "Enter the name of player:";
                    cin >> footplayername[f];
                    cout << "Enter the player type: ";
                    cin >> footplayerfield[f];
                    cout << endl;
                    storedatafootball();
                }
                cout << endl;
                cout << "Press any key to add oponent team... ";
                getch();
                system("cls");

                cout << "-----------Information of oponent team----------" << endl;
                cout << "--------------Game Football-----------------" << endl;
                cout << "Enter the name of your team: ";
                cin >> footopteamname;
                cout << endl;
                displayfootballtype();
                cout << endl;

                for (int footop = 0; footop < howmanyplayer; footop++)
                {

                    cout << "Enter the name of player: ";
                    cin >> opfootplayername[footop];
                    cout << "Enter the player type: ";
                    cin >> opfootplayerfield[footop];
                    cout << endl;
                    storedatafootball();
                }
                cout << endl;
                cout << "Enter if you remove player(Y or N): ";
                cin >> yesno;
                if (yesno == 'y')
                {
                    cout << "How many player you want to remove ";
                    cin >> value;
                    string nameofplayer;
                    for (int ss = 1; ss <= value; ss++)
                    {

                        cout << "--" << ss << "--"
                             << "Enter name of player to Remove: " << endl;
                        cin >> nameofplayer;
                        for (int i = 0; i < howmanyplayer; i++)
                        {
                            if (playername[i] == nameofplayer)
                            {
                                footplayername[i] = ' ';
                                footplayerfield[i] = ' ';
                            }
                            else if (opentplayername[i] == nameofplayer)
                            {
                                opentplayername[i] = ' ';
                                opentplayerfield[i] = ' ';
                            }
                        }
                    }
                }
                if (yesno == 'n')
                {
                    menu();
                    cout << "**********     ONLY ADMIN CAN LOGIN    **************" << endl;

                    while (logemail != "qaim@" || logpassword != "12345")
                    {
                        cout << "Enter your email id(qaim@):";
                        cin >> logemail;
                        cout << "Enter your password(12345) :";
                        cin >> logpassword;
                    }
                    if (logemail == "qaim@" && logpassword == "12345")
                    {
                        menu();
                        cout << "***********************   ADMIN    **************************" << endl;
                        int options = admincheck();
                        if (options == 2)
                        {
                            cout << "-----------------  YOUR TEAM    ----------------" << endl;
                            cout << "TEAM NAME ----------------" << footteamname << "---------" << endl;

                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (footplayerfield[i] == "g")
                                {
                                    s_footfield[flag3] = footplayerfield[i];
                                    s_footname[flag3] = footplayername[i];

                                    flag3++;
                                }
                            }
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (footplayerfield[i] == "d")
                                {
                                    s_footfield[flag3] = footplayerfield[i];
                                    s_footname[flag3] = footplayername[i];

                                    flag3++;
                                }
                            }
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (footplayerfield[i] == "m")
                                {
                                    s_footfield[flag3] = footplayerfield[i];
                                    s_footname[flag3] = footplayername[i];

                                    flag3++;
                                }
                            }
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (footplayerfield[i] == "f")
                                {
                                    s_footfield[flag3] = footplayerfield[i];
                                    s_footname[flag3] = footplayername[i];

                                    flag3++;
                                }
                            }

                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                cout << s_footname[i] << "\t" << s_footfield[i] << endl;
                            }

                            vsdisplay();

                            cout << "-----------------   OPPONENT TEAM    ----------------" << endl;
                            cout << "TEAM NAME ----------------" << footopteamname << "---------" << endl;

                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (opfootplayerfield[i] == "g")
                                {
                                    s_footoptfield[flag4] = opfootplayerfield[i];
                                    s_footoptname[flag4] = opfootplayername[i];

                                    flag4++;
                                }
                            }
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (opfootplayerfield[i] == "d")
                                {
                                    s_footoptfield[flag4] = opfootplayerfield[i];
                                    s_footoptname[flag4] = opfootplayername[i];

                                    flag4++;
                                }
                            }
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (opfootplayerfield[i] == "m")
                                {
                                    s_footoptfield[flag4] = opfootplayerfield[i];
                                    s_footoptname[flag4] = opfootplayername[i];

                                    flag4++;
                                }
                            }
                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                if (opfootplayerfield[i] == "f")
                                {
                                    s_footoptfield[flag4] = opfootplayerfield[i];
                                    s_footoptname[flag4] = opfootplayername[i];

                                    flag4++;
                                }
                            }

                            for (int i = 0; i < howmanyplayer; i++)
                            {
                                cout << s_footoptname[i] << "\t" << s_footoptfield[i] << endl;
                            }
                        }
                    }
                }
            }
        }
        // end of football
        if (option == 3)
        {
            string opbadplayername;
            string badplayername;
            cout << "----------Game Badminton--------------" << endl;
            cout << "Enter your  name:";
            cin >> badplayername;
            cout << endl;

            cout << "Press any key to add oponent team... ";
            getch();
            system("cls");

            cout << "----Information of oponent player-----";
            cout << "----------Game Badminton--------------" << endl;
            cout << "Enter your  name:";
            cin >> opbadplayername;

            menu();
            cout << "**********     ONLY ADMIN CAN LOGIN    **************" << endl;
            // this is the login password and id

            while (logemail != "qaim@" || logpassword != "12345")
            {
                cout << "Enter your email id(qaim@):";
                cin >> logemail;
                cout << "Enter your password(12345) :";
                cin >> logpassword;
            }
            if (logemail == "qaim@" && logpassword == "12345")
            {
                menu();
                cout << "***********************   ADMIN    **************************" << endl;
                int options = admincheck();
                if (options == 3)
                {
                    cout << "----------   " << badplayername << "    ---------- ";
                    vsdisplay();
                    cout << "----------   " << opbadplayername << "  ---------- ";
                }
            }
        }

        if (option == 4)
        {
            string chessplayername;
            string opchessplayername;
            cout << endl;
            cout << "------------Game Chess----------" << endl;
            cout << "Enter your name: ";
            cin >> chessplayername;

            cout << endl;

            cout << "Press any key to add oponent team... ";
            getch();
            system("cls");

            cout << "------------Game Chess----------" << endl;
            cout << "----Information of oponent player---- ";
            cout << "Enter your name: ";
            cin >> opchessplayername;
            cout << endl;
            menu();
            cout << "\n";
            cout << "**********     ONLY ADMIN CAN LOGIN    **************" << endl;
            // this is the login password and id

            while (logemail != "qaim@" || logpassword != "12345")
            {
                cout << "Enter your email id(qaim@):";
                cin >> logemail;
                cout << "Enter your password(12345) :";
                cin >> logpassword;
            }
            if (logemail == "qaim@" && logpassword == "12345")
            {
                menu();
                cout << "***********************   ADMIN    **************************" << endl;
                int options = admincheck();
                if (options == 4)
                {
                    cout << "----------   " << chessplayername << "    ---------- ";
                    vsdisplay();
                    cout << "----------   " << opchessplayername << "  ---------- ";
                }
            }
        }
    }
    else if (email != logemail)
    {
        cout << " TEAM enter a wrong id" << endl;
    }
}

void menu()
{
    cout << "*****************************************************" << endl;
    cout << "*********   TOURNAMENT MANAGEMENT SYSTEM    *********" << endl;
}
int selectgame()
{

    cout << "1.cricket" << endl;
    cout << "2.football" << endl;
    cout << "3.badminton" << endl;
    cout << "4.chess" << endl;
    int op;

    cout << "Select options of the game" << endl;
    cin >> op;
    return op;
}

void checkpassdigit(string passwort)
{

    for (int y = 0; y < passwort[y]; y++)
    {
        count++;
    }
}
void checkmail(string emails)
{

    for (int o = 0; o < emails[o]; o++)
    {
        if (emails[o] == '@')
        {
            yes = true;
            // continue;
            break;
        }
        else
        {
            yes = false;
        }
    }
}
void playertype()
{
    cout << "\n";
    cout << "Press (b for batsman) & (a for All Rounder) & (bo for Bowler):" << endl;
    cout << "Batsman" << endl;
    cout << "All Rounder" << endl;
    cout << "Bowler" << endl;
    cout << "\n";
}
void display(string criteamname, string playername[9], string playerfield[9])
{
    cout << "!------------" << criteamname << "------------!";
    for (int i = 0; i < 9; i++)
    {
        cout << i << "----" << playername[i] << "\t\t" << playerfield[i];
    }
    cout << endl;
}
int admincheck()
{
    int optio;
    cout << "View Record " << endl;
    cout << "1.cricket" << endl;
    cout << "2.football" << endl;
    cout << "3.badminton" << endl;
    cout << "4.chess" << endl;
    cout << "Which game your want to check: ";
    cin >> optio;
    return optio;
}

void displayplname()
{
    cout << "  Players Name    Players Type" << endl;
}

void displayfootballtype()
{
    cout << "Press (g for Goalkeeper) (d for Defender) (m for Midfielder) (f for Forward) " << endl;
    cout << "Goalkeeper\n";
    cout << "Defender\n";
    cout << "Midfielder\n";
    cout << "Forward\n";
}

void vsdisplay()
{
    cout << "\n\n";
    cout << "          %        %    %%%%%%%%%         " << endl;
    cout << "           %      %     %                   " << endl;
    cout << "            %    %      %%%%%%%%%         " << endl;
    cout << "             %  %               %         " << endl;
    cout << "              %%        %%%%%%%%%         " << endl;
    cout << "\n\n";
}

// _______________________________  File handling  ______________________________
void storedata()
{
    fstream file;
    file.open("cricket.txt", ios::out);
    for (int i = 0; i < howmanyplayer; i++)
    {

        file << playername[i] << "," << playerfield[i] << endl;
    }

    file << "-" << endl;

    for (int z = 0; z < howmanyplayer; z++)
    {

        file << opentplayername[z] << "," << opentplayerfield[z] << endl;
    }

    file.close();
}

void storedatafootball()
{
    fstream football;
    football.open("football.txt", ios::out);
    for (int i = 0; i < howmanyplayer; i++)
    {

        football << footplayername[i] << "," << footplayerfield[i] << endl;
    }

    football << "-" << endl;

    for (int z = 0; z < howmanyplayer; z++)
    {

        football << opentplayername[z] << "," << opentplayerfield[z] << endl;
    }

    football.close();
}

string slice(string line, int field)
{
    string word;
    int comma = 0;
    for (int s = 0; s < line.length(); s++)
    {
        if (line[s] = ',')
        {
            comma++;
        }
        else if (comma == field)
        {
            word += line[s];
        }
    }
    return word;
}

int change(string n)
{
    if (n == "0")
    {
        return 0;
    }
    float num = 0;
    int x = 0;
    for (int i = 0; i < n.length(); i++)

    {
        x = (n[n.length() - i - 1]) - 48;
        num = num + x * pow(10, i);
    }
    return num;
}

void load_datacricket()
{
    string line;
    fstream cricket;
    cricket.open("cricket.txt", ios::in);
    int i = 0;
    string name;
    string field;
    while (!(cricket.eof()))
    {
        getline(cricket, line);
        playername[i] = slice(line, 0);
        name = slice(line, 1);

        i++;
    }

    cricket.close();
}

void load_datafootball()
{
    string line;
    fstream foot;
    foot.open("football.txt", ios::in);
    for (int i = 0; i < howmanyplayer; i++)
    {
        getline(foot, line);
        footplayername[i] = line[i];
    }
    foot.close();
}
