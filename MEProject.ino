#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <BigNumber.h>

const byte LED = 13;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Keypad's number of rows and columns
const byte numRows = 4;
const byte numCols = 4;

// Keypad's mapping
char keymap[numRows][numCols] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'.', '0', '-', 'D'}
};

// Arduino's pins used for keypad
byte rowPins[numRows] = {9, 8, 7, 6};
byte colPins[numCols]= {5, 4, 3, 2};

// Keypad object
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

// Type of units
char* unitTypes[] = {
    "Time",
    "Temperature",
    "Length",
    "Mass",
};

const PROGMEM char timeMul1[] = "1"; // seconds
const PROGMEM char timeMul2[] = "0.001"; // millisecond
const PROGMEM char timeMul3[] = "0.000001"; // microsecond
const PROGMEM char timeMul4[] = "0.000000001"; // nanosecond
const PROGMEM char timeMul5[] = "0.000000000001"; // picosecond
const PROGMEM char timeMul6[] = "60"; // minute
const PROGMEM char timeMul7[] = "3600"; // hour
const PROGMEM char timeMul8[] = "86400"; // day
const PROGMEM char timeMul9[] = "604800"; // week
const PROGMEM char timeMul10[] = "31536000"; // year

const PROGMEM char timeUnit1[] = "Second";
const PROGMEM char timeUnit2[] = "Millisecond";
const PROGMEM char timeUnit3[] = "Microsecond";
const PROGMEM char timeUnit4[] = "Nanosecond";
const PROGMEM char timeUnit5[] = "Picosecond";
const PROGMEM char timeUnit6[] = "Minute";
const PROGMEM char timeUnit7[] = "Hour";
const PROGMEM char timeUnit8[] = "Day";
const PROGMEM char timeUnit9[] = "Week";
const PROGMEM char timeUnit10[] = "Year";

const PROGMEM char* const timeMultipliers[] = {
    timeMul1, timeMul2, timeMul3, timeMul4, timeMul5,
    timeMul6, timeMul7, timeMul8, timeMul9, timeMul10
};

const PROGMEM char* const timeUnits[] = {
    timeUnit1, timeUnit2, timeUnit3, timeUnit4, timeUnit5,
    timeUnit6, timeUnit7, timeUnit8, timeUnit9, timeUnit10
};

// 1 / tempMultiplier
const PROGMEM char tempMul1[] = "1"; // Celsius
const PROGMEM char tempMul2[] = "1.8"; // Fahrenheit
const PROGMEM char tempMul3[] = "1"; // Kelvin
const PROGMEM char tempMul4[] = "-1.5"; // Delisle
const PROGMEM char tempMul5[] = "0.33"; // Newton
const PROGMEM char tempMul6[] = "1.8"; // Rankine
const PROGMEM char tempMul7[] = "0.525"; // Romer

const PROGMEM char tempUnit1[] = "Celsius";
const PROGMEM char tempUnit2[] = "Fahrenheit";
const PROGMEM char tempUnit3[] = "Kelvin";
const PROGMEM char tempUnit4[] = "Delisle";
const PROGMEM char tempUnit5[] = "Newton";
const PROGMEM char tempUnit6[] = "Rankine";
const PROGMEM char tempUnit7[] = "Romer";

const PROGMEM char* const tempMultipliers[] = {
    tempMul1, tempMul2, tempMul3, tempMul4, tempMul5,
    tempMul6, tempMul7
};

const PROGMEM char* const tempUnits[] = {
    tempUnit1, tempUnit2, tempUnit3, tempUnit4, tempUnit5,
    tempUnit6, tempUnit7
};

const PROGMEM char tempOffset1[] = "0";
const PROGMEM char tempOffset2[] = "-32";
const PROGMEM char tempOffset3[] = "-273.15";
const PROGMEM char tempOffset4[] = "-150";
const PROGMEM char tempOffset5[] = "-0";
const PROGMEM char tempOffset6[] = "-491.67";
const PROGMEM char tempOffset7[] = "-7.5";

const PROGMEM char* const tempOffset[] = {
    tempOffset1, tempOffset2, tempOffset3,
    tempOffset4, tempOffset5, tempOffset6, tempOffset7
};

