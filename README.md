# ⏰ RTC Clock with LCD using DS3231 and LiquidCrystal_I2C

This project displays real-time **date and time** on a 16x2 LCD using an **RTC DS3231 module** and **I2C LCD** with Arduino.

## 🧰 Components Required

| Component          | Quantity |
|-------------------|----------|
| Arduino UNO/Nano   | 1        |
| RTC Module (DS3231)| 1        |
| LCD 16x2 I2C       | 1        |
| Jumper Wires       | As needed|
| Breadboard         | 1        |

## 🔌 Circuit Connections

### LCD (I2C 0x27)
| LCD Pin | Arduino Pin |
|---------|-------------|
| GND     | GND         |
| VCC     | 5V          |
| SDA     | A4          |
| SCL     | A5          |

### RTC DS3231
| RTC Pin | Arduino Pin |
|---------|-------------|
| GND     | GND         |
| VCC     | 5V          |
| SDA     | A4          |
| SCL     | A5          |

## 📦 Libraries Required

Install from **Library Manager**:
- `LiquidCrystal_I2C`
- `RTClib`
- `Wire`

## 🛠 How to Use

1. Connect the components as per the table above.
2. Open `RTC_LCD_Clock.ino` in Arduino IDE.
3. Upload the code.
4. **First time only**: Uncomment and adjust the `rtc.adjust()` line to set the time.
5. Comment that line after uploading to preserve RTC time on reset.

## 🖥 Sample LCD Output

```
Date: 14/09/2024
Time: 11:37:00PM
```
