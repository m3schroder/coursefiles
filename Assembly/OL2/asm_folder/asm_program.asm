global main

   extern printf



  segment .text





   main:

  

           mov r14, array          ;add x to each iteration



         mov rcx, 0             ;rcx will be the counter



         jmp loop
 loop:



         cmp rcx, 13

         je done



         push r14

         push rcx





         mov r8,[r14]

         mov r9,[r14+8]
         mov r10,[r14+16]

         mov r11,[r14+24]


         call compute



         mov [result], rax



         call print              ;look again later



         pop rcx

         pop r14


         add r14, 8

         inc rcx

         jmp loop


 compute:

         add r8, r9              ;get sum of 1st and 2nd



         sub r10, r11            ;get difference of 3rd and 4th



         mov rax, r8             ;multiply the sum and difference



         mul r10                 ;move the final product into rax


         ret



 print:                          ;this should be all right

         mov rdi, string

         mov rsi, [r14]
	 mov rdx, [r14 + 8]
         mov rcx, [r14+16]
	 mov r8, [r14+24]
         mov rax,0
         call printf             ;( rsi + rdx ) * ( rcx - r8 ) = 

	mov rdi, strAnswer
	mov rsi, [result]
	mov rax,0
        call printf

        ret



  done:



         mov rax, 60

         mov rdi, 0

         syscall



 segment .data


         array: dq 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15

         string: db "( %ld + %ld ) * ( %ld - %ld ) = " ,0
         strAnswer: db "%ld", 10, 0

         result: dq 0

 