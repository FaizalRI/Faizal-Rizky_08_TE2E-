#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoOTA.h>
#include <DHT.h>

// Konfigurasi Wi-Fi
const char* ssid = "MATIC HEDON !!!";       // Ganti dengan SSID WiFi Anda
const char* password = "12345678"; // Ganti dengan password WiFi Anda

// Konfigurasi sensor DHT
#define DHTPIN 4  // Pin data DHT
#define DHTTYPE DHT22 // Tipe DHT: DHT11 atau DHT22
DHT dht(DHTPIN, DHTTYPE);

// Web server
ESP8266WebServer server(80);

// Fungsi untuk menampilkan halaman web
void handleRoot() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  String html = "<!DOCTYPE html><html>";
  html += "<head><title>DHT Sensor</title></head>";
  html += "<body>";
  html += "<h1>Data Sensor DHT</h1>";
  if (isnan(temperature) || isnan(humidity)) {
    html += "<p>Gagal membaca data dari sensor!</p>";
  } else {
    html += "<p><strong>Suhu:</strong> " + String(temperature) + " &deg;C</p>";
    html += "<p><strong>Kelembapan:</strong> " + String(humidity) + " %</p>";
  }
  html += "</body></html>";
  server.send(200, "text/html", html);
}

// Fungsi setup OTA
void setupOTA() {
  ArduinoOTA.setHostname("ESP8266-DHT"); // Nama perangkat OTA
  ArduinoOTA.onStart([]() {
    String type = (ArduinoOTA.getCommand() == U_FLASH) ? "sketch" : "filesystem";
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  Serial.println("OTA Ready");
}

// Setup awal
void setup() {
  Serial.begin(115200);
  dht.begin();

  // Koneksi ke Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan ke WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi terhubung");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Konfigurasi server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server siap");

  // Inisialisasi OTA
  setupOTA();
}

// Loop utama
void loop() {
  server.handleClient(); // Menangani request HTTP
  ArduinoOTA.handle();   // Menangani OTA
}
