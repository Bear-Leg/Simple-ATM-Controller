# Simple-ATM-Controller
간단한 ATM Controller를 구현한 코드입니다.
파이프라인은 다음과 같습니다.  
카드에 맞는 PIN번호를 입력(디폴트 카드의 PIN번호는 0000입니다.) -> 사용자 계정에 등록된 계좌를 선택 -> 입금/출금/잔액 선택 


## File Struct
- main.cpp : 프로그램의 메인 코드 입니다.

~~~
├──  README.md
├──  main.cpp
├──  CMakeLists.txt
└──  include
    ├── user.cpp / h
    ├── system.cpp / h
    ├── account.cpp /h
~~~


# How to run
`$ cd Simple-ATM-Controller`  
`$ mkdir build`  
`$ cd build`  
`$ cmake .. && make`  
`$ ./ATM_Controller`
