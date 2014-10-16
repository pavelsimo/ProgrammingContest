       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 BIN-VAR PIC X(16). 
       01 NUMER1 PIC 9(5).                                     
       01 I      PIC 99.                                       
       01 J      PIC 9.
       01 A1        PIC X(1)   VALUE ZEROES.
       01 A2        PIC X(2)   VALUE ZEROES.
       01 A3        PIC X(3)   VALUE ZEROES.
       01 A4        PIC X(4)   VALUE ZEROES.
       01 A5        PIC X(5)   VALUE ZEROES.
       01 A6        PIC X(6)   VALUE ZEROES.
       01 A7        PIC X(7)   VALUE ZEROES.
       01 A8        PIC X(8)   VALUE ZEROES.
       01 A9        PIC X(9)   VALUE ZEROES.

       PROCEDURE DIVISION.
         ACCEPT NUMER1.                                       
         PERFORM VARYING I FROM 16 BY -1 UNTIL I < 1         
            DIVIDE NUMER1 BY 2 GIVING NUMER1 REMAINDER J       
            MOVE J TO BIN-VAR(I:1)                             
         END-PERFORM.
         IF BIN-VAR < 10 THEN
            MOVE BIN-VAR TO A1
            DISPLAY A1
         ELSE IF BIN-VAR < 100 THEN
            MOVE BIN-VAR TO A2
            DISPLAY A2
         ELSE IF BIN-VAR < 1000 THEN
            MOVE BIN-VAR TO A3
            DISPLAY A3
         ELSE IF BIN-VAR < 10000 THEN
            MOVE BIN-VAR TO A4
            DISPLAY A4
         ELSE IF BIN-VAR < 100000 THEN
            MOVE BIN-VAR TO A5
            DISPLAY A5
         ELSE IF BIN-VAR < 1000000 THEN
            MOVE BIN-VAR TO A6
            DISPLAY A6
         END-IF                               . 
         STOP RUN.
         
