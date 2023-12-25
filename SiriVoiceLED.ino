#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

// WiFi 설정
const char* ssid = "iPhone";
const char* password = "10101010";

// 호스트 주소 (Json값 받아올 때 필요)
const char* host = "dweet.io";

// LED 제어핀 설정
int LED = D1;

void setup() {
  Serial.begin(115200);

  // WiFi 연결 시도
  WiFi.begin(ssid, password);

  // 핀을 출력모드로 설정
  pinMode(LED, OUTPUT);

  // WiFi 연결상태 루프
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  getDweets();
}

void getDweets() {
  // 통신에 사용할 client 생성
  WiFiClient client;

  // 클라이언트 타임아웃 설정
  // client.setTimeout(10000);
  
  // Dweet(서버) 연결 실패 처리
  if (!client.connect(host, 80)) {
    Serial.println(F("Dweet connection failed"));
    return;
  }

  delay(1000);
  
  client.println("GET /get/latest/dweet/for/soraeya HTTP/1.0"); // 서버에 HTTP GET 요청을 전송
  client.println("Host: dweet.io"); // 호스트 헤더 추가
  client.println("Connection: closed"); //연결을 닫는 것을 요청

  delay(1000);
  
  // 요청 실패 처리
  if (client.println() == 0) {
    Serial.println("Failed to send request to dweet.io");
    return;
  }

  // json 부분 추출
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      // 빈 줄이 나타나면 HTTP 헤더의 끝
      break;
    }
  }

  String jsonData = client.readString();
  
  // 출력
  Serial.println("Server Response:");
  Serial.println(jsonData);
  
  // Json 데이터를 저장할 정적 JsonDocument를 생성함 (최대 크기 512)
  StaticJsonDocument<512> doc;

  // 서버에서 받은 Json 데이터를 JsonDocument에 파싱함
  DeserializationError error = deserializeJson(doc, jsonData);

  // 파싱 실패 처리
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  
  // 각 필드의 값을 가져와 변수에 저장
  const char* this_ = doc["this"]; // "succeeded"
  const char* by = doc["by"]; // "getting"
  const char* the = doc["the"]; // "dweets"

  JsonObject with_0 = doc["with"][0];
  const char* with_0_thing = with_0["thing"]; // "soraeya"
  const char* with_0_created = with_0["created"]; // "2023-12-12T18:36:03.668Z"

  // 해당 값으로 on/off 처리할 수 있음
  const char* with_0_content_LED_Status = with_0["content"]["LED Status"]; // "On"
  
  Serial.print("with_0_content_LED_Status value --------------:");Serial.println(with_0_content_LED_Status);
  
  // LED 제어
  if (strcmp(with_0_content_LED_Status, "On") == 0) {
    digitalWrite(LED, HIGH);  // LED를 켬
  } else {
    digitalWrite(LED, LOW);  // LED를 끔
  }
  
  // 서버 연결 끊어진 경우, 클라이언트를 중지하며 프로그램 종료
  if (!client.connected()) {
    Serial.println();
    Serial.println("Disconnected from server");
    client.stop(); // Stop the client
    return; // 루프 종료
  }
}
