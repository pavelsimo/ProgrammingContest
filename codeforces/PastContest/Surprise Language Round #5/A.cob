       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 A        PIC 9(10)   VALUE ZEROES.
       01 B        PIC 9(10)   VALUE ZEROES.
       01 STR      PIC X(10).
       01 A1       PIC 9(1).
       01 A2       PIC 9(2).
       01 A3       PIC 9(3).
       01 A4       PIC 9(4).
       01 A5       PIC 9(5).
       01 A6       PIC 9(6).
       01 A7       PIC 9(7).

       PROCEDURE DIVISION.
         ACCEPT STR
         MOVE STR TO A
         ACCEPT STR
         MOVE STR TO B
         ADD A TO B
         IF B < 10 THEN
            MOVE B TO A1
            DISPLAY A1
         ELSE IF B < 100 THEN
            MOVE B TO A2
            DISPLAY A2
         ELSE IF B < 1000 THEN
            MOVE B TO A3
            DISPLAY A3
         ELSE IF B < 10000 THEN
            MOVE B TO A4
            DISPLAY A4
         ELSE IF B < 100000 THEN
            MOVE B TO A5
            DISPLAY A5
         ELSE IF B < 1000000 THEN
            MOVE B TO A6
            DISPLAY A6
         END-IF
         STOP RUN.
         
