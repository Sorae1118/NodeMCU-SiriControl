# Siri를 활용하여 LED 제어하기 (NodeMCU)
<br>

## 프로젝트 소개
* ESP8266 마이크로컨트롤러와 Dweet.io 플랫폼, Siri를 이용하여, 인터넷을 통한 원격 LED 제어를 구현했습니다.
* 이를 통해 언제 어디서나 스마트폰 또는 다른 장치를 통해 LED의 상태를 제어할 수 있습니다.
<br>

## 🔨 Tech
* Arduino IDE
* Shortcuts<br><img width="154" alt="image" src="https://github.com/Sorae1118/NodeMCU-SiriControl/assets/115053276/0514cc39-d658-44e1-b978-77d7014ce297">
* [dweet.io](https://dweet.io/)<br><img width="230" alt="image" src="https://github.com/Sorae1118/NodeMCU-SiriControl/assets/115053276/18b53b9f-2045-4de5-986a-f7b44ecd5141">

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


3. 회원가입 화면
* 회원가입 페이지입니다.
* 각 절차마다 예외 처리 필요(구현 예정)![image](https://github.com/Sorae1118/Music-Streaming/assets/115053276/2c06c600-9902-486e-88c2-137e2f081bbe)
<br><br><br>

4. 메인 스트리밍 화면
* 메인 스크롤시 보이는 스트리밍 앨범 페이지입니다.
* 앨범을 클릭하면 해당 노래의 URL이 호출됩니다. 음원 재생 푸터는 해당 URL로 초기화되어 노래를 재생할 수 있습니다. ![image](https://github.com/Sorae1118/Music-Streaming/assets/115053276/36e7334b-5b0d-4b4a-9f53-e473ec78ebf3)
<br><br><br>






      



