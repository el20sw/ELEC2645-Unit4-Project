/*  Screen Controller Class
*   Methods for interfacing with LCD
*/

#ifndef SCREEN_CONTROLLER_H
#define SCREEN_CONTROLLER_H

#include "mbed.h"
#include "N5110.h"

class ScreenController{
    public:
        //LCD (N5110) Object
        N5110 *lcd;

        //constructor
        ScreenController();

        //turn Off LCD
        void ScreenOff();

        //custom initialisation of LCD
        void customInit();

        //clears entire LCD
        void clearLCD();

        //LCD Displays Alert and flashes
        void dispAlert();

        //LCD Displays Locked
        void dispLocked();
        
        //LCD Displays Unlocked
        void dispUnlocked();

    private:

};

#endif