#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <LiquidCrystal_I2C.h>

const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

ESP8266WebServer server(80);

LiquidCrystal_I2C lcd(0x27, 16, 2);

String notice = "Welcome";

void displayNotice()
{
    lcd.clear();

    if (notice.length() <= 16)
    {
        lcd.setCursor(0, 0);
        lcd.print(notice);
    }
    else
    {
        lcd.setCursor(0, 0);
        lcd.print(notice.substring(0, 16));

        lcd.setCursor(0, 1);
        lcd.print(notice.substring(16, 32));
    }
}

void handleHome()
{
    String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>IoT Notice Board</title>
</head>

<body>
    <h2>IoT Notice Board</h2>

    <form action="/update" method="GET">
        <input type="text"
               name="message"
               maxlength="32"
               placeholder="Enter notice">

        <input type="submit" value="Update Notice">
    </form>

    <p>Current Notice:</p>
    <strong>
)rawliteral";

    page += notice;

    page += R"rawliteral(
    </strong>
</body>
</html>
)rawliteral";

    server.send(200, "text/html", page);
}

void handleUpdate()
{
    if (server.hasArg("message"))
    {
        notice = server.arg("message");
        notice.trim();

        if (notice.length() == 0)
        {
            notice = "No Notice";
        }

        displayNotice();
    }

    server.sendHeader("Location", "/");
    server.send(303);
}

void connectWiFi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
}

void setup()
{
    Serial.begin(115200);

    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("IoT Notice");
    lcd.setCursor(0, 1);
    lcd.print("Connecting...");

    connectWiFi();

    displayNotice();

    server.on("/", handleHome);
    server.on("/update", handleUpdate);

    server.begin();

    Serial.println();
    Serial.println("IoT Notice Board Ready");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
    server.handleClient();
}
