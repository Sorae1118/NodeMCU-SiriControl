# Siri를 활용하여 LED 제어하기 (NodeMCU)
<br>

## 프로젝트 소개
* ESP8266 마이크로컨트롤러와 Dweet.io 플랫폼, Siri를 이용하여, 인터넷을 통한 원격 LED 제어를 구현했습니다.
* 이를 통해 언제 어디서나 스마트폰 또는 다른 장치를 통해 LED의 상태를 제어할 수 있습니다.
<br>

## 🔨 Tech
* Arduino IDE
* Shortcuts<br><img width="154" alt="image" src="https://github.com/Sorae1118/NodeMCU-SiriControl/assets/115053276/0514cc39-d658-44e1-b978-77d7014ce297">
* [dweet.io](https://dweet.io/)<br><img width="230" alt="image" src="https://github.com/Sorae1118/NodeMCU-SiriControl/assets/115053276/18b53b9f-2045-4de5-986a-f7b44ecd5141"><br>
* Dweet은 디바이스 간에 데이터를 쉽게 주고 받을 수 있음. HTTP요청을 통해 JSON 형식의 데이터를 송수신
* 단점 : 테스트 결과 응답 속도가 생각보다 많이 느린 듯 하다...

<br>

## 📀 Function
1. 시리 음성 제어 (Shortcuts==단축어)
2. dweet.io 객체 저장
3. LED on/off
<br>

## 📺 구현순서

1. dweet.io에서 URL 생성하기
* Play버튼 클릭
* POST/dweet/for/{thing} 라벨 클릭, 이름 정하기
* Try it out! 버튼 클릭후 URL 복사
<img width="458" alt="image" src="https://github.com/Sorae1118/NodeMCU-SiriControl/assets/115053276/cbb812f3-b3ba-4e8f-a7b9-3c33f17869a6">
<br><br><br>

2. Shortcuts(단축어) 생성
* URL 변수 생성 후 링크 붙여넣기
* 컨텐츠 가져오기에 URL 변수 연결. POST 메소드 사용 String 형태의 키와 값을 생성
* 말하기에서 원하는 실행 보이스를 설정
<img width="439" alt="image" src="https://github.com/Sorae1118/NodeMCU-SiriControl/assets/115053276/a5905cbf-a2eb-4923-b07c-c111694399da">
<br><br><br>

* 브라우저로 해당 링크로 들어가면 객체에 담긴 정보를 확인할 수 있음.
<img width="838" alt="image" src="https://github.com/Sorae1118/NodeMCU-SiriControl/assets/115053276/0fd06a3e-c056-4b3f-920a-3c80a56999fe">
<img width="838" alt="image" src="https://github.com/Sorae1118/NodeMCU-SiriControl/assets/115053276/6043150f-c82b-403b-962b-7958fb058428">
<br><br><br>

3. Arduino Json Assistant 사이트 활용
* JSON 객체를 넣으면 자동으로 IDE 내에서 사용할 수 있는 파싱 코드 생성
* 번호 순으로 진행하면 된다.
* <img width="450" alt="image" src="https://github.com/Sorae1118/NodeMCU-SiriControl/assets/115053276/20134be2-0816-429a-a38e-226f9fb9d91c">
<br><br><br>

4. IDE 프로그래밍
* 필요한 라이브러리 추가(ESP8266,ArduinoJson)
* 클라이언트 생성, 연결 실패 처리
* GET 요청 => /get/latest/dweet/for/soraeya 경로 필수 (thing 이름) => 헤더 추가 => 연결 닫기
<img width="480" alt="image" src="https://github.com/Sorae1118/NodeMCU-SiriControl/assets/115053276/5581981c-cc8a-40fa-9a6b-fc12799c345c">
<br><br><br>

5. IDE 프로그래밍
* 데이터 한 줄 씩 읽어오는 것을 반복해 JSON 부분만 추출
* JSON 데이터를 파싱
* 각 값을 가져와 변수에 저장. (이 프로젝트에서는 LED Status 값만 사용)
<img width="487" alt="image" src="https://github.com/Sorae1118/NodeMCU-SiriControl/assets/115053276/fb124808-722c-4b42-ba31-a0459f1bef90">
<br><br><br>


