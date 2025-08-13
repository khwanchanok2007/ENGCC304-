## โจทย์
จงเขียนโปรแกรมทายตัวเลขซึ่งทำงานดังนี้
- ตอนเริ่มเกมผู้เล่นจะมีคะแนนเต็ม 100
- โปรแกรมจะสุ่มตัวเลขที่มีค่าตั้งแต่ 1 ถึง 100
- ให้ผู้เล่นทายว่าตัวเลขที่โปรแกรมสุ่มมามีค่าเป็นเท่าใด
- หากทายผิด โปรแกรมจะลบคะแนนของผู้เล่นไป 10 หน่วย พร้อมแจ้งคะแนนปัจจุบันให้ผู้เล่นทราบด้วย
- หากทายผิด โปรแกรมจะต้องบอกใบ้ว่าคำตอบที่ถูกมีค่า "มากกว่า" หรือ "น้อยกว่า" ตัวเลขที่ผู้ใช้ทาย
- หากทายผิด ให้โปรแกรมรอรับตัวเลขถัดไปได้เลย
- หากทายถูก ให้โปรแกรมแสดงความยินดีกับผู้ใช้ พร้อมแจ้งคะแนนปัจจุบันให้กับผู้เช่น
- เมื่อเล่นเสร็จโปรแกรมรอรับคำสั่งจากผู้ใช้ หากผู้ใช้กรอกเลข 1 จะเข้าสู่โหมดการเล่นเกมใหม่อีกครั้ง หากกด -1 ให้หยุดการทำงานของโปรแกรม

<br />หมายเหตุ : การสุ่มตัวเลขจะใช้คำสั่ง rand() ที่อยู่ใน stdlib.h หากต้องการสุ่มตัวเลข 0 ถึง 100 ต้องใช้คำสั่งดังนี้
```c++
rand() % 100 + 1
```
<br />หมายเหตุ : หากต้องการสุ่มตัวเลขที่เปลี่ยนแปลงตามเวลา ต้องใช้คำสั่ง srand( time( NULL ) ) ในตอนต้นของโปรแกรมด้วย
```c++
srand( time( NULL ) ) ;
```

## FIX CODE
```c++
#include <stdio.h>
#include <stdlib.h> // สำหรับฟังก์ชันที่เกี่ยวข้องกับการแปลงข้อมูล
#include <time.h>   // สำหรับใช้กับฟังก์ชัน time() เพื่อทำคำตอบให้ random เปลี่ยนทุกครั้ง

int main()
{
    int play, answer, guess, score; // play เก็บค่า 1 หรือ -1 answer คำตอบ guess ตัวเลขที่ผู้ใช้ทายคะแนน
    int min, max;                   // min, max – ขอบเขตของการทาย 1-100
    char input[100];

    srand(time(NULL)); // ให้สุ่มตัวเลขเปลี่ยนทุกครั้งโดยใช้เวลา

    do
    { // เริ่มต้นลูป do-while เพื่อให้เล่นซ้ำจนกว่าจะเลือก -1
        printf("Do you want to play game (1=play,-1=exit) :\n");
        fgets(input, sizeof(input), stdin); // รับค่าที่ผู้ใช้พิมพ์โดยไม่สนว่าจะถูกหรือผิดก่อนแล้วค่อยไปตรวจสอบภายหลัง

        if (sscanf(input, "%d", &play) != 1 || (play != 1 && play != -1))
        { // sscanf() พยายามแปลง input ให้เป็นเลขจำนวนเต็มแล้วเก็บใน play
            // ถ้าแปลงไม่ได้ (!= 1) หรือค่าที่กรอกไม่ใช่ 1 หรือ -1 ถือว่าไม่ถูกต้อง
            printf("Please enter only 1 or -1.\n\n");
            play = 0; // แจ้งว่าค่าที่ป้อนไม่ถูกต้อง แล้ววนลูปใหม่
            continue;
        }

        if (play == 1)
        {
            answer = rand() % 100 + 1;
            score = 100;
            min = 1;
            max = 100;

            printf("\n(Score=100)\n\n");

            while (1)
            {                                                             // ลูปไม่มีที่สิ้นสุดรอให้ผู้เล่นทายถูกจึงจะbreak
                printf("Guess the winning number (%d-%d) :\n", min, max); // ให้ผู้ใช้ทายเลขพร้อมบอกช่วง(min-max)
                fgets(input, sizeof(input), stdin);                       // รับค่าที่ผู้ใช้พิมพ์โดยไม่สนว่าจะถูกหรือผิดก่อนแล้วค่อยไปตรวจสอบภายหลัง

                if (sscanf(input, "%d", &guess) != 1 || guess < min || guess > max)
                { // ตรวจสอบว่าค่าที่ป้อนเป็นตัวเลขหรือไม่และอยู่ในช่วงที่กำหนดหรือเปล่า
                    printf("Invalid input. Please enter a number between %d and %d.\n\n", min, max);
                    continue; // ข้ามคำสั่งที่เหลือในลูปรอบนั้นแล้วกลับไปเริ่มรอบใหม่
                }

                if (guess == answer)
                { // แจ้งว่าถูกต้องแสดงคำตอบที่ถูกแสดงคะแนนแล้ว break ออกจากลูป
                    printf("\nThat is correct! The winning number is %d.\n", answer);
                    printf("\nScore this game: %d\n\n", score);
                    break; //	หยุดลูปทันทีเมื่อคำตอบถูก
                }

                score -= 10; // เมื่อทายผิด

                if (guess < answer)
                { // บอกช่วงที่จะทายถ้าทายน้อยเกินไป
                    printf("\nSorry, the winning number is HIGHER than %d. (Score=%d)\n\n", guess, score);
                    if (guess + 1 > min)
                        min = guess + 1;
                }
                else
                { // บอกช่วงที่จะทายถ้าทายมากเกินไป
                    printf("\nSorry, the winning number is LOWER than %d. (Score=%d)\n\n", guess, score);
                    if (guess - 1 < max)
                        max = guess - 1;
                }

                if (score == 0) {
                    printf("Game over. Please start again.\n\n");
                    break;
                }
            }
        }

    } while (play != -1); // ทำลูปซ้ำถ้าผู้เล่นยังไม่เลือกออก (-1)

    printf("\nSee you again.\n");
    return 0;
}

```

