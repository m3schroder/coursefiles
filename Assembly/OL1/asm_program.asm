;Matthew Schroder
;CSCI 3130
;Open Lab 1
;1/29/2018

global main
extern cPrint

segment.text

main:
        mov rdi, message
        mov rsi, 76
        call cPrint
        ret

segment.data

        message         db      "I kill an ant", 10, "and realize my three children", 10, "have been watching",10, "-Kato Shuson", 10
