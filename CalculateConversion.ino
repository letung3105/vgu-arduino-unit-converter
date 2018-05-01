BigNumber convert(){
    BigNumber baseMultiplier;
    BigNumber targetMultiplier;
    BigNumber baseOffset = 0;
    BigNumber targetOffset = 0;

    char baseBuffer[20], targetBuffer[20];

    byte n = user_input.length() + 1;
    char input[n];
    user_input.getBytes(input, n);

    if (currentUnitType == 0){
        strcpy_P(baseBuffer, (char*)pgm_read_word(&(timeMultipliers[currentBaseUnit[currentUnitType]])));
        strcpy_P(targetBuffer, (char*)pgm_read_word(&(timeMultipliers[currentTargetUnit[currentUnitType]])));

        baseMultiplier = BigNumber(baseBuffer);
        targetMultiplier = BigNumber(targetBuffer);
    } else if (currentUnitType == 1){
        char baseBufferOffset[20], targetBufferOffset[20];

        strcpy_P(baseBuffer, (char*)pgm_read_word(&(tempMultipliers[currentBaseUnit[currentUnitType]])));
        strcpy_P(targetBuffer, (char*)pgm_read_word(&(tempMultipliers[currentTargetUnit[currentUnitType]])));
        strcpy_P(baseBufferOffset, (char*)pgm_read_word(&(tempOffset[currentBaseUnit[currentUnitType]])));
        strcpy_P(targetBufferOffset, (char*)pgm_read_word(&(tempOffset[currentTargetUnit[currentUnitType]])));

        baseMultiplier = BigNumber(1) / BigNumber(baseBuffer);
        targetMultiplier = BigNumber(1) / BigNumber(targetBuffer);
        baseOffset = BigNumber(baseBufferOffset);
        targetOffset = BigNumber(targetBufferOffset);
    } else if (currentUnitType == 2){
        strcpy_P(baseBuffer, (char*)pgm_read_word(&(lengthMultipliers[currentBaseUnit[currentUnitType]])));
        strcpy_P(targetBuffer, (char*)pgm_read_word(&(lengthMultipliers[currentTargetUnit[currentUnitType]])));

        baseMultiplier = BigNumber(baseBuffer);
        targetMultiplier = BigNumber(targetBuffer);
    } else if (currentUnitType == 3){
        strcpy_P(baseBuffer, (char*)pgm_read_word(&(massMultipliers[currentBaseUnit[currentUnitType]])));
        strcpy_P(targetBuffer, (char*)pgm_read_word(&(massMultipliers[currentTargetUnit[currentUnitType]])));

        baseMultiplier = BigNumber(baseBuffer);
        targetMultiplier = BigNumber(targetBuffer);
    }

    Serial.println(baseMultiplier);
    Serial.println(baseOffset);
    Serial.println(targetMultiplier);
    Serial.println(targetOffset);

    BigNumber result = BigNumber(input) + baseOffset;
    result *= baseMultiplier;
    result /= targetMultiplier;
    result -= targetOffset;
    return result;
}
