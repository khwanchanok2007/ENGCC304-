## โจทย์
จงแก้ไขโค้ดต่อไปนี้ ให้สามารถรับค่าจากผู้ใช้ เพื่อแสดงผลบนหน้าจอคอมพิวเตอร์ให้ได้ พร้อมทั้งจัดรูปแบบให้ตรงตาม Syntax ที่เรียนมาในห้องเรียน

```c++
#include <stduio.h>

int main() {
    char Name[50] ;
    int  Age = 0 ;
    printf( "Enter your name: " ) 
    scanf( "%s", Name ) ;
    printf( "Enter your age: " ) ;
    scanf( "%d", Age ) ;
    print( "- - - - - -\n" ) ;
    printf( "Hello %s \n", ___ ) ; 
    printf( "Age = %d\n", ___ ) ; 
    
}//end main function
```

## FIX CODE
```c++
#include <stdio.h> 

int main() {
    char Name[50] ;
    int  Age ;
    printf( "Enter your name: ",Name);
    scanf( "%s", Name ) ;
    printf( "Enter your age: ", Age ) ;
    scanf( "%d", &Age ) ;
    printf( "- - - - - -\n" ) ;
    printf( "name= %s \n",Name ) ; 
    printf( "Age = %d\n", Age ) ;  
    
}//end main function

```

## TEST CASE
### Input
```bash
Enter your name: Thongchai
Enter you age: 56
```
![image](https://github.com/user-attachments/assets/fbd5207e-a333-4fb9-8ef8-f66a75e898b3)

### Output
```bash
- - - - - -
Hello Thongchai
Age = 56
```
![image](https://github.com/user-attachments/assets/7ea8120a-1aa9-487b-839b-63ff62f878a9)
