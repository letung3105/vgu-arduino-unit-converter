BigNumber getTimeMultiplier(byte selection){
    char *value;
    if (selection == 0)
        value = "1"; // seconds
    else if (selection == 1)
        value = "0.001"; // millisecond
    else if (selection == 2)
        value = "0.000001"; // microsecond
    else if (selection == 3)
        value = "0.000000001"; // nanosecond
    // else if (selection == 4)
    //     value = "0.000000000001"; // picosecond
    else if (selection == 4)
        value = "60"; // minute
    else if (selection == 5)
        value = "3600"; // hour
    else if (selection == 6)
        value = "86400"; // day
    else if (selection == 7)
        value = "604800"; // week
    // else if (selection == 9)
    //     value = "31536000"; // year

    return BigNumber(value);
}


BigNumber getTempOffset(byte selection){
    char *value;
    if (selection == 0)
        value = "0";
    else if (selection == 1)
        value = "-32";
    else if (selection == 2)
        value = "-273.15";
    else if (selection == 3)
        value = "-150";
    else if (selection == 4)
        value = "-0";
    else if (selection == 5)
        value = "-491.67";
    else if (selection == 6)
        value = "-7.5";

    return BigNumber(value);
}


BigNumber getTempMultiplier(byte selection){
    char *value;
    if (selection == 0 )
        value = "1"; // Celsius
    else if (selection == 1)
        value = "1.8"; // Fahrenheit
    else if (selection == 2)
        value = "1"; // Kelvin
    else if (selection == 3)
        value = "-1.5"; // Delisle
    else if (selection == 4)
        value = "0.33"; // Newton
    else if (selection == 5)
        value = "1.8"; // Rankine
    else if (selection == 6)
        value = "0.525"; // Romer

    BigNumber multiplier = BigNumber(1) / BigNumber(value);
    return multiplier;
}


BigNumber getLengthMultiplier(byte selection){
    char *value;
    if (selection == 0)
        value = "1000"; // km
    else if (selection == 1)
        value = "100"; // hm
    else if (selection == 2)
        value = "10"; // dam
    else if (selection == 3)
        value = "1"; // m
    else if (selection == 4)
        value = "0.1"; // dm
    else if (selection == 5)
        value = "0.01"; // cm
    else if (selection == 6)
        value = "0.001"; // mm
    else if (selection == 7)
        value = "0.0000254"; // th
    else if (selection == 8)
        value = "0.0254"; // in
    else if (selection == 9)
        value = "0.3048"; // ft
    else if (selection == 10)
        value = "0.9144"; // yd
    else if (selection == 11)
        value = "20.1168"; // ch
    else if (selection == 12)
        value = "201.168"; // fur
    else if (selection == 13)
        value = "1609.344"; // mi
    else if (selection == 14)
        value = "4828.032"; // lea
    else if (selection == 15)
        value = "1.852";  // ftm
    else if (selection == 16)
        value = "185.2"; // cable
    else if (selection == 17)
        value = "1852"; // nautical mile
    else if (selection == 18)
        value = "0.0000000001"; // Angstrom
    else if (selection == 19)
        value = "149597870700"; // AU

    return BigNumber(value);
}


BigNumber getMassMultiplier(byte selection){
    char *value;
    // if (selection == 0)
    //     value = "5972200000000000000000000"; // Earth mass
    if (selection == 0)
        value = "0.0000002176"; // Planck mass
    // else if (selection == 2)
    //     value = "1990000000000000000000000000000"; // Solar mass
    else if (selection == 1)
        value = "0.0002"; // Cara
    else if (selection == 2)
        value = "1"; // Kilogram
    // else if (selection == 5)
    //     value = "0.00000000000000000000000000166053886"; // U
    else if (selection == 3)
        value = "0.000001"; // milligram
    else if (selection == 4)
        value = "0.001"; // gram
    else if (selection == 5)
        value = "0.01"; // decagram
    else if (selection == 6)
        value = "0.1"; // hectogram
    else if (selection == 7)
        value = "0.000000001"; // microgram
    else if (selection == 8)
        value = "0.000000000001"; // nanogram
    // else if (selection == 12)
    //     value = "0.000000000000001"; // picogram
    else if (selection == 9)
        value = "0.0283495231"; // ounce avoirdupois
    else if (selection == 10)
        value = "0.0311034768"; // ounce troy

    return BigNumber(value);
}
