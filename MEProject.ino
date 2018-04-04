#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const byte numRows= 4;
const byte numCols= 4;

char keymap[numRows][numCols] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

char* unitTypes[] = {
    "Length",
    "Mass",
    "Time"
};
uint8_t currentType = 0;
const uint8_t nTypes = 3;

char* conversion[nTypes][2] = {
    {"cm->m", "m->Angstrom"},
    {"Kg->g", "Ton->Kg"},
    {"Hour->Min", "Min->Sec"}
};
uint8_t nConvertion[] = {2, 2, 2};
uint8_t currentConversion = 0;

byte rowPins[numRows] = {9, 8, 7, 6};
byte colPins[numCols]= {5, 4, 3, 2};

Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
    // initialize the LCD
    lcd.begin(20, 4);

    lcd.setCursor(0, 0);
    lcd.write("Unit type:");
    clearPrint(unitTypes[currentType], 11, 19, 0);

    lcd.setCursor(0, 1);
    lcd.write("Convert:");
    clearPrint(conversion[currentType][currentConversion], 9, 19, 1);

    Serial.begin(9600);
}

void loop()
{
    char keypressed = myKeypad.getKey();
    if (keypressed == 'A'){
        currentConversion = 0;
        currentType += 1;
        if (currentType == nTypes){
            currentType = 0;
        }
        clearPrint(conversion[currentType][currentConversion], 9, 19, 1);
        Serial.println(currentType);
        clearPrint(unitTypes[currentType], 11, 19, 0);
    }
    if (keypressed == 'B'){
        currentConversion += 1;
        if (currentConversion == nConvertion[currentType]){
            currentConversion = 0;
        }
        Serial.println(currentConversion);
        clearPrint(conversion[currentType][currentConversion], 9, 19, 1);
    }
}


void clearPrint(char writeString[], uint8_t startCol, uint8_t endCol, uint8_t row){
    for (uint8_t i=startCol; i <= endCol; i++){
        lcd.setCursor(i, row);
        lcd.write(' ');
    }
    lcd.setCursor(startCol, row);
    lcd.write(writeString);
}