const PROGMEM char lengthMul1[] = "1000"; // km
const PROGMEM char lengthMul2[] = "100"; // hm
const PROGMEM char lengthMul3[] = "10"; // dam
const PROGMEM char lengthMul4[] = "1"; // m
const PROGMEM char lengthMul5[] = "0.1"; // dm
const PROGMEM char lengthMul6[] = "0.01"; // cm
const PROGMEM char lengthMul7[] = "0.001"; // mm
const PROGMEM char lengthMul8[] = "0.0000254"; // th
const PROGMEM char lengthMul9[] = "0.0254"; // in
const PROGMEM char lengthMul10[] = "0.3048"; // ft
const PROGMEM char lengthMul11[] = "0.9144"; // yd
const PROGMEM char lengthMul12[] = "20.1168"; // ch
const PROGMEM char lengthMul13[] = "201.168"; // fur
const PROGMEM char lengthMul14[] = "1609.344"; // mi
const PROGMEM char lengthMul15[] = "4828.032"; // lea
const PROGMEM char lengthMul16[] = "1.852";  // ftm
const PROGMEM char lengthMul17[] = "185.2"; // cable
const PROGMEM char lengthMul18[] = "1852"; // nautical mile
const PROGMEM char lengthMul19[] = "0.0000000001"; // Angstrom
const PROGMEM char lengthMul20[] = "149597870700"; // AU

const PROGMEM char lengthUnit1[] = "Kilometer"; // km
const PROGMEM char lengthUnit2[] = "Hectometer"; // hm
const PROGMEM char lengthUnit3[] = "Decameter"; // dam
const PROGMEM char lengthUnit4[] = "Meter"; // m
const PROGMEM char lengthUnit5[] = "Decimeter"; // dm
const PROGMEM char lengthUnit6[] = "Centimeter"; // cm
const PROGMEM char lengthUnit7[] = "Millimeter"; // mm
const PROGMEM char lengthUnit8[] = "Thou"; // th
const PROGMEM char lengthUnit9[] = "Inch"; // in
const PROGMEM char lengthUnit10[] = "Foot"; // ft
const PROGMEM char lengthUnit11[] = "Yard"; // yd
const PROGMEM char lengthUnit12[] = "Chain"; // ch
const PROGMEM char lengthUnit13[] = "Furlong"; // fur
const PROGMEM char lengthUnit14[] = "Mile"; // mi
const PROGMEM char lengthUnit15[] = "League"; // lea
const PROGMEM char lengthUnit16[] = "Fathom";  // ftm
const PROGMEM char lengthUnit17[] = "Cable"; // cable
const PROGMEM char lengthUnit18[] = "Nautical mile"; // nautical mile
const PROGMEM char lengthUnit19[] = "Angstrom"; // Angstrom
const PROGMEM char lengthUnit20[] = "Astronomic unit"; // AU

const PROGMEM char* const lengthMultipliers[] = {
    lengthMul1, lengthMul2, lengthMul3, lengthMul4, lengthMul5,
    lengthMul6, lengthMul7, lengthMul8, lengthMul9, lengthMul10,
    lengthMul11, lengthMul12, lengthMul13, lengthMul14, lengthMul15,
    lengthMul16, lengthMul17, lengthMul18, lengthMul19, lengthMul20
};

const PROGMEM char* const lengthUnits[] = {
    lengthUnit1, lengthUnit2, lengthUnit3, lengthUnit4, lengthUnit5,
    lengthUnit6, lengthUnit7, lengthUnit8, lengthUnit9, lengthUnit10,
    lengthUnit11, lengthUnit12, lengthUnit13, lengthUnit14, lengthUnit15,
    lengthUnit16, lengthUnit17, lengthUnit18, lengthUnit19, lengthUnit20
};

const PROGMEM char massMul1[] = "5972200000000000000000000"; // Earth mass
const PROGMEM char massMul2[] = "0.0000002176"; // Planck mass
const PROGMEM char massMul3[] = "1990000000000000000000000000000"; // Solar mass
const PROGMEM char massMul4[] = "0.0002"; // Cara
const PROGMEM char massMul5[] = "1"; // Kilogram
const PROGMEM char massMul6[] = "0.00000000000000000000000000166053886"; // U
const PROGMEM char massMul7[] = "0.000001"; // milligram
const PROGMEM char massMul8[] = "0.001"; // gram
const PROGMEM char massMul9[] = "0.01"; // decagram
const PROGMEM char massMul10[] = "0.1"; // hectogram
const PROGMEM char massMul11[] = "0.000000001"; // microgram
const PROGMEM char massMul12[] = "0.000000000001"; // nanogram
const PROGMEM char massMul13[] = "0.000000000000001"; // picogram
const PROGMEM char massMul14[] = "0.0283495231"; // ounce avoirdupois
const PROGMEM char massMul15[] = "0.0311034768"; // ounce troy

