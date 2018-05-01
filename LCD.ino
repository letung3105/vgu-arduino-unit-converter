void lcdPrintCenter(char msg[], uint8_t row){
    lcdClearLine(row);
    uint8_t col = (20 - strlen(msg)) / 2;
    lcd.setCursor(col, row);
    lcd.print(msg);
}


void lcdClearLine(byte row){
    lcd.setCursor(0, row);
    lcd.print("                    ");
}


void lcdPrintUnitType(){
    lcdClearLine(0);
    lcd.setCursor(0, 0);
    lcd.print(unitTypes[currentUnitType]);
}


void lcdPrintBaseUnit(){
    char buffer[20];
    if (currentUnitType == 0){
        strcpy_P(buffer, (char*)pgm_read_word(&(timeUnits[currentBaseUnit[currentUnitType]])));
        lcdPrintCenter(buffer, 1);
    } else if (currentUnitType == 1){
        strcpy_P(buffer, (char*)pgm_read_word(&(tempUnits[currentBaseUnit[currentUnitType]])));
        lcdPrintCenter(buffer, 1);
    } else if (currentUnitType == 2){
        strcpy_P(buffer, (char*)pgm_read_word(&(lengthUnits[currentBaseUnit[currentUnitType]])));
        lcdPrintCenter(buffer, 1);
    } else if (currentUnitType == 3){
        strcpy_P(buffer, (char*)pgm_read_word(&(massUnits[currentBaseUnit[currentUnitType]])));
        lcdPrintCenter(buffer, 1);
    }
}

void lcdPrintTargetUnit(){
    char buffer[20];
    if (currentUnitType == 0){
        strcpy_P(buffer, (char*)pgm_read_word(&(timeUnits[currentTargetUnit[currentUnitType]])));
        lcdPrintCenter(buffer, 2);
    } else if (currentUnitType == 1){
        strcpy_P(buffer, (char*)pgm_read_word(&(tempUnits[currentTargetUnit[currentUnitType]])));
        lcdPrintCenter(buffer, 2);
    } else if (currentUnitType == 2){
        strcpy_P(buffer, (char*)pgm_read_word(&(lengthUnits[currentTargetUnit[currentUnitType]])));
        lcdPrintCenter(buffer, 2);
    } else if (currentUnitType == 3){
        strcpy_P(buffer, (char*)pgm_read_word(&(massUnits[currentTargetUnit[currentUnitType]])));
        lcdPrintCenter(buffer, 2);
    }
}

void lcdPrintNumber(char number[]){
    byte n = strlen(number);
    bool isLarge = true;
    byte countPower = 0;
    byte countDecimal;
    byte firstPos;
    if (number[0] != '0'){
        for (byte i=0; i < n; i++){
            if (number[i] == '.'){
                if (i < 20) isLarge = false;
                break;
            } else countPower += 1;
        }
        if (isLarge){
            for (byte i=0; i < 14; i++){
                lcd.print(number[i]);
            }
            lcd.setCursor(14, 3);
            lcd.print("x10^");
            lcd.setCursor(18, 3);
            lcd.print(countPower - 14);
        } else {
            for (byte i=0; i < 20; i++){
                lcd.print(number[i]);
            }
        }
    } else {
        for (byte i=0; i < n; i++){
            if (number[i] != '0' && number[i] != '.'){
                countDecimal = i - 1;
                firstPos = i;
                Serial.print(countDecimal);
                break;
            }
        }
        if (firstPos + 13 <= n){
            for (byte i=firstPos; i < firstPos+13; i++){
                lcd.print(number[i]);
            }
        } else {
            for (byte i=firstPos; i < n; i++){
                lcd.print(number[i]);
            }
        }
        lcd.setCursor(13, 3);
        lcd.print("x10^-");
        lcd.setCursor(18, 3);
        lcd.print(countDecimal);
    }
}

void lcdPrintLayout(){
    lcdPrintUnitType();
    lcdPrintBaseUnit();
    lcdPrintTargetUnit();
}
