#include<bits/stdc++.h>
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

int main(int argc,char *argv[])
{

    int x=1,y=11,w=0,t=45;
    char letter;
    vector<char> word;
    vector<char> original;
    cout<<"type in th coded word,type '0' to exit,press 'ENTER' to type new word"<<endl;
    while(letter!='0')
    {
        t=45;

        letter=getch();
        cout<<letter;
        gotoxy(x,6);
        switch(letter)
        {
            case 'a':
            case 'A':
            cout<<"Z";
            word.push_back('Z');
            original.push_back(letter);
            break;
            case 'b':
            case 'B':
            cout<<"Y";
            word.push_back('Y');
            original.push_back(letter);
            break;
            case 'c':
            case 'C':
            cout<<"X";
            word.push_back('X');
            original.push_back(letter);
            break;
            case 'd':
            case 'D':
            cout<<"W";
            word.push_back('W');
            original.push_back(letter);
            break;
            case 'e':
            case 'E':
            cout<<"V";
            word.push_back('V');
            original.push_back(letter);
            break;
            case 'f':
            case 'F':
            cout<<"U";
            word.push_back('U');
            original.push_back(letter);
            break;
            case 'g':
            case 'G':
            cout<<"T";
            word.push_back('T');
            original.push_back(letter);
            break;
            case 'h':
            case 'H':
            cout<<"S";
            word.push_back('S');
            original.push_back(letter);
            break;
            case 'i':
            case 'I':
            cout<<"R";
            word.push_back('R');
            original.push_back(letter);
            break;
            case 'j':
            case 'J':
            cout<<"Q";
            word.push_back('Q');
            original.push_back(letter);
            break;
            case 'k':
            case 'K':
            cout<<"P";
            word.push_back('P');
            original.push_back(letter);
            break;
            case 'l':
            case 'L':
            cout<<"O";
            word.push_back('O');
            original.push_back(letter);
            break;
            case 'm':
            case 'M':
            cout<<"N";
            word.push_back('N');
            original.push_back(letter);
            break;
            case 'n':
            case 'N':
            cout<<"M";
            word.push_back('M');
            original.push_back(letter);
            break;
            case 'o':
            case 'O':
            cout<<"L";
            word.push_back('L');
            original.push_back(letter);
            break;
            case 'p':
            case 'P':
            cout<<"K";
            word.push_back('K');
            original.push_back(letter);
            break;
            case 'q':
            case 'Q':
            cout<<"J";
            word.push_back('J');
            original.push_back(letter);
            break;
            case 'r':
            case 'R':
            cout<<"I";
            word.push_back('I');
            original.push_back(letter);
            break;
            case 's':
            case 'S':
            cout<<"H";
            word.push_back('H');
            original.push_back(letter);
            break;
            case 't':
            case 'T':
            cout<<"G";
            word.push_back('G');
            original.push_back(letter);
            break;
            case 'u':
            case 'U':
            cout<<"F";
            word.push_back('F');
            original.push_back(letter);
            break;
            case 'v':
            case 'V':
            cout<<"E";
            word.push_back('E');
            original.push_back(letter);
            break;
            case 'w':
            case 'W':
            cout<<"D";
            word.push_back('D');
            original.push_back(letter);
            break;
            case 'x':
            case 'X':
            cout<<"C";
            word.push_back('C');
            original.push_back(letter);
            break;
            case 'y':
            case 'Y':
            cout<<"B";
            word.push_back('B');
            original.push_back(letter);
            break;
            case 'z':
            case 'Z':
            cout<<"A";
            word.push_back('A');
            original.push_back(letter);
            break;
            case '0':
            return EXIT_SUCCESS;
            break;
            case '\b':
                gotoxy(x,4);
                cout<<"\b"<< " "<<"\b\b";
                gotoxy(x,6);
                cout<<"\b"<<"  "<<"\b\b";
                x=x-2;
                word.pop_back();
                original.pop_back();
                break;
            case '\r':
                gotoxy(1,4);
                cout<<"                                                          ";
                gotoxy(1,6);
                cout<<"                                                          ";


                x=0;
                gotoxy(45,10);
                cout<<"previously entered:";
                vector<char>::iterator input;
                vector<char>::iterator final;
                gotoxy(t,y);
                for(input=original.begin();input!=original.end();input++)
                {
                    cout<<* input;
                }
                cout<<" * ";
                t=t+3+original.size();
                gotoxy(t,y);
                for(final=word.begin();final!=word.end();final++)
                {
                    cout<< *final;
                }
                y++;
                word.clear();
                original.clear();
                break;
        }
        x++;

    }
    return EXIT_SUCCESS;
}
