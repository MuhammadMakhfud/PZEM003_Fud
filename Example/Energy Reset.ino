#include <PZEM003_Fud.h>

// Define RX and TX pins (SoftwareSerial)
PZEM003_Fud pzem(7, 8); // RX, TX

void setup()
{
    Serial.begin(115200);
    pzem.begin(9600);
    Serial.println("Ketik 'reset' di Serial Monitor untuk reset energi");
}

void loop()
{
    pzem.update();

    Serial.print("Energy: ");
    Serial.print(pzem.getEnergy());
    Serial.println(" Wh");

    if (Serial.available())
    {
        String command = Serial.readStringUntil('\n');
        command.trim();
        if (command == "reset")
        {
            pzem.resetEnergy();
            Serial.println("Energi di-reset!");
        }
    }

    delay(1000);
}
