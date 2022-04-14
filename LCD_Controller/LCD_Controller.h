/*  LCD Controller Class
*   Methods for interfacing with LCD
*/

#ifndef LCD_CONTROLLER_H
#define LCD_CONTROLLER_H

#include "mbed.h"
#include "N5110.h"

class LCD_Controller{
    public:
        //LCD (N5110) Object
        N5110 *lcd;

        //constructor
        LCD_Controller();

        //turn Off LCD
        void lcdOff();

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