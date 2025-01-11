#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4 //define green LED pin
#define LED_R 5 //define red LED
#define BUZZER 2 //buzzer pin

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
Servo myServo; //define servo name

String content = "";

void setup() {
    Serial.begin(9600);                 // Initialize serial communications with the PC
    while (!Serial);                    // Do nothing if no serial port is opened (for ATMEGA32U4 boards)
    SPI.begin();                        // Init SPI bus
    mfrc522.PCD_Init();                 // Init MFRC522
    delay(4);                           // Optional delay. Some boards require more time after initialization
    myServo.attach(7); //servo pin
    myServo.write(0); //servo start position

    pinMode(LED_G, OUTPUT);
    pinMode(LED_R, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    noTone(BUZZER);
    Serial.println("Put your card to the reader...");
}

void loop() {
    // Check if a new card is present
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }

    // Select the card
    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }

    // Display the card's UID
    Serial.print(F("Card UID: "));
    content = ""; // Clear the content first
    for (byte i = 0; i < mfrc522.uid.size; i++) {
        content += String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ") + String(mfrc522.uid.uidByte[i], HEX);
    }
    content.replace(" ", ""); // Remove spaces
    content.toUpperCase();     // Convert to uppercase
    Serial.println("Captured UID: " + content);
    mfrc522.PICC_HaltA();

    if (content == "73DE3529") {
        Serial.println("Authorized access");
        digitalWrite(LED_G, HIGH);
        tone(BUZZER, 500);
        delay(300);
        noTone(BUZZER);
        myServo.write(180);
        delay(5000);
        myServo.write(0);
        digitalWrite(LED_G, LOW);
    } else {
        Serial.println("Access denied");
        digitalWrite(LED_R, HIGH);
        tone(BUZZER, 300);
        delay(1000);
        digitalWrite(LED_R, LOW);
        noTone(BUZZER);
    }
}