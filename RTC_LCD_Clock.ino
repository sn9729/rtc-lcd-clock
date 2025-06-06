#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

// Initialize the LCD with I2C address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Create an RTC object
RTC_DS3231 rtc;

void setup() {
  lcd.begin(16, 2);  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  Serial.begin(9600);

  // Initialize the RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1); // Stop if RTC not found
  }
  rtc.adjust(DateTime(2024, 9, 14, 23, 37, 0)); // Set time manually while running the code for the first time and then change this statement into a comment
}

void loop() {
  DateTime now = rtc.now();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  lcd.print(twoDigit(now.day()));
  lcd.print("/");
  lcd.print(twoDigit(now.month()));
  lcd.print("/");
  lcd.print(now.year());

  lcd.setCursor(0, 1);
  lcd.print("Time: ");

  // Convert hour to 12-hour format
  int hour = now.hour();
  String ampm;

  if (hour >= 12) {
    ampm = "PM";
    if (hour > 12) hour -= 12;
  } else {
    ampm = "AM";
    if (hour == 0) hour = 12;
  }

  lcd.print(twoDigit(hour));
  lcd.print(":");
  lcd.print(twoDigit(now.minute()));
  lcd.print(":");
  lcd.print(twoDigit(now.second()));
  lcd.print("");
  lcd.print(ampm);

  delay(1000);
}

String twoDigit(int number) {
  if (number < 10) {
    return "0" + String(number);
  } else {
    return String(number);
  }
}
