## โจทย์
จงเขียนฟังก์ชันในการตรวจสอบตัวเลขที่ผู้ใช้ป้อนเข้ามา ว่าเป็นตัวเลขที่เป็นอาร์มสตรองหรือไม่ หากใช่ให้แสดงคำว่า Pass หากไม่ใช่แสดงคำว่า Not Pass
<br /><br />**หมายเหตุ** : ตัวเลขอาร์มสตรอง คือ ตัวเลขที่ผลรวมของเลขยกกำลังของจำนวนหลัก เช่น
153 เป็นตัวเลขอาร์มสตรอง เพราะ 153 มีทั้งหมด 3 หลัก จึงมีค่าเท่ากับ = 1^3 +  5^3 +  3^3 (โดยที่เครื่องหมาย ^ หมายถึงเลขยกกำลัง)
370 = 3^3 + 7^3 + 0^3

## FIX CODE
```c++
#include <stdio.h>

int ipow( int base, int exp ) {
    int r = 1 ;
    for ( int i = 0; i < exp; i++ )
        r *= base ;
    return r ;
}

int isArmstrong( int n ) {
    if ( n < 0 )
        return 0 ;
    int digits = 0, temp = n ;

    /* นับจำนวนหลัก (อย่างน้อย 1 หลักสำหรับ 0) */
    do
    {
        digits++ ;
        temp /= 10 ;
    } while ( temp != 0 ) ;

    /* คำนวณผลรวมเลขยกกำลังจำนวนหลัก */
    int sum = 0 ;
    temp = n ;
    do 
    {
        int d = temp % 10 ;
        sum += ipow( d, digits ) ;
        temp /= 10 ;
    } while ( temp != 0 ) ;

    return sum == n ;
}

int main() {
    int n ;

    printf( "Enter Number:\n" ) ;
    if ( scanf("%d", &n) != 1 )
        return 0 ;

    if ( isArmstrong(n) )
        printf( "Pass.\n" ) ;
    else
        printf( "Not Pass.\n" ) ;

    return 0 ;//end function
}

```

## TEST CASE
### Input
```bash
Enter Number:
153
```
### Output
```bash
Pass.
```

## TEST CASE
### Input
```bash
Enter Number:
370
```
### Output
```bash
Pass.
```

## TEST CASE
### Input
```bash
Enter Number:
372
```
### Output
```bash
Not Pass.
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

