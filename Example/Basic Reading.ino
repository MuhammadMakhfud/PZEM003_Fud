#include <PZEM003_Fud.h>

// Define RX and TX pins (SoftwareSerial)
PZEM003_Fud pzem(7, 8); // RX, TX

void setup()
{
    Serial.begin(115200);
    pzem.begin(9600);
}

void loop()
{
    pzem.update();

    Serial.print("Voltage: ");
    Serial.print(pzem.getVoltage());
    Serial.println(" V");

    Serial.print("Current: ");
    Serial.print(pzem.getCurrent());
    Serial.println(" A");

    Serial.print("Power: ");
    Serial.print(pzem.getPower());
    Serial.println(" W");

    Serial.print("Energy: ");
    Serial.print(pzem.getEnergy());
    Serial.println(" Wh");

    delay(1000);
}