## TEST CASE
### Input & Output
```bash
Do you want to play game (1=play,-1=exit) :
1

(Score=100)

Guess the winning number (1-100) :
20

Sorry, the winning number is HIGHER than 20. (Score=90)

Guess the winning number (21-100) :
50

Sorry, the winning number is LOWER than 50. (Score=80)

Guess the winning number (21-49) :
42

That is correct! The winning number is 42.

Score this game: 80

Do you want to play game (1=play,-1=exit) :
-1

See you again.
```

## TEST CASE
### Input & Output
```bash
Do you want to play game (1=play,-1=exit) :
hi

Please enter only 1 or -1.

Do you want to play game (1=play,-1=exit) :
-1

See you again.
```

## TEST CASE
### Input & Output
```bash
Do you want to play game (1=play,-1=exit) :
1

(Score=100)

Guess the winning number (1-100) :
20

Sorry, the winning number is HIGHER than 20. (Score=90)

Guess the winning number (21-100) :
50

Sorry, the winning number is LOWER than 50. (Score=80)

Guess the winning number (21-49) :
10

Sorry, the winning number is HIGHER than 21. (Score=70)

Guess the winning number (21-49) :
60

Sorry, the winning number is LOWER than 49. (Score=60)

Guess the winning number (21-49) :
22

Score this game: 60

That is correct! The winning number is 22.

Do you want to play game (1=play,-1=exit) :
1

(Score=100)

Guess the winning number (1-100) :
20

Score this game: 100

That is correct! The winning number is 20.

Do you want to play game (1=play,-1=exit) :
-1

See you again.
```

## มาตรฐานการตรวจตามหลักการเรียนรู้ของบลูม
| ลำดับการเรียนรู้ | เกณฑ์การวัด | คะแนน |
| -------- | -------- | -------- |
| รู้จำ | เห็นโครงสร้างของโค้ดโปรแกรมชัดเจน ได้มาตรฐาน | 1 pts |
| เข้าใจ | แก้ไขปัญหาได้ตามที่โจทย์กำหนด | 1 pts |
| ประยุกต์ใช้ | สามารถผ่านเงื่อนไขได้ทุก testcase | 1 pts |
| วิเคราะห์ | หาจุดผิดของโปรแกรมได้ | 1 pts |
| ประเมินค่า | โปรแกรมเสร็จสมบูรณ์ระยะเวลาที่กำหนด | 1 pts |
| สร้างสรรค์ | แก้ไขสถานการณ์ของโจทย์ | 1 pts |
||<p style='text-align: right !important;'>**รวม**</p>|**6 pts**|