const PROGMEM char massUnit1[] = "Earth's mass"; // Earth mass
const PROGMEM char massUnit2[] = "Planck mass"; // Planck mass
const PROGMEM char massUnit3[] = "Solar's mass"; // Solar mass
const PROGMEM char massUnit4[] = "Cara"; // Cara
const PROGMEM char massUnit5[] = "Kilogram"; // Kilogram
const PROGMEM char massUnit6[] = "Unified atomic mass"; // U
const PROGMEM char massUnit7[] = "Milligram"; // milligram
const PROGMEM char massUnit8[] = "Gram"; // gram
const PROGMEM char massUnit9[] = "Decagram"; // decagram
const PROGMEM char massUnit10[] = "Hectogram"; // hectogram
const PROGMEM char massUnit11[] = "Microgram"; // microgram
const PROGMEM char massUnit12[] = "Nanogram"; // nanogram
const PROGMEM char massUnit13[] = "Picogram"; // picogram
const PROGMEM char massUnit14[] = "Ounce avoirdupois"; // ounce avoirdupois
const PROGMEM char massUnit15[] = "Ounce troy"; // ounce troy

const PROGMEM char* const massMultipliers[] = {
    massMul1, massMul2, massMul3, massMul4, massMul5,
    massMul6, massMul7, massMul8, massMul9, massMul10,
    massMul11, massMul12, massMul13, massMul14, massMul15
};

const PROGMEM char* const massUnits[] = {
    massUnit1, massUnit2, massUnit3, massUnit4, massUnit5,
    massUnit6, massUnit7, massUnit8, massUnit9, massUnit10,
    massUnit11, massUnit12, massUnit13, massUnit14, massUnit15
};

byte currentUnitType = 0;
byte maxUnitType = 4;
BigNumber conversionMultiplier[20];

byte currentBaseUnit[] = {0, 0, 0, 0}; // current selected unit for each unit type
byte currentTargetUnit[] = {0, 0, 0, 0};
byte maxUnit[] = {10, 7, 20, 15}; // max number of unit in each unit type

String user_input = "";


void setup()
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    // initialize the LCD
    lcd.begin(20, 4);
    // initialize BigNumber library
    BigNumber::begin();
    BigNumber::setScale(40);
    lcdPrintLayout();
}

void loop()
{
    char keyPressed = myKeypad.getKey();

    if (keyPressed != NO_KEY){
        byte user_input_length = user_input.length();

        Serial.println(keyPressed);

        if (keyPressed == 'A'){
            currentUnitType +=1;
            if (currentUnitType == maxUnitType){
                currentUnitType = 0;
            }
            lcdClearLine(3);
            user_input = "";
            lcdPrintLayout();
        } else if (keyPressed == 'B'){
            currentBaseUnit[currentUnitType] += 1;
            if (currentBaseUnit[currentUnitType] == maxUnit[currentUnitType]){
                currentBaseUnit[currentUnitType] = 0;
            }
            lcdClearLine(3);
            user_input = "";
            lcdPrintBaseUnit();
        } else if (keyPressed == 'C'){
            currentTargetUnit[currentUnitType] += 1;
            if (currentTargetUnit[currentUnitType] == maxUnit[currentUnitType]){
                currentTargetUnit[currentUnitType] = 0;
            }
            lcdClearLine(3);
            user_input = "";
            lcdPrintTargetUnit();
        } else if (keyPressed == 'D'){
            if (user_input != ""){
                BigNumber result = convert();
                Serial.println(result);
                lcdClearLine(3);
                lcd.setCursor(0, 3);
                lcdPrintNumber(result.toString());
                user_input = "";
            }
        } else if (keyPressed == '-'){
            lcdClearLine(3);
            user_input = "";
        } else {
            if (user_input_length < 20){
                user_input += keyPressed;
            }
            lcdClearLine(3);
            lcd.setCursor(0, 3);
            lcd.print(user_input);
        }
    }
}
