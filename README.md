# MFC_GameProject
mfc로 만든 똥 피하기 게임

-mysql 로컬호스트 주소로 연동
-코드 찾기에서 dsn을 검색 후 자기 자신의 환경에 맞게 설정 바람

schemas : gameproject

1. 회원관리 관련 member 테이블
ID : VARCHAR()
/PW : VARCHAR()
/NICKNAME : VARCHAR()
/NAME : VARCHAR()
/GENDER : VARCHAR(3)
/BIRTHDAY : VARCHAR(10)
/PHONE : VARCHAR(13)
/EXIST : INT

2. 랭킹 구현 관련 play_record 테이블
nickname : VARCHAR()
/score : INT
/date : DATETIME
/level : INT

<구현>
- 아이디 중복 시 아이디 중복 메시지가 뜨도록
- 비밀번호 입력과 비밀번호 확인 입력이 같을 때에만 회원가입이 되도록
- 닉네임 중복 구현하지 못함.

- 게임화면이 선택되어 있어야(화면을 더블클릭해야) 게임을 플레이 할 수 있으며, 난이도 선택/순위 조회가 가능
- 메뉴바를 통해 난이도 조절을 할 수 있음. (Easy/Normal/Hard/Hell)
- 공마다 크기와 속도가 다름
- 난이도 조절 시 점수 등 기록이 리셋 됨.

- 자기 기록 / 전체 기록을 볼 수 있음.
- 전체 기록의 경우 중복되는 닉네임의 점수들 중 최고값으로 각 닉네임 순위를 계산하여 출력
- 랭킹 조회는 모달리스로 구현. 한 번 종료하면 다시 메뉴에서 누르더라도 실행되지 않음.
- 대신, 조회를 누르면 새로 초기화되서 목록이 출력됨.
